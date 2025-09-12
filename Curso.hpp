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
void buscarCursosPorNombre(Curso* inicio, const std::string& nombre);
void eliminarCurso(Curso*& inicio, int codigo);
void listarResumenCursos(Curso* inicio);
