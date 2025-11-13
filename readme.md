# Proyecto de Programación Orientada a Objetos – C++

Este repositorio contiene los programas desarrollados para las actividades del curso, cada uno ubicado en un archivo independiente: `codigomio1.cpp` hasta `codigomio6.cpp`.  

Todos los programas pueden compilarse y ejecutarse desde cualquier terminal, incluyendo el terminal integrado de Visual Studio Code.

---

## Instrucciones para Compilar y Ejecutar

En Windows (usando g++):

1. Abrir la terminal (CMD) en la carpeta donde están los archivos `.cpp`.
2. Escribir el siguiente comando para compilar:  
   `g++ codigomioX.cpp -o codigomioX.exe`
3. Ejecutar el archivo generado con:  
   `codigomioX.exe`
4. Repetir los pasos anteriores cambiando el número del archivo (`codigomio1.cpp`, `codigomio2.cpp`, etc.). Cada programa es independiente y se ejecuta por separado.

---

## codigomio1.cpp — Vector3D

**Metodología:**
- Implementación de la clase `Vector3D` para representar vectores en un espacio tridimensional.
- Incluye constructor, métodos para calcular magnitud y normalización.
- Sobrecarga de operadores de suma, resta y producto escalar.
- Método para imprimir las coordenadas en la consola.

**Objetivo:** Practicar el uso de clases, encapsulación y sobrecarga de operadores en C++.

---

## codigomio2.cpp — Matriz

**Metodología:**
- Clase `Matriz` que representa una matriz cuadrada `n×n`.
- Constructor que inicializa la matriz con valores aleatorios.
- Métodos para calcular la transpuesta, multiplicar matrices y mostrar la matriz en consola.
- Sobrecarga del operador de acceso y destructor para liberar memoria dinámica.

**Objetivo:** Reforzar el uso de clases, memoria dinámica, sobrecarga de operadores y manipulación de matrices.

---

## codigomio3.cpp — Polinomio

**Metodología:**
- Clase `Polinomio` que representa un polinomio de grado `n`.
- Métodos para evaluar el polinomio, derivarlo y mostrarlo en forma estándar.
- Sobrecarga de operadores de suma y multiplicación entre polinomios.
- Uso de destructor para liberar memoria dinámica.

**Objetivo:** Aplicar manejo de arreglos dinámicos, sobrecarga de operadores y funciones matemáticas.

---

## codigomio4.cpp — Números Complejos y Polares

**Metodología:**
- Clases `complex` (forma binomial) y `polar` (forma polar) para representar números complejos.
- Implementación de operadores `+`, `-`, `*`, `/`, `conj`.
- Funciones de conversión entre formas y constructores flexibles.
- Función `acumula` que suma un número indefinido de complejos y polares.

**Objetivo:** Comprender la representación de números complejos, conversión entre formas y sobrecarga de operadores.

---

## codigomio5.cpp — Ecuaciones Algebraicas y Polinomios

**Metodología:**
- Clase `CTermino` para representar cada término de un polinomio (coeficiente y exponente).
- Clase `CPolinomio` que almacena los términos en un arreglo dinámico.
- Métodos para insertar términos, sumar y multiplicar polinomios, y mostrarlos en formato estándar.
- Gestión de polinomios en orden ascendente de exponentes y manejo de coeficientes nulos.

**Objetivo:** Aplicar manejo de arreglos dinámicos, operaciones algebraicas y programación orientada a objetos.

---

## codigomio6.cpp — Juego de Dominó (POO)

**Metodología:**
- Implementación completa de un juego de dominó clásico usando Programación Orientada a Objetos.
- Clases implementadas:
  - `Ficha`: representa una ficha de dominó con dos valores.
  - `Jugador`: almacena el nombre y las fichas del jugador.
  - `JuegoDomino`: controla el flujo del juego, baraja, reparte fichas, verifica turnos y reglas.
- Métodos para colocar fichas, verificar jugadas válidas, determinar ganador y reiniciar el juego.
- Interfaz de usuario en consola para mostrar fichas, estado del juego y movimientos.
- Manejo de entre 2 y 4 jugadores humanos, puntuación acumulada y rondas múltiples.
- Principios de POO: encapsulación, herencia y polimorfismo donde corresponde.
- Distribución aleatoria de fichas y control de estados bloqueados.

**Objetivo:** Simular partidas completas de dominó, reforzando el uso de clases, objetos, manejo de colecciones y lógica de juego.

---
## Instrucciones de Uso

A continuación se indican algunas recomendaciones importantes para que los programas funcionen correctamente:

- **codigomio1.cpp a codigomio5.cpp:**  
  - El programa solicitará datos al usuario (números, matrices, vectores, polinomios, etc.).  
  - Ingrese los datos **tal como el programa lo solicita**.  
  - Siga las indicaciones en pantalla para obtener los resultados correctos.

- **codigomio6.cpp — Juego de Dominó:**  
  - Al ejecutar, aparecerá un **menú inicial** con opciones para iniciar el juego, ver reglas o salir.  
  - Seleccione **“Iniciar Juego”** para comenzar una partida.  
  - Ingrese el número de jugadores humanos (2 a 4).  
  - Cada jugador verá sus fichas y podrá seleccionar cuál colocar.  
  - Lea cuidadosamente las instrucciones en pantalla; si se omite un paso o no se selecciona correctamente, el programa puede parecer que “no funciona”.  
  - El juego permite varias rondas y mantiene un registro de victorias.  
  - Para reiniciar una partida, use la opción de reinicio sin cerrar el programa.

> Nota: No ingresar datos fuera del formato esperado puede generar errores o resultados inesperados.
# Autores

Juan Suárez Herron  
Santiago Torres Guerrero  
Marbin Fabián Rivero  

Año: 2025
