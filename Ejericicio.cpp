#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

// =======================
// Estructura del Libro
// =======================
struct Libro {
    string titulo;
    string autor;
    int anioPublicacion;
    int numPaginas;
};

// =======================
// Estructura de Biblioteca
// =======================
struct Biblioteca {
    string nombre;
    string ubicacion;
    string telefono;
    int numEmpleados;
    string horarioApertura;
    vector<Libro> coleccion;  // Arreglo dinámico de libros
};

// =======================
// Función para ingresar libros
// =======================
void ingresarLibros(vector<Libro> &coleccion) {
    int cantidad;
    cout << "\n¿Cuántos libros desea agregar a esta biblioteca?: ";
    cin >> cantidad;
    cin.ignore();

    for (int i = 0; i < cantidad; i++) {
        Libro libro;
        cout << "\n--- Libro " << i + 1 << " ---\n";
        cout << "Título: ";
        getline(cin, libro.titulo);
        cout << "Autor: ";
        getline(cin, libro.autor);
        cout << "Año de publicación: ";
        cin >> libro.anioPublicacion;
        cout << "Número de páginas: ";
        cin >> libro.numPaginas;
        cin.ignore();
        coleccion.push_back(libro);
    }
}

// =======================
// Función 1: Ingresar biblioteca
// =======================
void agregarBiblioteca(list<Biblioteca> &bibliotecas) {
    Biblioteca biblio;
    cout << "\n=== Agregar Nueva Biblioteca ===\n";
    cout << "Nombre: ";
    getline(cin, biblio.nombre);
    cout << "Ubicación: ";
    getline(cin, biblio.ubicacion);
    cout << "Teléfono: ";
    getline(cin, biblio.telefono);
    cout << "Número de empleados: ";
    cin >> biblio.numEmpleados;
    cin.ignore();
    cout << "Horario de apertura: ";
    getline(cin, biblio.horarioApertura);

    ingresarLibros(biblio.coleccion);
    bibliotecas.push_back(biblio);

    cout << "\n Biblioteca agregada con éxito.\n";
}

// =======================
// Función 2: Imprimir toda la información
// =======================
void mostrarBibliotecas(const list<Biblioteca> &bibliotecas) {
    if (bibliotecas.empty()) {
        cout << "\n No hay bibliotecas registradas.\n";
        return;
    }

    cout << "\n=== Lista de Bibliotecas ===\n";
    for (const auto &biblio : bibliotecas) {
        cout << "\n-------------------------------------\n";
        cout << "Nombre: " << biblio.nombre << endl;
        cout << "Ubicación: " << biblio.ubicacion << endl;
        cout << "Teléfono: " << biblio.telefono << endl;
        cout << "Número de empleados: " << biblio.numEmpleados << endl;
        cout << "Horario: " << biblio.horarioApertura << endl;
        cout << "Colección de libros:\n";

        if (biblio.coleccion.empty()) {
            cout << "  (Sin libros registrados)\n";
        } else {
            for (const auto &libro : biblio.coleccion) {
                cout << "  - " << libro.titulo << " | " << libro.autor
                     << " | Año: " << libro.anioPublicacion
                     << " | Páginas: " << libro.numPaginas << endl;
            }
        }
    }
}

// =======================
// Función 3: Ordenar bibliotecas
// =======================
void ordenarBibliotecas(list<Biblioteca> &bibliotecas) {
    if (bibliotecas.size() < 2) {
        cout << "\n No hay suficientes bibliotecas para ordenar.\n";
        return;
    }

    int opcion;
    cout << "\n=== Ordenar Bibliotecas ===\n";
    cout << "1. Por nombre\n";
    cout << "2. Por número de empleados\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
    cin.ignore();

    vector<Biblioteca> temp(bibliotecas.begin(), bibliotecas.end());

    if (opcion == 1) {
        sort(temp.begin(), temp.end(),
             [](const Biblioteca &a, const Biblioteca &b) {
                 return a.nombre < b.nombre;
             });
    } else if (opcion == 2) {
        sort(temp.begin(), temp.end(),
             [](const Biblioteca &a, const Biblioteca &b) {
                 return a.numEmpleados < b.numEmpleados;
             });
    } else {
        cout << "\nOpción no válida.\n";
        return;
    }

    bibliotecas.assign(temp.begin(), temp.end());
    cout << "\n Bibliotecas ordenadas correctamente.\n";
}

// =======================
// Función 4: Buscar biblioteca por nombre
// =======================
void buscarBiblioteca(const list<Biblioteca> &bibliotecas) {
    if (bibliotecas.empty()) {
        cout << "\n No hay bibliotecas registradas.\n";
        return;
    }

    string nombreBuscado;
    cout << "\nIngrese el nombre de la biblioteca a buscar: ";
    getline(cin, nombreBuscado);

    bool encontrada = false;
    for (const auto &biblio : bibliotecas) {
        if (biblio.nombre == nombreBuscado) {
            cout << "\n=== Biblioteca Encontrada ===\n";
            cout << "Nombre: " << biblio.nombre << endl;
            cout << "Ubicación: " << biblio.ubicacion << endl;
            cout << "Teléfono: " << biblio.telefono << endl;
            cout << "Número de empleados: " << biblio.numEmpleados << endl;
            cout << "Horario: " << biblio.horarioApertura << endl;

            cout << "\nColección de libros:\n";
            for (const auto &libro : biblio.coleccion) {
                cout << "  - " << libro.titulo << " | " << libro.autor
                     << " | Año: " << libro.anioPublicacion
                     << " | Páginas: " << libro.numPaginas << endl;
            }
            encontrada = true;
            break;
        }
    }

    if (!encontrada)
        cout << "\n No se encontró una biblioteca con ese nombre.\n";
}

// =======================
// Función principal (Menú)
// =======================
int main() {
    list<Biblioteca> bibliotecas;
    int opcion;

    do {
        cout << "\n========== MENÚ PRINCIPAL ==========\n";
        cout << "1. Agregar biblioteca\n";
        cout << "2. Mostrar bibliotecas\n";
        cout << "3. Ordenar bibliotecas\n";
        cout << "4. Buscar biblioteca por nombre\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarBiblioteca(bibliotecas);
                break;
            case 2:
                mostrarBibliotecas(bibliotecas);
                break;
            case 3:
                ordenarBibliotecas(bibliotecas);
                break;
            case 4:
                buscarBiblioteca(bibliotecas);
                break;
            case 5:
                cout << "\n Saliendo del programa...\n";
                break;
            default:
                cout << "\n Opción no válida.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}
