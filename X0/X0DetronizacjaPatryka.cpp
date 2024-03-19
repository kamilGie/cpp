//Kamil Gieras
#include<iostream>
main(){long long A,B,z,Z,x,y,X,Y;double a,b,c;std::cin>>A>>B>>x>>y>>z>>X>>Y>>Z>>a>>b>>c;b=b*b-4*a*c,X-=x,Y-=y,Z+=z;printf("Hello world!\n%lld %lld%spuste\n%s",A*B,2*(A+B),X*X+Y*Y<=Z*Z?"\nnie":"\n",a?b>0?"2":b?"0":"1":"blad");}