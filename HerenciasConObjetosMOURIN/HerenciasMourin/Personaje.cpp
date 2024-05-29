#include "Personaje.h"
//Constructor
Personaje::Personaje(int vida, int ataque, std::string nombre, int x, int y)
    : vida(vida), ataque(ataque), nombre(nombre), posicionX(x), posicionY(y) {}

int Personaje::getVida() const { return vida; }
int Personaje::getAtaque() const { return ataque; }
std::string Personaje::getNombre() const { return nombre; }
int Personaje::getPosicionX() const { return posicionX; }
int Personaje::getPosicionY() const { return posicionY; }

void Personaje::setVida(int vida) { this->vida = vida; }
void Personaje::setAtaque(int ataque) { this->ataque = ataque; }
void Personaje::setNombre(std::string nombre) { this->nombre = nombre; }
void Personaje::setPosicionX(int x) { this->posicionX = x; }
void Personaje::setPosicionY(int y) { this->posicionY = y; }

void Personaje::recibirDano(int dano) { vida -= dano; }
bool Personaje::estaVivo() const { return vida > 0; }
