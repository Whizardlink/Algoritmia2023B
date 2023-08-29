//Actividad 2, Enrique Gutierrez Patiño

#include <iostream>
#include <list>

class Neurona {
private:
    int id;
    double voltaje;
    int posX;
    int posY;
    int red;
    int green;
    int blue;

public:
    Neurona(int _id, double _voltaje, int _posX, int _posY, int _red, int _green, int _blue)
        : id(_id), voltaje(_voltaje), posX(_posX), posY(_posY), red(_red), green(_green), blue(_blue) {}

    void print() const {
        std::cout << "ID: " << id << "\n";
        std::cout << "Voltaje: " << voltaje << "\n";
        std::cout << "Posición X: " << posX << "\n";
        std::cout << "Posición Y: " << posY << "\n";
        std::cout << "Color (R,G,B): (" << red << "," << green << "," << blue << ")\n";
    }
};

class AdministradorNeuronas {
private:
    std::list<Neurona> neuronas;

public:
    void agregarInicio(const Neurona& neurona) {
        neuronas.emplace_front(neurona);
    }

    void agregarFinal(const Neurona& neurona) {
        neuronas.emplace_back(neurona);
    }

    void mostrar() const {
        for (const Neurona& neurona : neuronas) {
            neurona.print();
            std::cout << "\n";
        }
    }
};

int main() {
    AdministradorNeuronas admin;

    Neurona neurona1(1, 3.5, 10, 20, 255, 0, 0);
    Neurona neurona2(2, 2.8, 5, 15, 0, 255, 0);

    admin.agregarInicio(neurona1);
    admin.agregarFinal(neurona2);

    std::cout << "Neuronas almacenadas:\n";
    admin.mostrar();

    return 0;
}
