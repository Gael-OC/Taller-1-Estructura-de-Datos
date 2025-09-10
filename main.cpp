#include <iostream>
#include "Alumno.hpp"

int main() {
    Alumno* head = nullptr;

    agregarAlumno(head, 1, "Ana", "Pérez", "ITI", "03-2024");
    agregarAlumno(head, 2, "Juan", "Gómez", "INGECO", "03-2025");

    std::cout << "Lista de alumnos:\n";
    listarAlumnos(head);

    return 0;
}
