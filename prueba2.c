#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

int main(int argc, char **argv){
    //FILE *file = fopen("C:\\Users\\dgonz\\Documents\\UNIVERSIDAD_lalos\\c_pbn\\data.txt","rt");
    // solo 8 datos iniciales
    FILE* file;
    char nombre[80] = "data copy.txt";
    char linea[2100];
    char *ptr;
    ptr = linea;

    int cont = 0;      // contador que cuenta el largo del dato a recoger
    //int pos = 0;       //posicion en la linea 
    char dif[]= ";";  //separador de datos
    int i = 0;
    char var[300];      // variable de datos
    char lis[27][200];  //Lista que contiene los datos var
    int n_dat = 0;
    char *aux;
    char* ptrlist[30];
    file = fopen(nombre, "rt");
    if (file == NULL)
    {
    printf("No existe el fichero!\n");
    exit(1);
    }
    //while (! feof(file)) {
    for (int h=0;h<1;h++){
    fgets(linea, 2100, file);
    //printf("Linea %d, lenght: %d, primer dato: %c\n",i,strlen(linea),ptr[0]);
    //printf("Posiciones de ptr: %c\n",ptr[0]);

    //for (int a=0; a<strlen(linea);a++)
    for (int a=0; a<strlen(linea);a++)
    { 
        cont++;

        if ( ptr[a] == ';' )
        {
            for (int b=0; b<cont-1; b++)
            {
                var[b] = ptr[(a-cont)+1+b];
                
            }
            var[cont-1]='\0';

            strcpy(lis[n_dat],var);
            aux = (char *)malloc(cont + 1);
            strcpy(aux,var);
            ptrlist[n_dat]=aux;
            cont = 0;
            n_dat ++;
            
        }
    }
    }
    for (i = 0; i < 30; i++)
        printf("%s\n", ptrlist[i]);
    //  printf("%s",lis[2]);
    fclose(file);
}