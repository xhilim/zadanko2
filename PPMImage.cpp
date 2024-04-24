#include "PPMIMAGE.h"
using namespace std;

std::string PPMImage::convert(unsigned char c)
{
    int d = c;
    return std::to_string(d);
};


void PPMImage::clear() {
    if (tab) {
        delete tab;
    }
    if (tab1D) {
        delete tab1D;
    }
}

void PPMImage::allocate() {
    tab1D = new struct color[dX * dY];

    tab = new struct color* [dY];
    for (int i = 0; i < dY; i++) {
        tab[i] = tab1D + i * dX;
    }
}

PPMImage::PPMImage(int x, int y)
    :dX(x), dY(y)
{
    allocate();
    }


PPMImage::PPMImage() {
    dX = 0;
    dY = 0;
    tab = NULL;
    tab1D = NULL;
}


PPMImage::~PPMImage() {
    clear();
    if (k)
        delete k;
    std::cout << "dekomstruktor";
}

void PPMImage::loadfile(std::string filename)
{
    ifstream plik;
    string tmp;
    plik.open(filename, ios::binary);
    getline(plik, tmp);
    cout << tmp << endl;
    plik >> dX;
    plik >> dY;
    getline(plik, tmp);
    getline(plik, tmp);

    plik.read((char*)tab1D, 3 * dX * dY);
    plik.close();


    allocate();
}

void   PPMImage::saveFile(string filename, int fraktal = 1)
{
    ofstream plik;
    plik.open(filename, ios::binary);
       saveFile(plik, fraktal);
    plik.close();
}

void   PPMImage::saveFile(ostream& plik,  int fraktal = 1)
{
  
    plik << "P6" << endl;
    plik << dX << " " << dY << endl;
    plik << "255" << endl;

    if (fraktal == 1)
    {
        for (int j = 0; j < dY; ++j)
            for (int i = 0; i < dX; ++i) {
                tab[i][j].r = i % 256;
                tab[i][j].g = (i - j) % 256;
                tab[i][j].b = (i + j) % 256;


            }
    }

    else
    {
    }
    plik.write((char*)tab1D, 3 * dX * dY);
}

void   PPMImage::saveFileP3(string filename)
{
    ofstream plik;
    plik.open(filename);
    plik << "P3" << endl;
    plik << dX << " " << dY << endl;
    plik << "255" << endl;


    for (int j = 0; j < dY; ++j)
        for (int i = 0; i < dX; ++i)
        {
            plik << convert(i % 256) << " ";
            plik << convert((i - j) % 256) << " ";
            plik << convert((i + j) % 256) << " ";


        }

    plik.close();
}

void PPMImage::wihteBoard()
{
    for(int j = 0;j<dY;++j)
        for (int i = 0; i < dX; ++i)
        {
            tab[i][j].r = tab[i][j].g = tab[i][j].b = 255;
        }
}

void PPMImage::addPoint(const Point* p)
{
    for (int j = p->J*pointsize; j < (p->J+1)*pointsize-1; ++j)
        for (int i = p->I * pointsize; i < (p->I + 1) * pointsize - 1; ++i)
        {
            tab[j][i] = p->mycolor;
        }
}

void PPMImage::addShape( Shape* s)
{

}

std::ostream& operator <<(std::ostream& s, PPMImage& ppm)
{
    ppm.saveFile(s,0);
    return s;
}
std::ostream& operator >>(std::ostream& s, PPMImage& ppm)
{
    ppm.saveFile(s,0);
    return s;
}

PPMImage & PPMImage::operator= ( const PPMImage& p)
{
    if (&p != this)
    {
        this->dY = p.dY;
        this->dX = p.dX;

        this->allocate();
        for (int j = 0; j < this->dY; j++)
            for (int i = 0; i < this->dX; i++)
                this->tab[j][i] = p.tab[j][i];
    }

    return *this;
    
}

PPMImage& PPMImage::operator+= (const Point& p)
{
    this->addPoint(&p);
    return *this;
}