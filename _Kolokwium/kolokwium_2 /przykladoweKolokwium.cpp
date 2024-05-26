// Ten program można skompilować z linii komend poleceniem g++ *.cpp
// Należy poprawić wszystkie błędy kompilacji - należy na nie zwrócic uwagę. 
// Są one celowe i ważne dla potrzeby kolokwium.
// Nastepnie należy program uruchomić i sprawdzic jego działanie - czy daje oczekiwane wyniki.
// To też jest ważne z punktu widzenia Kolokwium. 

#include <iostream>
using namespace std;

void foo(double* d);
void foo(int a) { cout << "a " << a << endl; a++; }
void foo(double& b) { cout << "b " << b << endl; b*=2; }
int  foo(const double& c);
void foo(double* d);

int main(){
    int z = 15, w = 0; 
    double y = 3.5;
    const double PI = 3.14;
    double t[3] = {1.1, 2.2, 3.3};
    foo(z); 
    foo(y); 
    foo(t[0]);     
    foo(PI);    
    foo(t);
    foo(t+1);
    cout << z << " "<< y << " " << PI << endl; 
    cout << t[0] << " " << t[1] << " " <<  t[2] << endl;    
    w = foo(static_cast<const double&>(y));
    w = foo(PI);
    return 0;
}

int foo(const double& c) { 
    cout << "c " << c << endl; 
    // c/=3;
    return c + 1;
}

void foo(double* d) { 
    cout << "d " << *d << endl; (*d) += 3; 
}