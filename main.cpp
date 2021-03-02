#include "funciones.h"

int main()
{
    vector<string> diccionario;
    if(inicializarDiccionario(diccionario))
    {
        for(string word : diccionario)
            cout<<word<<"\n";
    }
}