//Kamil gieras
#include<iostream>
#include"tablica.h"
int main(){
int N,s,L=65536,d,i=0;
ushort*t=tablica,*p=t+L;
for(std::cin>>N>>s;i++<N;std::cin>>*p++);

for(;std::cin>>s>>d;puts("")){
p=t;
for(i=0;i++<L;*p++=0);
for(;;s+=d){
  s%=N;s<0?s+=N:0;
  if((*(t+*t+s+L))++)break;
  printf("%d ",*(t+s+L));
}
}}