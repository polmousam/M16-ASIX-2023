
#include <iostream>
#include <windows.h>
#include "Rutina.h"
using namespace std;
namespace MathLibrary
{
    double Funciones::IMC(double peso, double altura)
    {
        return peso / (altura * altura);
    }
    double Funciones::TMB(double peso, double altura, string genero, int edad)
    {
        if (genero == "H") {
            return ((10 * peso) + (6.25 * altura) - (5 * edad) + 5);
        }
        else if (genero == "M") {
            return (10 * peso) + (6.25 * altura) - (5 * edad) - 161;
        }

    }

    string Funciones::Sport(double TMB, double IMC) {
        if (TMB > 1900) {
                return "Calistenia";
        }
        else if (TMB < 1800) {
            if (IMC >= 25) {
                return "Entrenamiento HIIT";
            }
            else if (IMC < 25) {
                return "Boxeo";
            }
        }
    }
    void Funciones::Calorias(string Sport) {
        if (Sport == "Boxeo") {
            cout << "   Este rutina de " << Sport << " consistira en rounds de 3 minutos con 1 minuto de descanso entre rounds.\n"; Sleep(500);
            cout << "        Seran 10 minutos de calentamiento, 10 rounds de saco y 10 minutos de abdominales\n"; Sleep(500);
            cout << "              Durante estos 10 rounds de saco quemaras aproximadamente 350 calorias\n"; Sleep(500);
            cout << "             Para acabar, unas series de abdominales para quemar unas calorias extras\n"; Sleep(500);
        }
        else if (Sport == "Entrenamiento HIIT") {
            cout << "          Este rutina de " << Sport << " consistira en ejercicios aerobicos de alta intensidad.\n"; Sleep(500);
            cout << "        Consistira en una hora divdidia en 4 estaciones donde se trabajaran aptitudes diferentes.\n"; Sleep(500);
            cout << "                 Estas estaciones seran sentadillas , burpees, jumping jacks y flexiones."; Sleep(500);
            cout << "                        Durante este entrenamiento quemaras unas 300 calorias.\n"; Sleep(500);
        }
        else if (Sport == "Calistenia") {
            cout << "        Este rutina de " << Sport << " consistira en 4 ejercicios de 3 series cada uno.\n"; Sleep(500);
            cout << "              Los ejercicios seran domindas, flexiones, remo y fondos en paralelas\n"; Sleep(500);
            cout << "              Deberas de hacer entre 8 y 10 repeticiones de cada ejercicio por serie.\n"; Sleep(500);
            cout << "                        Durante este entrenamiento quemaras unas 200 calorias.\n"; Sleep(500);
        }
        Sleep(500);
        system("CLS");
    }
}