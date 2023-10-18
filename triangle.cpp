#include "qgraphicsitem.h"


#include "triangle.h"
#include "helper.h"


#include <iostream>
#include <ostream>


Triangle::Triangle(std::shared_ptr<QGraphicsScene> p_myScene):_currentScene{p_myScene}
{

}
Triangle::~Triangle(){
    this->clear();
}
void Triangle::addPoint(const QPointF p_point){

    _points.append(p_point);

    QGraphicsEllipseItem *pointColor = new QGraphicsEllipseItem(p_point.x(), p_point.y(), 4, 4);
    pointColor->setBrush(Qt::red);
    _currentScene->addItem(pointColor);

    _pointsItem.append(pointColor);

}
void Triangle::display(){

    uint index=0;
    for(uint i=0;i<2;i++){
        for(uint j=i+1;j<3;j++){
            QGraphicsLineItem *line = new QGraphicsLineItem(_points[i].x(), _points[i].y(), _points[j].x(), _points[j].y());
            line->setPen(QPen(Qt::blue, 3, Qt::SolidLine));
            _linesItem[index]=line;
            _currentScene->addItem(line);
            index++;
        }
    }

}
void Triangle::clear(){

   for(QGraphicsLineItem* line : _linesItem){
        _currentScene->removeItem(line);
   }

    for(QGraphicsEllipseItem* point : _pointsItem){
        _currentScene->removeItem(point);
    }



    for (QGraphicsEllipseItem* item : _pointsItem) {
        delete item;
    }

    for (uint i = 0; i < 3; i++) {
        if (_linesItem[i] != nullptr) {
            delete _linesItem[i];
            _linesItem[i] = nullptr;
        }
    }

    _pointsItem.clear();

}


bool Triangle::pointInsideTriangle (QPointF p_point)const
{
    float o1, o2, o3;
    bool negative, positive;

    o1 = Helper::sign(p_point, _points[0], _points[1]);
    o2 =Helper::sign(p_point, _points[1], _points[2]);
    o3 = Helper::sign(p_point, _points[2], _points[0]);

    negative = (o1 < 0) || (o2 < 0) || (o3 < 0);
    positive = (o1 > 0) || (o2 > 0) || (o3 > 0);

    return !(negative && positive);//if its the same orientation return true
}


Polygone Triangle::intersect(const std::unique_ptr<Triangle>& p_other)const{ // Other = Triangle Fixe

    QPointF result;
    QList<QPointF> allIntersectedPoints;

    uint secondIndexThisTriangle,secondIndexOtherTriangle;
    for(uint i=0;i<3;i++){// indices => 0-1  1-2  2-0

        secondIndexThisTriangle=(i+1)%3;

        QList<QPointF> allAcceptedPoint{};

        for(uint j=0;j<3;j++){
            secondIndexOtherTriangle=(j+1)%3;

            bool intersect=Helper::lineIntersection(_points[i],_points[secondIndexThisTriangle],p_other->_points[j],p_other->_points[secondIndexOtherTriangle],result);

            if(intersect){
                allAcceptedPoint.append(result);
            }
        }

        //ajouter les points qui sont dans le triangle
        if(p_other->pointInsideTriangle(_points[i]))
            allIntersectedPoints.append(_points[i]);

        if(this->pointInsideTriangle(p_other->_points[i]))
            allIntersectedPoints.append(p_other->_points[i]);

        //ajouter les intersections de ligne
        if(allAcceptedPoint.size()==1){
            allIntersectedPoints.append(allAcceptedPoint[0]);
        }else if(allAcceptedPoint.size()>1){

              QPointF currentPoint=_points[i];
              std::sort(allAcceptedPoint.begin(), allAcceptedPoint.end(), [&currentPoint](const QPointF& a, const QPointF& b) {
                  return Helper::compareDistance(a, b, currentPoint);
              });

                allIntersectedPoints.append(allAcceptedPoint);
        }
    }

    allIntersectedPoints.shrink_to_fit();
    return Polygone(allIntersectedPoints,_currentScene);

}
