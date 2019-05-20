#include "cutvoxel.h"

CutVoxel::CutVoxel(int _x, int _y, int _z)
{
    x = _x;
    y = _y;
    z = _z;
}

void CutVoxel::draw(Sculptor &S)
{
    S.cutVoxel(x,y,z);
}
