// kamil gieras
#include <iostream>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    unsigned short tablica[N];//musi byc taka bo tylko usigned short moze miec az 65536 elementow(takie moze byc N)

    for (int i = 0; i < N; i++)
    {
        cin >> tablica[i];
    }

    int s, d;
    for (int i = 0; i < M; i++)
    {
        cin >> s >> d;
        bool WystapilaLiczba[65536] = {};//napoczatku zadna liczba sie nie powtorzyla daje wszystkie numery na falsz->{}
        while (true)
        {
            s = s % N;//jakby s bylo na modul wieksze od ilosci elementow to zmniejsze go  jak nie bedzie to nic nie zepsuje  sie tutaj tak sie robi ta cyklicznosci jak cos 
            if (s < 0)
                s = s + N;

            if (WystapilaLiczba[tablica[s]])//widze ze ta liczba sie juz kiedys pojawila wychodze z while 
                break;

            WystapilaLiczba[tablica[s]] = true;//ustawiam w tablocy ze dana liczba sie juz pojawila 
            cout << tablica[s] << " ";
            s = s + d;
        }
        cout << endl;
    }
}