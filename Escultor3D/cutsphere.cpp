#include "cutsphere.h"

CutSphere::CutSphere(int _xc, int _yc, int _zc, int _raio)
{
    xc = _xc;
    yc = _yc;
    zc = _zc;
    raio = _raio;
}

void CutSphere::draw(Sculptor &S)
{
    S.cutSphere(xc,yc,zc,raio);
}
