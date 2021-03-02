#include "funciones.h"

bool verificarPalabra(string palabra)
{
    bool valida = true; 
    for(char letra : palabra)
        if (letra < 65 || (letra>90 && letra<97) || letra > 122)
            valida = false;
    return valida;
}

bool inicializarDiccionario(vector<string>& diccionario)
{
    string palabra;
    //input file stream object //stream significa transmitir flujo de datos 
    ifstream file; //ifstream arch("diccionario.txt"); es mas corto
    file.open("diccionario.txt");
    
    if(file.is_open())
    {
        while(file >> palabra) //similar a cin>>palabra solo que lo hacemos desde file
        {
            if(verificarPalabra(palabra))
                diccionario.push_back(palabra);
        }
        file.close();
        return true;
    }
    return false;
}