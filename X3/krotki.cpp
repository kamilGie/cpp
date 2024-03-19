//Kamil gieras
#include<iostream>
main(){
int N,s,d=0;std::cin>>N>>s;unsigned short x[N];
for(;d<N;std::cin>>x[d++]);
for(;std::cin>>s>>d;puts(""))
 for(bool r[65536]={};;s+=d){
  s%=N;s<0?s+=N:0;
  if(r[x[s]])break;
  r[x[s]]=1;
  printf("%hu ",x[s]);}
}