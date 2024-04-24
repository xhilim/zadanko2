#include <iostream>
#include "lib.h"

using namespace std;

class Shape {
protected:
    int I, J; // kordynatory
    int h, w; // wysokosc i szerokosc
    color fg; // kolor konturu
public:
    virtual void Rysuj(color** tab) = 0;
    Shape(int x, int y) : h(x), w(y) {};
    Shape() { cout << "Shape"; };
    void set_JI(int j, int i) { J = j; I = i; }
    void set_fg(struct color tmp) { fg = tmp; }

};

class Line : public Shape {
private:
    string rodzaj;
public:
    Line() {};
    Line(int x, int y, int i, int j, struct color c) : Shape(x, y) {
        I = i; J = j; fg = c;
        cout << h << " " << w;
        if (h == 1 && w > 1)
            rodzaj = "pozioma";
        else if (h > 1 && w == 1)
            rodzaj = "pionowa";
        else if (h == 1 && w == 1)
            rodzaj = "punkt";
        else if (h == w)
            rodzaj = "ukosna";
        else
            rodzaj = "nie umiem tego namalowac";
        cout << rodzaj;
    }
    int lewy_skos = 0;

    void Rysuj(color** tab) override {
        if (rodzaj == "punkt")
            tab[I][J] = fg;
        if (rodzaj == "pozioma")
            for (int i = I; i < I + w; i++)
                tab[J][i] = fg;
        if (rodzaj == "pionowa")
            for (int j = J; j < J + h; j++)
                tab[j][I] = fg;
        if (rodzaj == "ukosna")
            for (int k = 0; k < w; k++)
                if (lewy_skos)
                    tab[J + h - k - 1][I + k] = fg; // w prawo i do gory
                else
                    tab[J + k][I + k] = fg;  // w prawo i w dol
    };

};

class Filling {
protected:
    struct color bg;
    void Fill(int x, int y) {};
public:
    Filling() { cout << "@@@@"; };

};

class Figure : public Shape, public Filling {
public:
    int cos_tam;
    Figure(int size1, int size2) : cos_tam(0), Shape(size1, size2), Filling() {};
    Figure() { cout << "figura"; };
    virtual void Rysuj(color** tab) {
        Draw_Circuit(tab);
    }

private:
    virtual void Draw_Circuit(color** tab) = 0;
};



class Rectangle : public Figure {
protected:
    Line boki[4];
public:
    Rectangle(int size1, int size2) : Figure(size1, size2) {};
    Rectangle() {};
    void Rysuj(color** tab) override {
        Figure::Rysuj(tab);
        cout << "\nRysuje prostokat\n";
      for(int i=I;i<I+w;i++)
          for(int j=J;j<J+h;j++)
              tab[j][I] = fg;


    }
private:
    void Draw_Circuit(color** tab) override {

        cout << "\nObwod prostokata\n";
        // Implementacja rysowania konturu prostok¹ta
        Line l1(1, w, I, J, fg);
        Line l2(h, 1, I, J, fg);
        Line l3(1, w, I, J + h - 1, fg);
        Line l4(h, 1, I + w - 1, J, fg);
        boki[0] = l1; boki[1] = l2; boki[2] = l3; boki[3] = l4;

        for (int i = 0; i < 4; i++)
            boki[i].Rysuj(tab);

    }
};

class Square : public Rectangle {
public:
    Square(int size) : Rectangle(size, size) { cout << " SQUARE\n "; };


};

class Triangle : public Figure {
public:
    Triangle(int size1, int size2) : Figure(size1, size2) {};
    Triangle();
    void Rysuj(color** tab) override {
        Figure::Rysuj(tab);
        cout << "\nRysuje prostokat\n";
        // Tutaj mo¿na dodaæ kod rysowania prostok¹ta na tablicy kolorów

    }
private:
    void Draw_Circuit(color** tab) override {

        cout << "\nObwod trojkata\n";
    }
};

class Circle : public Figure {
public:
    Circle(int r) : radius(r) {
        h = w = 2 * r;
    };
    void Rysuj(color** tab) override {
        Figure::Rysuj(tab);
        cout << "\nRysuje kolo\n";
    }
private:
    int radius;
    void setPixel(struct color** tab, int x, int y) {
        tab[x][y] = fg;
    }

    void Draw_Circuit(color** tab) override {
        int xc = I + h / 2;
        int yc = J + w / 2;

        int x = 0;
        int y = radius;
        int d = 1 - radius;

        while (x <= y) {
            setPixel(tab, xc + x, yc + y);
            setPixel(tab, xc - x, yc + y);
            setPixel(tab, xc + x, yc - y);
            setPixel(tab, xc - x, yc - y);
            setPixel(tab, xc + y, yc + x);
            setPixel(tab, xc - y, yc + x);
            setPixel(tab, xc + y, yc - x);
            setPixel(tab, xc - y, yc - x);

            if (d < 0)
                d += 2 * x + 3;
            else {
                d += 2 * (x - y) + 5;
                y--;
            }
            x++;
        }
    }
};

class RectTriangle : public Triangle {
public:
    RectTriangle(int size1, int size2) : Triangle(size1, size2) {};
    RectTriangle();
    void Rysuj(color** tab) override {
        Figure::Rysuj(tab);
        cout << "\nRysuje prostokat\n";
        // Tutaj mo¿na dodaæ kod rysowania prostok¹ta na tablicy kolorów

    }
private:
    void Draw_Circuit(color** tab) override {

        cout << "\nObwod trojkata\n";
    }
};

class RightRectTriangle : public  RectTriangle {
public:
    RightRectTriangle(int size1, int size2) : RectTriangle(size1, size2) {};
    RightRectTriangle();
    void Rysuj(color** tab) override {
        Figure::Rysuj(tab);
        cout << "\nRysuje prostokat\n";
        // Tutaj mo¿na dodaæ kod rysowania prostok¹ta na tablicy kolorów

    }
private:
    void Draw_Circuit(color** tab) override {

        cout << "\nObwod trojkata\n";
    }
};

class LeftRectTriangle : public  RectTriangle {
public:
    LeftRectTriangle(int size1, int size2) : RectTriangle(size1, size2) {};
    LeftRectTriangle();
    void Rysuj(color** tab) override {
        Figure::Rysuj(tab);
        cout << "\nRysuje prostokat\n";
        // Tutaj mo¿na dodaæ kod rysowania prostok¹ta na tablicy kolorów

    }
private:
    void Draw_Circuit(color** tab) override {

        cout << "\nObwod trojkata\n";
    }
};

class EqualRectTriangle : public  RectTriangle {
public:
    EqualRectTriangle(int size1, int size2) : RectTriangle(size1, size2) {};
    EqualRectTriangle();
    void Rysuj(color** tab) override {
        Figure::Rysuj(tab);
        cout << "\nRysuje prostokat\n";
        // Tutaj mo¿na dodaæ kod rysowania prostok¹ta na tablicy kolorów

    }
private:
    void Draw_Circuit(color** tab) override {

        cout << "\nObwod trojkata\n";
    }
};