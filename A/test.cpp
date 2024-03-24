#include <iostream>
using namespace std;
int main()
{

    int kostki[4] = {4, 2, 1, 3};

    for (int i = 0; i < 4; i++)
        for (int j = 1; j < 4; j++)
            if (kostki[j - 1] > kostki[j])
                swap(kostki[j - 1], kostki[j]);// \todo  cos takiego istenieje to sam sie zdziwilem xddd

    cout<<kostki[0]<<endl;
    cout<<kostki[1]<<endl;
    cout<<kostki[2]<<endl;
    cout<<kostki[3]<<endl;



}