#include "Curso.hpp"
#include <iostream>

void agregarCurso(Curso*& inicio, int codigo, std::string nombre, int cupoMaximo, std::string carrera, std::string profesor) {
    Curso* nuevo = new Curso{codigo, nombre, cupoMaximo, carrera, profesor, inicio};
    inicio = nuevo;
}

void listarCursos(Curso* inicio) {
    Curso* actual = inicio;
    while (actual != nullptr) {
        std::cout << "Codigo: " << actual->codigo << " | Nombre: " << actual->nombre
                  << " | Cupo maximo: " << actual->cupoMaximo << " | Carrera: " << actual->carrera
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

void buscarCursosPorNombre(Curso* inicio, const std::string& nombre) {
    Curso* c = inicio;
    bool alguno = false;
    while (c != nullptr) {
        if (c->nombre == nombre) {
            std::cout << "Codigo: " << c->codigo << " | " << c->nombre
                      << " | Cupo: " << c->cupoMaximo << " | Carrera: " << c->carrera
                      << " | Profesor: " << c->profesor << "\n";
            alguno = true;
        }
        c = c->siguiente;
    }
    if (!alguno) std::cout << "No hay cursos con ese nombre.\n";
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

void listarResumenCursos(Curso* inicio) {
    std::cout << "----- Listado Cursos -----\n";
    if (inicio == nullptr) { std::cout << "No hay cursos registrados.\n"; return; }
    Curso* c = inicio;
    while (c != nullptr) {
        std::cout << "Codigo: " << c->codigo << " | Nombre: " << c->nombre << "\n";
        c = c->siguiente;
    }
}

