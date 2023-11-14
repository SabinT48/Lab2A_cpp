#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    char denumire[100], directorie[100];
    int op, marimea, current = 0, index;
    File f[10];

    while(1){
        cout << "---------------------------------------------\n";
        cout << "|0.  Iesire                                 |\n";
        cout << "|1.  Introdu un nou fisier                  |\n";
        cout << "|2.  Afiseaza fisierele                     |\n";
        cout << "|3.  Schimba denumirea la fisier            |\n";
        cout << "|4.  Schimba directoriul                    |\n";
        cout << "|5.  Modificarea a anexei de asociere       |\n";
        cout << "|6.  Constructor general                    |\n";
        cout << "|7.  Constructor de copiere                 |\n";
        cout << "|8.  Constructor de schimbare a tipului     |\n";
        cout << "---------------------------------------------\n-->";
        cin >> op;

        switch(op){
            case 0:{
                cout << "Sfarsit de program!\n";
                exit (0);
            }
                break;
            case 1:{
                if(checkFull(current)){
                    cout << "Nu ma este loc!!\n";
                }else{
                    cout << "Introdu denumirea fisierului - ";
                    cin >> denumire;
                    cout << "Introdu marimea fisierului - ";
                    cin >> marimea;
                    cout << "Introdu directoria - ";
                    cin >> directorie;
                    f[current].SetClass(denumire, marimea, directorie);
                    current++;
                }
            }
                break;
            case 2:{
                if(CheckEmpty(current)){
                    cout << "Lista este pustie!!\n";
                }else{
                    cout << "Lista de fisiere\n";
                    for(int i = 0;i < current;i++){
                        cout << "Fisierul nr." << i+1 << endl;
                        f[i].afisare();
                    }
                }
            }
                break;
            case 3:{
                if(CheckEmpty(current)){
                    cout << "Lista este pustie!!\n";
                }else{
                    cout << "Alege fisierul - ";
                    cin >> index;
                    index--;
                    if((index < 0)||(index >= current)){
                        cout << "Nu exista asa fisier!!\n";
                    }else{
                        char numetemp[100];
                        cout << "Introdu noua denumire - ";
                        cin >> numetemp;
                        f[index].SetNume(numetemp);
                    }
                }
            }
                break;
            case 4:{
                if(CheckEmpty(current)){
                    cout << "Lista este pustie!!\n";
                }else{
                    cout << "Alege fisierul - ";
                    cin >> index;
                    index--;
                    if((index < 0)||(index >= current)){
                        cout << "Nu exista asa fisier!!\n";
                    }else{
                        char numetemp[100];
                        cout << "Introdu noul directoriu - ";
                        cin >> numetemp;
                        f[index].SetDirectoriu(numetemp);
                    }
                }
            }
                break;
            case 5:{
                if(CheckEmpty(current)){
                    cout << "Lista este pustie!!\n";
                }else{
                    cout << "Alege fisierul - ";
                    cin >> index;
                    index--;
                    if((index < 0)||(index >= current)){
                        cout << "Nu exista asa fisier!!\n";
                    }else{
                        char numetemp[100];
                        cout << "Introdu extensia - ";
                        cin >> numetemp;
                        f[index].SetExtensie(numetemp);
                    }
                }
            }
                break;
            case 6:{
                cout << "Introdu denumirea fisierului - ";
                cin >> denumire;
                cout << "Introdu marimea fisierului - ";
                cin >> marimea;
                cout << "Introdu directoria - ";
                cin >> directorie;
                File temp(denumire, marimea, directorie);
                temp.afisare();
            }
                break;
            case 7:{
                cout << "Alege fisierul - ";
                cin >> index;
                index--;
                if((index < 0)||(index >= current)){
                    cout << "Nu exista asa fisier!!\n";
                }else{
                    File temp(f[index]);
                    temp.afisare();
                }
            }
                break;
            case 8:{
                cout << "Alege fisierul - ";
                cin >> index;
                index--;
                if((index < 0)||(index >= current)){
                    cout << "Nu exista asa fisier!!\n";
                }else{
                    char strtemp[100];
                    cout << "Introdu denumirea - ";
                    cin >> strtemp;
                    File temp(f[index], strtemp);
                    temp.afisare();
                }
            }
                break;
            default:{
                cout << "Nu exista asa optiune!!\n\n";
            }
        }
    }
    return 0;
}
