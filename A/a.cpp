//Kamil Gieras
#include<iostream>
using namespace std;

char Players[26];
int Wins[26] = {0}, Losses[26] = {0}, Draws[26] = {0};

void Duel(); int Winner(short rolls_P1[], short rolls_P2[]); int RepsValuesCounter(short roll[], int *value, int *doubleReps, int *sumaric);
void PrintRanking(); double percentage(int P,int events); void PrintStats(int player);

int main() {
    for (int i=0;i<26;i++) Players[i]='a'+i;
    unsigned G; cin>>G;
    for (int i=0;i<G;i++)
        Duel();

    PrintRanking();
}

void Duel() 
{
char p1,p2;short R1[4],R2[4];
cin>>p1>>R1[0]>>R1[1]>>R1[2]>>R1[3]>>p2>>R2[0]>>R2[1]>>R2[2]>>R2[3];

switch (Winner(R1,R2)) {
case 1:
    ++Wins[p1-'a'];
    ++Losses[p2-'a'];
break;
case 2:
    ++Wins[p2-'a'];
    ++Losses[p1-'a'];
    break;
default :
    ++Draws[p1-'a'];
    ++Draws[p2-'a'];
}
}

int Winner(short rolls_P1[], short rolls_P2[])
{
int reps_P1, repsValue_P1=0,doubleRepsValue_P1=0,sumaricValue_P1=0;
int reps_P2, repsValue_P2=0,doubleRepsValue_P2=0,sumaricValue_P2=0;

reps_P1=RepsValuesCounter(rolls_P1,&repsValue_P1,&doubleRepsValue_P1,&sumaricValue_P1);
reps_P2=RepsValuesCounter(rolls_P2,&repsValue_P2,&doubleRepsValue_P2,&sumaricValue_P2);

if(reps_P1==reps_P2){
    if(doubleRepsValue_P1!=doubleRepsValue_P2) return(doubleRepsValue_P1 > doubleRepsValue_P2?1:2);
    if(repsValue_P1!=repsValue_P2) return(repsValue_P1 > repsValue_P2?1:2);
    if(sumaricValue_P1!=sumaricValue_P2) return(sumaricValue_P1 > sumaricValue_P2?1:2);
    return 0;
}
if(reps_P1%3==1 || reps_P2%3==1)
    return (reps_P1>reps_P2?1:2);
if(doubleRepsValue_P1 || doubleRepsValue_P2)
    return (doubleRepsValue_P1>doubleRepsValue_P2?1:2);
return(reps_P1>reps_P2?1:2);
}

int RepsValuesCounter(short roll[], int *value, int *doubleReps, int *sumaric)
{
int result=0;
for (int i=0;i<4;i++){
    int counter=0;
    for (int j=i+1;j<4;j++)
        if (roll[i]==roll[j]) counter++;
    if (result==counter && counter==1){
        *doubleReps=(*value>roll[i]?*value:roll[i]);
        *value=*doubleReps;
    }
    if (result<counter){
        *value=roll[i];
        result=counter;
    }
    *sumaric += roll[i];
}
return ++result;
}

void PrintRanking() 
{
bool flag=0;
for (int i=0;i<26;i++){
    if(Wins[i]||Losses[i]||Draws[i]) {
        if(!flag) flag=true;
        else cout<<endl;
        PrintStats(i);
    }
}
}

void PrintStats(int player) 
{
cout <<"gracz "<<Players[player]<<endl;
if (Wins[player])  cout<<"    wygrane: "<<percentage(player,Wins[player])<<"%\n";
if (Draws[player]) cout<<"    remisy: "<<percentage(player,Draws[player])<<"%\n";
if (Losses[player])cout<<"    przegrane: "<<percentage(player,Losses[player])<<"%\n";
}
double percentage(int P,int events) {return 100*(double)events/(Wins[P]+Draws[P]+Losses[P]);}