#include "polygone.h"
#include "qgraphicsitem.h"

Polygone::Polygone(const QList<QPointF>& p_listPoints,std::shared_ptr<QGraphicsScene> p_myScene): _listPoints{p_listPoints}, _currentScene{p_myScene}
{
}

void Polygone::display(){


    for(QPointF currentPoint:_listPoints){
        QGraphicsEllipseItem *point = new QGraphicsEllipseItem(currentPoint.x(), currentPoint.y(), 4, 4);
        point->setBrush(Qt::yellow);
        _currentScene->addItem(point);
        _pointsItem.append(point);
    }

    for(uint i=0;i<_listPoints.size()-1;i++){
        QGraphicsLineItem *line = new QGraphicsLineItem(_listPoints[i].x(), _listPoints[i].y(), _listPoints[i+1].x(), _listPoints[i+1].y());
        line->setPen(QPen(Qt::red, 3, Qt::SolidLine));
        _currentScene->addItem(line);
        _linesItem.append(line);
    }
    if(_listPoints.size()>2){
        QGraphicsLineItem *line = new QGraphicsLineItem(_listPoints[0].x(), _listPoints[0].y(), _listPoints[_listPoints.size()-1].x(), _listPoints[_listPoints.size()-1].y());
        line->setPen(QPen(Qt::red, 3, Qt::SolidLine));
        _linesItem.append(line);
        _currentScene->addItem(line);
    }


}

Polygone::~Polygone() {
    removeDisplay();
}

void Polygone::removeDisplay(){
    for (QGraphicsEllipseItem* item : _pointsItem) {
        delete item;
    }
    _pointsItem.clear();

    for (QGraphicsLineItem* item : _linesItem) {
        delete item;
    }
    _linesItem.clear();
}
