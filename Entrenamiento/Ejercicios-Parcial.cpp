#include<iostream>
#include<cstdlib>
#include<math.h>
#include<cstdio>
#include "Usuarios.h"
#include "configuracion.h"
#include "Ejercicios-Parcial.h"

using namespace std;

/*A partir de un IDUsuario que se ingresa por teclado,
listar el entrenamiento de mayor cantidad de calorías y la fecha en que
 las registró. Si hay dos registro con misma cantidad,
 mostrar el primero de ellos.*/

 void Punto_A() {
    int id;
    float calorias;
    Entrenamiento reg;
    system("cls");
    cout<<endl<<"Ingrese el ID de usuario: ";
    cin>>id;
    while(Validar_ID(id)==0){
        cout<<endl<<"ID INEXISTENTE";
        cout<<endl<<"Ingrese el ID de usuario: ";
        cin>>id;
    }

    calorias=Buscar_Entrenamiento_intenso(&reg,id);
    if(calorias>0){
        mostrar_Entrenamiento(reg);
        system("pause");
        return;
    }
    else{
            if(calorias==0){
                cout<<endl<<"No hubo entrenamientos aun";
                system("pause");
            }else{
                system("pause");
                return;
            }
        }
    }


float Buscar_Entrenamiento_intenso(Entrenamiento *reg,int id){
    float calorias=0;
    Entrenamiento aux;
    FILE *p=fopen("Entrenamiento.dat","rb");
    if(p==NULL){
        cout<<"No se puedo abrir el archivo";
        calorias=-1;
        return calorias;
    }
    while(fread(&aux,sizeof(Entrenamiento),1,p)){
        if(aux.IDUsuario==id){
            if(aux.Calorias>calorias){
                calorias=aux.Calorias;
                *reg=aux;
            }
        }
    }
    fclose(p);
    return calorias;
}

void Punto_B(){
///Por cada tipo de actividad, listar la cantidad de entrenamientos discriminado por perfil de usuario
    int CantEntrenamientos,j,i,x,y;
    int Tabla[5][3]={};
    Entrenamiento *PunteroEntrenamiento;
    CantEntrenamientos=contador_entrenamiento();

    PunteroEntrenamiento=new Entrenamiento[CantEntrenamientos];


    if(PunteroEntrenamiento==NULL){
        cout<<"No hay memoria suficiente";
        system("pause");
        return;
    }
    CargarVector(PunteroEntrenamiento);
    for(i=0;i<CantEntrenamientos;i++){

        Tabla[PunteroEntrenamiento[i].Actividad-1][TipoActividad(PunteroEntrenamiento[i].IDUsuario)]++;

    }

    cout<< endl<<endl;
    cout<<"\tA"<<"\tB"<<"\tC"<<endl;
    for(j=0;j<5;j++){
    cout<<j+1<<"\t"<<Tabla[j][0]<<"\t"<<Tabla[j][1]<<"\t"<<Tabla[j][2]<<endl;
    }
    delete[] PunteroEntrenamiento;
    system("pause");

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
    return -2;
}

void CargarVector(Entrenamiento *reg){
    Entrenamiento aux;
    int i=0;
    FILE *p=fopen("Entrenamiento.dat","rb");
    if(p==NULL){
        cout<<"No se puedo abrir el archivo";

        return ;
    }
    while(fread(&aux,sizeof(Entrenamiento),1,p)){
        reg[i]=aux;
        i++;
    }
    fclose(p);
}



///Listar todos los entrenamientos cuyo tiempo supere el tiempo promedio.

void Punto_C(){

    Entrenamiento *PunteroEntrenamiento;
    int CantEntrenamientos,i,promedio=0,media;

    CantEntrenamientos=contador_entrenamiento();
    PunteroEntrenamiento=new Entrenamiento [CantEntrenamientos];
    CargarVector(PunteroEntrenamiento);

    for(i=0;i<CantEntrenamientos;i++){
        promedio+=PunteroEntrenamiento[i].Tiempo;

    }
    media=promedio/CantEntrenamientos;
    for(i=0;i<CantEntrenamientos;i++){
        if(PunteroEntrenamiento[i].Tiempo>186){
            mostrar_Entrenamiento(PunteroEntrenamiento[i]);
            cout<<endl<<endl;
        }
    }
    system("pause");
}
