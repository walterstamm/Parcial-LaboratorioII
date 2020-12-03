//NOMBRE: HUGO FABIAN GOMEZ
//TP N°: PRIMER PARCIAL
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <clocale>
#include <iostream>
using namespace std;
#include "Usuarios.h"


///         FUNCIONES POR UNICO REGISTR0
Usuarios Cargar_Usuarios(){ ///carga registros por un registro.
    Usuarios reg;
    int dia, mes, anio, id, pos;
    bool carga=false,valido=false;
    char Perfil;
    cout<<"Ingresar ID: "; cin>>id;
    while(Buscar_Usuario(id)>=0){
        cout<<"YA EXISTE EL ID\n";
        cout<<"Ingresar ID: "; cin>>id;
    }
    reg.ID=id;


    cin.ignore();
    cout<<"Nombres:     "; cin.getline(reg.Nombres, 50);
    while(strlen(reg.Nombres)<1){
        cout<<">Nombres:     "; cin.getline(reg.Nombres, 50);
    }
    cout<<"Apellido:    "; cin.getline(reg.Apellido, 50);
    while(strlen(reg.Apellido)<1){
        cout<<">Apellido:    "; cin.getline(reg.Apellido, 50);
    }
    cout<<"Fecha Día:   "; cin>>dia;
    cout<<"Fecha Mes:   "; cin>>mes;
    cout<<"Fecha Año:   "; cin>>anio;
    while(carga==false||valido==false){///VERIFICO QUE SE CUMPLA UNA FECHA VALIDA.
            carga = Control_Fecha(dia, mes, anio);
            valido = validacionMayor(dia,mes,anio);
            if(carga==false||valido==false){
                cout<<">Reingrese la fecha";
                cout<<">Fecha Día:   "; cin>>dia;
                cout<<">Fecha Mes:   "; cin>>mes;
                cout<<">Fecha Año:   "; cin>>anio;
            }
    }

    reg.Nac.Dia=dia;
    reg.Nac.Mes=mes;
    reg.Nac.Anio=anio;

    cout<<"Peso:        "; cin>>reg.Peso;
    while(reg.Peso<50){///VALIDO EL PESO QUE SEA >50 KGS IMC MINIMA
        cout<<">Peso:        "; cin>>reg.Peso;
    }
    cout<<"Perfil:      "; cin>>Perfil;
    while(Valido_Perfil(Perfil)==false){
        cout<<"Perfil:      "; cin>>Perfil;
    }



    reg.Perfil=Perfil;
    cout<<"Apto Médico: "; cin>>reg.Apto_Med;
    reg.Estado=true;
    return reg;
}

void Mostrar_Usuarios(Usuarios reg){///MUESTRA DE A UN USUARIO

    cout<<"\n ID:         "<<reg.ID;
    cout<<"\nNombres:     "<<reg.Nombres;
    cout<<"\nApellido:    "<<reg.Apellido;
    cout<<"\nFecha Nacimiento";
    Mostrar_Fecha(reg.Nac);
    cout<<"\nPeso:        "<<reg.Peso;
    cout<<"\nPerfil:      "<<reg.Perfil;
    cout<<"\nApto Médico: "<<reg.Apto_Med;
    cout<<"\nEstado:      "<<reg.Estado;

}

///             CONTROL FECHA
int Buscar_Usuario(int id){
    Usuarios registro;
    FILE *f;
    int posicion=0;
    f = fopen("texto.dat", "rb");
    if(f==NULL){
        cout<<"No se puede continuar";
        return -1;
    }

    while(fread(&registro,sizeof(Usuarios),1,f)){
        if(id==registro.ID){
            fclose(f);
            return posicion;
        }

        posicion++;
    }
    fclose(f);
    return -1;
 }

bool Control_Fecha(int dia, int mes, int anio){

        switch(mes){
            case 1:if(dia<1||dia>31){
                    return false;
                }break;
            case 3:if(dia<1||dia>31){
                    return false;
                }break;
            case 5:if(dia<1||dia>31){
                    return false;
                } break;
            case 7:if(dia<1||dia>31){
                    return false;
                } break;
            case 8:if(dia<1||dia>31){
                    return false;
                } break;
            case 10:if(dia<1||dia>31){
                    return false;
                } break;
            case 12:
                if(dia<1||dia>31){
                    return false;
                }
            break;
            case 2:
                if(anio%4==0 && (dia<1||dia>29)){
                    return false;
                }
                if(anio%4!=0 && (dia<1||dia>28)){
                    return false;
                }
            break;
            case 4:
                 if(dia<1 || dia>30){
                    return false;
                } break;
            case 6:
                 if(dia<1 || dia>30){
                    return false;
                } break;
            case 9:
                 if(dia<1 || dia>30){
                    return false;
                } break;
            case 11:
                 if(dia<1 || dia>30){
                    return false;
                }
        }


    return true;
}


