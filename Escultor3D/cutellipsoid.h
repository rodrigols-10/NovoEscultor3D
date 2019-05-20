#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutEllipsoid : public FiguraGeometrica
{
protected:
    int xc,yc,zc,rx,ry,rz;
public:
    CutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz);
    void draw(Sculptor &S);
};

#endif // CUTELLIPSOID_H
