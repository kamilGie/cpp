//Kamil Gieras
#include <iostream>
int main() {
    unsigned int BokA, BokB, z, Z;short x, y, X, Y;double a, b, c;

    std::cin >> BokA >> BokB >> x >> y >> z >> X >> Y >> Z >> a >> b >> c;

    std::cout <<"Hello world!\n" << BokB * BokA << " " << BokA * 2 + BokB * 2 << std::endl;
    std::cout << ((X - x) * (X - x) + (Y - y) * (Y - y) <= (z + Z) * (z + Z) ? "niepuste\n" : "puste\n");
    std::cout << (a == 0 ? "blad" : (b * b - 4 * a * c > 0 ? "2" : (b * b - 4 * a * c == 0 ? "1" : "0"))) << std::endl;
    
    return 0;
}
