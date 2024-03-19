// kamil gieras
#include <iostream>
int main()
{
    int liczbaDzielona, liczbaCyfr;
    std::cin >> liczbaDzielona >> liczbaCyfr;
    int Liczby;
    for (int i = 0; i < liczbaCyfr; i++)
    {
        std::cin >> Liczby;
        if (liczbaDzielona % Liczby == 0)
            std::cout << "TAK\n";
        else
            std::cout << "NIE\n";
    }
}