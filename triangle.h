#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "polygone.h"
#include "qgraphicsscene.h"
#include "qpoint.h"

class Triangle
{
public:
    Triangle(std::shared_ptr<QGraphicsScene> p_myScene);
    Triangle(const QPointF p_p0,const QPointF p_p1,const QPointF p_p2);
    ~Triangle();
    void display();
    void clear();

    Polygone intersect(const std::unique_ptr<Triangle>& p_other)const;
    bool pointInsideTriangle(const QPointF p_point)const;
    void addPoint(const QPointF p_point);
private:
    std::shared_ptr<QGraphicsScene> _currentScene{nullptr};
    QList<QPointF> _points;
    QGraphicsLineItem *_linesItem[3];
    QList<QGraphicsEllipseItem*> _pointsItem;

};

#endif // TRIANGLE_H
