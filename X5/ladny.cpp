// kamil gieras
#include <iostream>

using namespace std;

void increaseCapacity(int **&arr, int a, int& capacity) {
    int *tmp = new int[capacity * 2];
    for (int i = 0; i < capacity; i++) {
        tmp[i] = arr[a][i];
    }
    delete[] arr[a];
    arr[a] = tmp;
    capacity *= 2;
}

void set() {
    // tworze tablice wraz z wielkoscia i pojemnoscia
    int **arr = new int *[8];
    int capacity[8], size[8]{};

    for (int i = 0; i < 8; i++) {
        arr[i] = new int[2];
        capacity[i] = 2;
    }

    //dodaje te liczby co wymagane 
    int a, b;
    while (true) {
        cin >> a >> b;

        if (a == -1) break;
        if (a > 7) continue;
        if (++size[a] == capacity[a]) increaseCapacity(arr, a, capacity[a]);

        arr[a][size[a] - 1] = b;
    }

    //wypisuje tabice
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < size[i]; j++) {
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;

    //usuwam z pamieci tablicze
    for (int i = 0; i < 8; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        set();
    }
}