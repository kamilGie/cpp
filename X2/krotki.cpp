//Kamil Gieras
#include<iostream>
main(){
int I,x,i,m,M;
while(std::cin>>I>>x){
  float sr=m=M=x;i=I;
  while(--i){std::cin>>x;x<m?m=x:x>M?M=x:0;sr+=x;}
  printf("%d %d %g\n",m,M,sr/I);
  }
}