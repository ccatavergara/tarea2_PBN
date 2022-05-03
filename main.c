#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    char *c = malloc(10*sizeof(char));
    printf("\nDe que supeheroe desea ver su informacion? ");
    scanf("%[^\n]",c); //permite guardar todo el nombre del superheroe
    hero(c, supers,contador); //hace la funcion hero para encontrar el superheroe de la lista
    free(c); //libera la memoria
}

void tophero(char*name, char *habilidad, struct Superhero **supers,int contador){
    int m;
    for(int x=0;x<6;x++){
        if(strcmp(poderes[x],habilidad) ==0){
            m=x; //guarda el indice de cual es el poder que pidieron
        }
    }
    qsort(supers,contador,sizeof(superhero*),comparar[m]); //ordena en base al poder que pidieron
    
    for (int x = 0; x<contador;x++){
        if(strcmp(supers[x]->name,name)==0){
            //imprime el primer superheroe con ese valor
            printf("\n%s: %d\n",supers[x]->name,habilidades(x,m,supers));
            for(int i = 1;i<10;i++){
                printf("\t%d) %s: %d\n",i,supers[x-i]->name,habilidades(x-i,m,supers));
            }
        }
    }
    char *c = malloc(10*sizeof(char));
    printf("\nDe que supeheroe desea ver su informacion? ");
    scanf("%[^\n]",c);
    hero(c, supers,contador);
    free(c);
}


int main(int argc, char **argv){
    FILE * file = fopen("data.txt","r");
    char *var;
    char *linea = malloc(100*sizeof(char));
    char **datos = malloc(7*732*sizeof(char*)); //una lista de las cada datos
    for(int i = 0;i<7*732;i++){
        datos[i] = malloc(10*sizeof(char)); //agregarle espacio a cada item de la lista
    }

    if (file == NULL) // como el file tiene una direccion especifica, se cae si es que esta mal puesta.
    {
    printf("No existe el archivo!\nColoque el nombre del archivo correcto.\n");
    exit(1);
    }
    int i = 0;
    int contador = 0;
    while(fgets(linea,2100,file)){
        var = strtok(linea,";"); //corta la primera parte del codigo
        datos[i] = strdup(var); // agrega var como string a datos
        for(int j=0;j<7;j++){
            var = strtok(NULL,";"); //despues cada strtok tiene un NULL para separa con ;
            datos[i+j] = strdup(var); //hace un ciclo de 7 entonces todo queda junto
            //solo se guardaran el nombre y las habilidades de los superheroes
        }
        i+=7;
        contador++; //cuenta cuantas lineas hay
    }

    superhero **super = malloc(contador*sizeof(superhero)); //lista de supeheroes con el espacio de la cantidad de lineas del archivo

    for (int i=0; i<contador; i++){ // por cada superheroe hay que asignarle espacio a las variables
        super[i] = malloc(sizeof(superhero));
        super[i]-> name = malloc(sizeof(char));
    }
    int l = 0;
    for(int j =0;j<contador*7;j+=7){ //dentro de un ciclo de 7 se agregan los datos de la lista
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

    if(argc == 1){ //se hace el codigo por stdin
        printf("Iniciaste la consola por stdin.");
    //     estandar(); //aca iria el STDIN
    }
    if(argc == 2){ //funciona por argv y argc
        if (strcmp(argv[1],"-terminal") == 0){
            printf("Iniciaste la consola por terminal.");
        }
        if (strcmp(argv[1],"salir") == 0){
            printf("Termino la revision de datos."); //corta la revision de datos
            exit(1); 
        }
    }
    if(argc == 3){
        if (strcmp(argv[1],"-hero") == 0){ //busca al heroe por su nombre cuando tiene solo un nombre
            hero(argv[2],super,contador);
        }
    }
    if(argc == 4){
        if (strcmp(argv[1],"-hero") == 0){
            char *name = malloc(10*sizeof(char));
            strcat(name,argv[2]);
            for(int i = 3;i<4;i++){ //permite guardar el nombre compuesto
                strcat(name," ");
                strcat(name,argv[i]);
            }
            hero(name,super,contador);
            free(name); //libera la memoria del nombre
        }
        if (strcmp(argv[1],"-topvalue") == 0){ //topvalue solo sirve cuando argc==4
            topvalue(atoi(argv[3]),argv[2],super,contador);
        }
        if (strcmp(argv[1],"-tophero") == 0){ //tophero necesita minimo 3 caracteristicas del argv
            tophero(argv[3],argv[2],super,contador);
        }
    }
    if(argc==5){
        if (strcmp(argv[1],"-hero") == 0){
            char *name1 = malloc(10*sizeof(char));
            strcat(name1,argv[2]);
            for(int i = 3;i<5;i++){ //3 nombres compuestos
                strcat(name1," ");
                strcat(name1,argv[i]);
            }
            hero(name1,super,contador);
            free(name1);
        }
        if(strcmp(argv[1],"-tophero") == 0){
            char *name = malloc(10*sizeof(char));
            strcat(name,argv[3]);
            for(int i = 4;i<5;i++){
                strcat(name," ");
                strcat(name,argv[i]);
            }
            tophero(name,argv[2],super,contador);
            free(name);
        }
    }
    if(argc>5){
        if(strcmp(argv[1],"-tophero") == 0){
            char *name = malloc(10*sizeof(char));
            strcat(name,argv[3]);
            for(int i = 4;i<6;i++){
                strcat(name," ");
                strcat(name,argv[i]);
            }
            tophero(name,argv[2],super,contador);
            free(name);
        }
    }
    for(int i = 0;i<7*contador;i++){
        free(datos[i]); 
    }
    for(int i = 0;i<contador;i++){
        free(super[i]);
    }
    free(linea);
    fclose(file);
    return 0; //hay que liberar todos los datos entregados.
} 
