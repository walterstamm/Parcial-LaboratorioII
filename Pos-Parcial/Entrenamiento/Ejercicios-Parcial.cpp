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


///Se que no cuenta como nota, pero al menos queria hacerlo =D

void Punto_B(){
///Por cada tipo de actividad, listar la cantidad de entrenamientos discriminado por perfil de usuario.


int numero,PerfilA[5]={},PerfilB[5]={},PerfilC[5]={},cantidadArchivos;
FILE *archivo;
char actividad;
Usuarios *registro;
Entrenamiento reg;
archivo= fopen("texto.dat", "rb");
    if(archivo==NULL){
        cout<<"No se puede leer el archivo";
        system("pause");
        fclose(archivo);
        return;
    }
    fseek(archivo,0,SEEK_END);
    cantidadArchivos=ftell(archivo)/sizeof(Usuarios);
    registro=(Usuarios *) malloc(sizeof(Usuarios)*cantidadArchivos);
    if (registro==NULL){
        return;
    }
    fseek(archivo,0,SEEK_SET);
    fread(registro,sizeof(Usuarios),cantidadArchivos,archivo);
    fclose(archivo);
    archivo= fopen("Entrenamiento.dat", "rb");
    if(archivo==NULL){
        cout<<"No se puede leer el archivo";
        system("pause");
        fclose(archivo);
        return;
    }

    while(fread(&reg,sizeof(Entrenamiento),1,archivo)){
       actividad=Buscar_Actividad(reg.IDUsuario,registro,cantidadArchivos);
        if(actividad=='a'||actividad=='A'){
            PerfilA[reg.Actividad-1]++;
        }  else{
                if(actividad=='b'||actividad=='B'){
                PerfilB[reg.Actividad-1]++;
        }       else{
                    if(actividad=='c'||actividad=='C'){
                    PerfilC[reg.Actividad-1]++;
                    }
            }
        }
    }
    Mostrar_Tabla(PerfilA,PerfilB,PerfilC);


    system("pause");
    return;
}


char Buscar_Actividad(int IDUsuario,Usuarios *registro,int Cantidad_Registros){
    int i;

    for(i=0;i<=Cantidad_Registros;i++){
        if(IDUsuario==registro[i].ID){
            return registro[i].Perfil;
        }
    }
}


void Mostrar_Tabla(int perfilA [],int perfilB [],int perfilC []){
    system("cls");

    cout<<"\tA\t\tB\t\t\tC";
    cout<<endl<<"1\t"<<perfilA[0]<<"\t\t"<<perfilB[0]<<"\t\t\t"<<perfilC[0];
    cout<<endl<<endl<<"2\t"<<perfilA[1]<<"\t\t"<<perfilB[1]<<"\t\t\t"<<perfilC[1];
    cout<<endl<<endl<<"3\t"<<perfilA[2]<<"\t\t"<<perfilB[2]<<"\t\t\t"<<perfilC[2];
    cout<<endl<<endl<<"4\t"<<perfilA[3]<<"\t\t"<<perfilB[3]<<"\t\t\t"<<perfilC[3];
    cout<<endl<<endl<<"5\t"<<perfilA[4]<<"\t\t"<<perfilB[4]<<"\t\t\t"<<perfilC[4];
    cout<<endl;
    system("pause");
    return;

}
