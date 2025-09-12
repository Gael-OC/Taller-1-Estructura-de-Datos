#include "Alumno.hpp"
#include <iostream>

int siguienteIDAlumno(Alumno* inicio) {
    int maxId = 0;
    Alumno* a = inicio;
    while (a != nullptr) {
        if (a->id > maxId) maxId = a->id;
        a = a->siguiente;
    }
    return maxId + 1; // IDs comienzan en 1
}

int agregarAlumno(Alumno*& inicio, std::string nombre, std::string apellido, std::string carrera, std::string fechaIngreso) {
    int nuevoId = siguienteIDAlumno(inicio);
    Alumno* nuevo = new Alumno{ nuevoId, nombre, apellido, carrera, fechaIngreso, inicio };
    inicio = nuevo;
    return nuevoId;
}

void listarAlumnos(Alumno* inicio) {
    Alumno* actual = inicio;
    while (actual != nullptr) {
        std::cout << "ID: " << actual->id << " | Nombre: " << actual->nombre
                  << " " << actual->apellido << " | Carrera: " << actual->carrera
                  << " | Fecha ingreso: " << actual->fechaIngreso << std::endl;
        actual = actual->siguiente;
    }
}

Alumno* buscarAlumnoPorID(Alumno* inicio, int id) {
    Alumno* actual = inicio;
    while (actual != nullptr) {
        if (actual->id == id) return actual;
        actual = actual->siguiente;
    }
    return nullptr;
}

void buscarAlumnosPorNombre(Alumno* inicio, const std::string& nombre) {
    Alumno* a = inicio;
    bool alguno = false;
    while (a != nullptr) {
        if (a->nombre == nombre) {
            std::cout << "ID: " << a->id << " | " << a->nombre << " " << a->apellido
                      << " | Carrera: " << a->carrera << " | Ingreso: " << a->fechaIngreso << "\n";
            alguno = true;
        }
        a = a->siguiente;
    }
    if (!alguno) std::cout << "No hay alumnos con ese nombre.\n";
}

void eliminarAlumno(Alumno*& inicio, int id) {
    Alumno* actual = inicio;
    Alumno* anterior = nullptr;
    while (actual != nullptr && actual->id != id) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual != nullptr) {
        if (anterior == nullptr) inicio = actual->siguiente;
        else anterior->siguiente = actual->siguiente;
        delete actual;
    }
}

void listarResumenAlumnos(Alumno* inicio) {
    std::cout << "----- Listado Alumnos -----\n";
    if (inicio == nullptr) { std::cout << "No hay alumnos registrados.\n"; return; }
    Alumno* a = inicio;
    while (a != nullptr) {
        std::cout << "ID: " << a->id << " | Nombre: " << a->nombre << " " << a->apellido << "\n";
        a = a->siguiente;
    }
}



