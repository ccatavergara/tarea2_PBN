#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Superhero{
    int id;
    char *name;
    int intelligence;
    int strength;
    int speed;
    int durability;
    int power;
    int combat;
    char *full_name;
    char *alter_ego;
    char *aliases;
    char *place_of_birth;
    char *first_appearance;
    char *publisher;
    char *alignment;
    char *gender;
    char *race;
    char *height_1;
    char *height_2;
    char *weight_1;
    char *weight_2;
    char *eye_color;
    char *hair_color;
    char *work_occupation;
    char *work_base;
    char *connections_group;
    char *connections_relatives;

}superhero;





#define MAX_LINE_LENGTH 80

int main(int argc, char **argv){
//FILE *file = fopen("C:\\Users\\dgonz\\Documents\\UNIVERSIDAD_lalos\\c_pbn\\data.txt","rt");
// solo 8 datos iniciales
    FILE* file;
    char nombre[80] = "data.txt";
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
    int n = 1;
    file = fopen(nombre, "rt");
    if (file == NULL)
    {
    printf("No existe el fichero!\n");
    exit(1);
    }
 superhero **super = malloc(30*sizeof(superhero));
 for (int i=0; i<1; i++){
        super[i] = malloc(sizeof(superhero));
        super[i]-> name = malloc(sizeof(char)*100);
        super[i]-> full_name = malloc(sizeof(char));
        super[i]-> alter_ego = malloc(sizeof(char));
        super[i]-> aliases = malloc(sizeof(char));
        super[i]-> place_of_birth = malloc(sizeof(char));
        super[i]-> first_appearance = malloc(sizeof(char));
        super[i]-> publisher = malloc(sizeof(char));
        super[i]-> alignment = malloc(sizeof(char));
        super[i]-> gender = malloc(sizeof(char));
        super[i]-> race = malloc(sizeof(char));
        super[i]-> height_1 = malloc(sizeof(char));
        super[i]-> height_2 = malloc(sizeof(char));
        super[i]-> weight_1 = malloc(sizeof(char));
        super[i]-> weight_2 = malloc(sizeof(char));
        super[i]-> eye_color = malloc(sizeof(char));
        super[i]-> hair_color = malloc(sizeof(char));
        super[i]-> work_occupation = malloc(sizeof(char));
        super[i]-> work_base = malloc(sizeof(char));
        super[i]-> connections_group = malloc(sizeof(char));
        super[i]-> connections_relatives = malloc(sizeof(char));
    }
 //while (! feof(file)) {
for (int i=0;i<1;i++){
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
         cont = 0;
         n_dat ++;     
     }
        super[i] ->id = n;
        strcpy(super[i] ->name,lis[i+1]);
        super[i] ->intelligence = i*2;
        super[i] ->strength = i*3;
        super[i] ->speed = i*4;
        super[i] ->durability = i*5;
        super[i] ->power = i*6;
        super[i] ->combat = i*7;
        strcpy(super[i] ->full_name,lis[i*8]);
        strcpy(super[i] ->alter_ego,lis[i*9]);
        strcpy(super[i] ->aliases,lis[i*10]);
        strcpy(super[i] ->place_of_birth,lis[i*11]);
        strcpy(super[i] ->first_appearance,lis[i*12]);
        strcpy(super[i] ->publisher,lis[i*13]);
        strcpy(super[i] ->alignment,lis[i*14]);
        strcpy(super[i] ->gender,lis[i*15]);
        strcpy(super[i] ->race,lis[i*16]);
        strcpy(super[i] ->height_1,lis[i*17]);
        strcpy(super[i] ->height_2,lis[i*18]);
        strcpy(super[i] ->weight_1,lis[i*19]);
        strcpy(super[i] ->weight_2,lis[i*20]);
        strcpy(super[i] ->eye_color,lis[i*21]);
        strcpy(super[i] ->hair_color,lis[i*22]);
        strcpy(super[i] ->work_occupation,lis[i*23]);
        strcpy(super[i] ->work_base,lis[i*24]);
        strcpy(super[i] ->connections_group,lis[i*25]);
        strcpy(super[i] ->connections_relatives,lis[i*26]);
    }


 }
 for (int i=0;i<800;i++){
 printf("%d",super[i]->id);
 }
 printf("%s",lis[2]);
 fclose(file);
}