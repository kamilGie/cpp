#include <iostream>
#include <map>
#include "Depot.hpp"

using namespace std;
using FunctionMap = map<string,function<void()>>;

FunctionMap INIT_MethodExecutorMap(Depot &D);
    

int main(){
    
    Depot D;
    FunctionMap methodExecutor=INIT_MethodExecutorMap(D);

    string command;
    do
    {   
        cin>>command;
        if (methodExecutor.find(command) != methodExecutor.end()) { methodExecutor[command](); }

    } while(command!="END");

}


FunctionMap INIT_MethodExecutorMap(Depot &D){

    FunctionMap res;

    //name                    arguemts                      cin                                  execute method
    res["FILL"]   = [&D]() { int W, R, S, P, A;            cin>>W>>R>>S>>P>>A;                  D.FILL(W,R,S,P,A);               };
    res["SET-AP"] = [&D]() { int wb, rb, sb, Pe;           cin>>wb>>rb>>sb>>Pe;                 D.SET_AP(wb,rb,sb,Pe);           };
    res["SET-AR"] = [&D]() { int wb, Re, Se, Pe;           cin>>wb>>Re>>Se>>Pe;                 D.SET_AR(wb,Re,Se,Pe);           };
    res["SET-AW"] = [&D]() { int We, Re, Se, Pe;           cin>>We>>Re>>Se>>Pe;                 D.SET_AW(We,Re,Se,Pe);           };
    res["SET-HW"] = [&D]() { int w, P;                     cin>>w>>P;                           D.SET_HW(w,P);                   };
    res["SET-HR"] = [&D]() { int S, P;                     cin>>S>>P;                           D.SET_HR(S,P);                   };
    res["SET-HS"] = [&D]() { int P;                        cin>>P;                              D.SET_HS(P);                     };
    res["PUT-W"]  = [&D]() { int w, r, s, p, A;            cin>>w>>r>>s>>p>>A;                  D.PUT_W(w,r,s,p,A);              };
    res["PUT-H"]  = [&D]() { int w, p, A;                  cin>>w>>p>>A;                        D.PUT_H(w, p, A);                };
    res["PUT-R"]  = [&D]() { int s, p, A;                  cin>>s>>p>>A;                        D.PUT_R(s, p, A);                };
    res["PUT-S"]  = [&D]() { int p, A;                     cin>>p>>A;                           D.PUT_S(p, A);                   };
    res["POP-W"]  = [&D]() { int w, r, s, p, A;            cin>>w>>r>>s>>p>>A;                  D.POP_W(w, r, s, p, A);          };
    res["POP-H"]  = [&D]() { int w, p, A;                  cin>>w>>p>>A;                        D.POP_H(w, p, A);                };
    res["POP-R"]  = [&D]() { int s, p, A;                  cin>>s>>p>>A;                        D.POP_R(s, p, A);                };
    res["POP-S"]  = [&D]() { int p, A;                     cin>>p>>A;                           D.POP_S(p,A);                    };
    res["MOV-W"]  = [&D]() { int wb,rb,sb,we,re,se,p,A;    cin>>wb>>rb>>sb>>we>>re>>se>>p>>A;   D.MOV_W(wb,rb,sb,we,re,se,p,A);  };
    res["MOV-H"]  = [&D]() { int w, r, s, p, A;            cin>>w>>r>>s>>p>>A;                  D.MOV_H(w, r, s, p, A);          };
    res["MOV-R"]  = [&D]() { int w, r, sb, se, p, A;       cin>>w>>r>>sb>>se>>p>>A;             D.MOV_R(w, r, sb, se, p, A);     };
    res["MOV-S"]  = [&D]() { int s, p, A;                  cin>>s>>p>>A;                        D.MOV_S(s, p, A);                };
    res["GET-E"]  = [&D]() {                                                                    D.GET_E();                       };
    res["GET-W"]  = [&D]() { int w;                        cin>>w;                              D.GET_W(w);                      };
    res["GET-RW"] = [&D]() { int w, r;                     cin>>w>>r;                           D.GET_RW(w, r);                  };
    res["GET-RH"] = [&D]() {                                                                    D.GET_RH();                      };
    res["GET-SW"] = [&D]() { int w, r, s;                  cin>>w>>r>>s;                        D.GET_SW(w, r, s);               };
    res["GET-SH"] = [&D]() { int w;                        cin>>w;                              D.GET_SH(w);                     };
    res["GET-SR"] = [&D]() { int s;                        cin>>s;                              D.GET_SR(s);                     };
    res["GET-S"]  = [&D]() {                                                                    D.GET_S();                       };
    res["SET-LW"] = [&D]() { int w, r, s, p, dd;           cin>>w>>r>>s>>p>>dd;                 D.SET_LW(w, r, s, p, dd);        };
    res["SET-LH"] = [&D]() { int w, p, dd;                 cin>>w>>p>>dd;                       D.SET_LH(w, p, dd);              };
    res["SET-LR"] = [&D]() { int s, p, dd;                 cin>>s>>p>>dd;                       D.SET_LR(s, p, dd);              };
    res["SET-LS"] = [&D]() { int p, dd;                    cin>>p>>dd;                          D.SET_LS(p, dd);                 };
    res["GET-LW"] = [&D]() { int w, r, s, p;               cin>>w>>r>>s>>p;                     D.GET_LW(w, r, s, p);            };
    res["GET-LH"] = [&D]() { int w, p;                     cin>>w>>p;                           D.GET_LH(w, p);                  };
    res["GET-LR"] = [&D]() { int s, p;                     cin>>s>>p;                           D.GET_LR(s, p);                  };
    res["GET-LS"] = [&D]() { int p;                        cin>>p;                              D.GET_LS(p);                     };

    return res;
}