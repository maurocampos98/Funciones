                                        //*******************************
                                        //  DESARROLLO DE FUNCIONES     *
                                        //*******************************
//********************************
// Include de librerias          *
//********************************

#include "funciones.h"

//*******************************
//  INICIALIZACION DE TABLA     *
//*******************************


void inicializarPersona (eTabla listado[] , int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
      listado[i].estado = LIBRE;
    }
}

//*******************************
//      CARGA DE TABLA          *
//*******************************

void cargarListadoDePersonas (eTabla listado[], int tam)

{
    int encontro;
    encontro = buscarLibre(listado ,tam);
    if(encontro!=-1)
    {
       listado[encontro] = CargarPersona();
       printf("usuario cargado con exito :\n");
    }
    else
    {
        printf("No hay espacio:\n");
    }

}

//*************************************************
//     BUSCO ESPACIO LIBRE PARA LA CARGA DE TABLA *
//*************************************************


int buscarLibre(eTabla* listado, int tam)
{
    int i;
    int index =-1;
    for(i=0; i<tam; i++)
    {
        if(listado[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

//********************************
//      CARGA DE PERSONA / TABLA *
//********************************

eTabla CargarPersona(void)
{
    eTabla miPersona;

    printf("Ingrese ID: ");
    scanf("%d", &miPersona.id);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(miPersona.nombre);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(miPersona.apellido);

    printf("Ingrese producto: ");
    fflush(stdin);
    gets(miPersona.producto);

    printf("Ingrese email: ");
    fflush(stdin);
    gets(miPersona.email);

    printf("Ingrese Precio: ");
    scanf("%f", &miPersona.precio);

 //   fgets(miPersona.nombre,20,stdin);
 //   miPersona.nombre[strlen( miPersona.nombre)-1]='\0';

 //   fgets(miPersona.email,20,stdin);
 //   miPersona.email[strlen( miPersona.email)-1]='\0';

    miPersona.estado = OCUPADO;
    return miPersona;
}

//***************************************
//      MOSTRAR LISTADO DE PERSONAS     *
//***************************************

void mostrarListadoDePersonas(eTabla listado[], int tam)

{
    int i;

    for(i=0; i<tam; i++)
    {
       if(listado[i].estado == OCUPADO)
        {
            mostrarUnaPersona(listado[i]);
        }

    }

}

//***********************************************************
//   MOSTRAR UNA PERSONA PARA IR CARGANDO UNO POR UNO       *
//***********************************************************

void mostrarUnaPersona(eTabla miPersona)
{
    printf("%8d %20s %20s %10s %8f %20s\n", miPersona.id,
                                            miPersona.nombre,
                                            miPersona.apellido,
                                            miPersona.producto,
                                            miPersona.precio,
                                            miPersona.email);

}

//***********************************************************
//                  ELIMINAR PERSONA                        *
//***********************************************************

void eliminarPersona(eTabla listado[], int tam)
{
    int id;
    int i;

    printf("Ingrese ID de la persona a eliminar: ");
    scanf("%d", &id);

    for(i=0;i<tam; i++)
    {
        if(listado[i].estado == OCUPADO && id == listado[i].id)
        {
            listado[i].estado = LIBRE;
            printf("USUARIO ELIMINADO CON EXITO: :\n");
            break;
        }
    }

}

//***********************************************************
//                  MODIFICAR PERSONA                       *
//***********************************************************

void modificarPersona(eTabla listado [], int tam)
{
    int id;
    int i;
 //   int nombre;

    printf("Ingrese el id de la persona a modificar: ");
    scanf("%d", &id);

    for(i=0;i<tam; i++)
    {
        if(listado[i].estado == OCUPADO && id == listado[i].id)
        {
            printf("MOD / Ingrese nombre : ");
            fflush(stdin);
            fgets(listado[i].nombre,20,stdin);
            listado[i].nombre[strlen(listado[i].nombre)-1]='\0';
            printf("USUARIO MODIFICADO CON EXITO: :\n");
            break;
        }
         else
         {
             if (id != listado[i].id)
             {
             printf("USUARIO NO ENCONTRADO :\n");
             break;
             }
          }
     }
}

//***********************************************************
//             ORDENAR LISTADO DE PERSONA POR NOMBRE        *
//***********************************************************

void ordenarListadoDePersonasPorNombre(eTabla listado[], int tam)

{
    int i;
    int j;
    eTabla auxPersona;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            {
               auxPersona  =  listado[i];
               listado[i] = listado[j];
               listado[j] = auxPersona;

            }

        }
    }
    printf("Listado ordenado por nombre, ingrese opcion 4 para verlo: \n ");
}

//***********************************************************
//     ORDENAR LISTADO DE PERSONA POR NOMBRE Y PRECIO       *
//***********************************************************

void ordenarListadoDePersonasPorNombreYPorPrecio(eTabla listado[], int tam)
{
    int i;
    int j;
    eTabla auxPersona;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            {
               auxPersona = listado[i];
               listado[i] = listado[j];
               listado[j] = auxPersona;
            }
            else
            {
               if(strcmp(listado[i].nombre,listado[j].nombre)==0)
               {
                   if(listado[i].precio>listado[j].precio)
                   {
                          auxPersona  =  listado[i];
                          listado[i] = listado[j];
                          listado[j] = auxPersona;
                   }
               }
            }
        }
    }
    printf("Listado ordenado por nombre y precio, ingrese opcion 4 para verlo: :\n");
}
//**********************************************
//       MOSTRAR PRODUCTOS CON SU PRECIO       *
//**********************************************