///         FECHA
Fecha Cargar_Fecha(){
    Fecha reg;
    cout<<"Dia:  "; cin>>reg.Dia;
    cout<<"Mes:  "; cin>>reg.Mes;
    cout<<"Año:  "; cin>>reg.Anio;
    return reg;
}

void Mostrar_Fecha(Fecha reg){
    cout<<"\nFecha: "<<reg.Dia<<"/"<<reg.Mes<<"/"<<reg.Anio;
}


bool validacionFecha(int dia,int mes, int anio){
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    //tmPtr->tm_year+1900;


    bool valido=true;

        if(anio>tmPtr->tm_year+1900){
            valido=false;
            return valido;
        }
        else{
            if(mes==(tmPtr->tm_mon+1)&& dia<=tmPtr->tm_mday){
                    return valido;}

                    else{
                            if(anio<(tmPtr->tm_year+1900)){
                                return valido;
                            }
                            else{
                                if(anio==(tmPtr->tm_year+1900)&&mes<(tmPtr->tm_mon+1)){
                                    return valido;
                                }
                            }
                    }
        }

    valido=false;
    return valido;
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
            return valido;
        }else{
            if(((tmPtr->tm_year+1900-anio)==13)&&(tmPtr->tm_mon+1)-mes==0 && (dia<=tmPtr->tm_mday)){
                valido=true;
                return valido;
        }
        }
    }
    return valido;
}

void Modificar_Usuarios(){
    bool valido,grabo,*Valido_no_Error;
    Usuarios registro;
    int id,posicionArchivo;
    char respuesta;
    cout<<endl<<"Ingrese el ID de usuario a modificar: ";
    cin>>id;
    valido=Validar_ID(id);
    if(valido==false){
        cout<<endl<<"El ID no exite...";
        system("pause");
        return;
    }

    posicionArchivo=Buscar_Usuario(id);
    if (posicionArchivo==-1){
        return;
    }
    registro=Levantar_Participantes(posicionArchivo,Valido_no_Error);
    if(Valido_no_Error==false){
        cout<<"Hubo un error al intentar abrir el archivo";
        return;
    }
    system("cls");
    cout<<"Usuario: "<<registro.Apellido<<", "<<registro.Nombres<<endl;
    cout<<"Peso: "<<registro.Peso<<endl;
    cout<<"Desea modificar este campo?  ";
    cin>>respuesta;
    if(respuesta=='S'||respuesta=='s'){
        cout<<"Peso: ";
        cin>>registro.Peso;
    }
    cout<<"Perfil de actividad: "<<registro.Perfil<<endl;
    cout<<"Desea modificar este campo?  ";
    cin>>respuesta;
    if(respuesta=='S'||respuesta=='s'){
        cout<<"Perfil de actividad: ";
        cin>>registro.Perfil;
    }
    cout<<"Apto medico: "<<registro.Apto_Med<<endl;
    cout<<"Desea modificar este campo?  ";
    cin>>respuesta;
    if(respuesta=='S'||respuesta=='s'){
        cout<<"Apto medico: ";
        cin>>registro.Apto_Med;
    }
    system("pause");
    grabo=Guardar_Usuario(registro,posicionArchivo);
    if(grabo==true){
        cout<<"LOS CAMBIOS SE GUARDARON EXITOSAMENTE!";
        system("pause");
        return;
    }

    cout<<"No se puedieron grabar los cambios...";
    system("pause");
    return;
}

bool Validar_ID(int id){
    Usuarios registro;
    bool valido;
    FILE *f;
    f = fopen("texto.dat", "rb");
    if(f==NULL){
        cout<<"No se puede continuar";
        fclose(f);
        return 0;
    }

    while(fread(&registro,sizeof(Usuarios),1,f)){
        if(id==registro.ID){
            fclose(f);
            valido=true;
            return valido;
        }
    }
    valido=false;
    return valido;
}

