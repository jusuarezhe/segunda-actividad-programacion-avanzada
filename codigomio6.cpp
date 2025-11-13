#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

// ===========================================================
// CLASE FICHA
// ===========================================================
class Ficha {
public:
    int lado1, lado2;

    Ficha(int a, int b) : lado1(a), lado2(b) {}

    void mostrar() const {
        cout << "[" << lado1 << "|" << lado2 << "]";
    }

    bool encaja(int valor) const {
        return (lado1 == valor || lado2 == valor);
    }

    void girar() {
        swap(lado1, lado2);
    }
};

// ===========================================================
// CLASE JUGADOR
// ===========================================================
class Jugador {
public:
    string nombre;
    vector<Ficha> fichas;
    int puntuacion = 0;

    Jugador(string n) : nombre(n) {}

    void agregarFicha(const Ficha &f) {
        fichas.push_back(f);
    }

    void mostrarFichas() const {
        cout << nombre << " tiene las siguientes fichas:\n";
        for (int i = 0; i < fichas.size(); i++) {
            cout << i << ": ";
            fichas[i].mostrar();
            cout << "  ";
        }
        cout << "\n";
    }

    bool tieneMovimientos(int extremoIzq, int extremoDer) const {
        for (auto &f : fichas)
            if (f.encaja(extremoIzq) || f.encaja(extremoDer))
                return true;
        return false;
    }

    Ficha jugarFicha(int indice) {
        Ficha f = fichas[indice];
        fichas.erase(fichas.begin() + indice);
        return f;
    }

    bool sinFichas() const {
        return fichas.empty();
    }
};

// ===========================================================
// CLASE JUEGO DOMINÓ
// ===========================================================
class JuegoDomino {
private:
    vector<Ficha> todasLasFichas;
    vector<Ficha> mesa;
    vector<Jugador> jugadores;
    int turnoActual;

public:
    void crearFichas() {
        todasLasFichas.clear();
        for (int i = 0; i <= 6; i++)
            for (int j = i; j <= 6; j++)
                todasLasFichas.emplace_back(i, j);
    }

    void registrarJugadores() {
        jugadores.clear();
        int cant;
        cout << "Ingrese la cantidad de jugadores (2 a 4): ";
        cin >> cant;
        while (cant < 2 || cant > 4) {
            cout << "Cantidad inválida. Ingrese un número entre 2 y 4: ";
            cin >> cant;
        }

        for (int i = 0; i < cant; i++) {
            string nombre;
            cout << "Nombre del jugador " << i + 1 << ": ";
            cin >> nombre;
            jugadores.emplace_back(nombre);
        }
    }

    void repartirFichas() {
        random_shuffle(todasLasFichas.begin(), todasLasFichas.end());
        int cantJugadores = jugadores.size();

        for (int i = 0; i < cantJugadores; i++) {
            for (int j = 0; j < 7; j++) {
                jugadores[i].agregarFicha(todasLasFichas.back());
                todasLasFichas.pop_back();
            }
        }
    }

    void mostrarMesa() {
        cout << "\nMesa: ";
        for (auto &f : mesa)
            f.mostrar();
        cout << "\n";
    }

    void iniciarJuego() {
        crearFichas();
        repartirFichas();
        mesa.clear();

        cout << "\nEl juego comienza...\n";
        // El primer jugador coloca la primera ficha
        Jugador &primer = jugadores[0];
        primer.mostrarFichas();
        cout << "Elige la ficha inicial para colocar en la mesa (índice): ";
        int idx;
        cin >> idx;
        while (idx < 0 || idx >= primer.fichas.size()) {
            cout << "Índice inválido, elige otro: ";
            cin >> idx;
        }

        mesa.push_back(primer.jugarFicha(idx));
        cout << "El juego comienza con la ficha ";
        mesa[0].mostrar();
        cout << " colocada por " << primer.nombre << "\n";

        // Pasa el turno al siguiente jugador
        turnoActual = 1 % jugadores.size();
        jugar();
    }

