#pragma once
#include <iostream>

class Lancha {
private:
    int velocidad;
    int distancia;
    int nitro;
    std::string name;

public:
    Lancha();
    int getVelocidad();
    void setVelocidad(int pVelocidad);
    void usarNitro();
    int lanzarDado();
    void avanzar();
    bool haTerminado();
    int getDistancia();
};
