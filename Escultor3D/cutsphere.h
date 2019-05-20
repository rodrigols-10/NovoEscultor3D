#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutSphere : public FiguraGeometrica
{
protected:
    int xc,yc,zc,raio;
public:
    CutSphere(int _xc, int _yc, int _zc, int _raio);
    void draw(Sculptor &S);
};

#endif // CUTSPHERE_H
