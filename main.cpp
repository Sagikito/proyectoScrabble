#include "funciones.h"

int main()
{
    vector<string> diccionario;
    if(inicializarDiccionario(diccionario))
    {
        for(auto it = diccionario.begin(); it!=diccionario.end(); it++)
            cout<<*it<<"\n";
    }
}