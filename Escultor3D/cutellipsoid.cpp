#include "cutellipsoid.h"

CutEllipsoid::CutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz)
{
    xc = _xc;
    yc = _yc;
    zc = _zc;
    rx = _rx;
    ry = _ry;
    rz = _rz;
}

void CutEllipsoid::draw(Sculptor &S)
{
    S.cutEllipsoid(xc,yc,zc,rx,ry,rz);
}
