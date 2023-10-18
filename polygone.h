#ifndef POLYGONE_H
#define POLYGONE_H


#include "qgraphicsscene.h"
#include "qpoint.h"
#include <list>
class Polygone
{
public:
    Polygone()=delete;
    Polygone(const QList<QPointF>& p_listPoints, std::shared_ptr<QGraphicsScene> p_scene);
    ~Polygone();
    void display();
    void removeDisplay();
private:

    bool isClockWise()const;
    void makeClockWise();

    QList<QPointF> _listPoints{};
    std::shared_ptr<QGraphicsScene> _currentScene{nullptr};
    QList< QGraphicsEllipseItem*> _pointsItem{};
    QList< QGraphicsLineItem*> _linesItem{};
};

#endif // POLYGONE_H
