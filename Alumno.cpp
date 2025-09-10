#include "Alumno.hpp"
#include <iostream>

void agregarAlumno(Alumno*& head, int id, std::string nombre, std::string apellido, std::string carrera, std::string fechaIngreso) {
    Alumno* nuevo = new Alumno{ id, nombre, apellido, carrera, fechaIngreso, nullptr };
    nuevo->next = head;
    head = nuevo;
}

void listarAlumnos(Alumno* head) {
    Alumno* actual = head;
    while (actual != nullptr) {
        std::cout << "ID: " << actual->id << " | Nombre: " << actual->nombre
                  << " " << actual->apellido << " | Carrera: " << actual->carrera
                  << " | Fecha ingreso: " << actual->fechaIngreso << std::endl;
        actual = actual->next;
    }
}

Alumno* buscarAlumnoPorID(Alumno* head, int id) {
    Alumno* actual = head;
    while (actual != nullptr) {
        if (actual->id == id)
            return actual;
        actual = actual->next;
    }
    return nullptr;
}

void eliminarAlumno(Alumno*& head, int id) {
    Alumno* actual = head;
    Alumno* anterior = nullptr;
    while (actual != nullptr && actual->id != id) {
        anterior = actual;
        actual = actual->next;
    }
    if (actual != nullptr) {
        if (anterior == nullptr)
            head = actual->next;
        else
            anterior->next = actual->next;
        delete actual;
    }
}

