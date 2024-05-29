#ifndef ENEMIGOFINAL_H
#define ENEMIGOFINAL_H

#include "Personaje.h"

class EnemigoFinal : public Personaje {
private:
    int superAtaque1;
    int superAtaque2;

public:
    EnemigoFinal(int vida, int ataque, std::string nombre, int x, int y, int superAtaque1, int superAtaque2);

    // Getters adicionales
    int getSuperAtaque1() const;
    int getSuperAtaque2() const;
};

#endif // ENEMIGOFINAL_H
