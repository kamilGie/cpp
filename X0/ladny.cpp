// Alicja Ulidowska
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    // Wczytanie wymiarów prostokąta
    int width, height;
    cin >> width >> height;

    // Wczytanie danych o pierwszym okręgu
    int x1, y1, r1;
    cin >> x1 >> y1 >> r1;

    // Wczytanie danych o drugim okręgu
    int x2, y2, r2;
    cin >> x2 >> y2 >> r2;

    // Wczytanie współczynników równania kwadratowego
    double a, b, c;
    cin >> a >> b >> c;

    // Wypisanie "Hello world!"
    cout << "Hello world!" << endl;

    // Obliczenie i wypisanie pola oraz obwodu prostokąta
    int area = width * height;
    int perimeter = 2 * (width + height);
    cout << area << " " << perimeter << endl;

    // Sprawdzenie, czy okręgi się przecinają
    int dx = x2 - x1;
    int dy = y2 - y1;
    double distance = sqrt(dx * dx + dy * dy);
    if (distance <= r1 + r2) {
        cout << "niepuste" << endl;
    } else {
        cout << "puste" << endl;
    }

    // Rozwiązanie równania kwadratowego
    double discriminant = b * b - 4 * a * c;
    if (a == 0) {
        cout << "blad" << endl;
    } else if (discriminant > 0) {
        cout << "2" << endl;
    } else if (discriminant == 0) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}