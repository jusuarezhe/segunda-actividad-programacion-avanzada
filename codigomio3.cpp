#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Aqui hicimos la clase Polinomio que representa un polinomio de grado n
class Polinomio {
private:
    int grado;         // Grado del polinomio
    double* coef;      // Arreglo dinámico de coeficientes

public:
    // Constructor que inicializa los coeficientes
    Polinomio(int n) {
        grado = n;
        coef = new double[grado + 1]; // hay n+1 coeficientes
        cout << "Ingrese los coeficientes del polinomio (desde el termino independiente hasta el de mayor grado):\n";
        for (int i = 0; i <= grado; i++) {
            cout << "Coeficiente de x^" << i << ": ";
            cin >> coef[i];
        }
    }

    // Constructor alterno para uso interno (como la derivada o resultados de suma/multiplicacion)
    Polinomio(int n, bool vacio) {
        grado = n;
        coef = new double[grado + 1];
        for (int i = 0; i <= grado; i++) coef[i] = 0;
    }

    // Metodo para imprimir el polinomio en forma estandar
    void imprimir() const {
        cout << fixed << setprecision(2);
        // Aqui nosotros imprimimos los terminos con formato tipo a_n*x^n
        for (int i = grado; i >= 0; i--) {
            if (coef[i] == 0) continue;
            if (i != grado && coef[i] > 0) cout << " + ";
            else if (coef[i] < 0) cout << " - ";
            cout << fabs(coef[i]);
            if (i > 0) cout << "x";
            if (i > 1) cout << "^" << i;
        }
        cout << endl;
    }

    // Metodo para evaluar el polinomio en un valor dado de x
    double evaluar(double x) const {
        double resultado = 0;
        // Aqui usamos la regla de Horner aunque tambien se podria hacer con pow()
        for (int i = 0; i <= grado; i++) {
            resultado += coef[i] * pow(x, i);
        }
        return resultado;
    }

    // Sobrecarga del operador + para sumar dos polinomios
    Polinomio operator+(const Polinomio& otro) const {
        int nuevoGrado = (grado > otro.grado) ? grado : otro.grado;
        Polinomio suma(nuevoGrado, true);
        // Aqui realizamos la suma coeficiente a coeficiente
        for (int i = 0; i <= nuevoGrado; i++) {
            double c1 = (i <= grado) ? coef[i] : 0;
            double c2 = (i <= otro.grado) ? otro.coef[i] : 0;
            suma.coef[i] = c1 + c2;
        }
        return suma;
    }

    // Sobrecarga del operador * para multiplicar dos polinomios
    Polinomio operator*(const Polinomio& otro) const {
        int nuevoGrado = grado + otro.grado;
        Polinomio producto(nuevoGrado, true);
        // Aqui hicimos la multiplicacion clasica doble ciclo
        for (int i = 0; i <= grado; i++) {
            for (int j = 0; j <= otro.grado; j++) {
                producto.coef[i + j] += coef[i] * otro.coef[j];
            }
        }
        return producto;
    }

    // Metodo para derivar el polinomio
    Polinomio derivar() const {
        if (grado == 0) {
            Polinomio derivada(0, true);
            derivada.coef[0] = 0;
            return derivada;
        }
        Polinomio derivada(grado - 1, true);
        // Aqui realizamos la derivada multiplicando el exponente por el coeficiente
        for (int i = 1; i <= grado; i++) {
            derivada.coef[i - 1] = coef[i] * i;
        }
        return derivada;
    }

    // Destructor que libera la memoria
    ~Polinomio() {
        // Aqui liberamos la memoria que reservamos dinamicamente
        delete[] coef;
    }
};

int main() {
    cout << "=== POLINOMIOS ===" << endl;
    int grado1;
    cout << "Ingrese el grado del primer polinomio: ";
    cin >> grado1;
    Polinomio p1(grado1);

    int grado2;
    cout << "\nIngrese el grado del segundo polinomio: ";
    cin >> grado2;
    Polinomio p2(grado2);

    cout << "\nPolinomio 1: ";
    p1.imprimir();
    cout << "Polinomio 2: ";
    p2.imprimir();

    // Suma
    cout << "\nSuma de polinomios:\n";
    Polinomio suma = p1 + p2;
    suma.imprimir();

    // Multiplicacion
    cout << "\nMultiplicacion de polinomios:\n";
    Polinomio mult = p1 * p2;
    mult.imprimir();

    // Derivada
    cout << "\nDerivada del primer polinomio:\n";
    Polinomio deriv = p1.derivar();
    deriv.imprimir();

    // Evaluar
    double x;
    cout << "\nIngrese un valor de x para evaluar el primer polinomio: ";
    cin >> x;
    cout << "P(" << x << ") = " << p1.evaluar(x) << endl;

    cout << "\nAqui nosotros probamos todas las operaciones principales del polinomio: suma, producto, derivada y evaluacion." << endl;
    cout << "Cada uno de nosotros reviso una parte del codigo para comprobar que funcionara bien." << endl;

    return 0;
}
