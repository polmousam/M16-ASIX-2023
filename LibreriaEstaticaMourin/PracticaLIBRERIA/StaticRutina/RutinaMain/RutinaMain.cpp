
#include <iostream>
#include <windows.h>
#include <ctime>
#include <chrono>
#include <thread>
#include "Rutina.h"


using namespace std;
const int PAUSA_ENTRE_CARACTERES = 20;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
double altura;
double peso;
int edad;
double TMB;
double IMC;
string genero;
string Sport;



void datos() {
    SetConsoleTextAttribute(hConsole, 11);
    cout << "                         _______  ______    _______  ___   __    _  ___   __    _  _______ \n"; Sleep(300);
    cout << "                        |       ||    _ |  |   _   ||   | |  |  | ||   | |  |  | ||       |\n"; Sleep(300);
    cout << "                        |_     _||   | ||  |  |_|  ||   | |   |_| ||   | |   |_| ||    ___|\n"; Sleep(300);
    cout << "                          |   |  |   |_||_ |       ||   | |       ||   | |       ||   | __ \n"; Sleep(300);
    cout << "                          |   |  |    __  ||       ||   | |  _    ||   | |  _    ||   ||  |\n"; Sleep(300);
    cout << "                          |   |  |   |  | ||   _   ||   | | | |   ||   | | | |   ||   |_| |\n"; Sleep(300);
    cout << "                          |___|  |___|  |_||__| |__||___| |_|  |__||___| |_|  |__||_______|\n"; Sleep(300);
    SetConsoleTextAttribute(hConsole, 6); cout << "\n\n";
    string intro = "                              Bienvenido al programa de entrenamiento oficial de MONLAU.\n";
    string intro1 = "                    Este programa esta adapatado a cualquier persona, nivel y dificultad posible.\n";
    string intro2 = "                               Para emepzar el programa, deberas rellenar ciertos datos. \n";
    string intro3 = "                                            Pulsa Intro cuando estes listo!";

    for (char d : intro + intro1 + intro2) {
        cout << d << flush;
        this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
    }
    SetConsoleTextAttribute(hConsole, 1);
    for (char d : intro3) {
        cout << d << flush;
        this_thread::sleep_for(chrono::milliseconds(PAUSA_ENTRE_CARACTERES));
    }
    cin.get();
    Sleep(500);
    system("CLS");
    boolean genere = false; boolean pesou = false; boolean alturau = false; boolean edadu = false;
    while (genere == false) {
        Sleep(1000);
        SetConsoleTextAttribute(hConsole, 6); cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "                                               Eres hombre o mujer(H/M)? "; cin >> genero;
        if (genero == "H" || genero == "M") {
            genere = true;
        }
        else {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "                                                 Respuesta no valida...";
            Sleep(500);

        }
        system("CLS");
    }
    while (pesou == false) {
        Sleep(1000);
        SetConsoleTextAttribute(hConsole, 6); cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "                                                  Cuanto pesas(kg)? "; cin >> peso;
        if (peso > 0 && peso < 300) {
            pesou = true;
        }
        else {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "                                                 Respuesta no valida...";
            Sleep(500);

        }
        system("CLS");
    }
    while (alturau == false) {
        Sleep(1000);
        SetConsoleTextAttribute(hConsole, 6); cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "                                                  Cuanto mides(cm)? "; cin >> altura;
        if (altura > 0 && altura < 250) {
            alturau = true;
        }
        else {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "                                                 Respuesta no valida...";
            Sleep(500);

        }
        system("CLS");
    }
    while (edadu == false) {
        Sleep(1000);
        SetConsoleTextAttribute(hConsole, 6); cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "                                                   Que edad tienes? "; cin >> edad;
        if (edad > 0 && edad < 150) {
            edadu = true;
        }
        else {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "                                                 Respuesta no valida...";
            Sleep(500);

        }
        system("CLS");
    }
    altura = altura / 100; Sleep(500); SetConsoleTextAttribute(hConsole, 1);
    cout << "\n\n";
    cout << "                              Perfecto, gracias a estos datos hemos podido averiguar lo siguiente:"; Sleep(500); SetConsoleTextAttribute(hConsole, 6);
    cout << "\n                                                  Tu IMC es de " << MathLibrary::Funciones::IMC(peso, altura); Sleep(500);
    altura = altura * 100;
    cout << "\n                                    Tu TMB(consumo de calorias dirario) es de " << MathLibrary::Funciones::TMB(peso, altura, genero, edad) << " kcal"; Sleep(500);
    IMC = MathLibrary::Funciones::IMC(peso, altura);
    TMB = MathLibrary::Funciones::TMB(peso, altura, genero, edad);
    Sport = MathLibrary::Funciones::Sport(IMC, TMB);
    cout << "\n                          Debido a esto, hemos realizado un estudio y vas a realizar la rutina de " << MathLibrary::Funciones::Sport(IMC, TMB); Sleep(500);
    system("CLS");
    MathLibrary::Funciones::Calorias(Sport);
}
int main()
{
    datos();
    cout << "Espero que te haya gustado el entrenamiento de Monlau Extreme!"; Sleep(500);
    return 0;
}