#ifndef ENTRENAR_H_INCLUDED
#define ENTRENAR_H_INCLUDED

struct Entrenamiento{
    int ID;
    int IDUsuario;
    Fecha Fecha_Entrenamiento;
    int Actividad;
    float Calorias;
    int Tiempo;
};

///     MENU
void Menu_Entrenamiento();

///     FUNCIONES DE ENTRENAMIENTO
Entrenamiento Cargar_Entrenamiento();
void mostrar_Entrenamiento();
void Listar_Entrenamiento()



#endif // ENTRENAR_H_INCLUDED
