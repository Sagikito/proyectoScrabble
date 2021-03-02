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

//invierte la palabra del parametro
string invertirPalabra(string palabra)
{
    int n = palabra.size();
    char aux;
    for(int i = 0; i< n/2; i++)
    {
        aux = palabra[i];
        palabra[i] = palabra[n-i-1];
        palabra[n-i-1] = aux;
    }
    return palabra;
}

//conversion de una palabra a mayusculas
string mayus(string palabra)
{
    for(int i=0; i<palabra.size(); i++)
        palabra[i] = toupper(palabra[i]);
    return palabra;
}

/*Inicializa el diccionario con las palabras validas del archivo de entrada
retorna falso si el archivo no se puede abrir, ordennormal dice si se almacenan de izq a der
o de der a izq*/
bool inicializarDiccionario(vector<string>& diccionario, bool ordennormal)
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
            //si la palabra es valida y el orden es normal se annade al diccionario
            if(verificarPalabra(palabra) && ordennormal)
                diccionario.push_back(mayus(palabra));

            //si la palabra es valida pero el orden es inverso se annade 'al reves'    
            if(verificarPalabra(palabra) && !ordennormal)
                diccionario.push_back(mayus(invertirPalabra(palabra)));
            
        }
        file.close();
        return true;
    }
    return false;
}


//calculo del puntaje de una palabra (si es invalida retorna puntaje = -1)
int puntajePalabra(string palabra)
{
    if(verificarPalabra(palabra) == false) //!verificarPalabra()
        return -1;

    int puntaje = 0;
    palabra = mayus(palabra);
    for(char letra : palabra)
    {
        if(letra == 'Q' || letra == 'Z')
            puntaje += 10;

        else if(letra == 'J' || letra == 'X')
            puntaje += 8;
        
        else if(letra == 'K')
            puntaje += 5;
        
        else if(letra == 'D' || letra == 'G')
            puntaje += 2;
        
        else if(letra == 'B' || letra == 'C')
            puntaje += 3;
        
        else if(letra == 'M' || letra == 'P')
            puntaje += 3;

        else if(letra == 'F' || letra == 'H' || letra == 'Y')
            puntaje += 4;
        
        else if(letra == 'V' || letra == 'W')
            puntaje += 4;
        else
            puntaje += 1;
    }
    return puntaje;
}
