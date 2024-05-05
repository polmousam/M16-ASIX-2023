#include "Lancha.h"
#include <cstdlib>

Lancha::Lancha() {
    velocidad = 0;
    distancia = 0;
    nitro = 1;
}

int Lancha::getVelocidad() {
    return velocidad;
}

void Lancha::setVelocidad(int pVelocidad) {
    velocidad = pVelocidad;
}

void Lancha::usarNitro() {
    if (nitro > 0) {
        nitro--;
        int random = rand() % 2; // número aleatorio entre 0 y 1
        if (random == 0) {
            velocidad /= 2; // dividir velocidad
        }
        else {
            velocidad *= 2; // multiplicar velocidad x2
        }
    }
}

int Lancha::lanzarDado() {
    return rand() % 6 + 1; // número aleatorio entre 1 y 6
}

void Lancha::avanzar() {
    distancia += velocidad * 100;
}

bool Lancha::haTerminado() {
    return distancia >= 5000; // suponiendo que la distancia total es de 5000 metros
}

int Lancha::getDistancia() {
    return distancia;
}