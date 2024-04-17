#include <iostream>
//Trzbea ogarniac co oznacza * oraz & tyle wystarczy by wiedziec o co chodzi tutaj mamy 3 sposoby by wskazywac na jeden obszar w pamieci i go zmieniac 
int main(){
    int n = 1, *p = &n; //Tu jest tworzenie zmiennej n; Oraz pointer *p ktory wskazuje na miejsce w pamieci &n;
    int &r = n; // tu jest referencja na n,  to znaczy ze mamy 2 zmienne ktore sa w tym samym miejscu w pamieci wiec sa takie same i jak zmienimi jedna zmieni sie tez 2;

    std::cout << n << *p <<r;
    *p = 2;//tutaj zmieniamy wartosci ktora jest w miejscu w ktorym wskazuje pointer, wiec kazde te 3 sie zmiena bo wszystkie wskazuja w te same xd 
    std::cout << n << *p << r;
    r = 3;//tu tak samo zmieniamy r ktore bylo referencja na n, wiec wszystkie 3 sie zmiena 
    std::cout << n << *p << r;
    std::cout << endl; //tu trzeba dodac std przy endl by to dzialalo 

    return 0;
}