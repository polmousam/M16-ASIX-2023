#include "EnemigoFinal.h"

EnemigoFinal::EnemigoFinal(int vida, int ataque, std::string nombre, int x, int y, int superAtaque1, int superAtaque2)
    : Personaje(vida, ataque, nombre, x, y), superAtaque1(superAtaque1), superAtaque2(superAtaque2) {}

int EnemigoFinal::getSuperAtaque1() const { return superAtaque1; }
int EnemigoFinal::getSuperAtaque2() const { return superAtaque2; }
