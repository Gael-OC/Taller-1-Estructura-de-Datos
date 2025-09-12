#include <iostream>
#include <limits>
#include <iomanip>
#include "Alumno.hpp"
#include "Curso.hpp"
#include "Inscripcion.hpp"
#include "Nota.hpp"
using namespace std;

int main() {
    Alumno* inicioAlumnos = nullptr;
    Curso* inicioCursos = nullptr;
    Inscripcion* inicioInscripciones = nullptr;
    Nota* inicioNotas = nullptr;

    int opcion = -1;
    while (opcion != 0) {
        cout << "\n=== Menu Principal ===\n";
        cout << "1) Alumnos\n";
        cout << "2) Cursos\n";
        cout << "3) Inscripciones\n";
        cout << "4) Notas\n";
        cout << "5) Consultas y Reportes\n";
        cout << "0) Salir\n> ";
        cin >> opcion;
        if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        // ----- MENU ALUMNOS -----
        if (opcion == 1) {
            int opA = -1;
            while (opA != 0) {
                cout << "\n-- Alumnos --\n";
                cout << "1) Crear alumno\n";
                cout << "2) Listar alumnos\n";
                cout << "3) Buscar por ID\n";
                cout << "4) Buscar por nombre\n";
                cout << "5) Eliminar por ID (borra inscripciones y notas)\n";
                cout << "0) Volver\n> ";
                cin >> opA;
                if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

                if (opA == 1) {
                    string nombre, apellido, carrera, fecha;
                    cin.ignore();
                    cout << "Nombre: "; getline(cin, nombre);
                    cout << "Apellido: "; getline(cin, apellido);
                    cout << "Carrera: "; getline(cin, carrera);
                    cout << "Fecha ingreso (AAAA-MM): "; getline(cin, fecha);
                    if (nombre.empty() || apellido.empty() || carrera.empty() || fecha.empty()) {
                        cout << "Datos vacios no permitidos.\n"; 
                        continue;
                    }
                    int nuevoId = agregarAlumno(inicioAlumnos, nombre, apellido, carrera, fecha);
                    cout << "Alumno creado. ID asignado: " << nuevoId << "\n";
                }

                else if (opA == 2) {
                    listarAlumnos(inicioAlumnos);
                }
                else if (opA == 3) {
                    int id; cout << "ID: "; cin >> id; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    Alumno* a = buscarAlumnoPorID(inicioAlumnos, id);
                    if (a) cout << "Encontrado: " << a->nombre << " " << a->apellido << " (" << a->carrera << ")\n";
                    else cout << "No existe.\n";
                }
                else if (opA == 4) {
                    string nombre; cin.ignore(); cout << "Nombre exacto: "; getline(cin, nombre);
                    buscarAlumnosPorNombre(inicioAlumnos, nombre);
                }
                else if (opA == 5) {
                    listarResumenAlumnos(inicioAlumnos);
                    int id; cout << "ID: "; cin >> id; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    // borrar inscripciones del alumno
                    bool cambio = true;
                    while (cambio) {
                        cambio = false;
                        Inscripcion* act = inicioInscripciones;
                        Inscripcion* ant = nullptr;
                        while (act != nullptr) {
                            if (act->alumnoID == id) {
                                if (ant == nullptr) inicioInscripciones = act->siguiente;
                                else ant->siguiente = act->siguiente;
                                delete act; cambio = true; break;
                            }
                            ant = act; act = act->siguiente;
                        }
                    }
                    // borrar notas del alumno
                    cambio = true;
                    while (cambio) {
                        cambio = false;
                        Nota* act = inicioNotas;
                        Nota* ant = nullptr;
                        while (act != nullptr) {
                            if (act->alumnoID == id) {
                                if (ant == nullptr) inicioNotas = act->siguiente;
                                else ant->siguiente = act->siguiente;
                                delete act; cambio = true; break;
                            }
                            ant = act; act = act->siguiente;
                        }
                    }
                    eliminarAlumno(inicioAlumnos, id);
                    cout << "Alumno e historial asociado eliminados.\n";
                }
            }
        }
        // ----- MENU CURSOS -----
        else if (opcion == 2) {
            int opC = -1;
            while (opC != 0) {
                cout << "\n-- Cursos --\n";
                cout << "1) Crear curso\n";
                cout << "2) Listar cursos\n";
                cout << "3) Buscar por codigo\n";
                cout << "4) Buscar por nombre\n";
                cout << "5) Eliminar por codigo (borra inscripciones y notas)\n";
                cout << "0) Volver\n> ";
                cin >> opC;
                if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

                if (opC == 1) {
                    int codigo, cupo; string nombre, carrera, profesor;
                    cout << "Codigo: "; cin >> codigo; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    if (codigo <= 0) { cout << "Codigo invalido.\n"; continue; }
                    cin.ignore();
                    cout << "Nombre: "; getline(cin, nombre);
                    cout << "Cupo maximo: "; cin >> cupo; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    if (cupo <= 0) { cout << "Cupo invalido.\n"; continue; }
                    cin.ignore();
                    cout << "Carrera: "; getline(cin, carrera);
                    cout << "Profesor: "; getline(cin, profesor);
                    if (nombre.empty() || carrera.empty() || profesor.empty()) {
                        cout << "Datos vacios no permitidos.\n"; continue;
                    }
                    if (buscarCursoPorCodigo(inicioCursos, codigo) != nullptr) {
                        cout << "Ya existe un curso con ese codigo.\n";
                    } else {
                        agregarCurso(inicioCursos, codigo, nombre, cupo, carrera, profesor);
                        cout << "Curso creado.\n";
                    }
                }
                else if (opC == 2) {
                    listarCursos(inicioCursos);
                }
                else if (opC == 3) {
                    int codigo; cout << "Codigo: "; cin >> codigo; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    Curso* c = buscarCursoPorCodigo(inicioCursos, codigo);
                    if (c) cout << "Encontrado: " << c->nombre << " (" << c->carrera << "), cupo " << c->cupoMaximo << "\n";
                    else cout << "No existe.\n";
                }
                else if (opC == 4) {
                    string nombre; cin.ignore(); cout << "Nombre exacto: "; getline(cin, nombre);
                    buscarCursosPorNombre(inicioCursos, nombre);
                }
                else if (opC == 5) {
                    listarResumenCursos(inicioCursos);
                    int codigo; cout << "Codigo: "; cin >> codigo; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    // borrar inscripciones del curso
                    bool cambio = true;
                    while (cambio) {
                        cambio = false;
                        Inscripcion* act = inicioInscripciones;
                        Inscripcion* ant = nullptr;
                        while (act != nullptr) {
                            if (act->cursoCodigo == codigo) {
                                if (ant == nullptr) inicioInscripciones = act->siguiente;
                                else ant->siguiente = act->siguiente;
                                delete act; cambio = true; break;
                            }
                            ant = act; act = act->siguiente;
                        }
                    }
                    // borrar notas del curso
                    cambio = true;
                    while (cambio) {
                        cambio = false;
                        Nota* act = inicioNotas;
                        Nota* ant = nullptr;
                        while (act != nullptr) {
                            if (act->cursoCodigo == codigo) {
                                if (ant == nullptr) inicioNotas = act->siguiente;
                                else ant->siguiente = act->siguiente;
                                delete act; cambio = true; break;
                            }
                            ant = act; act = act->siguiente;
                        }
                    }
                    eliminarCurso(inicioCursos, codigo);
                    cout << "Curso e inscripciones/notas asociadas eliminados.\n";
                }
            }
        }
        // ----- MENU INSCRIPCIONES -----
        else if (opcion == 3) {
            int opI = -1;
            while (opI != 0) {
                cout << "\n-- Inscripciones --\n";
                cout << "1) Inscribir alumno en curso\n";
                cout << "2) Eliminar inscripcion\n";
                cout << "3) Listar cursos de un alumno\n";
                cout << "0) Volver\n> ";
                cin >> opI;
                if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

                if (opI == 1) {
                    listarResumenAlumnos(inicioAlumnos);
                    listarResumenCursos(inicioCursos);
                    int id, codigo;
                    cout << "ID alumno: "; cin >> id; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    cout << "Codigo curso: "; cin >> codigo; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    Alumno* a = buscarAlumnoPorID(inicioAlumnos, id);
                    Curso* c = buscarCursoPorCodigo(inicioCursos, codigo);
                    if (!a || !c) { cout << "Alumno o curso no existe.\n"; continue; }
                    if (a->carrera != c->carrera) { cout << "Carrera del alumno no coincide con la del curso.\n"; continue; }
                    // ya inscrito?
                    if (estaInscrito(inicioInscripciones, id, codigo)) { cout << "Ya esta inscrito.\n"; continue; }
                    // contar inscritos
                    int inscritos = 0;
                    Inscripcion* x = inicioInscripciones;
                    while (x != nullptr) { if (x->cursoCodigo == codigo) inscritos++; x = x->siguiente; }
                    if (inscritos >= c->cupoMaximo) { cout << "Curso lleno.\n"; continue; }
                    inscribirAlumno(inicioInscripciones, id, codigo);
                    cout << "Inscripcion hecha exitosamente.\n";
                }
                else if (opI == 2) {
                    listarResumenAlumnos(inicioAlumnos);
                    listarResumenCursos(inicioCursos);
                    int id, codigo;
                    cout << "ID alumno: "; cin >> id; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    cout << "Codigo curso: "; cin >> codigo; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    if (!estaInscrito(inicioInscripciones, id, codigo)) { cout << "No existe esa inscripcion.\n"; continue; }
                    eliminarInscripcion(inicioInscripciones, id, codigo);
                    // borrar notas del alumno en ese curso
                    bool cambio = true;
                    while (cambio) {
                        cambio = false;
                        Nota* act = inicioNotas;
                        Nota* ant = nullptr;
                        while (act != nullptr) {
                            if (act->alumnoID == id && act->cursoCodigo == codigo) {
                                if (ant == nullptr) inicioNotas = act->siguiente;
                                else ant->siguiente = act->siguiente;
                                delete act; cambio = true; break;
                            }
                            ant = act; act = act->siguiente;
                        }
                    }
                    cout << "Inscripcion eliminada (y notas del alumno en ese curso).\n";
                }
                    else if (opI == 3) {
                        listarResumenAlumnos(inicioAlumnos);
                        int id; cout << "ID alumno: "; cin >> id; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                        listarCursosDeAlumno(inicioInscripciones, id, inicioCursos);
                    }
            }
        }
        // ----- MENU NOTAS -----
        else if (opcion == 4) {
            int opN = -1;
            while (opN != 0) {
                cout << "\n-- Notas --\n";
                cout << "1) Agregar nota (1.0 a 7.0)\n";
                cout << "2) Promedio del alumno en un curso\n";
                cout << "3) Promedio general del alumno\n";
                cout << "0) Volver\n> ";
                cin >> opN;
                if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

                if (opN == 1) {
                    listarResumenAlumnos(inicioAlumnos);
                    listarResumenCursos(inicioCursos);
                    int id, codigo; float nota;
                    cout << "ID alumno: "; cin >> id; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    cout << "Codigo curso: "; cin >> codigo; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    cout << "Nota: "; cin >> nota; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    if (nota < 1.0f || nota > 7.0f) { cout << "Nota fuera de rango.\n"; continue; }
                    if (!estaInscrito(inicioInscripciones, id, codigo)) { cout << "Alumno no esta inscrito en el curso.\n"; continue; }
                    agregarNota(inicioNotas, id, codigo, nota);
                    cout << "Nota registrada.\n";
                }
                else if (opN == 2) {
                    listarResumenAlumnos(inicioAlumnos);
                    listarResumenCursos(inicioCursos);
                    int id, codigo;
                    cout << "ID alumno: "; cin >> id; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    cout << "Codigo curso: "; cin >> codigo; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    cout << fixed << setprecision(2);
                    cout << "Promedio: " << promedioPorCurso(inicioNotas, id, codigo) << "\n";
                }
                else if (opN == 3) {
                    listarResumenAlumnos(inicioAlumnos);
                    int id; cout << "ID alumno: "; cin >> id; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    cout << fixed << setprecision(2);
                    cout << "Promedio general: " << promedioGeneral(inicioNotas, id) << "\n";
                }
            }
        }
        // ----- MENU CONSULTAS -----
        else if (opcion == 5) {
            int opQ = -1;
            while (opQ != 0) {
                cout << "\n-- Consultas --\n";
                cout << "1) Alumnos por carrera\n";
                cout << "2) Cursos de un alumno\n";
                cout << "0) Volver\n> ";
                cin >> opQ;
                if (!cin) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

                if (opQ == 1) {
                    string carrera; cin.ignore(); cout << "Carrera: "; getline(cin, carrera);
                    Alumno* a = inicioAlumnos;
                    while (a != nullptr) {
                        if (a->carrera == carrera) {
                            cout << a->id << " - " << a->nombre << " " << a->apellido << "\n";
                        }
                        a = a->siguiente;
                    }
                }
                else if (opQ == 2) {
                    listarResumenAlumnos(inicioAlumnos);
                    int id; cout << "ID alumno: "; cin >> id; if (!cin) { cin.clear(); cin.ignore(99999, '\n'); continue; }
                    listarCursosDeAlumno(inicioInscripciones, id, inicioCursos);
                }
            }
        }
        else if (opcion != 0) {
            cout << "Opcion invalida. Intente de nuevo.\n";
        }       
    }

    cout << "Adios :D\n";
    return 0;
}

