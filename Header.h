#include <iostream>
#include <ctime>
using namespace std;

class File{
    char *nume;
    int marimea;
    char *timpul;
    char *directorie;
    char *extensie;
public:
    //constructor implicit
    File();
    
    //constructor general
    File(char *nume, int marimea, char *directorie){
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
    
    //constructor de copiere
    File(const File& other){
        cout << "S-a apelat constructorul de copiere\n\n";
        nume = new char[strlen(other.nume)+1];
        strcpy(nume, other.nume);
        extensie = new char[strlen(other.extensie)+1];
        strcpy(extensie, other.extensie);
        directorie = new char[strlen(other.directorie)+1];
        strcpy(directorie, other.directorie);
        timpul = new char[40];
        strcpy(timpul, other.timpul);
        marimea = other.marimea;
    }
    
    //constructor de conversie a tipului
    File(const File &other, const char *str){
        cout << "S-a apelat constructorul de schimbare a tipului\n\n";
        
        nume = new char[strlen(str)+1];
        strcpy(nume, str);
        
        marimea = other.marimea;
        
        directorie = new char[strlen(other.directorie)+1];
        strcpy(directorie, other.directorie);
        
        extensie = new char[strlen(other.extensie)+1];
        strcpy(extensie, other.extensie);
        
        timpul = new char[40];
        strcpy(timpul, other.timpul);
    }
    
    //destructor
    ~File();
    
    //afisare
    void afisare();
    
    void SetClass(char *nume, int marimea, char *directorie);
    
    void SetNume(char *temp);
    
    void SetDirectoriu(char *temp);
    
    void SetExtensie(char *temp);
};

bool CheckEmpty(int n);

bool checkFull(int n);
