// kamil gieras
#include <iostream>
using namespace std;
int main()
{
    int ilosciZestawow;
    cin >> ilosciZestawow;
    while (ilosciZestawow--)//sprawdza czy jest zerem i najstepnie odejmuje 1
    {
        int iloscLiczbLinia, liczba;
        cin >> iloscLiczbLinia >> liczba;//wczytuje 1 elemt odrazu by ustawic go jako najwieszy i najmniejszy i srednia  moge tak zrobic bo iloscLiczbLinia jest conajmniej 1
        float sredniaArmetyczna = liczba;
        int min=liczba, max=liczba;
        int  indeks = iloscLiczbLinia;
        while (--indeks)//najpierw odejmuje indekowsi  1 a potem sprawdza czy jest 0 jak jest 0 przestaje sie petlic 
        {
            cin >> liczba;
            if (liczba < min)
                min = liczba;
            if (liczba > max)
                max = liczba;
            sredniaArmetyczna = sredniaArmetyczna + liczba;
        }
        sredniaArmetyczna = sredniaArmetyczna / iloscLiczbLinia;
        cout << min << " " << max << " " << sredniaArmetyczna << endl;
    }
}