#include <iostream>
#include <cmath>
using namespace std;

// Aqui hicimos la clase que representa un vector en 3D
class Vector3D {
private:
    double x, y, z;

public:
    // Constructor que inicializa las coordenadas del vector
    Vector3D(double xVal = 0.0, double yVal = 0.0, double zVal = 0.0) {
        x = xVal;
        y = yVal;
        z = zVal;
    }

    // Método para calcular la magnitud del vector
    double magnitud() const {
        // Aqui usamos la formula de la magnitud √(x² + y² + z²)
        return sqrt(x * x + y * y + z * z);
    }

    // Metodo para normalizar el vector
    void normalizar() {
        double mag = magnitud();
        if (mag != 0) {
            x /= mag;
            y /= mag;
            z /= mag;
        } else {
            cout << "No se puede normalizar porque la magnitud es 0" << endl;
        }
    }

    // Sobrecarga del operador suma
    Vector3D operator+(const Vector3D &otro) const {
        // Realizamos la suma componente a componente
        return Vector3D(x + otro.x, y + otro.y, z + otro.z);
    }

    // Sobrecarga del operador resta
    Vector3D operator-(const Vector3D &otro) const {
        // Aqui hicimos la resta entre dos vectores
        return Vector3D(x - otro.x, y - otro.y, z - otro.z);
    }

    // Sobrecarga del operador * para producto escalar
    double operator*(const Vector3D &otro) const {
        // Este metodo calcula el producto punto 
        return x * otro.x + y * otro.y + z * otro.z;
    }

    // Metodo para imprimir las coordenadas del vector
    void imprimir() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

int main() {
    // Aqui hicimos las pruebas para ver si la clase funciona bien
    double x1, y1, z1, x2, y2, z2;

    cout << "Ingrese las coordenadas del primer vector separada por espacio (x y z): ";
    cin >> x1 >> y1 >> z1;

    cout << "Ingrese las coordenadas del segundo vector separada por espacio (x y z): ";
    cin >> x2 >> y2 >> z2;

    Vector3D v1(x1, y1, z1);
    Vector3D v2(x2, y2, z2);

    cout << "\nVector 1: ";
    v1.imprimir();
    cout << "Vector 2: ";
    v2.imprimir();

    // Calculamos la magnitud
    cout << "\nMagnitud del vector 1: " << v1.magnitud() << endl;
    cout << "Magnitud del vector 2: " << v2.magnitud() << endl;

    // Normalizamos ambos
    cout << "\nNormalizando ambos vectores..." << endl;
    v1.normalizar();
    v2.normalizar();

    cout << "Vector 1 normalizado: ";
    v1.imprimir();
    cout << "Vector 2 normalizado: ";
    v2.imprimir();

    // Suma y resta
    Vector3D suma = v1 + v2;
    Vector3D resta = v1 - v2;
    double producto = v1 * v2;

    cout << "\nSuma de vectores: ";
    suma.imprimir();

    cout << "Resta de vectores: ";
    resta.imprimir();

    cout << "Producto escalar: " << producto << endl;


    return 0;
}
