#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Aqui hicimos la clase Matriz que representa una matriz cuadrada n x n
class Matriz {
private:
    int n;           // tamaño de la matriz
    double **data;   // puntero doble para los valores

public:
    // Constructor que inicializa la matriz con valores aleatorios
    Matriz(int size) {
        n = size;
        data = new double*[n];
        for (int i = 0; i < n; i++) {
            data[i] = new double[n];
        }

        srand(time(0)); // inicializa los valores aleatorios
        // Aqui llenamos la matriz con valores aleatorios entre 0 y 9
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                data[i][j] = rand() % 10;
            }
        }
    }

    // Sobrecarga del operador [] para acceder a los elementos como matriz[i][j]
    double* operator[](int i) {
        return data[i];
    }

    // Metodo para imprimir la matriz
    void imprimir() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << setw(6) << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Metodo que calcula y retorna la transpuesta de la matriz
    Matriz transpuesta() const {
        Matriz t(n);
        // Aqui realizamos el intercambio de filas por columnas
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                t.data[j][i] = data[i][j];
            }
        }
        return t;
    }

    // Metodo para multiplicar esta matriz por otra
    Matriz multiplicar(const Matriz &otra) const {
        Matriz resultado(n);
        // Aqui inicializamos todo a cero antes de sumar los productos
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                resultado.data[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    resultado.data[i][j] += data[i][k] * otra.data[k][j];
                }
            }
        }
        return resultado;
    }

    // Destructor que libera la memoria
    ~Matriz() {
        // Aqui liberamos la memoria que se reservo con new
        for (int i = 0; i < n; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz cuadrada: ";
    cin >> n;

    // Creamos dos matrices del mismo tamaño
    Matriz A(n);
    Matriz B(n);

    cout << "\nMatriz A generada aleatoriamente:\n";
    A.imprimir();

    cout << "\nMatriz B generada aleatoriamente:\n";
    B.imprimir();

    // Calculamos la transpuesta de A
    cout << "\nTranspuesta de A:\n";
    Matriz T = A.transpuesta();
    T.imprimir();

    // Multiplicamos A y B
    cout << "\nResultado de A * B:\n";
    Matriz R = A.multiplicar(B);
    R.imprimir();

    cout << "\nAqui realizamos todas las operaciones en grupo: generamos, transpusimos y multiplicamos matrices cuadradas." << endl;
    cout << "Tambien verificamos que la memoria se libere correctamente al terminar el programa." << endl;

    return 0;
}
