#include<iostream>
#include<cstdlib>
#include<math.h>
#include<cstdio>
#include "Usuarios.h"
#include "configuracion.h"
#include "Ejercicios-Parcial.h"

using namespace std;
///Para cada perfil, indicar el porcentaje de usuarios
void Punto_A(){

    Usuarios *PunteroUsuarios;
    int CantUsuarios,Perfil[3]={},i,Actividad;
    CantUsuarios=Cantidad_Usuarios();
    PunteroUsuarios=new Usuarios[CantUsuarios];
    if(PunteroUsuarios==NULL){
        cout<<"ERROR";
        return;
    }
    if(CargarVectorUsuarios(PunteroUsuarios)==0){
        cout<<"ERROR";
        return;
    }
    for(i=0;i<CantUsuarios;i++){
        Actividad=TipoActividad(PunteroUsuarios[i].ID);
        if(Actividad==-1){
            cout<<"ERROR";
            return;
        }
        Perfil[Actividad]++;
    }

    cout<<endl<<"Perfil A: "<<(Perfil[0]*100)/(float)CantUsuarios;
    cout<<endl<<"Perfil B: "<<(Perfil[1]*100)/(float)CantUsuarios;
    cout<<endl<<"Perfil C: "<<(Perfil[2]*100)/(float)CantUsuarios;

    delete[]PunteroUsuarios;
    system("pause");
}



bool CargarVectorUsuarios(Usuarios *reg){
    Usuarios aux;
    int i=0;
    FILE *p=fopen("texto.dat","rb");
    if(p==NULL){
        cout<<"No se puedo abrir el archivo";

        return false ;
    }
    while(fread(&aux,sizeof(Usuarios),1,p)){
        reg[i]=aux;
        i++;
    }
    fclose(p);
    return true;
}

int TipoActividad(int idusuario){
    Usuarios reg;
    FILE *p=fopen("texto.dat", "rb");
    if(p==NULL){
        return -1;
    }
    while(fread(&reg,sizeof(Usuarios),1,p)){
        if(reg.ID==idusuario){

            if(reg.Perfil=='a'||reg.Perfil=='A'){
                    fclose(p);
                    return 0;
            }   else{
                    if(reg.Perfil=='b'||reg.Perfil=='B'){
                        fclose(p);
                        return 1;
                    }
                    else{
                        fclose(p);
                        return 2;
                    }
            }
        }
    }
    fclose(p);
    return -1;
}
/*A partir de una cantidad de calorías ingresadas por teclado, listar apellidos y nombres de todos
los usuarios que hayan quemado más calorías en total que la cantidad ingresada*/

void Punto_B(){
    Usuarios *PunteroUsuarios;
    int i,CantUsuarios,Bandera=1;
    float *Calorias,Cantidad;
    CantUsuarios=Cantidad_Usuarios();
    PunteroUsuarios=new Usuarios[CantUsuarios];
    if(PunteroUsuarios==NULL){
        cout<<"ERROR";
        return;
    }

    if(CargarVectorUsuarios(PunteroUsuarios)==0){
        cout<<"ERROR";
        return;
    }

    Calorias=new float[CantUsuarios];
    if(Calorias==NULL){
        cout<<"ERROR";
        return;
    }

    cout<<"Ingrese la cantidad de calorias: ";
    cin>>Cantidad;
    for(i=0;i<CantUsuarios;i++){
        Calorias[i]=CaloriasTotales(PunteroUsuarios[i].ID);
        if(Calorias[i]==-1){
            cout<<"ERROR";
            return;
        }
        if(Calorias[i]>Cantidad){
            Bandera=0;
            cout<<endl<<"Apellido: "<<PunteroUsuarios[i].Apellido;
            cout<<endl<<"Nombre: "<<PunteroUsuarios[i].Nombres;
            cout<<endl;
        }

    }
    if(Bandera==1){
        cout<<endl<<"No hay usuarios que hayan superado esa cantidad!";
    }
    delete[]Calorias;
    delete[]PunteroUsuarios;
    system("pause");
}


float CaloriasTotales(int id){
    Entrenamiento aux;
    float calorias=0;
    FILE *p=fopen("Entrenamiento.dat","rb");
    if(p==NULL){
        cout<<"No se puedo abrir el archivo";
        return -1;
    }
    while(fread(&aux,sizeof(Entrenamiento),1,p)){
        if(aux.IDUsuario==id){
            calorias+=aux.Calorias;
        }
    }
    fclose(p);
    return calorias;
}
