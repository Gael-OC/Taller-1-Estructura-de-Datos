#pragma once
#include <string>

struct Alumno {
    int id;
    std::string nombre;
    std::string apellido;
    std::string carrera;
    std::string fechaIngreso;
    Alumno* next;
};


void agregarAlumno(Alumno*& head, int id, std::string nombre, std::string apellido, std::string carrera, std::string fechaIngreso);
void listarAlumnos(Alumno* head);
Alumno* buscarAlumnoPorID(Alumno* head, int id);
void eliminarAlumno(Alumno*& head, int id);
