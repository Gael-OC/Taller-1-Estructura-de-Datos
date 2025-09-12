#pragma once

struct Curso;

struct Inscripcion {
    int alumnoID;
    int cursoCodigo;
    Inscripcion* siguiente;
};

void inscribirAlumno(Inscripcion*& inicio, int alumnoID, int cursoCodigo);
void eliminarInscripcion(Inscripcion*& inicio, int alumnoID, int cursoCodigo);
bool estaInscrito(Inscripcion* inicio, int alumnoID, int cursoCodigo);
void listarCursosDeAlumno(Inscripcion* inicio, int alumnoID, Curso* cursos);
void listarAlumnosDeCurso(Inscripcion* inicio, int cursoCodigo);
