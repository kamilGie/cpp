//Kamil Gieras
#include<iostream>
using namespace std;
char P[26];int W[26]={},L[26]={},D[26]={};
int R(int r[],int* v,int* d,int* s){
int q=0;for (int i=0;i<4;i++){int z=0;for(int j=i+1;j<4;j++)if (r[i]==r[j])z++;if (q==z&&z==1){*d=(*v>r[i]?*v:r[i]);*v=*d;}if (q<z){*v=r[i];q=z;}*s+=r[i];}return ++q;}
int Wn(int R1[],int R2[]){int rp1,rv1=0,dr1=0,sv1=0,rp2,rv2=0,dr2=0,sv2=0;rp1=R(R1,&rv1,&dr1,&sv1);rp2=R(R2,&rv2,&dr2,&sv2);if(rp1==rp2){if(dr1!=dr2)return(dr1>dr2?1:2);if(rv1!=rv2)return(rv1>rv2?1:2);if(sv1!=sv2)return(sv1>sv2?1:2);return 0;}if(rp1%3==1||rp2%3==1)return(rp1>rp2?1:2);if(dr1||dr2)return(dr1>dr2?1:2);return(rp1>rp2?1:2);}
void Duel(){char p,q;int R1[4],R2[4];cin>>p>>R1[0]>>R1[1]>>R1[2]>>R1[3]>>q>>R2[0]>>R2[1]>>R2[2]>>R2[3];switch(Wn(R1,R2)){case 1:++W[p-97];++L[q-97];break;case 2:++W[q-97];++L[p-97];break;case 0:++D[p-97];++D[q-97];}}
double Pc(int P,int e){return 100*(double)e/(W[P]+D[P]+L[P]);}
void PS(int p){cout<<"gracz "<<P[p]<<endl;if(W[p])cout<<"    wygrane: "<<Pc(p,W[p])<<"%\n";if(D[p])cout<<"    remisy: "<<Pc(p,D[p])<<"%\n";if(L[p])cout<<"    przegrane: "<<Pc(p,L[p])<<"%\n";}
void PR(){bool f=0;for(int i=0;i<26;i++){if(W[i]||L[i]||D[i]){if(!f)f=1;else cout<<endl;PS(i);}}}
int main(){for(int i=0;i<26;i++)P[i]=97+i;int G;cin>>G;for(int i=0;i<G;i++)Duel();PR();}