#include "Personaje.h"
#include "EnemigoFinal.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int TAMANYO = 5; // Tamaño del nivel

void mostrarNivel(Personaje* heroe, int salidaX, int salidaY, const std::vector<Personaje*>& enemigos) {
    for (int i = 0; i < TAMANYO; ++i) {
        for (int j = 0; j < TAMANYO; ++j) {
            if (heroe->getPosicionX() == i && heroe->getPosicionY() == j) {
                std::cout << "H ";
            }
            else if (i == salidaX && j == salidaY) {
                std::cout << "B ";
            }
            else {
                bool esEnemigo = false;
                for (auto enemigo : enemigos) {
                    if (enemigo->getPosicionX() == i && enemigo->getPosicionY() == j) {
                        esEnemigo = true;
                        break;
                    }
                }
                if (esEnemigo) {
                    std::cout << "E ";
                }
                else {
                    std::cout << ". ";
                }
            }
        }
        std::cout << std::endl;
    }
}

void batalla(Personaje* heroe, Personaje* enemigo) {
    std::cout << "Batalla con " << enemigo->getNombre() << "!" << std::endl;
    while (heroe->estaVivo() && enemigo->estaVivo()) {
        enemigo->recibirDano(heroe->getAtaque());
        if (enemigo->estaVivo()) {
            heroe->recibirDano(enemigo->getAtaque());
        }
    }
    if (heroe->estaVivo()) {
        std::cout << "El heroe ha ganado la batalla!" << std::endl;
    }
    else {
        std::cout << "El heroe ha sido derrotado! Game Over." << std::endl;
        exit(0);
    }
}

int main() {
    std::srand(std::time(nullptr));
    Personaje* heroe = new Personaje(500, 50, "Heroe", 0, 0);
    int salidaX = TAMANYO - 1;
    int salidaY = std::rand() % TAMANYO;
    EnemigoFinal* enemigoFinal = new EnemigoFinal(200, 20, "el Boss Final", salidaX, salidaY, 30, 40);
    std::vector<Personaje*> enemigos;

    // Spawnear enemigos
    int numeroEnemigos = 5;
    for (int i = 0; i < numeroEnemigos; ++i) {
        int x, y;
        do {
            x = std::rand() % TAMANYO;
            y = std::rand() % TAMANYO;
        } while ((x == 0 && y == 0) || (x == salidaX && y == salidaY)); // Evitar la posicion inicial y la salida
        enemigos.push_back(new Personaje(50, 5, "Enemigo", x, y));
    }

    // Juego principal
    while (heroe->estaVivo() && (heroe->getPosicionX() != salidaX || heroe->getPosicionY() != salidaY)) {
        mostrarNivel(heroe, salidaX, salidaY, enemigos);
        std::cout << "Mover heroe (w/a/s/d): ";
        char movimiento;
        std::cin >> movimiento;
        int nuevaX = heroe->getPosicionX();
        int nuevaY = heroe->getPosicionY();

        switch (movimiento) {
        case 'w': nuevaX--; break;
        case 's': nuevaX++; break;
        case 'a': nuevaY--; break;
        case 'd': nuevaY++; break;
        default: std::cout << "Movimiento no valido." << std::endl; continue;
        }

        if (nuevaX >= 0 && nuevaX < TAMANYO && nuevaY >= 0 && nuevaY < TAMANYO) {
            heroe->setPosicionX(nuevaX);
            heroe->setPosicionY(nuevaY);
        }
        else {
            std::cout << "Movimiento fuera de los limites. No puedes salir del mapa" << std::endl;
            continue;
        }

        // Comprobar si encuentra un enemigo en la nueva posicion
        for (auto it = enemigos.begin(); it != enemigos.end(); ++it) {
            if (heroe->getPosicionX() == (*it)->getPosicionX() && heroe->getPosicionY() == (*it)->getPosicionY()) {
                batalla(heroe, *it);
                if (!(*it)->estaVivo()) {
                    delete* it;
                    enemigos.erase(it);
                    break;
                }
            }
        }
    }

    if (heroe->estaVivo()) {
        std::cout << "Has llegado a la guarida del Boss final!" << std::endl;
        batalla(heroe, enemigoFinal);
        if (heroe->estaVivo()) {
            std::cout << "Has derrotado al Boss final y ganado el juego!" << std::endl;
        }
    }

    delete heroe;
    delete enemigoFinal;
    for (auto enemigo : enemigos) {
        delete enemigo;
    }

    return 0;
}
