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

int siguienteIDAlumno(Alumno* inicio);
int agregarAlumno(Alumno*& inicio, std::string nombre, std::string apellido, std::string carrera, std::string fechaIngreso);
void listarAlumnos(Alumno* inicio);
Alumno* buscarAlumnoPorID(Alumno* inicio, int id);
void buscarAlumnosPorNombre(Alumno* inicio, const std::string& nombre);
void eliminarAlumno(Alumno*& inicio, int id);
void listarResumenAlumnos(Alumno* inicio);

