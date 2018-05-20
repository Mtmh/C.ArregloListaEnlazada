#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANYO 20

typedef struct Pareja Pareja;

int geneaNumeroAlAzar(int limiteSuperior)
{
    int numeroGenerado = rand() % limiteSuperior + 1;

    return numeroGenerado;
}


void llenaNumeros(int numeros[TAMANYO])
{
    int x;
    for (x = 0; x < TAMANYO; ++x){
        numeros[x] = geneaNumeroAlAzar(TAMANYO);
    }

}
int comparacion(const void *punteroA, const void *punteroB)
{
    return *(int*) punteroA - *(int*) punteroB;
}

int obtieneValorGrande(int numeros[TAMANYO])
{
    int x;
    int valorGrande = numeros[0];
    for(x = 0; x < TAMANYO; ++x){
        if (numeros[x] > valorGrande){
            valorGrande = numeros[x];
        }
    }
    return valorGrande;
}

int obtieneValorPequenyo(int numeros[TAMANYO])
{
    int x;
    int valorPequenyo = numeros[0];
    for (x = 0; x < TAMANYO; ++x){
        if (numeros[x] < valorPequenyo){
            valorPequenyo = numeros[x];
        }
    }
    return valorPequenyo;
}


float obtieneMedia(int numeros[TAMANYO])
{
    float media;
    int suma = 0;
    int x;

    for (x = 0; x < TAMANYO; ++x){
        suma += numeros[x];
    }
    media = suma / TAMANYO;

    return media;
}



struct Pareja
{
  int numero;
  int ocurrencias;

  Pareja *siguiente;
};


void agregaElemento(Pareja *listaEnlazada, int elemento)
{
   Pareja *nodo = listaEnlazada;

   if (nodo == NULL){
       return;
   }

   while (nodo->siguiente != NULL){
       nodo = nodo->siguiente;
       }
   nodo->siguiente =(Pareja *) malloc(sizeof(Pareja));
   nodo = nodo->siguiente;
   nodo->numero = elemento;
   nodo->ocurrencias = -1;
   nodo->siguiente = NULL;
}

int obtieneOcurrenciasListaEnlazada(Pareja *listaEnlazada, int elemento)
{
    int ocurrencias = 0;

    Pareja *nodo = listaEnlazada;

    while (nodo != NULL){
        if (nodo->numero == elemento){
            ++ocurrencias;
        }
        nodo = nodo->siguiente;
    }
    return ocurrencias;
}

int obtieneOcurrenciasArreglo(int numeros[TAMANYO], int elemento)
{
    int x;
    int ocurrencias;

    for (x = 0; x < TAMANYO; ++x){
        if (elemento == numeros[x]){
            ++ocurrencias;
        }
    }
    return ocurrencias;

}

int obtieneModa(int numeros[TAMANYO])
{
    int x;
    int ocurrencias;

    Pareja *nodo;
    Pareja *moda;
    Pareja *listaEnlazada = (Pareja *) malloc(sizeof(Pareja));

    listaEnlazada->numero = -1;
    listaEnlazada->ocurrencias = -1;
    listaEnlazada->siguiente = NULL;

    for (x = 0; x < TAMANYO; ++x){
        ocurrencias = obtieneOcurrenciasListaEnlazada(listaEnlazada, numeros[x]);

        if (ocurrencias == 0) {
          agregaElemento(listaEnlazada, numeros[x]);
        }
    }
        nodo = listaEnlazada;

        while (nodo!= NULL){
            nodo->ocurrencias = obtieneOcurrenciasArreglo(numeros, nodo->numero);
            nodo = nodo->siguiente;
        }


    nodo = listaEnlazada;
    moda = nodo;
    while (nodo != NULL){
        if (nodo->ocurrencias > moda->ocurrencias){
            moda = nodo;
        }
         nodo = nodo->siguiente;
    }
    return moda->numero;

}

int obtieneSumaTotal(int numeros[TAMANYO])
{
    int x;
    int sumaTotal = 0;

    for (x = 0; x < TAMANYO; ++x){
        sumaTotal += numeros[x];
    }
    return sumaTotal;
}

void muestraArreglo(int numeros[TAMANYO])
{
    int x;
    for (x = 0; x < TAMANYO; ++x){
        printf("%d ", numeros[x]);
    }
    printf("\n");
}

int main(void)
{
    srand(time(NULL));

    int numeros[TAMANYO];
    int valorGrande;
    int valorPequenyo;
    int primerElemento;
    int ultimoElemento;
    int moda;
    int sumaTotal;
    int numeroConcreto = 10 ;
    int ocurrenciasNumeroConcreto;

    float media; // media o promedio


    llenaNumeros(numeros);
    qsort(numeros, TAMANYO, sizeof(int), &comparacion);
    valorGrande = obtieneValorGrande(numeros);
    valorPequenyo = obtieneValorPequenyo(numeros);
    primerElemento = numeros[0];
    ultimoElemento = numeros[TAMANYO -1];
    media = obtieneMedia(numeros);
    moda =  obtieneModa(numeros);
    sumaTotal = obtieneSumaTotal(numeros);
    ocurrenciasNumeroConcreto = obtieneOcurrenciasArreglo(numeros, numeroConcreto);
    muestraArreglo(numeros);

    printf("Valor grande:     %d\n", valorGrande);
    printf("Valor pequenyo:   %d\n", valorPequenyo);
    printf("Primer elemento:  %d\n", primerElemento);
    printf("Ultimo elemento:  %d\n", ultimoElemento);
    printf("Moda:             %d\n", moda);
    printf("Suma total:       %d\n", sumaTotal);
    printf("NumeroConcreto:   %d\n", numeroConcreto);
    printf("Ocurrencias:      %d\n", ocurrenciasNumeroConcreto);
    printf("Media:            %f\n", media);



    return 0;
}
