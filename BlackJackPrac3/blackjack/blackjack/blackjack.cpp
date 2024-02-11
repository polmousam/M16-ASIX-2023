#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Cartas
int manoJugador[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int manoCasa[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

int puntuacionJugador = 0;
int puntuacionCasa = 0;

bool turnoJugador = true;  // Si es true, es el turno del jugador; si es false, es el turno de la casa.
bool finDeJuego = false;  // Indica si el juego ha terminado.

// repartir una carta aleatoria
int repartirCarta() {
    // Genera un número aleatorio entre 1 y 13
    return rand() % 13 + 1;
}

// obtener el nombre del palo
string obtenerPalo(int palo) {
    switch (palo) {
    case 1:
        return "Diamantes";
    case 2:
        return "Treboles";
    case 3:
        return "Corazones";
    case 4:
        return "Picas";
    default:
        return "Error";
    }
}

// verificar si es un As
bool esAs(int carta) {
    return carta == 1;
}

// pedir una carta al jugador
void pedirCartaJugador() {
    int carta = repartirCarta();
    int palo = rand() % 4 + 1;  // palo random

    // mostrar la carta al jugador
    cout << "El croupier reparte una carta al jugador:" << endl;
    cout << "Palo: " << obtenerPalo(palo) << "\nNumero: " << carta << endl;

    // verificar si es un As
    if (esAs(carta)) {
        cout << "Es un As." << endl;
        // As vale 1 u 11
        cout << "Quieres que el As valga 1 o 11? (Ingresa 1 o 11): ";
        int valorAs;
        cin >> valorAs;
        while (valorAs != 1 && valorAs != 11) {
            cout << "Por favor, ingresa 1 o 11: ";
            cin >> valorAs;
        }
        // Actualizar la puntuación del jugador
        puntuacionJugador += valorAs;
    }
    else {
        // Si no es un As sumar puntos
        puntuacionJugador += carta;
    }
}

// pedir una carta al croupier
void pedirCartaCroupier() {
    int carta = repartirCarta();
    int palo = rand() % 4 + 1;  // Seleccionar un palo aleatorio

    // mostrar la carta al croupier
    cout << "El croupier reparte una carta para el:" << endl;
    cout << "Palo: " << obtenerPalo(palo) << "\nNumero: " << carta << endl;

    // verificar si es un As
    if (esAs(carta)) {
        cout << "Es un As. Se le da un valor de 11." << endl;
        puntuacionCasa += 11;
    }
    else {
        puntuacionCasa += carta;
    }
}

int main() {

    srand(static_cast<unsigned int>(time(0)));

    cout << "Bienvenido al juego de Blackjack!" << endl;

    // Repartir dos cartas al jugador
    for (int i = 0; i < 2; ++i) {
        pedirCartaJugador();
    }

    cout << "Puntuacion del jugador: " << puntuacionJugador << endl;

    // Repartir una carta para el croupier
    pedirCartaCroupier();
    cout << "Puntuacion del croupier: " << puntuacionCasa << endl;

    // Turno del jugador
    while (turnoJugador) {
        char decision;
        cout << "Quieres pedir una carta adicional? (s/n): ";
        cin >> decision;
        if (decision == 's') {
            pedirCartaJugador();
            cout << "Puntuacion del jugador: " << puntuacionJugador << endl;
            if (puntuacionJugador > 21) {
                cout << "Has superado 21. Pierdes." << endl;
                turnoJugador = false;
                finDeJuego = true;
            }
        }
        else {
            turnoJugador = false;
        }
    }

    // Turno del croupier
    while (!turnoJugador && !finDeJuego) {
        // Si la puntuación del croupier es menor o igual a 16, debe pedir una carta adicional
        if (puntuacionCasa <= 16) {
            pedirCartaCroupier();
            cout << "Puntuacion del croupier: " << puntuacionCasa << endl;
            if (puntuacionCasa > 21) {
                cout << "El croupier ha superado 21. Ganas!" << endl;
                finDeJuego = true;
            }
        }
        else {
            // El croupier se queda
            cout << "El croupier se queda." << endl;
            finDeJuego = true;
        }
    }

    // determinar quien gana o si hay empate
    if (!finDeJuego) {
        if (puntuacionJugador > puntuacionCasa) {
            cout << "Ganas!" << endl;
        }
        else if (puntuacionJugador < puntuacionCasa) {
            cout << "Pierdes." << endl;
        }
        else {
            cout << "Empate." << endl;
        }
    }

    return 0;
}
