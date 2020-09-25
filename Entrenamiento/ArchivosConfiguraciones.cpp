#include <iostream>
#include <ctime>
#include <time.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#include "ArchivosConfiguraciones.h"

bool Confirmacion(){
    int Confirmar, confirmacion;
    srand(time(NULL));
    Confirmar=(rand()%10000)+1000;
    cout<<"Para realizar la Copia debera validar el numero ingresado"<<endl<<endl;
    cout<<"\t|"<<Confirmar<<"|\t";
    cin>>confirmacion;
    if(Confirmar==confirmacion){
        return true;
    }
return false;
}

bool continuar(){
    char opcion[3]={};
    cin.getline(opcion, 4, '\n');
    if(strcmp(opcion, "si")==0){
        return true;
    }
    else{
        if(strcmp(opcion, "no")==0){
            return false;
        }
    }
    do{
        cout<<endl<<"-Error de ingreso de datos-"<<endl;
        cout<<"Desea continuar (SI/NO): ";
        cin.getline(opcion, 4, '\n');
        if(strcmp(opcion, "si")==0){
            return true;
        }
        else{
            if(strcmp(opcion, "no")==0){
                return false;
            }
        }
    }while(1!=0);
return true;
}