    void jugar() {
        bool juegoActivo = true;
        int jugadoresSinMovimiento = 0;

        while (juegoActivo) {
            mostrarMesa();
            Jugador &jug = jugadores[turnoActual];
            cout << "\nTurno de " << jug.nombre << "\n";

            int extremoIzq = mesa.front().lado1;
            int extremoDer = mesa.back().lado2;

            // Verificar si puede jugar
            if (!jug.tieneMovimientos(extremoIzq, extremoDer)) {
                cout << "❌ " << jug.nombre << " no tiene fichas válidas y pasa su turno.\n";
                jugadoresSinMovimiento++;
            } else {
                jugadoresSinMovimiento = 0;
                jug.mostrarFichas();

                int indice;
                cout << "Elige el índice de la ficha que quieres jugar: ";
                cin >> indice;

                if (indice < 0 || indice >= jug.fichas.size()) {
                    cout << "Índice inválido. Pierdes turno.\n";
                } else {
                    Ficha f = jug.jugarFicha(indice);
                    bool jugadaValida = false;

                    // Detección automática
                    if (f.lado2 == extremoIzq) {
                        mesa.insert(mesa.begin(), f);
                        jugadaValida = true;
                    } else if (f.lado1 == extremoIzq) {
                        f.girar();
                        mesa.insert(mesa.begin(), f);
                        jugadaValida = true;
                    } else if (f.lado1 == extremoDer) {
                        mesa.push_back(f);
                        jugadaValida = true;
                    } else if (f.lado2 == extremoDer) {
                        f.girar();
                        mesa.push_back(f);
                        jugadaValida = true;
                    }

                    if (!jugadaValida) {
                        cout << "❌ Esa ficha no encaja en ningún extremo. No puedes jugarla.\n";
                        jug.agregarFicha(f); // devolver ficha
                    } else {
                        cout << "✅ Ficha colocada correctamente.\n";
                    }
                }
            }

            // Verificar si alguien ganó
            if (jug.sinFichas()) {
                cout << "\n🎉 " << jug.nombre << " ha ganado el juego! 🎉\n";
                jug.puntuacion++;
                juegoActivo = false;
                break;
            }

            // Verificar bloqueo
            if (jugadoresSinMovimiento >= jugadores.size()) {
                cout << "\n🧱 El juego se bloqueó: nadie puede jugar.\n";
                int minPuntos = 999;
                string ganadorBloqueo;
                for (auto &j : jugadores) {
                    int suma = 0;
                    for (auto &f : j.fichas)
                        suma += f.lado1 + f.lado2;
                    if (suma < minPuntos) {
                        minPuntos = suma;
                        ganadorBloqueo = j.nombre;
                    }
                }
                cout << "Ganador por menor puntaje en mano: " << ganadorBloqueo << "\n";
                for (auto &j : jugadores)
                    if (j.nombre == ganadorBloqueo)
                        j.puntuacion++;
                break;
            }

            // Cambiar turno
            turnoActual = (turnoActual + 1) % jugadores.size();
        }

        mostrarTablaPuntuaciones();
        menuReinicio();
    }

    void mostrarTablaPuntuaciones() {
        cout << "\n===== TABLA DE PUNTUACIONES =====\n";
        for (auto &j : jugadores) {
            cout << j.nombre << " -> " << j.puntuacion << " puntos\n";
        }
        cout << "=================================\n";
    }

    void menuReinicio() {
        char opcion;
        cout << "\n¿Deseas reiniciar la partida? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            for (auto &j : jugadores)
                j.fichas.clear();
            iniciarJuego();
        } else {
            cout << "\nGracias por jugar Dominó 🎮\n";
        }
    }
};

// ===========================================================
// FUNCIÓN PRINCIPAL
// ===========================================================
int main() {
    srand(time(0));
    JuegoDomino juego;
    cout << "=== Bienvenido al Dominó Multijugador ===\n";
    juego.registrarJugadores();
    juego.iniciarJuego();
    return 0;
}