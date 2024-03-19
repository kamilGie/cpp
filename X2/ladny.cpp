// kamil gieras
#include <iostream>
using namespace std;
int main()
{
    int ilosciZestawow;
    cin >> ilosciZestawow;
    while (ilosciZestawow > 0)
    {
        int iloscLiczbLinia;
        cin >> iloscLiczbLinia;

        float sredniaArmetyczna = 0;
        int min, max, liczba, indeks = 0;
        while (indeks < iloscLiczbLinia)
        {
            cin >> liczba;
            if (indeks == 0)//przy 1 literacji ustawiam ze maxymalna i mininalma wartosci jest 1 wartoscai (no logiczne xd)
            {
                min = liczba;
                max = liczba;
            }

            if (liczba < min)
                min = liczba;
            if (liczba > max)
                max = liczba;

            sredniaArmetyczna = sredniaArmetyczna + liczba;
            indeks++;
        }
        sredniaArmetyczna = sredniaArmetyczna / iloscLiczbLinia;
        cout << min << " " << max << " " << sredniaArmetyczna << endl;
        ilosciZestawow--;
    }
}