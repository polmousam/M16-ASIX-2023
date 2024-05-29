#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

class Personaje {
protected:
    int vida;
    int ataque;
    std::string nombre;
    int posicionX;
    int posicionY;

public:
    Personaje(int vida, int ataque, std::string nombre, int x, int y);

    // Getters
    int getVida() const;
    int getAtaque() const;
    std::string getNombre() const;
    int getPosicionX() const;
    int getPosicionY() const;

    // Setters
    void setVida(int vida);
    void setAtaque(int ataque);
    void setNombre(std::string nombre);
    void setPosicionX(int x);
    void setPosicionY(int y);

    // Metodos propios
    void recibirDano(int dano);
    bool estaVivo() const;
};

#endif // PERSONAJE_H
