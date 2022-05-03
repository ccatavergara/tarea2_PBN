#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// seccion de preguntas:
//como hacer la lista con punteros y que funcione
// como hacemos los numeros numeros y como ponemos todo en las struct
// que hacer con el gets() que podriamos usar en cambio

typedef struct Superhero{ //struct con typedef superhero
    int id;
    char *name;
    int intelligence;
    int strength;
    int speed;
    int durability;
    int power;
    int combat;
    // char *full_name;
    // char *alter_ego;
    // char *aliases;
    // char *place_of_birth;
    // char *first_appearance;
    // char *publisher;
    // char *alignment;
    // char *gender;
    // char *race;
    // char *height_1;
    // char *height_2;
    // char *weight_1;
    // char *weight_2;
    // char *eye_color;
    // char *hair_color;
    // char *work_occupation;
    // char *work_base;
    // char *connections_group;
    // char *connections_relatives;

}superhero;

int cInteligence(const void * a, const void * b) {
    superhero **m = (superhero **)a;
    superhero **n = (superhero **)b;
    return ((*m)->intelligence - (*n)->intelligence);
}
int cStrength(const void * a, const void * b) {
    superhero **m = (superhero **)a;
    superhero **n = (superhero **)b;
    return ((*m)->strength - (*n)->strength);
}
int cSpeed(const void * a, const void * b) {
    superhero **m = (superhero **)a;
    superhero **n = (superhero **)b;
    return ((*m)->speed - (*n)->speed);
}
int cDurability(const void * a, const void * b) {
    superhero **m = (superhero **)a;
    superhero **n = (superhero **)b;
    return ((*m)->durability - (*n)->durability);
}
int cPower(const void * a, const void * b) {
    superhero **m = (superhero **)a;
    superhero **n = (superhero **)b;
    return ((*m)->power - (*n)->power);
}
int cCombat(const void * a, const void * b) {
    superhero **m = (superhero **)a;
    superhero **n = (superhero **)b;
    return ((*m)->combat - (*n)->combat);
}
int (*comparar[])(const void*, const void*) = {cInteligence,cStrength,cSpeed,cDurability,cPower,cCombat}; //lista que guarda todas las funciones de comparacion.
char *poderes[] = {"intellgence","strength","speed","durability","power","combat"}; //lista que guarda todos los nombres de poderes.
int habilidades(int h, int habilidad, struct Superhero **supers){
    int poder[]= {supers[h]->intelligence,supers[h]->strength,supers[h]->speed,supers[h]->durability,supers[h]->power,supers[h]->combat};
    return poder[habilidad]; //una funcion que crea todas las habilidades predeterminadas y las busca por indice.
}

void hero(char *a,struct Superhero **supers){
    printf("%s\n",a); //imprime el superheroe que buscamos
    for (int i=0;i<6;i++){
        qsort(supers,15,sizeof(superhero*),comparar[i]); //ordena en base a la lista de comparacion por poder
        for(int x = 0;x<15;x++){
            if(strcmp(supers[x]->name, a)==0){ 
                printf("\t%s: %d Posicion: %d\n", poderes[i],habilidades(x,i,supers),x+1);
            }
        }
    }
}

void topvalue(int value,char *habilidad,struct Superhero **supers){
    int m;
    for(int x=0;x<6;x++){
        if(strcmp(poderes[x],habilidad) ==0){
            m=x; //guarda el indice de cual es el poder que pidieron
        }
    }
    qsort(supers,15,sizeof(superhero*),comparar[m]);
    for(int x=0;x<15;x++){
        int habilidad = habilidades(x,m,supers);
        if((habilidad) == value){//si el poder, de la posicion m es igual al valor que pidieron evaluar entonces...
            printf("\n");
            for(int i=0;i<2;i++){
                printf("\t%s: %d\n",supers[x+i]->name,habilidades(x+i,m,supers));
            }
            break;
        }
    }
    char *c = malloc(sizeof(char));
    printf("De que supeheroe desea ver su informacion? ");
    scanf("%[^\n]",c);
    hero(c, supers);
}

void tophero(char *habilidad, char *nombre, struct Superhero **supers){
    
}

