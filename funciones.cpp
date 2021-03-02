#include "funciones.h"

bool verificarPalabra(string palabra)
{
    bool valida = true; 
    for(char letra : palabra)
        if (letra < 65 || (letra>90 && letra<97) || letra > 122)
            valida = false;
    return valida;
}

vector<string> inicializarDiccionario()
{
    string palabra;
    vector <string> diccionario;
    int n; cin>>n; //numero de lineas
    int i = 0;
    while(i<n)
    {
        cin>>palabra;
        if(verificarPalabra(palabra))
            diccionario.push_back(palabra);
        i++;
    }
    return diccionario;
}