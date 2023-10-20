#include <iostream>
#include <vector>
#include <string>

// Estructura para representar a un alumno
struct Alumno {
    int matricula;
    std::string nombreCompleto;
    double calificacion1;
    double calificacion2;
    double calificacion3;
    double calificacionFinal;
    bool dadoDeBaja;
};

// Función para calcular la calificación final
void calcularCalificacionFinal(Alumno& alumno) {
    alumno.calificacionFinal = (alumno.calificacion1 + alumno.calificacion2 + alumno.calificacion3) / 3;
}

int main() {
    std::vector<Alumno> alumnos;

    while (true) {
        std::cout << "Menu de opciones:" << std::endl;
        std::cout << "1.- Alta" << std::endl;
        std::cout << "2.- Baja" << std::endl;
        std::cout << "3.- Cambios" << std::endl;
        std::cout << "4.- Lista de Alumnos" << std::endl;
        std::cout << "5.- Salir" << std::endl;
        std::cout << "Ingrese una opción: ";

        int opcion;
        std::cin >> opcion;

        if (opcion == 1) {
            Alumno nuevoAlumno;
            std::cout << "Ingrese la matricula del alumno: ";
            std::cin >> nuevoAlumno.matricula;
            std::cin.ignore(); // Limpiar el buffer
            std::cout << "Ingrese el nombre completo del alumno: ";
            std::getline(std::cin, nuevoAlumno.nombreCompleto);
            std::cout << "Ingrese la calificación 1 de avance: ";
            std::cin >> nuevoAlumno.calificacion1;
            std::cout << "Ingrese la calificación 2 de avance: ";
            std::cin >> nuevoAlumno.calificacion2;
            std::cout << "Ingrese la calificación 3 de avance: ";
            std::cin >> nuevoAlumno.calificacion3;

            calcularCalificacionFinal(nuevoAlumno);

            nuevoAlumno.dadoDeBaja = false;

            alumnos.push_back(nuevoAlumno);
            std::cout << "Alumno dado de alta con éxito." << std::endl;
        }
        else if (opcion == 2) {
            int matriculaBaja;
            std::cout << "Ingrese la matricula del alumno a dar de baja: ";
            std::cin >> matriculaBaja;

            for (Alumno& alumno : alumnos) {
                if (alumno.matricula == matriculaBaja) {
                    alumno.dadoDeBaja = true;
                    std::cout << "Alumno dado de baja con éxito." << std::endl;
                }
            }
        }
        else if (opcion == 3) {
            int matriculaCambios;
            std::cout << "Ingrese la matricula del alumno a modificar: ";
            std::cin >> matriculaCambios;

            for (Alumno& alumno : alumnos) {
                if (alumno.matricula == matriculaCambios) {
                    std::cout << "Ingrese la nueva calificación 1 de avance: ";
                    std::cin >> alumno.calificacion1;
                    std::cout << "Ingrese la nueva calificación 2 de avance: ";
                    std::cin >> alumno.calificacion2;
                    std::cout << "Ingrese la nueva calificación 3 de avance: ";
                    std::cin >> alumno.calificacion3;

                    calcularCalificacionFinal(alumno);

                    std::cout << "Cambios realizados con éxito." << std::endl;
                }
            }
        }
        else if (opcion == 4) {
            std::cout << "Lista de Alumnos:" << std::endl;
            for (const Alumno& alumno : alumnos) {
                std::cout << "Matricula: " << alumno.matricula << std::endl;
                std::cout << "Nombre Completo: " << alumno.nombreCompleto << std::endl;
                std::cout << "Calificación 1 de avance: " << alumno.calificacion1 << std::endl;
                std::cout << "Calificación 2 de avance: " << alumno.calificacion2 << std::endl;
                std::cout << "Calificación 3 de avance: " << alumno.calificacion3 << std::endl;
                std::cout << "Calificación Final: " << alumno.calificacionFinal << std::endl;
                if (alumno.dadoDeBaja) {
                    std::cout << "Este alumno está dado de BAJA." << std::endl;
                }
                std::cout << std::endl;
            }
        }
        else if (opcion == 5) {
            break; // Salir del programa
        }
        else {
            std::cout << "Opción no válida. Por favor, ingrese una opción válida." << std::endl;
        }
    }

    return 0;

}
