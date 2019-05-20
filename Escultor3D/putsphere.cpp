#include "putsphere.h"

PutSphere::PutSphere(int _xc, int _yc, int _zc, int _raio, float _r, float _g, float _b, float _a)
{
    xc = _xc;
    yc = _yc;
    zc = _zc;
    raio = _raio;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void PutSphere::draw(Sculptor &S)
{
    S.setColor(r,g,b,a);
    S.putSphere(xc,yc,zc,raio);
}
