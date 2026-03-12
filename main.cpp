#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. Estructura de datos
struct Estudiante {
    int id;
    string nombre;
    string materia;
    string estado;
};

int main() {
    // 2. Vector: 
    vector<Estudiante> lista;

    // 3. Carga de los 10 registros iniciales 
    lista.push_back({101, "Ana", "Sistemas", "Presente"});
    lista.push_back({102, "Luis", "Sistemas", "Falta"});
    lista.push_back({103, "Maria", "Calculo", "Presente"});
    lista.push_back({104, "Juan", "Calculo", "Presente"});
    lista.push_back({105, "Elena", "Programacion", "Falta"});
    lista.push_back({106, "Pedro", "Programacion", "Presente"});
    lista.push_back({107, "Saul", "Estadistica", "Presente"});
    lista.push_back({108, "Rosa", "Estadistica", "Falta"});
    lista.push_back({109, "Hugo", "Sistemas", "Presente"});
    lista.push_back({110, "Ines", "Calculo", "Presente"});

    int opcion;

    do {
        // 4. Menú interactivo
        cout << "\n=== SISTEMA DE ASISTENCIA ESTUDIANTIL ===" << endl;
        cout << "1. Registrar datos" << endl;
        cout << "2. Mostrar todos los registros" << endl;
        cout << "3. Buscar un elemento por ID" << endl;
        cout << "4. Modificar un registro" << endl;
        cout << "5. Eliminar un registro" << endl;
        cout << "6. Generar reporte final" << endl;
        cout << "7. Salir del sistema" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: { 
                // CREAR REGISTRO 
                Estudiante nuevo;
                cout << "\n-- NUEVO REGISTRO --" << endl;
                cout << "ID: "; cin >> nuevo.id;
                cout << "Nombre (un solo nombre): "; cin >> nuevo.nombre;
                cout << "Materia (sin espacios): "; cin >> nuevo.materia;
                cout << "Estado (Presente/Falta): "; cin >> nuevo.estado;

                lista.push_back(nuevo);
                cout << "-> Registro guardado con exito." << endl;
                break; 
            }
            
            case 2: {
                // MOSTRAR TODOS 
                cout << "\n--- LISTADO DE ASISTENCIA ---" << endl;
                cout << "ID\tNombre\tMateria\t\tEstado" << endl;
                cout << "------------------------------------------------" << endl;
                
                for (int i = 0; i < lista.size(); i++) {
                    cout << lista[i].id << "\t" 
                         << lista[i].nombre << "\t" 
                         << lista[i].materia << "\t\t" 
                         << lista[i].estado << endl;
                }
                break;
            }
            
            case 3: { 
                // BUSCAR POR ID 
                int idBuscar;
                bool encontrado = false; 
                
                cout << "Ingrese el ID del estudiante a buscar: ";
                cin >> idBuscar;

                for (int i = 0; i < lista.size(); i++) {
                    if (lista[i].id == idBuscar) {
                        cout << "\nEstudiante encontrado:" << endl;
                        cout << "Nombre: " << lista[i].nombre << " | Materia: " << lista[i].materia << " | Estado: " << lista[i].estado << endl;
                        encontrado = true;
                        break; 
                    }
                }
                if (encontrado == false) {
                    cout << "Error: No se encontro ningun estudiante con ese ID." << endl;
                }
                break;
            }
            
            case 4: {
                // MODIFICAR REGISTRO 
                int idModificar;
                bool encontrado = false;
                
                cout << "Ingrese el ID del estudiante a modificar: ";
                cin >> idModificar;

                for (int i = 0; i < lista.size(); i++) {
                    if (lista[i].id == idModificar) {
                        cout << "Estudiante actual: " << lista[i].nombre << " (" << lista[i].estado << ")" << endl;
                        cout << "Ingrese el nuevo estado (Presente/Falta): ";
                        cin >> lista[i].estado;
                        cout << "Registro actualizado con exito." << endl;
                        encontrado = true;
                        break;
                    }
                }
                if (encontrado == false) {
                    cout << "Error: ID no encontrado." << endl;
                }
                break;
            }
            
            case 5: {
                // ELIMINAR REGISTRO 
                int idEliminar;
                bool encontrado = false;
                
                cout << "Ingrese el ID del estudiante a eliminar: ";
                cin >> idEliminar;

                for (int i = 0; i < lista.size(); i++) {
                    if (lista[i].id == idEliminar) {
                        lista.erase(lista.begin() + i); 
                        cout << "Registro eliminado." << endl;
                        encontrado = true;
                        break;
                    }
                }
                if (encontrado == false) {
                    cout << "Error: ID no encontrado." << endl;
                }
                break;
            }
            
            case 6: {
                // REPORTE FINAL
                int totalPresentes = 0;
                int totalFaltas = 0;

                for (int i = 0; i < lista.size(); i++) {
                    if (lista[i].estado == "Presente") {
                        totalPresentes++;
                    } else if (lista[i].estado == "Falta") {
                        totalFaltas++;
                    }
                }

                cout << "\n=== REPORTE FINAL DE ASISTENCIA ===" << endl;
                cout << "Total de registros: \t" << lista.size() << endl;
                cout << "Alumnos Presentes: \t" << totalPresentes << endl;
                cout << "Alumnos Ausentes: \t" << totalFaltas << endl;
                cout << "===================================" << endl;
                break;
            }
            
            case 7: {
                // SALIR
                cout << "\nGuardando cambios... Saliendo del sistema." << endl;
                break;
            }
            
            default: {
                // OPCIÓN INVÁLIDA 
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
                break;
            }
        }

    } while (opcion != 7);

    return 0; 
}
