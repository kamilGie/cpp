//kamil gieras
#include<iostream>

int main(){
int N;
std::cin>>N;
 std::cout<<"hallooo";
while(N--){
 int**T=new int*[8], C[8], S[8]{},a,b,i,j;
 for(i=0;i<8;C[i++]=2) T[i]=new int[2];
 for(;std::cin>>a>>b&&a>=0;T[a][S[a]-1]=b){
  if(++S[a]==C[a]){
   int*t=new int[C[a]*2];
   for(i=0;i<C[a];i++) t[i]=T[a][i];
   delete[]T[a];
   T[a]=t; C[a]*=2;
  }
 }

 for(i=0;i<8;) for(j=0;j<S[i];printf("%d ",T[i][j++]));
 puts("");
 }
}