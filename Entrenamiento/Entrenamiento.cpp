#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include <ctime>

using namespace std;

bool validacionMayor(int, int, int);


int main(){
    bool validacion;
    int dia, mes, anio;
    cout<<"Ingrese Dia mes y anio: ";
    cin>>dia>>mes>>anio;
    validacion=validacionMayor(dia, mes, anio);
    cout<<"VALIDACION: "<<validacion;
    return 0;
}

bool validacionMayor(int dia,int mes, int anio){
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    //tmPtr->tm_year+1900;

    bool valido=false;
    if((tmPtr->tm_year+1900-anio)>13){
        valido=true;
        return valido;
    }else{
        if(((tmPtr->tm_year+1900-anio)==13) && ((tmPtr->tm_mon+1)-mes>0)){
            valido=true;
        }else{
            if(((tmPtr->tm_year+1900-anio)==13)&&(tmPtr->tm_mon+1)-mes==0 && (dia<=tmPtr->tm_mday)){
                valido=true;
        }
        }
    }
    return valido;
}
