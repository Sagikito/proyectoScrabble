#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string palabra;
    vector <string> diccionario;
    while(cin>>palabra)
    {
        bool valida = true; 
        for(char letra : palabra)
            if (letra < 65 || (letra>90 && letra<97) || letra > 122)
                valida = false;
        if(valida)
            diccionario.push_back(palabra);
    }
    for(auto it = diccionario.begin(); it!=diccionario.end(); it++)
        cout<<*it<<"\n";
}
