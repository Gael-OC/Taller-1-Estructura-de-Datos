#include "Inscripcion.hpp"
#include "Curso.hpp"
#include <iostream>

void inscribirAlumno(Inscripcion*& inicio, int alumnoID, int cursoCodigo) {
    Inscripcion* nueva = new Inscripcion{alumnoID, cursoCodigo, inicio};
    inicio = nueva;
}

void eliminarInscripcion(Inscripcion*& inicio, int alumnoID, int cursoCodigo) {
    Inscripcion* actual = inicio;
    Inscripcion* anterior = nullptr;
    while (actual != nullptr && !(actual->alumnoID == alumnoID && actual->cursoCodigo == cursoCodigo)) {
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

bool estaInscrito(Inscripcion* inicio, int alumnoID, int cursoCodigo) {
    Inscripcion* actual = inicio;
    while (actual != nullptr) {
        if (actual->alumnoID == alumnoID && actual->cursoCodigo == cursoCodigo)
            return true;
        actual = actual->siguiente;
    }
    return false;
}

void listarCursosDeAlumno(Inscripcion* inicio, int alumnoID, Curso* cursos) {
    Inscripcion* actual = inicio;
    bool alguno = false;
    while (actual != nullptr) {
        if (actual->alumnoID == alumnoID) {
            Curso* c = buscarCursoPorCodigo(cursos, actual->cursoCodigo);
            if (c) std::cout << "Curso: " << c->nombre << " (codigo " << c->codigo << ")\n";
            else   std::cout << "Curso codigo: " << actual->cursoCodigo << "\n";
            alguno = true;
        }
        actual = actual->siguiente;
    }
    if (!alguno) std::cout << "El alumno no tiene cursos inscritos.\n";
}

void listarAlumnosDeCurso(Inscripcion* inicio, int cursoCodigo) {
    Inscripcion* actual = inicio;
    bool alguno = false;
    while (actual != nullptr) {
        if (actual->cursoCodigo == cursoCodigo) {
            std::cout << "Alumno ID: " << actual->alumnoID << std::endl;
            alguno = true;
        }
        actual = actual->siguiente;
    }
    if (!alguno) std::cout << "El curso no tiene alumnos inscritos.\n";
}


