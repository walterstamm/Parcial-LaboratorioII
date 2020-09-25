#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#include "Usuarios.h"


///         FUNCIONES POR UNICO REGISTR0;
Entrenamiento Cargar_Entrenamiento(){ ///carga registros de Entrenamiento.
    Entrenamiento Ent;
    int ID_Usuario, dia, mes, anio, Actividad,numero_entrenamiento;
    bool carga = false,valido;

    numero_entrenamiento=contador_entrenamiento()+1;
    Ent.ID=numero_entrenamiento;
    cout<<endl<<"Numero de ID de  entranamiento: "<<Ent.ID<<endl;
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
    Ent.IDUsuario=ID_Usuario;/// FIN DE VALIDACION

    cout<<"Ingrese la fecha dd/ mm /aaaa :\n";  ///FECHA VALIDADA
    cout<<"Fecha Día:   "; cin>>dia;
    cout<<"\tFecha Mes:   "; cin>>mes;
    cout<<"\t\tFecha Año:   "; cin>>anio;
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

    cout<<"\n Para ingresar debera tener en cuenta: \n";
    cout<<" 1:Caminata, 2:Correr, 3:Bicicleta, 4:Natación, 5:Pesas.\n";
    cout<<" Natación y Pesas debe tener el Apto Médico.\n\n";

    cout<<" Ingrese la Actividad: ";
    cin>>Actividad;
    while(carga==true){
        switch(Actividad){
            case 1:
                cout<<"Ha seleccionado Caminata.\n";
                carga=false;
                break;

            case 2:
                cout<<"Ha seleccionado Correr.\n";
                carga=false;
                break;

            case 3:
                cout<<"Ha seleccionado Bicicleta.\n";
                carga=false;
                break;

            case 4:
                if(Verificar_ApMedico(ID_Usuario)==false){
                    cout<<"Sin Apto Médico.\n";
                    cout<<"Respete las condiciones\n";
                    cout<<">>>Ingrese la Actividad: ";
                    cin>>Actividad;
                    carga=true;

                }else{
                    cout<<"Ha seleccionado Natación.\n";
                    carga=false;
                    }

                break;

            case 5:
                if(Verificar_ApMedico(ID_Usuario)==false){
                    cout<<"Sin Apto Médico.\n";
                    cout<<"Respete las condiciones\n";
                    cout<<">>>Ingrese la Actividad: ";
                    cin>>Actividad;
                    carga=true;

                }else{
                    cout<<"Ha seleccionado Pesas.\n";
                    carga=false;
                    }
                break;

            default:
                carga=true;
                break;
        }
    }
    Ent.Actividad=Actividad;

    cout<<"Ingrese las Calorias consumidas:";
    cin>>Ent.Calorias;
    while(Ent.Calorias<=0){
        cout<<">>>Ingrese un valor >0 de calorias consumidas: ";
        cin>>Ent.Calorias;
    }

    cout<<"Ingrese Tiempo de Entrenamiento en minutos: ";
    cin>>Ent.Tiempo;
    while(Ent.Tiempo<=4){
        cout<<">>>Ingrese un valor >5 minutos: ";
        cin>>Ent.Tiempo;
    }

    return Ent;
}

void Cargar_Nuevo_Entrenamiento(){
    Entrenamiento Ent;
    Ent=Cargar_Entrenamiento();
    FILE *f;
    f = fopen("Entrenamiento.dat", "ab");
    if(f==NULL){
        cout<<"No se puede continuar";

    }
    fwrite(&Ent, sizeof(Entrenamiento), 1, f);
    fclose(f);
}

void Listar_Entrenamiento(){ ///LISTO TODOS LOS ENTRENAMIENTOS
    Entrenamiento Ent;
    cout<<"Muestro lo cargado: ";
    FILE *f;
    f = fopen("Entrenamiento.dat", "rb");
    if(f==NULL){
        cout<<"No se puede leer el archivo";
        system("pause");
        return;
    }
    while(fread(&Ent, sizeof(Entrenamiento), 1, f)==1){
        mostrar_Entrenamiento(Ent);/// FALTA EL REGISTRP Ent
        cout<<"\n=====================================\n";
          }
    fclose(f);
    system("pause");
}

void Listar_Entrenamiento_Usuario(){ ///LISTO POR USUARIO
    Entrenamiento Ent;
    int ID_USUARIO, cant=0;
    cout<<"Ingrese el usuario que desea Listar: ";
    cin>>ID_USUARIO;
    FILE *f;
    f = fopen("Entrenamiento.dat", "rb");
    if(f==NULL){
        cout<<"No se puede leer el archivo";
        system("pause");
        return;
    }
    while(fread(&Ent, sizeof(Entrenamiento), 1, f)==1){
        if(Ent.IDUsuario == ID_USUARIO){
            mostrar_Entrenamiento(Ent);
            cout<<"\n=====================================\n";
            cant++;
        }
    }
    cout<<"\nSe muestraun total de: "<<cant<<" Registros.\n";
    fclose(f);
    system("pause");
}
///
void Listar_Entrenamiento_ID(){ ///LISTO POR USUARIO
    Entrenamiento Ent;
    int ID, cant=0;
    cout<<"Ingrese el usuario que desea Listar: ";
    cin>>ID;
    FILE *f;
    f = fopen("Entrenamiento.dat", "rb");
    if(f==NULL){
        cout<<"No se puede leer el archivo";
        system("pause");
        return;
    }
    while(fread(&Ent, sizeof(Entrenamiento), 1, f)==1){
        if(Ent.ID == ID){
            mostrar_Entrenamiento(Ent);
            cout<<"\n=====================================\n";
            cant++;
        }
    }
    cout<<"\nSe muestraun total de: "<<cant<<" Registros.\n";
    fclose(f);
    system("pause");
}

