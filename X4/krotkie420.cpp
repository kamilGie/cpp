//Kamil Gieras
#include<iostream>
#include"tablica.h"
main(){
 int N,M,d,s,L=65536,I; std::cin>>N>>M;
 ushort*t=tablica, *ptr=t+L;
 for(I=0;I<N;I++) std::cin>>*ptr++;

 for(I=0;I<M;I++){
    ptr=t;
    for(int i=0;i<L;++i) *ptr++=0;
    for(std::cin>>s>>d;;s+=d){
        s=s%N;
        if(s<0) s=s+N;
        if(*(t+*(t+s+L))) break;
        *(t+*(t+s+L))=1;
        printf("%d ",*(t+s+L));
    }
    puts("");
    }
}
