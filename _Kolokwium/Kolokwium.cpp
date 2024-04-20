#include <iostream>
using namespace std;

int main(){
    { int mem[10000]; for (int i = 0; i < 10000; ++i) mem[i] = -1; }//### jak cos to przez to ze jest to w tych klamrach to sie to wykonuje  ale nie mamy po za klamrami tej tablicy mem istnieje tylko w obrebie klamer  
    /** stwórz przykładowe dane. TODO: wypełnij losowymi danymi? */
    int* data[] = { new int[25], new int[25], new int[20] };
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 20; ++j)//### te tablice czasami sa 25 elementowe a tutaj wypelniamy tylko pierwsze 20 elementow pozostale beda losowe
            data[i][j] = (i+1) * (j+1);

    // wybierz jedną z poprawnych tablic, nie dopuść, aby wybrano spoza zakresu
    int choice; do { 
        cout << "Wybierz tablice (1-3): "; cin >> choice; --choice; 
    } while (choice < 1 && choice > 3);//### tutaj trzeba bylo zmienic whila bo byl zly zmieniać && na || oraz jak zmienilisy --choice to trzeba zmienic tez te wartosci o jeden 
    int* p = data[choice];

    // niech użytkownik zgadnie liczbę 
    int number;
    cout<<p[0]<<endl;
    cout << "Podaj liczbe: "; cin >> number; 
    // sprawdz czy liczba jest w tablicy
    int* l = p, *r = p + 25, *m;//### tam wczesniej mamy new int[20] wiec jedna  z tablic 20 elemtnowa jak dodamy to bedziemy sprawdzac za zakresem tej tablicy 
    while (l < r){
        if (*(l++) == number)
            m = l;//### przypisujemy wartosic l do m jak l bedzie poprawne ale zwiekszy;ismy o jeden wiec przypisujemy nastepny element a nie ten co sie zgadzal 
    }


    // jeśli użytkownik trafił, to wypisz
    if (*m == number) cout << "Trafiles!" << endl;//### nie zainicjowalismy tego m wiec jak uzytkoniwk nie zgadnie to tutaj niewiadomo co sie zdarzy (zadzialac, wyjebac program,niezadzialac xd wszystko )
    else cout << "Pudlo! Sprobuj jeszcze raz!" << endl;
}