#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

int main(int argc, char **argv){
    //FILE *file = fopen("C:\\Users\\dgonz\\Documents\\UNIVERSIDAD_lalos\\c_pbn\\data.txt","rt");
    // solo 8 datos iniciales
    FILE* file;
    file = fopen("data.txt", "rt");
    char *linea = malloc(100*sizeof(char));
    char *ptr;
    ptr = linea;

    int cont = 0, i = 0;      // contador que cuenta el largo del dato a recoger
    //int pos = 0;       //posicion en la linea 
    char *dif= ";";  //separador de datos
    char *var = malloc(sizeof(void));      // variable de datos
    // char datos[] = {};

    // for (int i = 0;i<(732*27);i++){
    //     datos[i] = malloc(sizeof(var));
    // }

    if (file == NULL)
    {
    printf("No existe el fichero!\n");
    exit(1);
    }
    //while (! feof(file)) {
    for (int h=0;h<3;h++){
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
            printf("variable V: %s\n",var);
            
            //   strcpy(datos[i],var);
            cont = 0;   
        }
    }
    i++;
    }
        // for (int i=0;i<40;i++){
        //     printf("%c",datos[i]);
        // }
    fclose(file);
}