int main(){
    srand(time(NULL));
    // superhero **super = malloc(30*sizeof(superhero));
    // for (int i=0; i<30; i++){
    //     super[i] = malloc(sizeof(superhero));
    //     super[i]-> name = malloc(sizeof(char));
        // super[i]-> full_name = malloc(sizeof(char));
        // super[i]-> alter_ego = malloc(sizeof(char));
        // super[i]-> aliases = malloc(sizeof(char));
        // super[i]-> place_of_birth = malloc(sizeof(char));
        // super[i]-> first_appearance = malloc(sizeof(char));
        // super[i]-> publisher = malloc(sizeof(char));
        // super[i]-> alignment = malloc(sizeof(char));
        // super[i]-> gender = malloc(sizeof(char));
        // super[i]-> race = malloc(sizeof(char));
        // super[i]-> height_1 = malloc(sizeof(char));
        // super[i]-> height_2 = malloc(sizeof(char));
        // super[i]-> weight_1 = malloc(sizeof(char));
        // super[i]-> weight_2 = malloc(sizeof(char));
        // super[i]-> eye_color = malloc(sizeof(char));
        // super[i]-> hair_color = malloc(sizeof(char));
        // super[i]-> work_occupation = malloc(sizeof(char));
        // super[i]-> work_base = malloc(sizeof(char));
        // super[i]-> connections_group = malloc(sizeof(char));
        // super[i]-> connections_relatives = malloc(sizeof(char));
    // }
    // for(int i = 0;i<30;i++){
    //     super[i] ->id = i;
    //     strcpy(super[i] ->name,"name");
    //     super[i] ->intelligence = i*2;
    //     super[i] ->strength = i*3;
    //     super[i] ->speed = i*4;
    //     super[i] ->durability = i*5;
    //     super[i] ->power = i*6;
    //     super[i] ->combat = i*7;
    //     strcpy(super[i] ->full_name,"full name");
    //     // strcpy(super[i] ->alter_ego,"alter ego");
    //     strcpy(super[i] ->aliases,"aliases");
    //     strcpy(super[i] ->place_of_birth,"place of birth");
    //     strcpy(super[i] ->first_appearance,"first appearance");
    //     strcpy(super[i] ->publisher,"publisher");
    //     strcpy(super[i] ->alignment,"alignment");
    //     strcpy(super[i] ->gender,"gender");
    //     strcpy(super[i] ->race,"race");
    //     strcpy(super[i] ->height_1,"height_1");
    //     strcpy(super[i] ->height_2,"height_2");
    //     strcpy(super[i] ->weight_1,"weight_1");
    //     strcpy(super[i] ->weight_2,"weight_2");
    //     strcpy(super[i] ->eye_color,"eye_color");
    //     strcpy(super[i] ->hair_color,"hair_color");
    //     strcpy(super[i] ->work_occupation,"work_occupation");
    //     strcpy(super[i] ->work_base,"work_base");
    //     strcpy(super[i] ->connections_group,"connections_group");
    //     strcpy(super[i] ->connections_relatives,"connections_relatives");
    // }

    superhero **super = malloc(732*sizeof(superhero)); //lista de supeheroes

    for (int i=0; i<15; i++){ // por cada superheroe hay que asignarle espacio a las variables
        super[i] = malloc(sizeof(superhero));
        super[i]-> name = malloc(sizeof(char));
    }
    for(int i = 0;i<15;i++){
        super[i] ->id = i;
        super[i] ->intelligence = rand() % 15;
        super[i] ->strength = rand() % 15;
        super[i] ->speed =rand() % 15;
        super[i] ->durability = rand() % 15;
        super[i] ->power = rand() % 15;
        super[i] ->combat = rand() % 15;
    }
    strcpy(super[0] ->name, "cata");
    strcpy(super[1] ->name, "cata 1");
    strcpy(super[2] ->name, "cata2");
    strcpy(super[3] ->name, "cata3");
    strcpy(super[4] ->name, "cata4");

    // for(int i = 0;i<6;i++){
    //     printf("%d\n",comparar[i]);
    // }
    char *a = "cata 1";
    hero(a,super);
    topvalue((super[0]->power),"power",super);

    // for (int i=0;i<6;i++){
    //     printf("%d %d %d %d %d %s\n",super[i] ->id,super[i] ->strength,super[i] ->speed,super[i] ->durability,super[i] ->power,super[i]->name);
    // }
    // for(int i =0;i<5;i++){
    //     printf("id = %d inte = %s\n", super[i]->id,super[i]->name);
    // }

    // qsort(super,30,sizeof(superhero*),cInteligence);

    // for(int i =0;i<30;i++){
    //     printf("id = %d inte = %d\n", super[i]->id,super[i]->intelligence);
    // }

    for(int i = 0; i<30; i++){
        free(super[i]); //libera la memoria de cada struct
    }
    free(super); //libera la memoria de la lista de structs

    return 0;
}


/*
id(int); name(char*); intelligence(int); strength(int); speed(int); durability(int);
power(int); combat(int); full-name(char*); alter-egos(char*); aliases__001(char*);
place-of-birth(char*); first-appearance(char*); publisher(char*); alignment(char*);
gender(char*); race(char*); height__001(char*); height__002(char*); weight__001(char*);
weight__002(char*); eye-color(char*); hair-color(char*); work__occupation(char*);
work__base(char*); connections__group-affiliation(char*); connections__relatives(char*)
*/