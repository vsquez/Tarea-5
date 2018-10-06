#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct Alumno{

    char nombre[64];
    int edad;
    Alumno *rigth, *left;

};

struct Alumno *raiz = NULL;

Alumno * crearNodo ();
void insertar (struct Alumno *, struct Alumno *);
Alumno * buscar(struct Alumno *, struct Alumno *);
void inorden(struct Alumno *);
void posorden(struct Alumno *);
void preorden(struct Alumno *);

int main()
{
    struct Alumno *nodoEncontrado = NULL;

    int numeroNodos,i;
    printf("Numero de nodos: ");
    scanf("%d",&numeroNodos);

    for(i = 0; i < numeroNodos; ++i)
    {
        Alumno *nuevo = crearNodo();
        if(raiz == NULL)
        {
            raiz = nuevo;
        }
        else
        {
            insertar(raiz,nuevo);
        }
    }

    preorden(raiz);
    printf("\n");
    inorden(raiz);
    printf("\n");
    posorden(raiz);


    return 0;
}

void preorden(struct Alumno *arbol)
{
    printf(" %s --- %d ",arbol->nombre,arbol->edad);
    if(arbol->left != NULL)
        preorden(arbol->left);
    if(arbol->rigth != NULL)
        preorden(arbol->rigth);
}

void posorden(struct Alumno *arbol)
{
    if(arbol->left != NULL)
        posorden(arbol->left);
    if(arbol->rigth != NULL)
        posorden(arbol->rigth);
    printf(" %s --- %d ",arbol->nombre,arbol->edad);
}

void inorden(struct Alumno *arbol)
{
    if(arbol->left != NULL)
        inorden(arbol->left);
    printf(" %s --- %d ",arbol->nombre,arbol->edad);
    if(arbol->rigth != NULL)
        inorden(arbol->rigth);
}

void insertar (struct Alumno *arbol, struct Alumno *nuevo)
{
    if(nuevo->edad < arbol->edad)
    {
        if(arbol->left == NULL)
        {
            arbol->left = nuevo;
        }
        else
        {
            insertar(arbol->left,nuevo);
        }
    }
    else
    {
        if(arbol->rigth == NULL)
        {
            arbol->rigth = nuevo;
        }
        else
        {
            insertar(arbol->rigth,nuevo);
        }
    }
}

Alumno * crearNodo ()
{
    Alumno *nuevo = new Alumno;
    printf("\nInserte nombre: ");
    scanf("%s",&nuevo->nombre);
    printf("Inserte edad: ");
    scanf("%d",&nuevo->edad);
    nuevo->left = NULL;
    nuevo->rigth = NULL;
    return nuevo;

}
