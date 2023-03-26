#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 5
#define M 7

void main (){
    int i,j;
    int mt[N][M];
    double k = 0; //Explicado en linea 19
    srand(time(NULL));

    for(i = 0;i<N; i++){
        for(j = 0;j<M; j++){
            *(*(mt+i)+j)=1+rand()%100;
            // printf("%d ", &mt[i][j]);
            printf("%lf ", k+*(*(mt+i)+j)); //Al querer inprimir un entero como un float A MI me da error y me pone todos los números en 0.000000, así que creé un double k para que al sumar haga una conversión numérica forzada.
            //No encontré otra solución en google.

        }
        printf("\n");
    }

}
