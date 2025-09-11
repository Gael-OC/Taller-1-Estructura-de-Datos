#pragma once

struct Nota {
    int alumnoID;
    int cursoCodigo;
    float valor;
    Nota* siguiente;
};

void agregarNota(Nota*& inicio, int alumnoID, int cursoCodigo, float valor);
float promedioPorCurso(Nota* inicio, int alumnoID, int cursoCodigo);
float promedioGeneral(Nota* inicio, int alumnoID);
