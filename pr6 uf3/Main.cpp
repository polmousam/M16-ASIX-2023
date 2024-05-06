#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "Lancha.h"
#include <vector>

int main() {
    srand(time(NULL)); // generar numeros aleatorios

    int numJugadores;
    std::cout << "Ingrese el número de jugadores: ";
    std::cin >> numJugadores;

    // Limpiar el búfer del teclado
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<Lancha> lanchas;
    for (int i = 0; i < numJugadores; ++i) {
        Lancha nuevaLancha;
        lanchas.push_back(nuevaLancha);
    }

    for (int turno = 1; turno <= 5; turno++) {
        std::cout << "Turno " << turno << std::endl;

        for (int i = 0; i < numJugadores; ++i) {
            std::cout << "Presiona Enter para lanzar el dado con la Lancha " << i + 1 << std::endl;
            getchar(); // Esperar hasta que se presione Enter

            int dado = lanchas[i].lanzarDado();
            lanchas[i].setVelocidad(lanchas[i].getVelocidad() + dado);

            
            if (!lanchas[i].haUtilizadoNitro()) {
                std::cout << "¿Deseas usar nitro en este turno? (S/N): ";
                char opcion;
                std::cin >> opcion;
                if (opcion == 'S' || opcion == 's') {
                    lanchas[i].usarNitro();
                }
            }

            lanchas[i].avanzar();
            std::cout << "Lancha " << i + 1 << ": " << lanchas[i].getVelocidad() << " m/s, Distancia recorrida: " << lanchas[i].getDistancia() << " metros\n";
        }

        std::cout << std::endl;
    }

    // determinar winner
    int maxDistancia = 0;
    int ganador = -1;
    for (int i = 0; i < numJugadores; ++i) {
        if (lanchas[i].getDistancia() > maxDistancia) {
            maxDistancia = lanchas[i].getDistancia();
            ganador = i;
        }
    }

    if (ganador == -1) {
        std::cout << "Ninguna lancha ha llegado a la meta.\n";
    }
    else {
        std::cout << "¡La lancha " << ganador + 1 << " ha ganado!\n";
    }

    return 0;
}