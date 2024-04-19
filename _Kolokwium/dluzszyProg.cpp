#include <iostream>
using namespace std;

int main(){
    { int mem[10000]; for (int i = 0; i < 10000; ++i) mem[i] = -1; }//### jak cos to przez to ze jest to w tych klamrach to sie to wykonuje  ale nie mamy po za klamrami tej tablicy mem istnieje tylko w obrebie klamer  
    /** stwórz przykładowe dane. TODO: wypełnij losowymi danymi? */
    int* data[] = { new int[25], new int[25], new int[20] };
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 20; ++j)
            data[i][j] = (i+1) * (j+1);

    // wybierz jedną z poprawnych tablic, nie dopuść, aby wybrano spoza zakresu
    int choice; do { 
        cout << "Wybierz tablice (1-3): "; cin >> choice; --choice; 
    } while (choice < 0 || choice > 2);//### tutaj trzeba bylo zmienic whila bo byl zly zmieniam && na || oraz jak zmienilisy --choice to trzeba zmienic tez te wartosci o jeden 
    int* p = data[choice];

    // niech użytkownik zgadnie liczbę 
    int number;
    cout<<p[0]<<endl;
    cout << "Podaj liczbe: "; cin >> number; 
    // sprawdz czy liczba jest w tablicy
    int* l = p, *r = p + 25, *m;//### tam wczesniej mamy new int[20] wiec jedna  z tablic 20 elemtnowa jak dodamy to bedziemy sprawdzac za zakresem tej tablicy 
    while (l < r){
        if (*(l++) == number) 
            m = l;
            cout<<*(l++)<<" "<<m<<endl;
    }


    // jeśli użytkownik trafił, to wypisz
    if (*m == number) cout << "Trafiles!" << endl;//### nie zainicjowalismy tego m wiec moze byc ono poprawne bo bedzie miala losoe wartosci i losowo moze wylosowac numer ktory gracz podal 
    else cout << "Pudlo! Sprobuj jeszcze raz!" << endl;
}