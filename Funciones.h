//*******************************
// .H DEFINICION DE FUNCIONES   *
//*******************************

#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1


    typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char email[20];
    char producto [10];
    float precio;
    int estado;
} eTabla;



void inicializarPersona(eTabla listaPersonas[], int tam);
eTabla CargarPersona(void);
int buscarLibre(eTabla* listaPersonas, int tam);
void cargarListadoDePersonas (eTabla listado[], int tam);
void mostrarUnaPersona(eTabla miPersona);
void mostrarListadoDePersonas(eTabla listado[], int tam);
void eliminarPersona(eTabla listado[], int tam);
void modificarPersona(eTabla listado[], int tam);
void ordenarListadoDePersonasPorNombre(eTabla listado[], int tam);
void ordenarListadoDePersonasPorNombreYPorPrecio(eTabla listado[], int tam);
void mostrarProductos(eTabla listado[], int tam);
void mostrarProductos(eTabla listado[], int tam);
void mostrarUnProducto(eTabla miPersona);


float calcularMaximoPrecio(eTabla listado[], int tam);
void mostrarListadoDePersonasConMaximo(eTabla listado[], int tam, int maximo);
void mostrarPersonasConMaximoPrecio(eTabla listado[], int tam);

float calcularMinimoPrecio(eTabla listado[], int tam);
void mostrarListadoDePersonasConMinimo(eTabla listado[], int tam, int maximo);
void mostrarPersonasConMinimoPrecio(eTabla listado[], int tam);

int ValidarOpcion(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo);
int ValInt(int* pResultado);
