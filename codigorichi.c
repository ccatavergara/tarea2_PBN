// gcc -std=c99 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self main.c -o salida
//gcc main.c -o ejecutable

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct heroe  
{
    int id;
    char* name;
    int intel;
    int strength;
    int speed;
    int dur;
    int power;
    int comb;
}heroes;   

// struct h todos[1000];

void menu()
{
    printf("Que desea hacer?\n");
    printf("1)tophero\n");
    printf("2)topvalue\n");
    printf("3)hero\n");
    printf("4)end\n");
}

int main(int argc, char **argv)
{
    char *line = malloc(100*sizeof(char));
    int cuenta = 0,a;
    char *value;
    FILE * data;
    data = fopen("data.txt", "r");
    // menu();
    heroes **h = malloc(732*sizeof(heroes)); //lista de supeheroes

    for (int i=0; i<732; i++)
    {
        h[i] = malloc(sizeof(heroes));
    }
    int i =0;
    while (!feof(data)){
        fgets (line, 2100, data);
        // cuenta = 0;
        // if(cuenta != 8)
        // {   s
            //id
            value = strtok(line, ";");
            a = atoi(value);
            h[i]->id = a;
            // strcpy(h[i]->id , value);
            printf("%s ", value);

            //name
            value = strtok(NULL, ";");
            strcpy(h[i]->name , value);
            printf("%s ", value);

            //intelligence
            value = strtok(NULL, ";");
            a = atoi(value);
            h[i]->intel = a;
            printf("%s ", value);

            //strength
            value = strtok(NULL, ";");
            a = atoi(value);
            h[i]->strength = a;
            printf("%s ", value);

            //speed
            value = strtok(NULL, ";");
            a = atoi(value);
            h[i]->speed = a;
            printf("%s ",value);

            //durability
            value = strtok(NULL, ";");
            a = atoi(value);
            h[i]->dur = a;
            printf("%s ",value);

            //power
            value = strtok(NULL, ";");
            a = atoi(value);
            h[i]->power = a;
            printf("%d ",atoi(value));

            //combat
            value = strtok(NULL, ";");
            a = atoi(value);
            h[i]->comb = a;
            printf("%s ", value);
            printf("\n");
            // cuenta = 8;
            i++;
        // }
    }

    // printf("\n");
    // for(int i = 0 ; i<10; i ++)
    // {
    // printf("%s\n", h[i]->name);
    // }
    free(line);
    free(h);
    fclose(data);
    return 0;
}