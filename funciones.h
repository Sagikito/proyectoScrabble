#pragma once
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

//verifica si la palabra es valida para guardarla o no
bool verificarPalabra(string palabra);

//Inicializa el diccionario con las palabras validas del archivo de entrada
bool inicializarDiccionario(vector<string>& diccionario);