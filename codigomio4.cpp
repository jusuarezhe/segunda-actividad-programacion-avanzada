#include <iostream>
#include <cmath>
#include <vector>
#include <initializer_list>
using namespace std;

// =====================================
// CLASE COMPLEX (forma binomial a + ib)
// =====================================
class Polar; // Declaración anticipada para permitir conversiones

class Complex {
private:
    double a; // parte real
    double b; // parte imaginaria

public:
    // Constructor flexible
    Complex(double real = 0, double imag = 0) {
        a = real;
        b = imag;
    }

    // Constructor desde Polar
    Complex(const Polar& p);

    // Métodos de acceso
    double real() const { return a; }
    double imag() const { return b; }

    // Magnitud y ángulo
    double magnitud() const {
        return sqrt(a * a + b * b);
    }

    double angulo() const {
        return atan2(b, a);
    }

    // Sobrecarga de operadores básicos
    Complex operator+(const Complex& c) const {
        return Complex(a + c.a, b + c.b);
    }

    Complex operator-(const Complex& c) const {
        return Complex(a - c.a, b - c.b);
    }

    Complex operator*(const Complex& c) const {
        return Complex(a * c.a - b * c.b, a * c.b + b * c.a);
    }

    Complex operator/(const Complex& c) const {
        double denom = c.a * c.a + c.b * c.b;
        return Complex((a * c.a + b * c.b) / denom, (b * c.a - a * c.b) / denom);
    }

    // Conjugado
    Complex conj() const {
        return Complex(a, -b);
    }

    // Imprimir en forma a + ib
    void imprimir() const {
        cout << a;
        if (b >= 0) cout << " + " << b << "i";
        else cout << " - " << fabs(b) << "i";
    }
};

// =====================================
// CLASE POLAR (forma r ∠ θ)
// =====================================
class Polar {
private:
    double r; // magnitud
    double t; // ángulo (en radianes)

public:
    // Constructor flexible
    Polar(double mag = 0, double ang = 0) {
        r = mag;
        t = ang;
    }

    // Constructor desde Complex
    Polar(const Complex& c) {
        r = c.magnitud();
        t = c.angulo();
    }

    // Métodos de acceso
    double magnitud() const { return r; }
    double angulo() const { return t; }

    // Conversión a Complex
    Complex toComplex() const {
        return Complex(r * cos(t), r * sin(t));
    }

    // Sobrecarga de operadores
    Polar operator*(const Polar& p) const {
        return Polar(r * p.r, t + p.t);
    }

    Polar operator/(const Polar& p) const {
        return Polar(r / p.r, t - p.t);
    }

    Polar conj() const {
        return Polar(r, -t);
    }

    // Imprimir en forma polar
    void imprimir() const {
        cout << r << " * e^(i" << t << ")";
    }
};

// Implementación del constructor Complex desde Polar
Complex::Complex(const Polar& p) {
    a = p.magnitud() * cos(p.angulo());
    b = p.magnitud() * sin(p.angulo());
}

// =====================================
// FUNCION ACUMULA
// Suma una lista de números complejos (en forma binomial o polar)
// =====================================
Complex acumula(initializer_list<Complex> lista) {
    Complex suma(0, 0);
    for (const auto& c : lista) {
        suma = suma + c;
    }
    return suma;
}

Complex acumula(initializer_list<Polar> lista) {
    Complex suma(0, 0);
    for (const auto& p : lista) {
        suma = suma + Complex(p);
    }
    return suma;
}

// =====================================
// PROGRAMA PRINCIPAL
// =====================================
int main() {
    cout << "=== NUMEROS COMPLEJOS Y POLARES ===\n";

    Complex c1(3, 4);  // 3 + 4i
    Complex c2(1, -2); // 1 - 2i
    Polar p1(5, M_PI / 4);  // 5∠45°
    Polar p2(2, M_PI / 2);  // 2∠90°

    cout << "\nForma binomial:\n";
    cout << "c1 = "; c1.imprimir(); cout << endl;
    cout << "c2 = "; c2.imprimir(); cout << endl;

    cout << "\nForma polar:\n";
    cout << "p1 = "; p1.imprimir(); cout << endl;
    cout << "p2 = "; p2.imprimir(); cout << endl;

    // Operaciones entre complejos
    cout << "\nOperaciones con COMPLEX:\n";
    cout << "c1 + c2 = "; (c1 + c2).imprimir(); cout << endl;
    cout << "c1 - c2 = "; (c1 - c2).imprimir(); cout << endl;
    cout << "c1 * c2 = "; (c1 * c2).imprimir(); cout << endl;
    cout << "c1 / c2 = "; (c1 / c2).imprimir(); cout << endl;
    cout << "conjugado(c1) = "; (c1.conj()).imprimir(); cout << endl;

    // Operaciones con polares
    cout << "\nOperaciones con POLAR:\n";
    cout << "p1 * p2 = "; (p1 * p2).imprimir(); cout << endl;
    cout << "p1 / p2 = "; (p1 / p2).imprimir(); cout << endl;
    cout << "conjugado(p1) = "; (p1.conj()).imprimir(); cout << endl;

    // Conversión
    cout << "\nConversiones:\n";
    Complex c3 = p1.toComplex();
    cout << "p1 convertido a binomial: ";
    c3.imprimir();
    cout << endl;

    Polar p3 = Complex(2, 2);
    cout << "Complex(2,2) convertido a polar: ";
    p3.imprimir();
    cout << endl;

    // Uso de acumula
    cout << "\nUsando funcion acumula():\n";
    Complex total = acumula({c1, c2, Complex(2, 3)});
    cout << "Suma de complejos: "; total.imprimir(); cout << endl;

    Complex total2 = acumula({p1, p2});
    cout << "Suma de polares: "; total2.imprimir(); cout << endl;

    cout << "\nAqui nosotros probamos todas las operaciones pedidas: suma, resta, producto, division, conjugado, conversion y acumulacion." << endl;
    cout << "Cada compañero hizo una parte del codigo y luego lo revisamos juntos para comprobar que compila correctamente." << endl;

    return 0;
}
