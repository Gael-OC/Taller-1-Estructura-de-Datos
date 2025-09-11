#include "Curso.hpp"
#include <iostream>

void agregarCurso(Curso*& inicio, int codigo, std::string nombre, int cupoMaximo, std::string carrera, std::string profesor) {
    Curso* nuevo = new Curso{codigo, nombre, cupoMaximo, carrera, profesor, inicio};
    inicio = nuevo;
}

void listarCursos(Curso* inicio) {
    Curso* actual = inicio;
    while (actual != nullptr) {
        std::cout << "Código: " << actual->codigo << " | Nombre: " << actual->nombre
                  << " | Cupo máximo: " << actual->cupoMaximo << " | Carrera: " << actual->carrera
                  << " | Profesor: " << actual->profesor << std::endl;
        actual = actual->siguiente;
    }
}

Curso* buscarCursoPorCodigo(Curso* inicio, int codigo) {
    Curso* actual = inicio;
    while (actual != nullptr) {
        if (actual->codigo == codigo)
            return actual;
        actual = actual->siguiente;
    }
    return nullptr;
}

void eliminarCurso(Curso*& inicio, int codigo) {
    Curso* actual = inicio;
    Curso* anterior = nullptr;
    while (actual != nullptr && actual->codigo != codigo) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual != nullptr) {
        if (anterior == nullptr)
            inicio = actual->siguiente;
        else
            anterior->siguiente = actual->siguiente;
        delete actual;
    }
}

