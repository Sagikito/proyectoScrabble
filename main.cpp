#include "funciones.h"

int main()
{
    vector<string> diccionario;
    if(inicializarDiccionario(diccionario, true))
    {
        for(string word : diccionario)
            cout<<word<<": "<<puntajePalabra(word)<<"\n";
    }
}