//kamil gieras
#include<iostream>
using namespace std;

char P[26];int W[26]={},L[26]={},D[26]={};

int R(short r[],int *v,int *d,int *s){
  int res=0;
  for (int i=0;i<4;i++)
  {
    int c=0;
    for (int j=i+1;j<4;j++)
      if (r[i]==r[j]) c++;
    if (res==c&&c==1) {*d=(*v>r[i]?*v:r[i]);*v=*d;}
    if (res<c) {*v=r[i];res=c;}
    *s+=r[i];
  }
  return ++res;
}
int Wn(short R1[], short R2[]){
  int rp1,rv1=0,dr1=0,sv1=0,rp2,rv2=0,dr2=0,sv2=0;
  rp1=R(R1,&rv1,&dr1,&sv1);rp2=R(R2,&rv2,&dr2,&sv2);
  if(rp1==rp2){
    if(dr1!=dr2) return(dr1>dr2?1:2);
    if(rv1!=rv2) return(rv1>rv2?1:2);
    if(sv1!=sv2) return(sv1>sv2?1:2);
    return 0;
  }
  if(rp1%3==1||rp2%3==1)return(rp1>rp2?1:2);
  if(dr1||dr2) return(dr1>dr2?1:2);
  return(rp1>rp2?1:2);
}
void Duel(){
 char p1,p2;short R1[4],R2[4];
 cin>>p1>>R1[0]>>R1[1]>>R1[2]>>R1[3]>>p2>>R2[0]>>R2[1]>>R2[2]>>R2[3];
 switch (Wn(R1,R2)){
  case 1:
   ++W[p1-97];
   ++L[p2-97];
   break;
  case 2:
    ++W[p2-97];
    ++L[p1-97];
    break;
  case 0:
    ++D[p1-97];
    ++D[p2-97];
  }
}
double Pc(int P,int e) {
 return 100*(double)e/(W[P]+D[P]+L[P]);
}
void PS(int p){
 cout<<"gracz "<<P[p]<<endl;
 if(W[p])cout<<"    wygrane: "<<Pc(p,W[p])<<"%\n";
 if(D[p])cout<<"    remisy: "<<Pc(p,D[p])<<"%\n";
 if(L[p])cout<<"    przegrane: "<<Pc(p,L[p])<<"%\n";
}
void PR() {
 bool f=0;
 for(int i=0;i<26;i++){
  if(W[i]||L[i]||D[i]) {
    if(!f)f=1;
    else cout<<endl;
    PS(i);
    }
  }
}
int main(){
 for(int i=0;i<26;i++) P[i]=97+i;
 int G;cin>>G;
 for(int i=0;i<G;i++) Duel();
 PR();
}