#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

class PutSphere : public FiguraGeometrica
{
protected:
    int xc,yc,zc,raio;
    float r,g,b,a;
public:
    PutSphere(int _xc, int _yc, int _zc, int _raio, float _r, float _g, float _b, float _a);
    void draw(Sculptor &S);
};

#endif // PUTSPHERE_H
