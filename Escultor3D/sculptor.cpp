#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <math.h>

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx; ny = _ny; nz = _nz;

    if(nx <= 0 || ny <= 0 || nz <= 0){
        nx = ny = nz = 0;
    }

    v = new Voxel**[nx];
    for(int i=0; i<nx; i++){
        v[i] = new Voxel*[ny];
        for(int j=0; j<ny; j++){
           v[i][j] = new Voxel[nz];
        }
    }

    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
                v[i][j][k].isOn = false;
            }
        }
    }

}

Sculptor::~Sculptor()
{
    std::cout << "Objeto destruido\n";
    if(nx == 0 || ny == 0 || nz ==0){
        return;
    }

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            delete [] v[i][j];
        }
            delete [] v[i];
    }
            delete [] v;
}

void Sculptor::setColor(float _r, float _g, float _b, float alpha)
{
    r = _r; g = _g; b = _b; a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i = x0; i<=x1; i++){
        for(int j = y0; j<=y1; j++){
            for(int k = z0; k<=z1; k++){
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
                v[i][j][k].isOn = true;
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i = x0; i<=x1; i++){
        for(int j = y0; j<=y1; j++){
            for(int k = z0; k<=z1; k++){
                v[i][j][k].isOn = false;
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int dist = 0;
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                dist = (i-xcenter)*(i-xcenter) + (j-ycenter)*(j-ycenter) + (k-zcenter)*(k-zcenter);

                if(dist <= radius*radius){
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                    v[i][j][k].isOn = true;
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int dist = 0;
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                dist = (i-xcenter)*(i-xcenter) + (j-ycenter)*(j-ycenter) + (k-zcenter)*(k-zcenter);

                if(dist <= radius*radius){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int dist = 0;
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                dist = (i-xcenter)*(i-xcenter)/(rx*rx) + (j-ycenter)*(j-ycenter)/(ry*ry) + (k-zcenter)*(k-zcenter)/(rz*rz);

                if(dist <= 1){
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                    v[i][j][k].isOn = true;
                }
            }
        }
    }

}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int dist = 0;
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                dist = (i-xcenter)*(i-xcenter)/(rx*rx) + (j-ycenter)*(j-ycenter)/(ry*ry) + (k-zcenter)*(k-zcenter)/(rz*rz);

                if(dist <= 1){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void Sculptor::writeOFF(std::string filename)
{
    std::ofstream fout;
    int cont=0;
    fout.open(filename);
      if(fout.is_open()){
        std::cout << "Sucesso na abertura do arquivo\n";
      }
      else{
        std::cout << "Falha na abertura do arquivo\n";
        exit(1);
      }

      for(int i = 0; i<nx; i++){
          for(int j = 0; j<ny; j++){
              for(int k = 0; k<nz; k++){
                  if(v[i][j][k].isOn){
                      cont++;
                  }
              }
          }
      }

      fout << "OFF\n";
      fout << cont*8 << " " << cont*6 << " " << 0 << "\n";

      for(int i = 0; i<nx; i++){
          for(int j = 0; j<ny; j++){
              for(int k = 0; k<nz; k++){
                  if(v[i][j][k].isOn){
                      fout << i-0.5 << " " << j+0.5 << " " << k-0.5 << "\n";
                      fout << i-0.5 << " " << j-0.5 << " " << k-0.5 << "\n";
                      fout << i+0.5 << " " << j-0.5 << " " << k-0.5 << "\n";
                      fout << i+0.5 << " " << j+0.5 << " " << k-0.5 << "\n";
                      fout << i-0.5 << " " << j+0.5 << " " << k+0.5 << "\n";
                      fout << i-0.5 << " " << j-0.5 << " " << k+0.5 << "\n";
                      fout << i+0.5 << " " << j-0.5 << " " << k+0.5 << "\n";
                      fout << i+0.5 << " " << j+0.5 << " " << k+0.5 << "\n";
                  }
              }
          }
      }

      cont = 0;
      for(int i = 0; i<nx; i++){
          for(int j = 0; j<ny; j++){
              for(int k = 0; k<nz; k++){
                  if(v[i][j][k].isOn){

                      char cr[6], cg[6], cb[6],ca[6];
                      std::sprintf(cr,"%.3f",v[i][j][k].r);
                      std::sprintf(cg,"%.3f",v[i][j][k].g);
                      std::sprintf(cb,"%.3f",v[i][j][k].b);
                      std::sprintf(ca,"%.3f",v[i][j][k].a);

                      fout << 4 << " " << cont*8+ 0 << " " << cont*8+ 3 << " " << cont*8+ 2 << " " << cont*8+ 1 << " " << cr << " " << cg << " " << cb << " " << ca << "\n";
                      fout << 4 << " " << cont*8+ 4 << " " << cont*8+ 5 << " " << cont*8+ 6 << " " << cont*8+ 7 << " " << cr << " " << cg << " " << cb << " " << ca << "\n";
                      fout << 4 << " " << cont*8+ 0 << " " << cont*8+ 1 << " " << cont*8+ 5 << " " << cont*8+ 4 << " " << cr << " " << cg << " " << cb << " " << ca << "\n";
                      fout << 4 << " " << cont*8+ 0 << " " << cont*8+ 4 << " " << cont*8+ 7 << " " << cont*8+ 3 << " " << cr << " " << cg << " " << cb << " " << ca << "\n";
                      fout << 4 << " " << cont*8+ 3 << " " << cont*8+ 7 << " " << cont*8+ 6 << " " << cont*8+ 2 << " " << cr << " " << cg << " " << cb << " " << ca << "\n";
                      fout << 4 << " " << cont*8+ 1 << " " << cont*8+ 2 << " " << cont*8+ 6 << " " << cont*8+ 5 << " " << cr << " " << cg << " " << cb << " " << ca << "\n";

                      cont++;
                  }
              }
          }
      }


      fout.close();
}

void Sculptor::writeVECT(std::string filename)
{
    std::cout << "O arquivo " << filename << " nao pode ser gravado em VECT ainda";
}
