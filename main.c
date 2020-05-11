//********************************************
//              MENU PRINCIPAL               *
//********************************************

#include <stdio.h>
#include <stdlib.h>
#define T 3
//#define LIBRE 0
//#define OCUPADO 1
#include "Funciones.h"

 int main()
{

  eTabla listaPersonas[T]= {  {10, "Maria", "lopez"," maria@gmail.com","mesa",1500,OCUPADO},
                              {15, "Luis", "gomez"," luis@gmail.com","escritorio",2500,OCUPADO},
                              {20, "Juan", "perez"," juan@gmail.com","silla",1200,OCUPADO}};

int opcion;
//inicializarPersona(listaPersonas, T);

      do
    {
      printf ("||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
      printf ("||         1.Cargar persona                       ||\n");
      printf ("||         2.Eliminar persona                     ||\n");
      printf ("||         3.Modificar persona                    ||\n");
      printf ("||         4.Listar personas                      ||\n");
      printf ("||         5.Ordenar personas                     ||\n");
      printf ("||         6.Mostrar productos                    ||\n");
      printf ("||         7.Mostrar personas con sus productos   ||\n");
      printf ("||         10.SALIR                               ||\n");
      printf ("||                                                ||\n");
      fflush(stdin);
      ValidarOpcion(&opcion,10,"Seleccione una opcion: ","Esa opcion no es valida \n",11,0);





      switch (opcion)
      {
        case 1:
          printf ("\nCARGA DE DATOS\n");
          cargarListadoDePersonas(listaPersonas, T);
          break;

        case 2:
          printf ("ELIMINAR PERSONA\n");
          eliminarPersona(listaPersonas, T);
          break;

        case 3:
          printf("MODIFICAR PERSONA\n");
          modificarPersona(listaPersonas, T);
          break;

        case 4:
          printf("MOSTRAR LISTADO DE PERSONAS: \n");
          mostrarListadoDePersonas(listaPersonas, T);
          break;

        case 5:
          printf("ORDENAR PERSONAS\n");
          ordenarListadoDePersonasPorNombre(listaPersonas, T);
          break;

        case 6:
          printf("MOSTRAR PRODUCTOS CON SU PRECIO: \n");
          mostrarProductos(listaPersonas, T);
          break;
/*
        case 7:
          printf("MOSTRAR PERSONAS CON SUS PRODUCTOS:\n");
          mostrarPersonasConProductos(listaPersonas, T);
          break;
 */
      }
    } while (opcion != 10);

     mostrarPersonasConMaximoPrecio(listaPersonas,T);
     mostrarPersonasConMinimoPrecio(listaPersonas,T);

    return 0;
}

