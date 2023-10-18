#include "helper.h"
#include "qline.h"

bool Helper::lineIntersection(const QPointF& p_a1, const QPointF& p_a2, const QPointF& p_b1,const  QPointF& p_b2, QPointF& p_r){
    double a1 = p_a2.y() - p_a1.y();
    double b1 = p_a1.x() - p_a2.x();
    double c1 = a1 * p_a1.x() + b1 * p_a1.y();

    double a2 = p_b2.y() - p_b1.y();
    double b2 = p_b1.x() - p_b2.x();
    double c2 = a2 * p_b1.x() + b2 * p_b1.y();

    double denominator = a1 * b2 - a2 * b1;

    // si denominateur =0 alors droite parallele
    if (denominator == 0) {
        return false;
    }

    // retrouver l'intersection
    p_r.setX(  (b2 * c1 - b1 * c2) / denominator);
    p_r.setY( (a1 * c2 - a2 * c1) / denominator);

    //calcul pour verifier la distance d'intersection
    double t = ((p_r.x() - p_a1.x()) / (p_a2.x() - p_a1.x()));
    double s = ((p_r.x() - p_b1.x()) / (p_b2.x() - p_b1.x()));

    if (t > 0 && t < 1 && s > 0 && s < 1) { // regarder si l'intersection est sur le segment et non la droite
        return true;
    } else {
        return false;
    }
}

float Helper::sign(const QPointF& p1,const QPointF& p2,const QPointF& p3)//determiner l'orientation de point
{
    return (p1.x() - p3.x()) * (p2.y() - p3.y()) - (p2.x() - p3.x()) * (p1.y() - p3.y());
}


float Helper::pointDistance(const QPointF& p1,const QPointF& p2){
    float dx = p2.x() - p1.x();
    float dy = p2.y() - p1.y();
    return std::sqrt(dx * dx + dy * dy);
}
bool Helper::compareDistance(const QPointF& p_p1, const QPointF& p_p2, const QPointF& p_ref) {
    qreal distance1 = QLineF(p_p1, p_ref).length();
    qreal distance2 = QLineF(p_p2, p_ref).length();
    return distance1 < distance2;
}
