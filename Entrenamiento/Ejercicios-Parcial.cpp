#include<iostream>
#include<cstdlib>
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

    system("cls");
    int ID_Usuario;
    bool valido;
    Entrenamiento Entre;
    cout<<endl<<endl;
    ///Validacion de que Usuario exista antes de cargar un entrenamieto
    cout<<"Ingrese ID Usuario: ";
    cin>>ID_Usuario;
    valido=Valida_Usuario_existente(ID_Usuario);
    while(valido==false){
        cout<<"El usuario no existe en la base de datos"<<endl;
        cout<<"Vuelva a ingresar el ID del Usuario: ";
        cin>>ID_Usuario;
        valido=Valida_Usuario_existente(ID_Usuario);
    }
    Entre=CantidadEntrenamientos(ID_Usuario);

    cout<<endl<<endl;
    cout<<" \tFecha en que se realizo en el entrenamiento: "<<Entre.Fecha_Entrenamiento.Dia<<"/"<<Entre.Fecha_Entrenamiento.Mes
    <<"/"<<Entre.Fecha_Entrenamiento.Anio;
    cout<<endl<<"\tCantidad de calorias quemadas: "<<Entre.Calorias;

    system("pause");
    return;


 }


Entrenamiento CantidadEntrenamientos( int ID_Usuario){
    FILE *archivo;
    Entrenamiento Entre,MaximaCalorias;
    float calorias=0;
    archivo= fopen("Entrenamiento.dat", "rb");
    if(archivo==NULL){
        cout<<"No se puede leer el archivo";
        system("pause");
        fclose(archivo);
        return Entre;
    }
    while(fread(&Entre,sizeof (Entrenamiento),1,archivo)){

        if(ID_Usuario==Entre.IDUsuario){
            if(Entre.Calorias>MaximaCalorias.Calorias){
                MaximaCalorias=Entre;
            }
        }
    }
    fclose(archivo);

    return MaximaCalorias;

}



///No llegue con el timpo
/*void Punto_B(){
///Por cada tipo de actividad, listar la cantidad de entrenamientos discriminado por perfil de usuario.*/

/*
int PerfilA[5]={},PerfilB[5]={},PerfilC[5]={},bandera=1,Id_Anterior;
FILE *archivo;
Usuarios registro;
archivo= fopen("texto.dat", "rb");
    if(archivo==NULL){
        cout<<"No se puede leer el archivo";
        system("pause");
        fclose(archivo);
        return;
    }

    while(fread(&registro,sizeof(Usuarios),1,archivo)){
        if(bandera==1){
            Id_Anterior=registro.ID;
            bandera=0;
        }



    }
    }

}*/
