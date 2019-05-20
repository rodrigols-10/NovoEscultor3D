#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

class PutEllipsoid : public FiguraGeometrica
{
protected:
    int xc,yc,zc,rx,ry,rz;
    float r,g,b,a;
public:
    PutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);
    void draw(Sculptor &S);
};

#endif // PUTELLIPSOID_H
