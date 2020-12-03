//NOMBRE: Stamm Walter
//TP N°: PRIMER PARCIAL

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <clocale>
#include <iostream>
using namespace std;
#include "Ejercicios-Parcial.h"
#include "Usuarios.h"
#include "configuracion.h"

void Menu(){
    int Opcion;
    while(Opcion){
        system("cls");
        cout<<"\n===========MENÚ PRINCIPAL============";
        cout<<"\n01.- USUARIOS........................";
        cout<<"\n02.- ENTRENAMIENTOS..................";
        cout<<"\n03.- REPORTES........................";
        cout<<"\n04.- CONFIGURACIÓN...................";
        cout<<"\n=====================================";
        cout<<"\n00.- SALIR DEL PROGRAMA..............";
        cout<<"\n=====================================";
        cout<<"\n       Opción:"; cin>>Opcion;

        switch(Opcion){
            case 1:
                Menu_Usuarios();
            break;
            case 2:
                Menu_Entrenamiento();
            break;
            case 3:
                Menu_Reportes();
            break;
            case 4:
                Menu_Configuracion();
            break;
            case 0:
                return;
            break;
        }
    }
}

void Menu_Usuarios(){
    Usuarios reg;
    int Opcion;
    while(true){
        system("cls");
        cout<<"\n===========MENÚ USUARIOS=============";
        cout<<"\n01.- NUEVO USUARIO...................";
        cout<<"\n02.- MODIFICAR USUARIO...............";
        cout<<"\n03.- LISTAR USUARIOS POR ID..........";
        cout<<"\n04.- LISTAR TODOS LOS USUARIOS.......";
        cout<<"\n05.- ELIMINAR USUARIO................";
        cout<<"\n=====================================";
        cout<<"\n00.- VOLVER AL MENÚ PRINCIPAL........";
        cout<<"\n=====================================";
        cout<<"\n       Opción:"; cin>>Opcion;

        switch(Opcion){
            case 1:
                Cargar_Nuevo_Usuario();
            break;
            case 2:
                Modificar_Usuarios();
            break;
            case 3:
                Listar_Usuarios_ID();
            break;
            case 4:
                Listar_Usuarios();
            break;
            case 5:
                Baja_Logica_Usuario();

            break;
            case 0:
                return;
            break;
        }
    }
}

void Menu_Entrenamiento(){
    Entrenamiento ent;
    int Opcion;
    while(true){
        system("cls");
        cout<<"\n===========MENÚ ENTRENAMIENTOS================";
        cout<<"\n01.- NUEVO ENTRENAMIENTO......................";
        cout<<"\n02.- MODIFICAR ENTRENAMIENTO..................";
        cout<<"\n03.- LISTAR ENTRENAMIENTO POR ID..............";
        cout<<"\n04.- LISTAR ENTRENAMIENTO POR IDUSUARIOS......";
        cout<<"\n05.- LISTAR TODOS LOS ENTRENAMIENTOS..........";
        cout<<"\n==============================================";
        cout<<"\n00.- VOLVER AL MENÚ PRINCIPAL.................";
        cout<<"\n==============================================";
        cout<<"\n       Opción:"; cin>>Opcion;

        switch(Opcion){
            case 1:
                Cargar_Nuevo_Entrenamiento();
            break;
            case 2:
                Modificar_Entrenamiento();
            break;
            case 3:
                Listar_Entrenamiento_ID();
            break;
            case 4:
                Listar_Entrenamiento_Usuario();
            break;
            case 5:
                Listar_Entrenamiento();
            break;
            case 0:
                return;
            break;
            default:
                cout<<"Reingrese elección";
            break;
        }
    }
}

void Menu_Reportes(){

    int Opcion;
    while(true){
        system("cls");
        cout<<"\n===========MEÚ REPORTES=======================";
        cout<<"\n01.- Punto A..................................";
        cout<<"\n02.- Punto B..................................";
        cout<<"\n03.- Punto C..................................";
        cout<<"\n==============================================";
        cout<<"\n00.- VOLVER AL MENÚ PRINCIPAL.................";
        cout<<"\n==============================================";
        cout<<"\n       Opción:"; cin>>Opcion;

        switch(Opcion){
            case 1:
                Punto_A();
            break;
            case 2:
                Punto_B();
            break;
            case 3:
                Punto_C();
            break;
            case 0:
                return;
            break;
            default:
                cout<<"Reingrese elección";
            break;
        }
    }

}

void Menu_Configuracion(){
    Entrenamiento ent;
    int Opcion;
    while(true){
        system("cls");
        cout<<"\n===========MEÚ CONFIGURACION==================";
        cout<<"\n01.- REALIZAR COPIA DE SEGURIDAD..............";
        cout<<"\n02.- RESTAURAR COPIA DE SEGURIDAD.............";
        cout<<"\n==============================================";
        cout<<"\n00.- VOLVER AL MENÚ PRINCIPAL.................";
        cout<<"\n==============================================";
        cout<<"\n       Opción:"; cin>>Opcion;

        switch(Opcion){
            case 1:
                RealizarCopiaSeguridad();
            break;
            case 2:
                RestaurarCopiaSeguridad();
            break;
            case 0:
                return;
            break;
        }
    }
}
