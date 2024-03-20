#include <iostream>
#include "source.cpp"
using namespace std;

int main(){
    int data[4096];
    data[0] = -1;
    int tablicaTestowa_1[10]={1,1,1,1,1,2,3,4,-1};
    int tablicaTestowa_2[10]={1,1,1,-1};

   //Complement(tablicaTestowa_1,data);
    int ilosci_elemetnow;
   // cout<<(Cardinality(tablicaTestowa_2))<<endl;
   Cardinality(tablicaTestowa_2,&ilosci_elemetnow);
   cout<<ilosci_elemetnow;
    for(int i=0;i<4096;i++)
    {
        if(data[i]==-1)
        break;
        cout<<data[i]<<endl;
      
    }
    return 0;
}