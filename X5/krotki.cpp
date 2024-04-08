//kamil gieras
#include<iostream>

int C2x(int*&T, int&C){
 int*tmp=new int[C*2],i;
 for(i=0; i<C; i++) tmp[i]=T[i];
 delete[] T;
 T=tmp;
 C*=2;
}

int set(){
 int**T=new int*[8], C[8], S[8]{},a,b,i,j;
 for(i=0; i<8; C[i++]=2) T[i]=new int[2];

 while(std::cin>>a>>b){
  if(a<0) break;
  if(++S[a]==C[a]) C2x(T[a], C[a]);
  T[a][S[a]-1]=b;
 }

 for(i=0; i<8; delete[] T[i++])
  for(j=0; j<S[i]; j++) printf("%d ",T[i][j]);
 puts("");
 delete[] T;
}

main(){
 int N;
 std::cin>>N;
 while(N--) set();
}