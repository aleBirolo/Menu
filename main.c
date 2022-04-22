#include <stdio.h>
#include <stdlib.h>

#define SALIR 0
#define CANT_FUNC 3


void menu();
void ingresoMenu(int *opc);

typedef void (*Llamada)() ;
void execMenu( Llamada llamar  );

void fun_1();
void fun_2();
void fun_3();

int sumar(int n1, int n2);

int main()
{
    int opc;
    void *ptr[]={fun_1, fun_2, fun_3};

    ingresoMenu(&opc);

    while (opc != SALIR)
    {
        execMenu(ptr[opc-1]);
        printf ("\n\n");
        system("pause");
        system("cls");

        ingresoMenu(&opc);
    }

    return 0;
}

void menu()
{
    printf("\tMenu\n\
            \r 1: Ejecutar funcion 1.\n\
            \r 2: Ejecutar funcion 2.\n\
            \r 3: Ejecutar funcion 3.\n\
            \r 0: Salir.\n");
}

void ingresoMenu(int *opc)
{
     do
    {
        menu();
        printf ("\n Ingrese opcion: ");
        scanf("%d",opc);

        if (*opc> CANT_FUNC)
        {
            printf ("\n Opcion invalida. Vuelva a ingresar opcion.\n");
            system("pause");
            system("cls");
        }
    }while (*opc> CANT_FUNC);
}

void execMenu( Llamada llamar  )
{
    llamar();
}

void fun_1()
{
    printf ("\n Funcion 1");
}

void fun_2()
{
    printf ("\n Funcion 2");
}

void fun_3()
{
    int n1,
        n2;

    printf ("\n Funcion 3\n");

    printf ("\n Ingrese numero 1: ");
    scanf("%d", &n1);

    printf ("\n Ingrese numero 2: ");
    scanf("%d", &n2);

    printf ("\n Resultado de la suma de %d + %d = %d", n1, n2, sumar(n1,n2) );

}

int sumar(int n1, int n2)
{
    return n1+n2;
}
