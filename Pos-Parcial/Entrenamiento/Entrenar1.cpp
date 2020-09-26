#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;
#include "Usuarios.h"
#include "Entrenar.h"

///         FUNCIONES POR UNICO REGISTR0;
Entrenamiento Cargar_Entrenamiento(){ ///carga registros de Entrenamiento.
    Entrenamiento Ent;
    int ID_Usuario, dia, mes, anio;
    bool carga = false;
    ///FALTA HACER QUE SEA AUTONUMERICO
    cin>>Ent.ID;
    ///FALTA HACER QUE SEA UN NUMERO EXISTENTE EN EL ARCHVO TEXTO.DAT
    cout<<"Ingrese ID Usuario: ";
    cin>>Ent.IDUsuario;
    ///FECHA VALIDADA
    cout<<"Ingrese la fecha dd mm aaaa :";
    cout<<"Fecha Día:   "; cin>>dia;
    cout<<"Fecha Mes:   "; cin>>mes;
    cout<<"Fecha Año:   "; cin>>anio;
    while(carga==false){ ///VERIFICO QUE SE CUMPLA UNA FECHA VALIDA.
            carga = Control_Fecha(dia, mes, anio);
            ///valido = validacionFecha(dia,mes,anio);
            if(carga==false){
                cout<<">Reingrese la fecha";
                cout<<">Fecha Día:   "; cin>>dia;
                cout<<">Fecha Mes:   "; cin>>mes;
                cout<<">Fecha Año:   "; cin>>anio;
            }
    }
    Ent.Fecha_Entrenamiento.Dia=dia;
    Ent.Fecha_Entrenamiento.Mes=mes;
    Ent.Fecha_Entrenamiento.Anio=anio;

    cout<<"Ingrese la Actividad: ";
    cin>>Ent.Actividad;

    cout<<"Ingrese las Calorias consumidas:";
    cin>>Ent.Calorias;
    while(Ent.Calorias>=0){
        cout<<">>>Ingrese un valor >0 de calorias consumidas: ";
        cin>>Ent.Calorias;
    }

    cout<<"Ingrese Tiempo de Entrenamiento en minutos: ";
    cin>>Ent.Tiempo;
    while(Ent.Tiempo>=4){
        cout<<">>>Ingrese un valor >5 minutos: ";
        cin>>Ent.Tiempo;
    }

    return Ent;
}

void Cargar_Nuevo_Entrenamiento(){
/**    Entrenamiento Ent;
    Ent=Cargar_Entrenamiento();
    FILE *f;
    f = fopen("Entrenamiento.dat", "ab");
    if(f==NULL){
        cout<<"No se puede continuar";

    }
    fwrite(&Ent, sizeof(Entrenamiento), 1, f);
    fclose(f);*/
}

void Listar_Entrenamiento(){
/**    Entrenamiento Ent;
    cout<<"Muestro lo cargado: ";
    FILE *f;
    f = fopen("Entrenameinto.dat", "rb");
    if(f==NULL){
        cout<<"No se puede leer el archivo";
        return;
    }
    while(fread(&Ent, sizeof(Entrenamiento), 1, f)==1){
        mostrar_Entrenamiento(Ent);/// FALTA EL REGISTRP Ent
        cout<<"\n=====================================\n";
          }

    fclose(f);
    system("pause");*/
}

void mostrar_Entrenamiento(Entrenamiento Ent){

   /** cout<<"\nID:                 "<<Ent.ID;
    cout<<"\nIDUsuario:          "<<Ent.IDUsuario;
    cout<<"\nFecha Entrenamiento:";
    Mostrar_Fecha(Ent.Fecha_Entrenamiento);
    cout<<"\nActividad:          "<<Ent.Actividad;
    cout<<"\nCalorias:           "<<Ent.Calorias;
    cout<<"\nTiempo:             "<<Ent.Tiempo;*/
}
