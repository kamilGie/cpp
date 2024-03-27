// kamil gieras
// jeszcez nwm czy to dziala baca nie dziala
#include <iostream>
#include "tablica.h"
using namespace std;
int main()
{
    int N, M, d, s;
    cin >> N >> M;

    unsigned short *ptr = tablica + 65536;
    for (int i = 0; i < N; i++)
    {
        cin >> *ptr++;
    }

    for (int i = 0; i < M; i++)
    {
        ptr = tablica;
        for (int i = 0; i < 65536; ++i)
        {
            *ptr++ = 0;
        }
        cin >> s >> d;
        while (true)
        {
            s = s % N;
            if (s < 0)
                s = s + N;

            if (*(tablica + *(tablica + s + 65536)))
                break;

            *(tablica + *(tablica + s + 65536)) = true;
            cout << *(tablica + s + 65536) << " ";
            s = s + d;
        }
        cout << endl;
    }
}