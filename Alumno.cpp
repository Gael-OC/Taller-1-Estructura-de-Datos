#include "Alumno.hpp"
#include <iostream>

void agregarAlumno(Alumno*& inicio, int id, std::string nombre, std::string apellido, std::string carrera, std::string fechaIngreso) {
    Alumno* nuevo = new Alumno{ id, nombre, apellido, carrera, fechaIngreso, inicio };
    inicio = nuevo;
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
        if (actual->id == id)
            return actual;
        actual = actual->siguiente;
    }
    return nullptr;
}

void eliminarAlumno(Alumno*& inicio, int id) {
    Alumno* actual = inicio;
    Alumno* anterior = nullptr;
    while (actual != nullptr && actual->id != id) {
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

