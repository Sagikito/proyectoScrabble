#include "funciones.h"

//verifica si la palabra es valida para guardarla o no
bool verificarPalabra(string palabra)
{
    bool valida = true;

    //si la palabra tiene algun simbolo 'raro' no es valida 
    for(char letra : palabra)
        if (letra < 65 || (letra>90 && letra<97) || letra > 122)
            valida = false;
    
    //si la palabra solo tiene caracteres 'normales' es valida
    return valida;
}

/*Inicializa el diccionario con las palabras validas del archivo de entrada
retorna falso si el archivo no se puede abrir*/
bool inicializarDiccionario(vector<string>& diccionario)
{
    string palabra;
    //input file stream object //stream significa transmitir flujo de datos 
    ifstream file; //ifstream arch("diccionario.txt"); es mas corto
    file.open("diccionario.txt");
    
    //si se puede abrir el archivo
    if(file.is_open())
    {
        //se van leyendo las palabras del archivo de entrada
        while(file >> palabra) //similar a cin>>palabra solo que lo hacemos desde file
        {
            //si la palabra es valida se annade al diccionario
            if(verificarPalabra(palabra))
                diccionario.push_back(palabra);
        }
        file.close();
        return true;
    }
    return false;
}