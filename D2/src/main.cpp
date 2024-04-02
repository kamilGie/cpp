#include <iostream>
#include <map>
#include "warehouse.hpp"

using namespace std;
using FunctionMap = map<string,function<void()>>;

FunctionMap INIT_MethodExecutorMap(Warehouse &Wh);
    

int main(){
    
    Warehouse Wh;
    FunctionMap methodExecutor=INIT_MethodExecutorMap(Wh);

    string command;
    do
    {   
        cin>>command;
        if (methodExecutor.find(command) != methodExecutor.end()) { methodExecutor[command](); }

    } while(command!="END");

}


FunctionMap INIT_MethodExecutorMap(Warehouse &Wh){

    FunctionMap res;

    //name                    arguemts                      cin                                  execute method
    res["FILL"]   = [&Wh]() { int W, R, S, P, A;            cin>>W>>R>>S>>P>>A;                  Wh.FILL(W,R,S,P,A);               };
    res["SET-AP"] = [&Wh]() { int wb, rb, sb, Pe;           cin>>wb>>rb>>sb>>Pe;                 Wh.SET_AP(wb,rb,sb,Pe);           };
    res["SET-AR"] = [&Wh]() { int wb, Re, Se, Pe;           cin>>wb>>Re>>Se>>Pe;                 Wh.SET_AR(wb,Re,Se,Pe);           };
    res["SET-AW"] = [&Wh]() { int We, Re, Se, Pe;           cin>>We>>Re>>Se>>Pe;                 Wh.SET_AW(We,Re,Se,Pe);           };
    res["SET-HW"] = [&Wh]() { int w, P;                     cin>>w>>P;                           Wh.SET_HW(w,P);                   };
    res["SET-HR"] = [&Wh]() { int S, P;                     cin>>S>>P;                           Wh.SET_HR(S,P);                   };
    res["SET-HS"] = [&Wh]() { int P;                        cin>>P;                              Wh.SET_HS(P);                     };
    res["PUT-W"]  = [&Wh]() { int w, r, s, p, A;            cin>>w>>r>>s>>p>>A;                  Wh.PUT_W(w,r,s,p,A);              };
    res["PUT-H"]  = [&Wh]() { int w, p, A;                  cin>>w>>p>>A;                        Wh.PUT_H(w, p, A);                };
    res["PUT-R"]  = [&Wh]() { int s, p, A;                  cin>>s>>p>>A;                        Wh.PUT_R(s, p, A);                };
    res["PUT-S"]  = [&Wh]() { int p, A;                     cin>>p>>A;                           Wh.PUT_S(p, A);                   };
    res["POP-W"]  = [&Wh]() { int w, r, s, p, A;            cin>>w>>r>>s>>p>>A;                  Wh.POP_W(w, r, s, p, A);          };
    res["POP-H"]  = [&Wh]() { int w, p, A;                  cin>>w>>p>>A;                        Wh.POP_H(w, p, A);                };
    res["POP-R"]  = [&Wh]() { int s, p, A;                  cin>>s>>p>>A;                        Wh.POP_R(s, p, A);                };
    res["POP-S"]  = [&Wh]() { int p, A;                     cin>>p>>A;                           Wh.POP_S(p,A);                    };
    res["MOV-W"]  = [&Wh]() { int wb,rb,sb,we,re,se,p,A;    cin>>wb>>rb>>sb>>we>>re>>se>>p>>A;   Wh.MOV_W(wb,rb,sb,we,re,se,p,A);  };
    res["MOV-H"]  = [&Wh]() { int w, r, s, p, A;            cin>>w>>r>>s>>p>>A;                  Wh.MOV_H(w, r, s, p, A);          };
    res["MOV-R"]  = [&Wh]() { int w, r, sb, se, p, A;       cin>>w>>r>>sb>>se>>p>>A;             Wh.MOV_R(w, r, sb, se, p, A);     };
    res["MOV-S"]  = [&Wh]() { int s, p, A;                  cin>>s>>p>>A;                        Wh.MOV_S(s, p, A);                };
    res["GET-E"]  = [&Wh]() {                                                                    Wh.GET_E();                       };
    res["GET-W"]  = [&Wh]() { int w;                        cin>>w;                              Wh.GET_W(w);                      };
    res["GET-RW"] = [&Wh]() { int w, r;                     cin>>w>>r;                           Wh.GET_RW(w, r);                  };
    res["GET-RH"] = [&Wh]() {                                                                    Wh.GET_RH();                      };
    res["GET-SW"] = [&Wh]() { int w, r, s;                  cin>>w>>r>>s;                        Wh.GET_SW(w, r, s);               };
    res["GET-SH"] = [&Wh]() { int w;                        cin>>w;                              Wh.GET_SH(w);                     };
    res["GET-SR"] = [&Wh]() { int s;                        cin>>s;                              Wh.GET_SR(s);                     };
    res["GET-S"]  = [&Wh]() {                                                                    Wh.GET_S();                       };
    res["SET-LW"] = [&Wh]() { int w, r, s, p, dd;           cin>>w>>r>>s>>p>>dd;                 Wh.SET_LW(w, r, s, p, dd);        };
    res["SET-LH"] = [&Wh]() { int w, p, dd;                 cin>>w>>p>>dd;                       Wh.SET_LH(w, p, dd);              };
    res["SET-LR"] = [&Wh]() { int s, p, dd;                 cin>>s>>p>>dd;                       Wh.SET_LR(s, p, dd);              };
    res["SET-LS"] = [&Wh]() { int p, dd;                    cin>>p>>dd;                          Wh.SET_LS(p, dd);                 };
    res["GET-LW"] = [&Wh]() { int w, r, s, p;               cin>>w>>r>>s>>p;                     Wh.GET_LW(w, r, s, p);            };
    res["GET-LH"] = [&Wh]() { int w, p;                     cin>>w>>p;                           Wh.GET_LH(w, p);                  };
    res["GET-LR"] = [&Wh]() { int s, p;                     cin>>s>>p;                           Wh.GET_LR(s, p);                  };
    res["GET-LS"] = [&Wh]() { int p;                        cin>>p;                              Wh.GET_LS(p);                     };

    return res;
}