Usuarios Levantar_Participantes(int posicionArchivo,bool *valido){
    Usuarios registro;

    FILE *f=fopen("texto.dat", "rb");
    if(f==NULL){
        fclose(f);
        valido=false;
        return registro;
    }

    fseek(f,posicionArchivo*sizeof(Usuarios),SEEK_SET);
    fread(&registro,sizeof(Usuarios),1,f);
    fclose(f);
    return registro;
}

bool Guardar_Usuario(Usuarios registro,int posicion_Archivo){

    FILE *f;
    f = fopen("texto.dat", "rb+");
    if(f==NULL){
        fclose(f);
        return false;
    }
    fseek(f,posicion_Archivo*sizeof(Usuarios),SEEK_SET);
    fwrite(&registro,sizeof(Usuarios),1,f);
    fclose(f);
    return true;
}

bool Valido_Perfil(char Perfil){
    bool resultado;
    if(Perfil=='a'||Perfil=='A'||Perfil=='b'||Perfil=='B'||Perfil=='c'||Perfil=='C'){
        resultado= true;
    }else{
        resultado=false;
    }
    return resultado;
}

///     FUNCIONES ENTRENAMIENTO

void Cargar_Nuevo_Usuario(){
    Usuarios reg;

    reg=Cargar_Usuarios();
    FILE *f;
    f = fopen("texto.dat", "ab");
    if(f==NULL){
        cout<<"No se puede continuar";
    }
    fwrite(&reg, sizeof(Usuarios), 1, f);
    fclose(f);
}

void Listar_Usuarios(){
    Usuarios reg;
    cout<<"Muestro lo cargado: ";
    FILE *f;
    f = fopen("texto.dat", "rb");
    if(f==NULL){
        cout<<"No se puede leer el archivo";
        return;
    }
    while(fread(&reg, sizeof(Usuarios), 1, f)==1){
        Mostrar_Usuarios(reg);
        cout<<"\n=====================================\n";
          }

    fclose(f);
    system("pause");
}



void Listar_Usuarios_ID(){
    Usuarios registro;
    int ID_Usuario,posicion_ID;
    bool valido,*validaion;
    system("cls");
    cout<<"Ingrese el ID del usuario: ";
    cin>>ID_Usuario;
    valido=Validar_ID(ID_Usuario);
    if(valido==false){
        cout<<"El ID no existe....";
        system("pause");
        return;
    }

    posicion_ID=Buscar_Usuario(ID_Usuario);
    if(posicion_ID==-1){
        cout<<"Hubo problemas al buscar el usuario";
        return;
    }
    registro=Levantar_Participantes(posicion_ID,validaion);
    Mostrar_Usuarios(registro);
    system("pause");
    return;
}

void Baja_Logica_Usuario(){
    Usuarios registro;
    int ID_Usuario,posicion_ID;
    bool valido,*validacion;
    char respuesta;
    system("cls");
    cout<<"Ingrese el ID del usuario: ";
    cin>>ID_Usuario;
    valido=Validar_ID(ID_Usuario);
    if(valido==false){
        cout<<"El ID no existe....";
        system("pause");
        return;
    }

    posicion_ID=Buscar_Usuario(ID_Usuario);
    if(posicion_ID==-1){
        cout<<"Hubo problemas al buscar el usuario";
        return;
    }
    registro=Levantar_Participantes(posicion_ID,validacion);
    cout<<endl<<"Usted va a dar de baja a este Usuario: ";
    Mostrar_Usuarios(registro);
    if(registro.Estado==false){
        cout<<endl<<"Este usuario ya esta dado de baja!";
        system("pause");
        return;
        }
    cout<<endl<<"Desea dar de baja(S/N): ";
    cin>>respuesta;
    if(respuesta=='s'||respuesta=='S'){
    registro.Estado=false;
    valido=Guardar_Usuario(registro,posicion_ID);
    if(valido){
        cout<<"La baja de usuario se realizo con exito";
    }
    system("pause");
    }
        else{
                cout<<endl<<"Ocurrio un problema al dar de baja";

        }

    return;
}


int Cantidad_Usuarios(){
    FILE *archivo;
    int Cantidad_Usuario;
    archivo=fopen("texto.dat", "rb");
    if (archivo==NULL){
        fclose(archivo);
        return 0;
    }
    fseek(archivo,0,SEEK_END);
    Cantidad_Usuario=ftell(archivo)/sizeof(Usuarios);
    fclose(archivo);
    return Cantidad_Usuario;

}
