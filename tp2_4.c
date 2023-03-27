#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu
{
    int velocidad; // 1 a 3
    int anio; //2015 a 2023
    int cantidad; // 1 a 8
    char *tipo_cpu; // char tipos[6][10]={“Intel”, “AMD”, “Celeron”, “Athlon”, “Core”, “Pentium”}
};

void cargarCto(struct compu *lugar, int cant, char tipo[][10], int cantTipos);
void mostrarCto( struct compu cto[], int tama, int largoTipo);
void mostrarMasVieja(struct compu *cto, int tama); 
void mostrarMasVeloz(struct compu cto[], int tama); 

////
void main(){
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    struct compu ctoDe5PCs[5]; 
    srand(time(NULL));


    cargarCto(ctoDe5PCs, 5, tipos, 6);
    mostrarCto(ctoDe5PCs, 5, 10); 
    mostrarMasVieja(ctoDe5PCs, 5);
    mostrarMasVeloz(ctoDe5PCs, 5);
}
////


void cargarCto(struct compu *lugar, int cant, char tipo[][10], int cantTipos){
    for (int i = 0; i < cant; i++){
        lugar->velocidad = 1+rand()%3;
        lugar->anio = 2015+rand()%(2023-2015)+1;
        lugar->cantidad = 1+rand()%8;
        lugar->tipo_cpu = &tipo[rand()%cantTipos][0];
        lugar++;
    }
}

void mostrarCto( struct compu cto[], int tama, int largoTipo){
    for (int i = 0; i < tama; i++)
    {
        printf("  PC nro %d:\n    -Velocidad de procesamiento: %dGHz \n    -Anio de fabricacion: %d \n    -Tipo de procesador: %s\n    -Cantidad de nucleos: %d \n\n", i+1, cto[i].velocidad, cto[i].anio, cto[i].tipo_cpu, cto[i].cantidad);
        // Había olvidado el %s 
        // printf("tipo: "); 
        // for (int j = 0; j < largoTipo; j++)
        // {
        //     printf("%c", cto[i].tipo_cpu[j]); 
        // }
        //     printf(" \n"); 
        // largo, si, pero salía bonito igual >.<
    }
}  

void mostrarMasVieja(struct compu *cto, int tama){
    struct compu* mayor;
    int nro = 1;
    mayor = cto;
    for (int i = 1; i < tama; i++) {
        if ((cto+i)->anio < mayor->anio){   
            mayor = cto+i;
            nro = i+1;
        }
    }
    printf("#PC mas vieja (nro %d):\n  -Velocidad de procesamiento: %dGHz \n  -Anio de fabricacion: %d \n  -Tipo de procesador: %s\n  -Cantidad de nucleos: %d \n\n", nro, mayor->velocidad, mayor->anio, mayor->tipo_cpu, mayor->cantidad);
}  

void mostrarMasVeloz(struct compu cto[], int tama){
    struct compu speedyGonzales;
    int nro = 1;
    speedyGonzales = cto[0];
    for (int i = 1; i < tama; i++) {
        if (cto[i].velocidad > speedyGonzales.velocidad){   
            speedyGonzales = cto[i];
            nro += i;
        }
    }
    printf("#PC mas veloz (nro %d):\n  -Velocidad de procesamiento: %dGHz \n  -Anio de fabricacion: %d \n  -Tipo de procesador: %s\n  -Cantidad de nucleos: %d \n\n", nro, speedyGonzales.velocidad, speedyGonzales.anio, speedyGonzales.tipo_cpu, speedyGonzales.cantidad);
}  

