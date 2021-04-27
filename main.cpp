#include <iostream>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual float Area() const = 0;
};

class Parallepiped : public Figure {
    float x, y, z;
public:
    Parallepiped() : x(0), y(0), z(0) {}
    Parallepiped(float x1, float y1, float z1) : x(x1), y(y1), z(z1) {}
    virtual float Area() const {
        return 2 * (x * y + x * z + y * z);
    }
};

class Tetraid : public Figure {
    float a;
public:
    Tetraid() : a(0) {}
    Tetraid(float a1) : a(a1) {}
    virtual float Area() const {
        return sqrt(3) * pow(a,2);
    }
};


class Shar : public Figure {
    float r;
public:

    Shar() : r(0) {}
    Shar(float r1) : r(r1) {}
    virtual float Area() const {
        return 4 * std::acos(-1.) * std::pow(r, 2.);
    }
};
int main() {
    Figure * mas[3];
    mas[0] = new Parallepiped(3, 4, 6);
    mas[1] = new Tetraid(27);
    mas[2] = new Shar(3);
    cout << "1-Паралелепіпед"  << endl << "2-Тетраедр"
         << endl << "3-Куля" << endl << endl;
    for (int i = 0; i < 4; i++) { //Для перевірки використовую массив посилань на абстрактний клас, яким присвоюю адреса різних об'єктів.
        cout << "Площа фігури номер " << i + 1 << " = " << mas[i]->Area() << endl;

    }

}
