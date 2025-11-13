#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Clase que representa un número complejo en forma binomial (a + ib)
class Complex {
private:
    double real;
    double imag;

public:
    // Constructor flexible: permite crear con o sin parámetros
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Método para imprimir el número complejo
    void imprimir() const {
        cout << "(" << real << " + " << imag << "i)";
    }

    // Operador suma
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Operador resta
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Operador multiplicación
    Complex operator*(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    // Operador división
    Complex operator/(const Complex& c) const {
        double denom = c.real * c.real + c.imag * c.imag;
        if (denom == 0) {
            cout << "Error: division por cero en complejo." << endl;
            return Complex();
        }
        return Complex((real * c.real + imag * c.imag) / denom,
                       (imag * c.real - real * c.imag) / denom);
    }

    // Conjugado del número complejo
    Complex conj() const {
        return Complex(real, -imag);
    }

    // Métodos para obtener los valores reales e imaginarios
    double getReal() const { return real; }
    double getImag() const { return imag; }
};

// Clase que representa un número complejo en forma polar (r, θ)
class Polar {
private:
    double r;       // Magnitud
    double theta;   // Ángulo en radianes

public:
    // Constructor flexible
    Polar(double radio = 0, double angulo = 0) : r(radio), theta(angulo) {}

    // Método para imprimir el número polar
    void imprimir() const {
        cout << "(" << r << ", " << theta << ")";
    }

    // Operador multiplicación
    Polar operator*(const Polar& p) const {
        return Polar(r * p.r, theta + p.theta);
    }

    // Operador división
    Polar operator/(const Polar& p) const {
        if (p.r == 0) {
            cout << "Error: division por cero en polar." << endl;
            return Polar();
        }
        return Polar(r / p.r, theta - p.theta);
    }

    // Conjugado del número polar (cambia el signo del ángulo)
    Polar conj() const {
        return Polar(r, -theta);
    }

    // Conversión a forma binomial
    Complex toComplex() const {
        return Complex(r * cos(theta), r * sin(theta));
    }

    // Métodos para obtener radio y ángulo
    double getR() const { return r; }
    double getTheta() const { return theta; }
};

// Funciones de conversión auxiliares
Complex toComplex(const Complex& c) { return c; }
Complex toComplex(const Polar& p) { return p.toComplex(); }

// Función plantilla para acumular (sumar) varios números complejos y polares
// Aquí hicimos que acepte cualquier cantidad de argumentos y los convierta todos a binomial
template<typename... Args>
Complex acumula(Args... args) {
    vector<Complex> lista = { toComplex(args)... };
    Complex suma;
    for (auto& c : lista)
        suma = suma + c;
    return suma;
}

// Función principal para probar las clases
int main() {
    // Nosotros probamos aquí con algunos valores simples
    Complex c1(3, 4);
    Complex c2(1, -2);
    Polar p1(2, M_PI / 4);
    Polar p2(3, M_PI / 3);

    cout << "=== Operaciones con Complejos ===" << endl;
    cout << "c1 = "; c1.imprimir(); cout << endl;
    cout << "c2 = "; c2.imprimir(); cout << endl;

    cout << "Suma: "; (c1 + c2).imprimir(); cout << endl;
    cout << "Resta: "; (c1 - c2).imprimir(); cout << endl;
    cout << "Multiplicacion: "; (c1 * c2).imprimir(); cout << endl;
    cout << "Division: "; (c1 / c2).imprimir(); cout << endl;
    cout << "Conjugado de c1: "; c1.conj().imprimir(); cout << endl;

    cout << "\n=== Operaciones con Polares ===" << endl;
    cout << "p1 = "; p1.imprimir(); cout << endl;
    cout << "p2 = "; p2.imprimir(); cout << endl;

    cout << "Multiplicacion: "; (p1 * p2).imprimir(); cout << endl;
    cout << "Division: "; (p1 / p2).imprimir(); cout << endl;
    cout << "Conjugado de p1: "; p1.conj().imprimir(); cout << endl;

    cout << "\n=== Suma acumulada de varios numeros ===" << endl;
    Complex total = acumula(c1, p1, c2, p2);
    cout << "Resultado acumulado: ";
    total.imprimir();
    cout << endl;

    // Realizamos las pruebas y verificamos que todo funcione correctamente
    return 0;
}
