#include <iostream>

class Aula {
private:
    static const int CAPACIDAD = 10;
    int puestos[CAPACIDAD] = {0}; // 0 indica puesto vacío

public:
    // 1. insertar: Asigna un estudiante a un puesto específico 
    void insertar(int posicion, int idEstudiante) {
        if (posicion >= 0 && posicion < CAPACIDAD) {
            puestos[posicion] = idEstudiante;
        }
    }

    // 2. eliminar: Deja el puesto vacío 
    void eliminar(int posicion) {
        if (posicion >= 0 && posicion < CAPACIDAD) {
            puestos[posicion] = 0;
        }
    }

    // 3. buscar: Recorre los puestos para encontrar a un estudiante
    int buscar(int idEstudiante) {
        for (int i = 0; i < CAPACIDAD; i++) {
            if (puestos[i] == idEstudiante) return i; // Retorna la posición
        }
        return -1; // No encontrado
    }

    // 4. mostrar: Imprime el estado actual de todos los puestos
    void mostrar() {
        for (int i = 0; i < CAPACIDAD; i++) {
            std::cout << "[" << puestos[i] << "] ";
        }
        std::cout << std::endl;
    }

    // 5. size: Retorna la capacidad total de puestos del aula
    int size() {
        return CAPACIDAD;
    }
};

int main() {
    Aula miAula;

    // Ejemplo de uso
    miAula.insertar(5, 101); // Acceso inmediato al puesto 5
    miAula.insertar(2, 202);
    
    std::cout << "Aula actual: ";
    miAula.mostrar();

    int pos = miAula.buscar(101);
    std::cout << "Estudiante 101 esta en el puesto: " << pos << std::endl;

    miAula.eliminar(5);
    std::cout << "Despues de eliminar puesto 5: ";
    miAula.mostrar();

    return 0;
}
