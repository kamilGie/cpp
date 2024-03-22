//kamil gieras
#include<iostream>
using namespace std;

int arrLen;

int FrVal(int L)
{
 int Counter=0;
 while(Counter <= arrLen) Counter+=L;
 return --Counter/L;
}

int Ival(int i)
{
 return i>=0 ? i%arrLen: (i%arrLen)+arrLen;
}

void swpE(int*V1,int*V2)
{
 int tmp=*V1; *V1=*V2; *V2=tmp;
}

void cyclicLeft(int*aray,int firstIndex,int Seglen)
{
 for(int i=1;i<Seglen;i++){
  swpE(&aray[firstIndex], &aray[Ival(firstIndex+1)]);
  firstIndex = Ival(firstIndex+1);
 }
 }
 
 void cyclicRight(int*aray,int lastIndex,int Seglen)
 {
 for(int i=1;i<Seglen;i++){
  swpE(&aray[lastIndex], &aray[Ival(lastIndex-1)]);
  lastIndex=Ival(lastIndex-1);
 }
}

void cyclicShift(int*aray)
{
 int i,L,s;
 cin>>i>>L>>s;
 int FrCount=FrVal(L);
 while(FrCount--){
  int S=s;
  while(S<0) {cyclicLeft(aray,Ival(i),L); S++;}
  while(S>0) {cyclicRight(aray,Ival(i+L-1),L); S--;}
 i=Ival(i+L);
 }
 
 int RestL=arrLen%L;
 if(RestL){
  while(s<0){cyclicLeft(aray,Ival(i),RestL); s++;} 
  while(s>0) {cyclicRight(aray,Ival(i+RestL),RestL); s--;};
 }
}

void switc(int*aray)
{
 int i,I,L;
 cin>>i>>L;
 int FrCount=FrVal(2*L);
 while(FrCount--){
  I=Ival(i+L);
  for(int j=0;j<L;j++,i++,I++){
   i=Ival(i); I=Ival(I);
   swpE(&aray[i],&aray[I]);
   }
  i=Ival(I+1);
 }
}

void reverse(int*aray)
{
 int i,L,I;
 cin>>i>>L;

 int FrCount=FrVal(L);
 while(FrCount--){
  I=Ival(i+L-1);
  int NextI=Ival(I+1);
  for(int j=0;j<L/2;j++,i++,I--){
   i=Ival(i);
   I=Ival(I);
   swpE(&aray[i],&aray[I]);
   }
  i=NextI;
 }
}

void operateOnAray(int*aray)
{
 char ch='X';
 while(ch!='F'){
 cin>>ch;
 switch(ch){
 case 'R':
  reverse(aray); break;
 case 'C':
  cyclicShift(aray); break;
 case 'S':
  switc(aray); break;
 default:
  break;
 }
 }
}

void printAray(int*aray)
{
 for(int i=0;i<arrLen;i++) cout<<aray[i]<<" ";
 cout<<endl;
}


int*readAray()
{
 int*aray=new int[arrLen];
 for(int i=0;i<arrLen;i++) cin>>aray[i];
 return aray;
}

void CircularAray()
{
 cin>>arrLen;
 int*aray=readAray();
 printAray(aray);
 operateOnAray(aray);
 printAray(aray);
 delete[]aray;
}

int main()
{
 int arays;
 cin>>arays;
 while(arays--) CircularAray();
 return 0;
}