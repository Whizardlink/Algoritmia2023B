// Enrique Gutierrez Patiño, Actividad 1

#include <iostream>
#include <fstream>
#include <string>

class Paquete {
public:
    int id;
    std::string origen;
    std::string destino;
    double peso;};

class Paqueteria {
private:
    struct Nodo {
        Paquete paquete;
        Nodo* siguiente;};
    Nodo* cabeza = nullptr;

public:
    void insertarAlInicio(const Paquete& paquete) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->paquete = paquete;
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;}

    void eliminarAlInicio() {
        if (cabeza) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;}}

    void mostrar() {
        Nodo* temp = cabeza;
        while (temp) {
            std::cout << "ID: " << temp->paquete.id << " | Origen: " << temp->paquete.origen
                      << " | Destino: " << temp->paquete.destino << " | Peso: " << temp->paquete.peso << " kg" << "\n" << std::endl;
            temp = temp->siguiente;}}

    void guardarEnArchivo() {
        std::ofstream archivo("paquetes.txt");
        Nodo* temp = cabeza;
        while (temp) {
            archivo << temp->paquete.id << " " << temp->paquete.origen << " "
                    << temp->paquete.destino << " " << temp->paquete.peso << "\n";
            temp = temp->siguiente;}
        archivo.close();}

    void abrirArchivo() {
        std::ifstream archivo("paquetes.txt");
        if (archivo.is_open()) {
            int id;
            std::string origen, destino;
            double peso;
            while (archivo >> id >> origen >> destino >> peso) {
                Paquete paquete;
                paquete.id = id;
                paquete.origen = origen;
                paquete.destino = destino;
                paquete.peso = peso;
                insertarAlInicio(paquete);}
            archivo.close();}}

    ~Paqueteria() {
        while (cabeza) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;}}
};

int main() {
    Paqueteria paqueteria;
    int op;

    do {
        system("cls");
        std::cout << "Menu:\n";
        std::cout << "1. Agregar paquete\n";
        std::cout << "2. Eliminar paquete\n";
        std::cout << "3. Mostrar\n";
        std::cout << "4. Guardar\n";
        std::cout << "5. Abrir\n";
        std::cout << "6. Salir\n";
        std::cout << "Selecciona una opcion: ";  std::cin >> op;

        switch (op) {

            case 1:{
                    system("cls");
                    Paquete nuevoPaquete;
                    std::cout << "Ingrese los datos que se solicitan: \n \n";
                    std::cout << "ID: ";
                    std::cin >> nuevoPaquete.id;
                    std::cout << "Origen: ";
                    std::cin >> nuevoPaquete.origen;
                    std::cout << "Destino: ";
                    std::cin >> nuevoPaquete.destino;
                    std::cout << "Peso: ";
                    std::cin >> nuevoPaquete.peso;
                    paqueteria.insertarAlInicio(nuevoPaquete);}
                break;

            case 2:
                system("cls");
                paqueteria.eliminarAlInicio();
                std::cout << "Paquete eliminado.\n \n";
                system("pause");
                break;

            case 3:
                system("cls");
                std::cout << "Paquetes almacenados: \n \n" << std::endl;
                paqueteria.mostrar();
                system("pause");
                break;

            case 4:
                system("cls");
                paqueteria.guardarEnArchivo();
                std::cout << "Paquetes guardados en archivo.\n \n";
                system("pause");
                break;

            case 5:
                system("cls");
                paqueteria.abrirArchivo();
                std::cout << "Paquetes cargados desde archivo.\n \n";
                system("pause");
                break;

            case 6:
                system("cls");
                std::cout << "Saliendo del programa.\n \n";
                system("pause");
                break;

            default:
                system("cls");
                std::cout << "Opcion invalida.\n \n";
                system("pause");
                break;
        }
    } while (op != 6);

    return 0;}
