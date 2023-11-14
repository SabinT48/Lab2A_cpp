#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

File::File(){
    nume = nullptr;
    timpul = nullptr;
    directorie = nullptr;
    extensie = nullptr;
}

File::~File(){
    if(nume == nullptr && timpul == nullptr && directorie == nullptr && extensie == nullptr){
        return;
    }else{
        delete[] nume;
        nume = nullptr;
        delete[] timpul;
        timpul = nullptr;
        delete[] directorie;
        directorie = nullptr;
        delete[] extensie;
        extensie = nullptr;
    }
}

void File::afisare(){
    cout << "Denumirea - " << nume << extensie << endl;
    cout << "Extensie - " << extensie << endl;
    cout << "Directoria - " << directorie << endl;
    cout << "Marimea - " << marimea << " mb\n";
    cout << "Timpul crearii - " << timpul << endl;
}

void File::SetClass(char *nume, int marimea, char *directorie){
    //denumirea
    int i;
    for(i = 0;nume[i] != '.';i++);
    this->nume = new char[i + 1];
    for(i = 0;nume[i] != '.';i++){
        this->nume[i] = nume[i];
    }

    //extensia
    int j = i;
    while(nume[j] != '\0'){
        j++;
    }
    j -= i;
    this->extensie = new char[j+1];

    for(int j = 0;nume[i] != '\0';i++, j++){
        this->extensie[j] = nume[i];
    }

    //timpul
    time_t now = time(0);
    char *dt = ctime(&now);
    this->timpul = new char[40];
    strcpy(this->timpul, dt);

    //directoria
    this->directorie = new char[strlen(directorie)+1];
    strcpy(this->directorie, directorie);

    //marimea
    this->marimea = marimea;
}

void File::SetNume(char *temp){
    delete[] nume;
    nume = new char(strlen(temp)+1);
    strcpy(nume, temp);
}

void File::SetDirectoriu(char *temp){
    delete[] directorie;
    directorie = new char(strlen(temp)+1);
    strcpy(directorie, temp);
}

void File::SetExtensie(char *temp){
    delete[] extensie;
    extensie = new char(strlen(temp)+1);
    strcpy(extensie, temp);
}

bool CheckEmpty(int n){
    if(n <= 0)
        return true;
    else
        return false;
}

bool checkFull(int n){
    if(n >= 10)
        return true;
    else
        return false;
}
