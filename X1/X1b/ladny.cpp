// kamil gieras
#include <iostream>
int main()
{
    int liczbaDzielona, liczbaCyfr,dzielniki;
    std::cin >> liczbaDzielona >> liczbaCyfr;
    for (int i = 0; i < liczbaCyfr; i++)
    {
        std::cin >> dzielniki;
        std::cout<<(liczbaDzielona % dzielniki == 0?"TAK\n":"NIE\n");
    }
}
