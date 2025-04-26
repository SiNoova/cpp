#include "Point.hpp"


int pvec_pos(Point const &vec1, Point const &vec2) 
{
    Fixed cross = vec1.getX() * vec2.getY() - vec1.getY() * vec2.getX();
    return (cross > 0) - (cross < 0);
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Point vecAB(b.getX() - a.getX(), b.getY() - a.getY());
    Point vecAP(point.getX() - a.getX(), point.getY() - a.getY());
    Point vecBC(c.getX() - b.getX(), c.getY() - b.getY());
    Point vecBP(point.getX() - b.getX(), point.getY() - b.getY());
    Point vecCA(a.getX() - c.getX(), a.getY() - c.getY());
    Point vecCP(point.getX() - c.getX(), point.getY() - c.getY());

    int apAbSign = pvec_pos(vecAP, vecAB);
    int bpBcSign = pvec_pos(vecBP, vecBC);
    int cpCaSign = pvec_pos(vecCP, vecCA);

    if (!apAbSign || !bpBcSign || !cpCaSign)
        return (0);
    return ((apAbSign > 0 && bpBcSign > 0 && cpCaSign > 0) ||
        (apAbSign < 0 && bpBcSign < 0 && cpCaSign < 0));
}