void mostrar_Entrenamiento(Entrenamiento Ent){

    cout<<"\nID:                 "<<Ent.ID;
    cout<<"\nIDUsuario:          "<<Ent.IDUsuario;
    cout<<"\nFecha Entrenamiento:";
    Mostrar_Fecha(Ent.Fecha_Entrenamiento);
    cout<<"\nActividad:          "<<Ent.Actividad;
    cout<<"\nCalorias:           "<<Ent.Calorias;
    cout<<"\nTiempo:             "<<Ent.Tiempo;
}

int contador_entrenamiento(){          ///CUANTIFICA LA CANTIDAD DE ENTRANAMIENTOS CARGADOS
        FILE *archivo;
    int Cantidad_Entranamientos;
    archivo=fopen("Entrenamiento.dat", "rb");
    if (archivo==NULL){
        fclose(archivo);
        return 0;
    }
    fseek(archivo,0,SEEK_END);
    Cantidad_Entranamientos=ftell(archivo)/sizeof(Entrenamiento);
    fclose(archivo);
    return Cantidad_Entranamientos;

}

bool Valida_Usuario_existente(int ID_usuario){   ///VALIDA QUE EXISTA EL USUARIO ANTES DE CARGAR EL ENTRENAMIENTOS
    Usuarios registro;
    FILE *archivo;
    archivo=fopen("texto.dat","rb");
    if(archivo==NULL){
        return false;
    }

    while(fread(&registro,sizeof(Usuarios),1,archivo)){
        if(ID_usuario==registro.ID){
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
    return false;
}

void Modificar_Entrenamiento(){
    Entrenamiento registro;
    char respuesta;
    bool validar,grabo,*valido;
    int ID_entrenamiento,posicion_ID;
    FILE *archivo;

    cout<<"Ingrese el ID de Entranamiento a modificar: ";
    cin>>ID_entrenamiento;
    ///VALIDACION DE QUE EL ID DE ENTRENAMIENTO EXISTA
    posicion_ID=Buscar_ID_Entrenamiento(ID_entrenamiento);
    while(posicion_ID==-1){
            cout<<endl<<"ID de Entrenamiento inexistente"<<endl;
            cout<<"Ingrese el ID de Entrenamiento nuevamente: ";
            cin>>ID_entrenamiento;
            posicion_ID=Buscar_ID_Entrenamiento(ID_entrenamiento);

    }
    system("cls");
    registro=Levantar_Entrenamiento(posicion_ID,valido);
    if(*valido==false){
        cout<<"Hubo un error al intentar abrir el archivo";
        return;
    }

    ///Modifico campos del registro de entrenamiento
    cout<<"ID del Usuario: "<<registro.IDUsuario<<endl;
    cout<<"ID de entrenamiento: "<<registro.ID<<endl;

    cout<<"Tiempo de entrenamiento: "<<registro.Tiempo<<endl;
    cout<<"Desea modificar este campo: (S/N)";
    cin>>respuesta;
    if(respuesta=='S'||respuesta=='s'){
        cout<<"Tiempo: ";
        cin>>registro.Tiempo;
    }
   cout<<"Calorias quemadas: "<<registro.Calorias<<endl;
    cout<<"Desea modificar este campo: (S/N)";
    cin>>respuesta;
    if(respuesta=='S'||respuesta=='s'){
        cout<<"Calorias quemadas: ";
        cin>>registro.Calorias;
    }
    system("pause");
    grabo=Guardar_Modificacion_Entranamiento(registro,posicion_ID);
    if(grabo){
        cout<<"Se guardo exitosamente los cambios";
    }else{
        cout<<"No se puedo guardar los cambios realizados";
    }
    system("pause");
}

int Buscar_ID_Entrenamiento(int ID_entrenamiento){
    Entrenamiento registro;
    FILE *archivo;
    archivo=fopen("Entrenamiento.dat", "rb");
    if(archivo==NULL){
        return -1;
    }
    int pos=0;
    while(fread(&registro,sizeof(Entrenamiento),1,archivo)){
        if(ID_entrenamiento==registro.ID){
            fclose(archivo);
            return pos;
        }
        pos++;
    }
    fclose(archivo);
    return -1;

}

Entrenamiento Levantar_Entrenamiento(int posicion_ID,bool *valido){
    FILE *archivo;
    Entrenamiento registro;
    archivo=fopen("Entrenamiento.dat","rb");
    if(archivo==NULL){
            fclose(archivo);
            *valido=false;
            return registro;
    }
    fseek(archivo,posicion_ID*sizeof(Entrenamiento),SEEK_SET);
    fread(&registro,sizeof (Entrenamiento),1,archivo);
    fclose(archivo);
    return registro;
}

bool Verificar_ApMedico(int ID_Usuario){
    Usuarios reg;
    FILE *p;
    p=fopen("texto.dat","rb");
    if(p==NULL){
        cout<<"No se pudo realizar la apertura del Archivo";
        return 0;
    }
    while(fread(&reg, sizeof (Usuarios),1,p)){
        if(ID_Usuario==reg.ID && reg.Apto_Med==1){
            return true;
        }
    }
    fclose(p);
    return false;
}

bool Guardar_Modificacion_Entranamiento(Entrenamiento registro,int posicionID){
    bool grabo;
    FILE *archivo=fopen("Entrenamiento.dat","rb+");
    if (archivo==NULL){
        fclose(archivo);
        return false;
    }
    fseek(archivo,posicionID*sizeof(Entrenamiento),SEEK_SET);
    grabo=fwrite(&registro,sizeof(Entrenamiento),1,archivo);
    fclose(archivo);
    return grabo;
    }
