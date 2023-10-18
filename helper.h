#ifndef HELPER_H
#define HELPER_H


#include "qpoint.h"

class Helper{ //create a class helper for function that can be used by multiple classJAMAIS DE CLASS DANS CPP, destructeur, erruer, pas utiliser nb click, unique ptr, intersection vide, tri des points clockwise , par ref au lieu par copie dans helper, faire une class object

public:
    static bool lineIntersection(const QPointF& p_a1, const QPointF& p_a2, const QPointF& p_b1,const  QPointF& p_b2, QPointF &p_r);
    static float sign (const QPointF& p_p1,const QPointF& p_p2,const QPointF& p_p3);
    static float pointDistance(const QPointF& p_p1,const QPointF& p_p2);
    static bool compareDistance(const QPointF& p_p1, const QPointF& p_p2, const QPointF& p_ref);
};

#endif // HELPER_H
