#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Superhero{ //struct con typedef superhero
    int id;
    char *name;
    int intelligence;
    int strength;
    int speed;
    int durability;
    int power;
    int combat;
}superhero;

//son las funciones de comparacion para las distintas 
int cInteligence(const void * a, const void * b) {
    superhero **m = (superhero **)a;
    superhero **n = (superhero **)b;
    return ((*n)->intelligence - (*m)->intelligence);
}
int cStrength(const void * a, const void * b) {
    superhero **m = (superhero **)a;
    superhero **n = (superhero **)b;
    return ((*n)->strength - (*m)->strength);
}
int cSpeed(const void * a, const void * b) {
    superhero **m = (superhero **)a;
    superhero **n = (superhero **)b;
    return ((*n)->speed - (*m)->speed);
}
int cDurability(const void * a, const void * b) {
    superhero **m = (superhero **)a;
    superhero **n = (superhero **)b;
    return ((*n)->durability - (*m)->durability);
}
int cPower(const void * a, const void * b) {
    superhero **m = (superhero **)a;
    superhero **n = (superhero **)b;
    return ((*n)->power - (*m)->power);
}
int cCombat(const void * a, const void * b) {
    superhero **m = (superhero **)a;
    superhero **n = (superhero **)b;
    return ((*n)->combat - (*m)->combat);
}

int (*comparar[])(const void*, const void*) = {cInteligence,cStrength,cSpeed,cDurability,cPower,cCombat}; //lista que guarda todas las funciones de comparacion.

char *poderes[] = {"intelligence","strength","speed","durability","power","combat"}; //lista que guarda todos los nombres de poderes.

int habilidades(int h, int habilidad, struct Superhero **supers){
    int poder[]= {supers[h]->intelligence,supers[h]->strength,supers[h]->speed,supers[h]->durability,supers[h]->power,supers[h]->combat};
    return poder[habilidad]; //una funcion que crea todas las habilidades predeterminadas y las busca por indice.
}

void hero(char *name,struct Superhero **supers,int contador){
    printf("\n%s:\n",name); //imprime el superheroe que buscamos
    for (int i=0;i<6;i++){
        qsort(supers,contador,sizeof(superhero*),comparar[i]); //ordena en base a la lista de comparacion por poder
        for(int x = 0;x<contador;x++){
            if(strcmp(supers[x]->name, name)==0){ //si encuentra el superheroe, imprime sus datos
                printf("\t%s: %d Posicion: %d\n", poderes[i],habilidades(x,i,supers),x+1);
            }
        }
    }
}

void topvalue(int value,char *habilidad,struct Superhero **supers,int contador){
    int m;
    for(int x=0;x<6;x++){
        if(strcmp(poderes[x],habilidad) ==0){
            m=x; //guarda el indice de cual es el poder que pidieron
        }
    }
    qsort(supers,contador,sizeof(superhero*),comparar[m]); //ordena la lista en base a la habilidad que pedian
    
    for(int x=0;x<contador;x++){
        int habilidad = habilidades(x,m,supers); //contador es posicion heroe, m es posicion de la habilidad, supers es struct
        if((habilidad) == value){//si el poder, de la posicion m es igual al valor que pidieron evaluar entonces...
            printf("\n");
            for(int i=0;i<10;i++){ //por 10 puestos, va a imprimir el nombre y el poder
                printf("\t%s: %d\n",supers[x-i]->name,habilidades(x-i,m,supers));
            }
            break;
        }
    }
    char *c = malloc(sizeof(char));
    printf("De que supeheroe desea ver su informacion? ");
    scanf("%[^\n]",c);
    hero(c, supers,contador);
}

void tophero(char*name, char *habilidad, struct Superhero **supers,int contador){
    int m;
    for(int x=0;x<6;x++){
        if(strcmp(poderes[x],habilidad) ==0){
            m=x; //guarda el indice de cual es el poder que pidieron
        }
    }
    qsort(supers,contador,sizeof(superhero*),comparar[m]);
    for (int x = 0; x<contador;x++){
        if(strcmp(supers[x]->name,name)==0){
            printf("\n%s: %d\n",supers[x]->name,habilidades(x,m,supers));
            for(int i = 1;i<10;i++){
                printf("\t%d) %s: %d\n",i,supers[x-i]->name,habilidades(x-i,m,supers));
            }
            break;
        }
    }
    char *c = malloc(sizeof(char));
    printf("De que supeheroe desea ver su informacion? ");
    scanf("%[^\n]",c);
    hero(c, supers,contador);
}

int main(){
    FILE * file = fopen("data.txt","r");
    char *var;
    char *linea = malloc(10*sizeof(char));
    char **datos = malloc(7*732*sizeof(char*));
    for(int i = 0;i<7*732;i++){
        datos[i] = malloc(10*sizeof(char));
    }
    
    int i = 0;
    if (file == NULL)
    {
    printf("No existe el fichero!\n");
    exit(1);
    }
    int contador = 0;
    while(fgets(linea,2100,file)){
        var = strtok(linea,";");
        datos[i] = strdup(var);
        for(int j=0;j<7;j++){
            var = strtok(NULL,";");
            datos[i+j] = strdup(var);
        }
        i+=7;
        contador++;
    }

    superhero **super = malloc(contador*sizeof(superhero)); //lista de supeheroes

    for (int i=0; i<contador; i++){ // por cada superheroe hay que asignarle espacio a las variables
        super[i] = malloc(sizeof(superhero));
        super[i]-> name = malloc(sizeof(char));
    }
    int l = 0;
    for(int j =0;j<contador*7;j+=7){
        super[l] ->id = i;
        super[l] ->name = datos[j];
        super[l] ->intelligence = atoi(datos[j+1]);
        super[l] ->strength = atoi(datos[j+2]);
        super[l] ->speed =atoi(datos[j+3]);
        super[l] ->durability = atoi(datos[j+4]);
        super[l] ->power = atoi(datos[j+5]);
        super[l] ->combat = atoi(datos[j+6]);
        l++;
    }


    for(int i = 0; i<contador;i++){
        printf("%s\n",super[i]->name);
    }
    
    qsort(super,contador,sizeof(superhero*),comparar[5]);
    for(int i = 0; i<10;i++){
        printf("%d %d\n",i,super[i]->combat);
    }


    for(int i = 0;i<7*contador;i++){
        free(datos[i]);
    }
    for(int i = 0;i<contador;i++){
        free(super[i]);
    }
    free(linea);
    fclose(file);
    return 0;
}