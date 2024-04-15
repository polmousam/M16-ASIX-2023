
#pragma once
#include <iostream>
using namespace std;

namespace MathLibrary
{
    class Funciones
    {
    public:
        static double IMC(double peso, double altura);
        static double TMB(double peso, double altura, string genero, int edad);
        static string Sport(double TMB, double IMC);
        static void Calorias(string Sport);
    };
}