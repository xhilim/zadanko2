#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "lib.h"
#include "Point.h"
#include "Shape.h"


class PPMImage {
private:
    int dX, dY;
    struct color** tab;
    struct color* tab1D;
    std::string convert(unsigned char c);
    struct shape ** shapes;

    void clear();
    void allocate();
public:
    const int pointsize = 20;
    Point* k = NULL;
    void saveFile(std::string filename, int fraktal);
    void saveFileP3(std::string filename);
    void saveFile(ostream & plik, int fraktal);
   
    void loadfile(std::string filename);
    PPMImage(int x, int y);
    PPMImage();
    void wihteBoard();
    void addPoint(const Point *p);
    void addShape( Shape *s);
    PPMImage & operator =(const PPMImage&);
    friend ostream& operator <<(std::ostream& s, PPMImage & ppm);
    friend ostream& operator >>(std::ostream& s, PPMImage& ppm);
    PPMImage& operator+= (const Point& p);
    ~PPMImage();
};