#include <iostream>
#include "Alumno.hpp"
#include "Curso.hpp"
#include "Inscripcion.hpp"
#include "Nota.hpp"

int main() {
    Alumno* inicioAlumnos = nullptr;
    Curso* inicioCursos = nullptr;
    Inscripcion* inicioInscripciones = nullptr;
    Nota* inicioNotas = nullptr;

    agregarAlumno(inicioAlumnos, 1, "Ana", "Pérez", "Informática", "2024-03");
    agregarAlumno(inicioAlumnos, 2, "Juan", "Gómez", "Civil", "2025-03");
    std::cout << "Lista de alumnos:\n";
    listarAlumnos(inicioAlumnos);

    agregarCurso(inicioCursos, 10, "Estructuras", 30, "Informática", "Profesor X");
    agregarCurso(inicioCursos, 20, "Álgebra", 40, "Civil", "Profesor Y");
    std::cout << "\nLista de cursos:\n";
    listarCursos(inicioCursos);

    inscribirAlumno(inicioInscripciones, 1, 10); // Ana en Estructuras
    inscribirAlumno(inicioInscripciones, 1, 20); // Ana en Álgebra

    agregarNota(inicioNotas, 1, 10, 6.0f);
    agregarNota(inicioNotas, 1, 10, 5.5f);
    agregarNota(inicioNotas, 1, 20, 6.3f);

    std::cout << "\nCursos del alumno 1:\n";
    listarCursosDeAlumno(inicioInscripciones, 1);

    std::cout << "\nPromedio alumno 1 en curso 10: "
              << promedioPorCurso(inicioNotas, 1, 10) << std::endl;

    std::cout << "Promedio general alumno 1: "
              << promedioGeneral(inicioNotas, 1) << std::endl;

    return 0;
}
