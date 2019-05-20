#include <iostream>
#include "sculptor.h"
#include <string>
#include "figurageometrica.h"
#include "putvoxel.h"
#include "putbox.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "cutsphere.h"
#include "cutellipsoid.h"

#include "vector"
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

int main()
{
    ifstream fin;
    string s;
    stringstream ss;
    Sculptor *obj;
    int nx=0,ny=0,nz=0;
    float r,g,b,a;
    int opt;

    vector<FiguraGeometrica*> fig;
    unsigned int qtd = 0;

    cout << "1- Ler arquivo?" << endl;
    cout << "2- Criar escultura?" << endl;
    cout << "Opcao: ";
    cin >> opt;
    if(opt == 1){

        fin.open("TESTE.txt");
          if(!fin.is_open()){
            exit(0);
          }

        getline(fin, s);
        ss.str(s);
        ss >> s;
        ss >> nx >> ny >> nz;
        obj = new Sculptor(nx,ny,nz);
        ss.clear();

        while(fin.good()){
            getline(fin, s);
            ss.str(s);
            ss >> s;

            if(s.compare("putvoxel") == 0){
                int x,y,z;
                ss >> x >> y >> z >> r >> g >> b >> a;
                fig.push_back(new PutVoxel(x,y,z,r,g,b,a));
                fig[qtd]->draw(*obj);
                qtd++;
            }
            if(s.compare("cutvoxel") == 0){
                int x,y,z;
                ss >> x >> y >> z;
                fig.push_back(new CutVoxel(x,y,z));
                fig[qtd]->draw(*obj);
                qtd++;
            }

            if(s.compare("putbox") == 0){
                int x0,x1,y0,y1,z0,z1;
                ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                fig.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
                fig[qtd]->draw(*obj);
                qtd++;
            }
            if(s.compare("cutbox") == 0){
                int x0,x1,y0,y1,z0,z1;
                ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                fig.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
                fig[qtd]->draw(*obj);
                qtd++;
            }

            if(s.compare("putsphere") == 0){
                int xc,yc,zc,raio;
                ss >> xc >> yc >> zc >> raio >> r >> g >> b >> a;
                fig.push_back(new PutSphere(xc,yc,zc,raio,r,g,b,a));
                fig[qtd]->draw(*obj);
                qtd++;
            }
            if(s.compare("cutsphere") == 0){
                int xc,yc,zc,raio;
                ss >> xc >> yc >> zc >> raio;
                fig.push_back(new CutSphere(xc,yc,zc,raio));
                fig[qtd]->draw(*obj);
                qtd++;
            }

            if(s.compare("putellipsoid") == 0){
                int xc,yc,zc,rx,ry,rz;
                ss >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b >> a;
                fig.push_back(new PutEllipsoid(xc,yc,zc,rx,ry,rz,r,g,b,a));
                fig[qtd]->draw(*obj);
                qtd++;
            }
            if(s.compare("cutellipsoid") == 0){
                int xc,yc,zc,rx,ry,rz;
                ss >> xc >> yc >> zc >> rx >> ry >> rz;
                fig.push_back(new CutEllipsoid(xc,yc,zc,rx,ry,rz));
                fig[qtd]->draw(*obj);
                qtd++;
            }

            ss.clear();
        }

        obj->writeOFF("teste99.off");

    } else {

    cout << "Digite as dimensoes da escultura:\nEm X: ";
    cin >> nx;
    cout << "Em Y: ";
    cin >> ny;
    cout << "Em Z: ";
    cin >> nz;

    obj = new Sculptor(nx,ny,nz);

    cout << "Defina a cor do objeto a desenhar no formato RGB:\n[0-1] Red: ";
    cin >> r;
    cout << "[0-1] Green: ";
    cin >> g;
    cout << "[0-1] Blue: ";
    cin >> b;
    cout << "\nDefina o grau de opacidade [0-1]: ";
    cin >> a;

    obj->setColor(r,g,b,a);

    do{
        system("cls");//Limpar tela

        cout << "ESCOLHA UMA DAS SEGUINTES ACOES\n\n";
        cout << "1- Redefinir Cor e Opacidade" << endl;
        cout << "2- Criar Voxel         3-Apagar Voxel" << endl;
        cout << "4- Criar Bloco         5-Apagar Bloco" << endl;
        cout << "6- Criar Esfera        7-Apagar Esfera" << endl;
        cout << "8- Criar Elipsoide     9-Apagar Elipsoide" << endl;
        cout << "10- Gravar em formato VECT" << endl;
        cout << "11- Gravar em formato OFF" << endl;
        cout << "12- Finalizar Programa" << endl;

        cin >> opt; // colocar condições para limitar os valores de 1 a 12...

       if(opt == 1){
           cout << "Defina a cor do objeto a desenhar no formato RGB:\n[0-1] Red: ";
           cin >> r;
           cout << "[0-1] Green: ";
           cin >> g;
           cout << "[0-1] Blue: ";
           cin >> b;
           cout << "\nDefina o grau de opacidade [0-1]: ";
           cin >> a;
           obj->setColor(r,g,b,a);

       } else if (opt == 2) {
           int x,y,z;
           cout << "Informe a posicao do voxel:\n[0-"<<nx-1<<"] X: ";
           cin >> x;
           cout << "[0-"<<ny-1<<"] Y: ";
           cin >> y;
           cout << "[0-"<<nz-1<<"] Z: ";
           cin >> z;

           fig.push_back(new PutVoxel(x,y,z,r,g,b,a));
           fig[qtd]->draw(*obj);
            qtd++;

       } else if (opt == 3) {
           int x,y,z;
           cout << "Informe a posicao do voxel:\n[0-"<<nx-1<<"] X: ";
           cin >> x;
           cout << "[0-"<<ny-1<<"] Y: ";
           cin >> y;
           cout << "[0-"<<nz-1<<"] Z: ";
           cin >> z;
           fig.push_back(new CutVoxel(x,y,z));
           fig[qtd]->draw(*obj);
            qtd++;

       } else if (opt == 4) {
           int x0,x1,y0,y1,z0,z1;
           cout << "Informe o inicio e o fim do bloco em X:\nX0: ";
           cin >> x0;
           cout << "X1: ";
           cin >> x1;
           cout << "Informe o inicio e o fim do bloco em Y:\nY0: ";
           cin >> y0;
           cout << "Y1: ";
           cin >> y1;
           cout << "Informe o inicio e o fim do bloco em Z:\nZ0: ";
           cin >> z0;
           cout << "Z1: ";
           cin >> z1;
           fig.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
           fig[qtd]->draw(*obj);
            qtd++;

       } else if (opt == 5) {
           int x0,x1,y0,y1,z0,z1;
           cout << "Informe o inicio e o fim do corte(bloco) em X:\nX0: ";
           cin >> x0;
           cout << "X1: ";
           cin >> x1;
           cout << "Informe o inicio e o fim do corte(bloco) em Y:\nY0: ";
           cin >> y0;
           cout << "Y1: ";
           cin >> y1;
           cout << "Informe o inicio e o fim do corte(bloco) em Z:\nZ0: ";
           cin >> z0;
           cout << "Z1: ";
           cin >> z1;
           fig.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
           fig[qtd]->draw(*obj);
            qtd++;
       } else if (opt == 6) {
            int xc,yc,zc,raio;
            cout << "Informe o centro da esfera:\nXc: ";
            cin >> xc;
            cout << "Yc: ";
            cin >> yc;
            cout << "Zc: ";
            cin >> zc;
            cout << "Informe o raio da esfera:\nRx: ";
            cin >> raio;
            fig.push_back(new PutSphere(xc,yc,zc,raio,r,g,b,a));
            fig[qtd]->draw(*obj);
             qtd++;
       } else if (opt == 7) {
           int xc,yc,zc,raio;
           cout << "Informe o centro da esfera:\nXc: ";
           cin >> xc;
           cout << "Yc: ";
           cin >> yc;
           cout << "Zc: ";
           cin >> zc;
           cout << "Informe o raio da esfera:\nRx: ";
           cin >> raio;
           fig.push_back(new CutSphere(xc,yc,zc,raio));
           fig[qtd]->draw(*obj);
            qtd++;

       } else if (opt == 8) {
            int xc,yc,zc,rx,ry,rz;
            cout << "Informe o centro da elipsoide:\nXc: ";
            cin >> xc;
            cout << "Yc: ";
            cin >> yc;
            cout << "Zc: ";
            cin >> zc;
            cout << "Informe os raios da elipsoide:\nRx: ";
            cin >> rx;
            cout << "Ry: ";
            cin >> ry;
            cout << "Rz: ";
            cin >> rz;
            fig.push_back(new PutEllipsoid(xc,yc,zc,rx,ry,rz,r,g,b,a));
            fig[qtd]->draw(*obj);
             qtd++;
       } else if (opt == 9) {
           int xc,yc,zc,rx,ry,rz;
            cout << "Informe o centro da elipsoide:\nXc: ";
            cin >> xc;
            cout << "Yc: ";
            cin >> yc;
            cout << "Zc: ";
            cin >> zc;
            cout << "Informe os raios da elipsoide:\nRx: ";
            cin >> rx;
            cout << "Ry: ";
            cin >> ry;
            cout << "Rz: ";
            cin >> rz;
            fig.push_back(new CutEllipsoid(xc,yc,zc,rx,ry,rz));
            fig[qtd]->draw(*obj);
             qtd++;
       } else if (opt == 10) {
            string arq;
            cout << "Nome do arquivo (sem extensao): ";
            cin >> arq;
            arq += ".vect";
            obj->writeVECT(arq);

       } else if (opt == 11) {
           string arq;
           cout << "Nome do arquivo (sem extensao): ";
           cin >> arq;
           arq += ".off";
           obj->writeOFF(arq);
       }

    }while(opt != 12);

    }//fim do if

    for(unsigned int i=0; i<fig.size(); i++){
        delete fig[i];
    }

    return 0;
}
