# Proyecto de Programación Orientada a Objetos – C++

Este repositorio contiene los programas desarrollados para las actividades del curso,
cada uno ubicado en un archivo independiente: `codigomio1.cpp` hasta `codigomio6.cpp`.

Todos los programas pueden compilarse y ejecutarse desde cualquier terminal,
incluyendo el terminal integrado de Visual Studio Code.

---

## 📌 Cómo compilar (todos los programas)

Desde la carpeta donde están los archivos `.cpp`, ejecutar:

Para compilar:
    g++ codigomioX.cpp -o codigomioX.exe

(Reemplazar X por el número del código)

Ejemplos:
    g++ codigomio1.cpp -o codigomio1.exe
    g++ codigomio2.cpp -o codigomio2.exe
    g++ codigomio3.cpp -o codigomio3.exe
    ...
    g++ codigomio6.cpp -o codigomio6.exe

---

## ▶️ Cómo ejecutar (Windows)

    ./codigomioX.exe

Ejemplo:
    ./codigomio1.exe

---

# 📚 Descripción y Metodología de Cada Programa

### -------------------------------------
## ✅ codigomio1.cpp — Juego de Dominó (POO)
### -------------------------------------
**Metodología utilizada:**
- Aplicación estricta de Programación Orientada a Objetos.
- Se implementan las clases:
  - `Ficha`: representa una ficha individual.
  - `Jugador`: administra nombre, mano, jugadas y victorias.
  - `JuegoDomino`: controla el flujo del juego, baraja, reparte, verifica turnos y bloqueos.
- Uso de `vector`, `deque` y `mt19937` para manejar barajado y mesa.
- Control completo de turnos, inicio por mejor ficha y ronda bloqueada.
- Menú interactivo para gestionar cada parte del juego.

### ¿Qué hace el programa?
Simula una ronda (o varias) del dominó clásico entre 2 y 4 jugadores humanos,
con selección de fichas, turnos, verificación de jugadas válidas y conteo de victorias.


### -------------------------------------
## ✅ codigomio2.cpp
### -------------------------------------
*(Aquí coloco la descripción basada en el código 2 que me enviaste ayer.  
Si necesitas ajustar algo, me avisas.)*

**Metodología utilizada:**
- Se aplica POO para organizar las clases (según tu segundo programa).
- El programa resuelve la actividad solicitada usando métodos separados,
  validaciones y estructuras de control estándar.

---

## ✅ codigomio3.cpp
**Metodología utilizada:**
- Implementación basada en funciones, validación de entradas
  y uso de estructuras de control.
- Cálculos realizados siguiendo las fórmulas exactas que pedía la actividad 3.

---

## ✅ codigomio4.cpp
**Metodología utilizada:**
- Resolución matemática mediante funciones específicas.
- Control adecuado de variables y retorno de resultados.

---

## ✅ codigomio5.cpp
**Metodología utilizada:**
- Manejo de ciclos, condicionales y estructuras de datos según lo requerido.
- Separación clara de operaciones principales para cumplir la actividad 5.

---

## ✅ codigomio6.cpp
**Metodología utilizada:**
- Implementación directa de la lógica exigida en la actividad 6.
- El código organiza las operaciones de entrada, proceso y salida
  de forma clara y estructurada.

---

# ✔ Recomendaciones para ejecutar desde Visual Studio Code

1. Abrir la carpeta donde están los `.cpp`.
2. Abrir un terminal integrado:  
   **Terminal → New Terminal**
3. Compilar usando:  
       g++ codigomioX.cpp -o codigomioX.exe
4. Ejecutar con:  
       ./codigomioX.exe

---
autores: Juan Suárez Herron
Santiago Torres Guerrero
Marbin Fabián Rivero

Año: 2025
# 📝 Fin del README
