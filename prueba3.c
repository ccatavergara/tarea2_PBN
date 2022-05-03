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

int main(int argc, char **argv){
    //FILE *file = fopen("C:\\Users\\dgonz\\Documents\\UNIVERSIDAD_lalos\\c_pbn\\data.txt","rt");
    // solo 8 datos iniciales
    FILE* file;
    file = fopen("data.txt", "rt");
    char linea[2100];
    char *ptr;
    ptr = linea;

    int cont = 0;      // contador que cuenta el largo del dato a recoger
    //int pos = 0;       //posicion en la linea 
    char dif[]= ";";  //separador de datos
    int i = 0;
    char var[300];      // variable de datos
    char lis[732*27][200];  //Lista que contiene los datos var
    int n_dat = 0;
    char *aux;
    char* ptrlist[30];
    if (file == NULL)
    {
    printf("No existe el fichero!\n");
    exit(1);
    }
 //while (! feof(file)) {
    for (int h=0;h<732;h++){
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
    // for (i = 0; i < (732*27); i++)
    //     printf("%s\n", ptrlist[i]);
    //  printf("%s",lis[2]);

    superhero **super = malloc(30*sizeof(superhero));
    for (int i=0; i<732; i++){
        super[i] = malloc(sizeof(superhero));
        super[i]-> name = malloc(sizeof(char));
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
    for(int i = 0;i<732;i+=27){
        super[i] ->id = i;
        strcpy(super[i] ->name,ptrlist[i+1]);
        strcpy(super[i] ->intelligence, ptrlist[i+2]);
        strcpy(super[i] ->strength, ptrlist[i+3]);
        strcpy(super[i] ->speed, ptrlist[i+4]);
        strcpy(super[i] ->durability, ptrlist[i+5]);
        strcpy(super[i] ->power,ptrlist[i+6]);
        strcpy(super[i] ->combat,ptrlist[i+7]);
        strcpy(super[i] ->full_name,ptrlist[i+8]);
        strcpy(super[i] ->alter_ego,ptrlist[i+9]);
        strcpy(super[i] ->aliases,ptrlist[i+10]);
        strcpy(super[i] ->place_of_birth,ptrlist[i+11]);
        strcpy(super[i] ->first_appearance,ptrlist[i+12]);
        strcpy(super[i] ->publisher,ptrlist[i+13]);
        strcpy(super[i] ->alignment,ptrlist[i+14]);
        strcpy(super[i] ->gender,ptrlist[i+15]);
        strcpy(super[i] ->race,ptrlist[i+16]);
        strcpy(super[i] ->height_1,ptrlist[i+17]);
        strcpy(super[i] ->height_2,ptrlist[i+18]);
        strcpy(super[i] ->weight_1,ptrlist[i+19]);
        strcpy(super[i] ->weight_2,ptrlist[i+20]);
        strcpy(super[i] ->eye_color,ptrlist[i+21]);
        strcpy(super[i] ->hair_color,ptrlist[i+22]);
        strcpy(super[i] ->work_occupation,ptrlist[i+23]);
        strcpy(super[i] ->work_base,ptrlist[i+24]);
        strcpy(super[i] ->connections_group,ptrlist[i+25]);
        strcpy(super[i] ->connections_relatives,ptrlist[i+26]);
    }

    for (int i=0;i<6;i++){
        printf("%d %d %d %d %d %s\n",super[i] ->id,super[i] ->strength,super[i] ->speed,super[i] ->durability,super[i] ->power,super[i]->name);
    }
    fclose(file);
    return 0;
}