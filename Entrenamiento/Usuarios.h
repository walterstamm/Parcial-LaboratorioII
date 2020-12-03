#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

struct Fecha{
    int Dia;
    int Mes;
    int Anio;
};

struct Usuarios{
    int ID;
    char Nombres[50];
    char Apellido[50];
    Fecha Nac;
    float Peso;
    char Perfil;
    bool Apto_Med;
    bool Estado;
};

struct Entrenamiento{
    int ID, IDUsuario, Actividad, Tiempo;
    Fecha Fecha_Entrenamiento;
    float Calorias;
};


///     USUARIOS INDIVIDUAl
Usuarios Cargar_Usuarios();
void Mostrar_Usuarios(Usuarios);
void Cargar_Nuevo_Usuario();
void Listar_Usuarios();///muestra los usuarios cargados en el archivo
void Modificar_Usuarios();///modifica algunos campos del usuario, pide numero de ID para modificar
bool Validar_ID(int);///Valida si el id existe
Usuarios Levantar_Participantes(int,bool *);///devuelve un usuario ya cargado, pide enviar lo posicion dentro del archivo
bool Guardar_Usuario(Usuarios,int);///pide posicion en el archivo y guarda en el archivo
void Listar_Usuarios_ID();///Pide ID de usuario y lista todos los campos
void Baja_Logica_Usuario();///Da de baja logica al usuario
bool Valido_Perfil(char);
int Cantidad_Usuarios();

///     FECHA
Fecha Cargar_Fecha();
void Mostrar_Fecha(Fecha);
bool validacionFecha(int ,int , int);
bool validacionMayor(int, int, int);

///     MENU
void Menu();
void Menu_Usuarios();
void Menu_Entrenamiento();
void Menu_Reportes();
void Menu_Configuracion();

///     CONTROLES
bool Control_Fecha(int, int, int);
int Buscar_Usuario(int);//devuelve la posicion dentro del archivo


///     ENTRENAMIENTO
Entrenamiento Cargar_Entrenamiento();
void Cargar_Nuevo_Entrenamiento();
void Listar_Entrenamiento();
void mostrar_Entrenamiento(Entrenamiento);
void Listar_Entrenamiento_Usuario();
void Listar_Entrenamiento_ID();
int contador_entrenamiento();///CUANTIFICA LA CANTIDAD DE ENTRANAMIENTOS CARGADOS
bool Valida_Usuario_existente(int);///VALIDA QUE EXISTA EL USUARIO ANTES DE CARGAR EL ENTRENAMIENTOS
void Modificar_Entrenamiento();
int Buscar_ID_Entrenamiento(int);
Entrenamiento Levantar_Entrenamiento(int,bool *);
bool Guardar_Modificacion_Entranamiento(Entrenamiento,int);
bool Verificar_ApMedico(int);



#endif // USUARIOS_H_INCLUDED
