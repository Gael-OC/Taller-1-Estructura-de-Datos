#pragma once
#include <string>

struct Curso {
    int codigo;
    std::string nombre;
    int cupoMaximo;
    std::string carrera;
    std::string profesor;
    Curso* siguiente;
};

void agregarCurso(Curso*& inicio, int codigo, std::string nombre, int cupoMaximo, std::string carrera, std::string profesor);
void listarCursos(Curso* inicio);
Curso* buscarCursoPorCodigo(Curso* inicio, int codigo);
void eliminarCurso(Curso*& inicio, int codigo);
