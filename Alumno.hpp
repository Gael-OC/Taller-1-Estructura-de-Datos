#pragma once
#include <string>

struct Alumno {
    int id;
    std::string nombre;
    std::string apellido;
    std::string carrera;
    std::string fechaIngreso;
    Alumno* siguiente;
};

void agregarAlumno(Alumno*& inicio, int id, std::string nombre, std::string apellido, std::string carrera, std::string fechaIngreso);
void listarAlumnos(Alumno* inicio);
Alumno* buscarAlumnoPorID(Alumno* inicio, int id);
void eliminarAlumno(Alumno*& inicio, int id);
