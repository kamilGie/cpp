#include <iostream>
#include "source.cpp"
using namespace std;

int main()
{
   //teraz jak chcecie sprawdzic czy jakas funkcja dziala wystarczy w takim programie w takim samym katologu sprawdzac 
   //czy wywolana przez was funckja zwraca oczekiwany wynik np
    int data[20];
    data[0] = -1;
    Add(3, data);
    Add(2, data);
    Add(1, data);
    int min, max;
    MinMax(data, &min, max);
    cout << min << " " << max;//powino oddac 1 3 
    cout<<endl<<endl;

    //lub np 
    int tablica[10]={123,23,12,423,123,9999999,-12312312,12312,2115,31231231};
    int tablicaWyjsciowa[10];
    tablicaWyjsciowa[0]=-1;
    Create(10,tablica,tablicaWyjsciowa);//sprawdzam create
    for(int i=0;tablicaWyjsciowa[i]!=-1;i++)
    {
      cout<<tablicaWyjsciowa[i]<<" ";//powino byc 123 23 12 423 2115
    }
    cout<<endl;
}
