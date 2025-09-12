#include "Nota.hpp"

void agregarNota(Nota*& inicio, int alumnoID, int cursoCodigo, float valor) {
    Nota* nueva = new Nota{alumnoID, cursoCodigo, valor, inicio};
    inicio = nueva;
}

float promedioPorCurso(Nota* inicio, int alumnoID, int cursoCodigo) {
    Nota* actual = inicio;
    int cantidad = 0;
    float suma = 0.0f;
    while (actual != nullptr) {
        if (actual->alumnoID == alumnoID && actual->cursoCodigo == cursoCodigo) {
            suma += actual->valor;
            cantidad++;
        }
        actual = actual->siguiente;
    }
    return cantidad > 0 ? suma / cantidad : 0.0f;
}

// Promedio general igual al promedio de los promedios por curso del alumno.
float promedioGeneral(Nota* inicio, int alumnoID) {
    Nota* i = inicio;
    float sumaPromedios = 0.0f;
    int cursosDistintos = 0;

    while (i != nullptr) {
        if (i->alumnoID == alumnoID) {
            int curso = i->cursoCodigo;
            // Verificar si ya consideramos este curso antes
            bool ya = false;
            Nota* j = inicio;
            while (j != i) {
                if (j->alumnoID == alumnoID && j->cursoCodigo == curso) { ya = true; break; }
                j = j->siguiente;
            }
            if (!ya) {
                float p = promedioPorCurso(inicio, alumnoID, curso);
                sumaPromedios += p;
                cursosDistintos++;
            }
        }
        i = i->siguiente;
    }
    return cursosDistintos > 0 ? (sumaPromedios / cursosDistintos) : 0.0f;
}

