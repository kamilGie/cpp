#include <iostream>
using namespace std;

int main(){
    { int mem[10000]; for (int i = 0; i < 10000; ++i) mem[i] = -1; }//mimo ze  to ze jest to w tych {klamrach} to sie to  wykonuje !
    //nie mamy po za klamrami tej tablicy, mem istnieje tylko w obrebie klamer  ale i tak zabiera czas wykonujac ta petle i wychodzac z klamer usuwa tablice mem 

    /**SZCZELINA stwórz przykładowe dane. TODO: wypełnij losowymi danymi? */
    // "losowe " oznacza ze tworzymy tablice ktore sa wypelnione i potem uzytkoniwk se wskaze z ktorej tablicy zgaduje i jak zgadnie to to wypisze ze zgadl te tabloce to :
    //data[0]= 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 21 22 23 24 25 
    //data[1]= 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50
    //data[2]= 3 6 9 12 15 18 21 24 27 30 33 36 39 42 45 48 51 54 57 60 // bo ta tablica jest jakas krotsza ma 20 elelmentow  pewnie bedzie pytanie jakie numery obejmuje ta tablica 
    int* data[] = { new int[25], new int[25], new int[25] };
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 25; ++j)//te tablice czasami sa 25 elementowe a tutaj wypelniamy tylko pierwsze 20 elementow pozostale beda losowe
            data[i][j] = (i+1) * (j+1);

    //SZCZELINA wybierz jedną z poprawnych tablic, nie dopuść, aby wybrano spoza zakresu
    int choice; do { 
        cout << "Wybierz tablice (1-3): "; cin >> choice; --choice; 
    } while (choice < 0 || choice > 2);//tutaj trzeba jakos zmienic whila bo byl zly zmieniać && na || oraz jak zmienilisy --choice to trzeba zmienic tez te wartosci o jeden no i dodac ';'
    int* p = data[choice];

    //SZCZELINA niech użytkownik zgadnie liczbę 
    int number;
    cout << "Podaj liczbe: "; cin >> number; 
    //SZCZELINA sprawdz czy liczba jest w tablicy
    int* l = p, *r = p + 25, *m=nullptr;//tam wczesniej mamy new int[20] wiec jedna  z tablic 20 elemtnowa jak dodamy to bedziemy sprawdzac za zakresem tej tablicy 
    while (l < r){
        if (*(l++) == number)
            m = l-1;//przypisujemy wartosic l do m jak l bedzie poprawne ale zwiekszy;ismy o jeden wiec przypisujemy nastepny element a nie ten co sie zgadzal 
    }

    //SZCZELINA jeśli użytkownik trafił, to wypisz
    // nie zainicjowalismy  na poczatku tego m a  jak uzytkoniwk nie zgadnie liczby to nigdzie jego wartosu nie ustawiamy 
    // wiec  tutaj porownujemy zmienna ktora jest niezaincjowna wiec wtedy  niewiadomo co sie zdarzy (zadziala,wyjebie program,niezadziala xd wszystko)
    if (m != nullptr &&  *m == number) cout << "Trafiles!" << endl;
    else cout << "Pudlo! Sprobuj jeszcze raz!" << endl;

    delete [] data[0];//bedac super poprawnym trzeba jeszcze dodac tutaj delete tych data bo stowrzylismy je dynamicznie ale to nie jest tez niezbednie 
    delete [] data[1];//bez tego program zadziala i jak sie skonczy sam je usunie
    delete [] data[2];
}