void mostrarProductos(eTabla listado[], int tam)

{
    int i;

    for(i=0; i<tam; i++)
    {
       if(listado[i].estado == OCUPADO)
        {
            mostrarUnProducto(listado[i]);
        }

    }

}

//***********************************************************
//           MOSTRAR UN PROCUCTO CON SU PRECIO              *
//***********************************************************

void mostrarUnProducto(eTabla miPersona)
{
    printf("%10s %8f\n", miPersona.producto,
                         miPersona.precio);
}

//***********************************************************
//         MAXIMO DE PRECIOS                                *
//***********************************************************

float calcularMaximoPrecio(eTabla listado[], int tam)
{
    float maxPrecio ;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].precio>maxPrecio || i==0)
        {
            maxPrecio = listado[i].precio;
        }
    }
    return maxPrecio;

//***********************************************************
//  BUSCA EN EL LISTADO LAS PERSONAS CON MAXIMO PRECIO      *
//***********************************************************
}
void mostrarListadoDePersonasConMaximo(eTabla listado[], int tam, int maximo)
{
    int i;

    printf("EL USUARIO CON EL PRECIO MAS ALTO ES : \n ");
    for(i=0; i<tam; i++)
    {
        if(listado[i].precio == maximo)
        {
                mostrarUnaPersona(listado[i]);
        }
    }
}
//***********************************************************
//  MOSTRAR PERSONAS CON MAXIMO PRECIO                      *
//***********************************************************
void mostrarPersonasConMaximoPrecio(eTabla listado[], int tam)
{
   float maximoPrecio;
   int i;

   maximoPrecio = calcularMaximoPrecio(listado,tam);

   mostrarListadoDePersonasConMaximo(listado,tam, maximoPrecio);

}

//***********************************************************
//         MINIMO DE PRECIOS                                *
//***********************************************************

float calcularMinimoPrecio(eTabla listado[], int tam)
{
    float minPrecio ;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].precio<minPrecio || i==0)
        {
            minPrecio = listado[i].precio;
        }
    }
    return minPrecio;

//***********************************************************
//  BUSCA EN EL LISTADO LAS PERSONAS CON MINIMO PRECIO      *
//***********************************************************
}
void mostrarListadoDePersonasConMinimo(eTabla listado[], int tam, int minimo)
{
    int i;
    printf("EL USUARIO CON EL PRECIO MAS BAJO ES : \n ");
    for(i=0; i<tam; i++)
    {
        if(listado[i].precio == minimo)
        {
                mostrarUnaPersona(listado[i]);
        }
    }

}
//***********************************************************
//  MOSTRAR PERSONAS CON MINIMO PRECIO                      *
//***********************************************************
void mostrarPersonasConMinimoPrecio(eTabla listado[], int tam)
{
   float minimoPrecio;
   int i;

   minimoPrecio = calcularMinimoPrecio(listado,tam);

   mostrarListadoDePersonasConMinimo(listado,tam, minimoPrecio);
}


//***********************************************************
//          VALIDAR OPCION                                  *
//***********************************************************

int ValidarOpcion(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo)
{
int auxiliarNum;
int retorno = -1;

       for(;reint>0;reint--)
       {
        printf(msg);
        if(ValInt(&auxiliarNum) == 0)
        {
            if(auxiliarNum > minimo && auxiliarNum < maximo)
            {
            *pNum = auxiliarNum;
            retorno = 0;
            break;

            }else
            {
            printf(msgError);
            }
        }else
        {
        printf(msgError);
        fflush(stdin);
        }

        }

        return retorno;
}
//***********************************************************
//          VALIDAR OPCION  (CONTINUACION)                  *
//***********************************************************


int ValInt(int* pResultado)
{
int ret=-1;
int num;

        if(scanf("%d",&num)==1)
          {
           *pResultado = num;
            ret=0;
          }
        return ret;
}




