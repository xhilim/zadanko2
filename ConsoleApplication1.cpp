#include <iostream>
#include <string>
#include <fstream>
#include "PPMImage.h"
#include "Shape.h"
using namespace std;




int main()
{
    PPMImage* obrazek = new PPMImage(500, 500);
    Point p2(3, 4, 0, 255, 255);
    Point p4(3, 4, 0, 255, 255);
    Point p3(3, 4, 0, 255, 255);
    Point p5(p3);
 //   PPMImage obrazek(500, 500);
   // obrazek += p2;
    //ofstream plik("obrazek3.ppm", ios::binary);
    //plik << obrazek;
    //plik.close();
    
    /*
    
    PPMImage *obrazek = new PPMImage(500,500);
    Point *p = new Point(3, 4, 0, 255, 255);
    obrazek->wihteBoard();
    obrazek->addPoint(p);

    obrazek->k = new Point(1, 1, 255, 0, 0);
    obrazek->addPoint(obrazek->k);
    obrazek->saveFile("obeazek2.ppm",0);
    delete obrazek;
    delete p;
  */
}
