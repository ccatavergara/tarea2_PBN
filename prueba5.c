#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

int main(int argc, char **argv){
//FILE *file = fopen("C:\\Users\\dgonz\\Documents\\UNIVERSIDAD_lalos\\c_pbn\\data.txt","rt");
// solo 8 datos iniciales
    FILE* file;
    char *linea = malloc(100*sizeof(char));
    char *ptr;
    ptr = linea;

    int cont = 0;      // contador que cuenta el largo del dato a recoger
 //int pos = 0;       //posicion en la linea 
    char *dif= ";";  //separador de datos
    int i = 0,n_dat = 0;
    char *var = malloc(sizeof(300));      // variable de datos
    char **lis = malloc(20*sizeof(char*));

    for (int i =0;i<20;i++){
        lis[i] = malloc(30*sizeof(char));
    }

    for (int i = 0;i<(732*27);i++){
        *lis[i] = malloc(sizeof(char));
    }  //Lista que contiene los datos var

 file = fopen("data.txt", "rt");
 if (file == NULL)
 {
 printf("No existe el fichero!\n");
 exit(1);
 }
 //while (! feof(file)) {
for (int h=0;h<2;h++){
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

        // lis[n_dat] = (char*)var;
        var[cont-1]='\0';
        strcpy(lis[n_dat],var);
        printf("variable V: %s\n",var);
        
        //   printf("%d\n", n_dat);
         cont = 0;
         printf("%d",n_dat);
         n_dat ++;
     }

  }
 }
for(int i =0; i<n_dat;i++){
    printf("%s\n",lis[i]);
}
 fclose(file);
}

