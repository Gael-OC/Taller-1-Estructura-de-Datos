#include "Nota.hpp"

void agregarNota(Nota*& inicio, int alumnoID, int cursoCodigo, float valor) {
    Nota* nueva = new Nota{alumnoID, cursoCodigo, valor, inicio};
    inicio = nueva;
}

float promedioPorCurso(Nota* inicio, int alumnoID, int cursoCodigo) {
    Nota* actual = inicio;
    int cantidad = 0;
    float suma = 0;
    while (actual != nullptr) {
        if (actual->alumnoID == alumnoID && actual->cursoCodigo == cursoCodigo) {
            suma += actual->valor;
            cantidad++;
        }
        actual = actual->siguiente;
    }
    return cantidad > 0 ? suma / cantidad : 0.0f;
}

float promedioGeneral(Nota* inicio, int alumnoID) {
    Nota* actual = inicio;
    int cantidad = 0;
    float suma = 0;
    while (actual != nullptr) {
        if (actual->alumnoID == alumnoID) {
            suma += actual->valor;
            cantidad++;
        }
        actual = actual->siguiente;
    }
    return cantidad > 0 ? suma / cantidad : 0.0f;
}
