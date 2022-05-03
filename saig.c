#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE * data_sh;
int size_fil = 0;

//DATA

struct data_heroes_st
{
    int * id;
    char ** name;
    int * intelligence;
    int * strength;
    int * speed;
    int * durability;
    int * power;
    int * combat;
};

struct data_heroes_st sh_data;

//TOOLS

void clean()
{
    int i;
    for(i=0; i<50; ++i)
    {
        printf("\n");
    }
}

void check_size()
{
    char c;
    while (!feof(data_sh))
    {
        c = fgetc(data_sh);
        if( c == '\n') size_fil += 1;
    }
    rewind(data_sh);
}

int * id_sort(int * position, int * values, int size) //we used https://www.javatpoint.com/c-program-to-sort-the-elements-of-an-array-in-ascending-order
{
    int i;
    int j;
    int temp_id = 0;
    int temp_value = 0;

    int * id_list = (int *) calloc(size, sizeof(int));
    int * value_list = (int *) calloc(size, sizeof(int));

    for(i=0; i<size; i++)
    {
        *(id_list+i) =  *(position+i);
        *(value_list+i) = *(values+i);
    }

    for(i = 0; i < size; i++)
    {
        for(j=i+1; j < size; j++)
        {
            if(*(value_list+i)>*(value_list+j))
            {
                temp_value = *(value_list+i);
                temp_id = *(id_list+i);

                *(value_list+i) = *(value_list+j);
                *(id_list+i) = *(id_list+j);

                *(value_list+j) = temp_value;
                *(id_list+j) = temp_id;
            }
        }
    }

    return id_list;
}

int * inverse_list(int * original_list, int size)
{
    int * inversed_list = (int *) calloc(size, sizeof(int));
    int i;
    int j = 0;

    for(i=size-1; i>=0; i--)
    {
        *(inversed_list + j) = *(original_list + i);
        j += 1;
    }
    free(original_list);
    return inversed_list;
}

char * data_solicitude(char ** data_ori, int data_num, int start_value)
{
    char * data_sol = (char *) calloc(100, sizeof(char));
    int i;

    strcpy(data_sol, data_ori[start_value-1]);
    
    for(i=start_value; i<data_num; i++)
    {
        strcat(data_sol, " ");
        strcat(data_sol, data_ori[i]);
    }
    return data_sol;
}

//FUNCTIONS FILE

void open()
{
    if(data_sh == NULL)
    {
        data_sh = fopen("data.txt", "r");
    }
    check_size();
}

void close()
{
    if(data_sh != NULL)
    {
        fclose(data_sh);
    }
}

//DEFINE DATA

int * get_value(int separate_solicitude, int size)
{
    
    int * list_values = (int *) calloc(size, sizeof(int));
    
    char * values = (char *) calloc(100, sizeof(char));
    
    char * c;
    c = (char *) calloc(5, sizeof(char));
    memset(c, 0, sizeof(char)); 

    int check_separate = 0;

    int num_value;

    int ite = 0;
    
    while (!feof(data_sh))
    {
        *c = fgetc(data_sh);
        //printf("%c", *c);
        if (*c == ';') 
        {
            check_separate += 1;
        }
        else if (*c == '\n') 
        {
            num_value = atoi(values);
            *(list_values + ite) = num_value;
            ite += 1;
            //printf("%d\n", num_value);
            check_separate = 0;
            memset(values, 0, 100*sizeof(char));
            
            
        }
        else if (check_separate == separate_solicitude && *c != '\"') 
        { 
            
            strcat(values, c);
        }
        
    }
    free(c);
    free(values);

    rewind(data_sh);
    return list_values;
    
}

char ** get_string(int separate_solicitude, int size)
{
    
    char ** list_names;
    list_names = malloc(size*sizeof(char*)); 
    for(int i=0; i<size; i++) list_names[i] = malloc(sizeof(char)*100);
    
    char * values = (char *) calloc(100, sizeof(char));
    
    char * c;
    c = (char *) calloc(5, sizeof(char));
    memset(c, 0, sizeof(char)); 

    int check_separate = 0;

    int ite = 0;
    
    while (!feof(data_sh))
    {
        *c = fgetc(data_sh);
        //printf("%c", *c);
        if (*c == ';') 
        {
            check_separate += 1;
        }
        else if (*c == '\n') 
        {
            strcpy(list_names[ite], values);
            ite += 1;
            //printf("%s\n", values);
            check_separate = 0;
            memset(values, 0, 100*sizeof(char));
            
            
        }
        else if (check_separate == separate_solicitude && *c != '\"') 
        { 
            
            strcat(values, c);
        }
        
    }
    free(c);
    free(values);

    rewind(data_sh);
    return list_names;
    
}

//if i want make variable for all datas is possible, I only need make more variables in original struct and define below here with the early functions. 
//That´s Inefficient because the programn need only first 8 values.
void define_data() 
{
    open();
    sh_data.id = get_value(0, size_fil);
    sh_data.name = get_string(1, size_fil);
    sh_data.intelligence = get_value(2, size_fil);
    sh_data.strength = get_value(3, size_fil);
    sh_data.speed = get_value(4, size_fil);
    sh_data.durability = get_value(5, size_fil);
    sh_data.power = get_value(6, size_fil);
    sh_data.combat = get_value(7, size_fil);
    close();
}

//AUX FUNCTION

int * type_caract_list(char * type_sol)
{
    int * return_false = (int *) calloc(1, sizeof(int));
    * return_false = 1;
    
    if(strcmp(type_sol, "intelligence") == 0) return sh_data.intelligence;
    else if(strcmp(type_sol, "strength")== 0) return sh_data.strength;
    else if(strcmp(type_sol, "speed")== 0) return sh_data.speed;
    else if(strcmp(type_sol, "durability")== 0) return sh_data.durability;
    else if(strcmp(type_sol, "power")== 0) return sh_data.power;
    else if(strcmp(type_sol, "combat")== 0) return sh_data.combat;
    return return_false;
}

int pos_heroe(char * name_heroe, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(strcmp(name_heroe, sh_data.name[i]) == 0) return (i+1);
    }
    return 0;
}

int rank_heroe(int id, char * caract_sol, int size)
{   
    int i;
    
    int * list_caract_sol = type_caract_list(caract_sol);

    int * id_sort_caract = id_sort(sh_data.id, list_caract_sol, size);
    id_sort_caract = inverse_list(id_sort_caract, size);

    for (i=0;i<size;i++)
    {
        //printf("%d,  %d\n", id_sort_caract[i], list_caract_sol[id_sort_caract[i]-1]);
        if (id == id_sort_caract[i])
        {
            return (i+1);
        }
    }
    return 0;
}

//FUNCTION PROGRAM

void topvalue()
{
    //code
}

void heroe(char * name_hero, int size)
{
    clean();
    int id_heroe = pos_heroe(name_hero, size);
    int pos_id = id_heroe-1;
    int rank_value;
    int value_caract;
    printf("id: %d || %s:\n\n",id_heroe, name_hero);

    rank_value = rank_heroe(id_heroe, "durability", size);
    value_caract = sh_data.durability[pos_id];
    printf("\t durability: \t%d  \tposicion: %d \n", value_caract,rank_value);

    rank_value = rank_heroe(id_heroe, "power", size);
    value_caract = sh_data.power[pos_id];
    printf("\t power: \t%d  \tposicion: %d \n", value_caract,rank_value);

    rank_value = rank_heroe(id_heroe, "strength", size);
    value_caract = sh_data.strength[pos_id];
    printf("\t strength: \t%d  \tposicion: %d \n", value_caract,rank_value);

    rank_value = rank_heroe(id_heroe, "speed", size);
    value_caract = sh_data.speed[pos_id];
    printf("\t speed: \t%d  \tposicion: %d \n", value_caract,rank_value);

    rank_value = rank_heroe(id_heroe, "combat", size);
    value_caract = sh_data.combat[pos_id];
    printf("\t combat: \t%d  \tposicion: %d \n", value_caract,rank_value);

    rank_value = rank_heroe(id_heroe, "intelligence", size);
    value_caract = sh_data.intelligence[pos_id];
    printf("\t intelligence: \t%d  \tposicion: %d \n", value_caract,rank_value);

}

void tophero(char * name_hero, char * caract_sol, int size)
{
    int id_heroe = pos_heroe(name_hero, size);
    int i;
    int count = 1;

    int start_add = 0;
    int user_select;

    int * list_caract_sol = type_caract_list(caract_sol);

    int * id_sort_caract = id_sort(sh_data.id, list_caract_sol, size);

    int * best_heroes = (int *) calloc(10, sizeof(int));

    best_heroes[0] = id_heroe;
    for (i=0;i<size;i++)
    {
        
        if(list_caract_sol[id_sort_caract[i]-1] > list_caract_sol[id_heroe-1]) start_add = 1;
        if(start_add == 1) 
        {
        best_heroes[count] = id_sort_caract[i];
        count += 1;
        }
        if (count == 11) break;
        
    }
    
    printf("%s:%d\n", name_hero, list_caract_sol[best_heroes[0]-1]);
    
    for (i=1;i<count;i++)
    {
        printf("\t%d) %s: %d\n", i, sh_data.name[best_heroes[i]-1] ,list_caract_sol[best_heroes[i]-1]);
    }

    printf("Seleccione Heroe: ");
    scanf("%d", &user_select);
    int id_heroe_sel = best_heroes[user_select];
    printf("%s", sh_data.name[id_heroe_sel-1]);

}

//STADIN METHOD

void stadin()
{
    char * caract_sol = (char *)calloc(100, sizeof(char));
    char * elemen_sol = (char *)calloc(100, sizeof(char));
    int value_sol;
    int user_select;
    char enter;
    define_data();
    memset(caract_sol, 0, 100*sizeof(char));
    memset(elemen_sol, 0, 100*sizeof(char));
    printf("Seleccione una opcion \n");
    printf("1) -tophero \n");
    printf("2) -topvalue \n");
    printf("3) -hero \n");
    printf("4) -exit\n> ");
    scanf("%d", &user_select);
    switch (user_select)
    {
        case 1:
            clean();
            printf("Coloque el rasgo que esta buscando, seguido del superheroe (ej. power Black Cat): ");
            scanf("%s ", caract_sol);
            scanf(" %[^\n]%*c", elemen_sol);
            if (*(type_caract_list(caract_sol)) == 1 || pos_heroe(elemen_sol, size_fil) == 0)
            {
                printf("Informacion Erronea");
            }
            else 
            {
            tophero(elemen_sol, caract_sol, size_fil);
            printf("\nde enter para continuar");
            scanf("%c", &enter);
            }
            break;

        case 2:
            clean();
            printf("Coloque el rasgo que esta buscando (power, combat, etc): ");
            scanf("%s", caract_sol);
            printf("Coloque el valor que desea analizar: ");
            scanf("%d", &value_sol);
            //printf("%s, %d", caract_sol, value_sol);
            if (*(type_caract_list(caract_sol)) == 1 || value_sol > 101 || value_sol < (-1))
            {
                printf("Informacion Erronea");
            }
            else 
            {
            printf("Funcion");
            printf("\n");
            }
            break;

        case 3:
            clean();
            printf("Coloque el super heroe que desea analizar: ");
            scanf(" %[^\n]%*c", elemen_sol);
            if (pos_heroe(elemen_sol, size_fil) == 0)
            {
                clean();
                printf("Heroe no encontrado");
                printf("\nde enter para continuar");
                scanf("%c", &enter);
            }
            else heroe(elemen_sol, size_fil);
            printf("\nde enter para continuar");
            scanf("%c", &enter);
            break;
        case 4:
            printf("Gracias por usar este programa");
            break;
        
        default:
            clean();
            printf("Opcion no existente \n");
            break;
        }
    free(caract_sol);
    free(elemen_sol);

}

int main(int argc, char **argv)
{    
    if (argc == 1) stadin();
    else if (argc > 1)
    {   
        define_data();
        //
        //-terminal
        if (strcmp(argv[1], "-terminal") == 0 && argc > 1)
        {
            printf("Modo Terminal");
            
        }
        //
        //-tophero
        else if (strcmp(argv[1], "-tophero") == 0 && argc > 3)
        {
            char * caract_sol = argv[2];
            char * tophero_sol = data_solicitude(argv, argc,4);
            if (*(type_caract_list(caract_sol)) == 1 || pos_heroe(tophero_sol, size_fil) == 0)
            {
                clean();
                printf("Informacion Erronea");
            }
            else 
            {
            tophero(tophero_sol, caract_sol, size_fil);
            printf("\n");
            }
            free(caract_sol);
            free(tophero_sol);
        }
        //
        //-topvalue
        else if (strcmp(argv[1], "-topvalue") == 0 && argc > 2)
        {
            char * caract_sol = argv[2];
            char * topvalue = argv[3];
            int topvalue_sol = atoi(topvalue);
            if (*(type_caract_list(caract_sol)) == 1 || topvalue_sol > 101 || topvalue_sol < (-1))
            {
                clean();
                printf("Informacion Erronea");
            }
            else 
            {
            printf("Funcion");
            printf("\n");
            }
            free(topvalue);
        }
        //
        //-topvalue
        else if (strcmp(argv[1], "-hero") == 0 && argc > 2)
        {
            char * hero_sol = data_solicitude(argv, argc,3);
            if (pos_heroe(hero_sol, size_fil) == 0)
            {
                clean();
                printf("Heroe no encontrado");
            }
            else 
            {
            heroe(hero_sol, size_fil);
            printf("\n");
            }
            free(hero_sol);
        }
        //
        //-exit
        else if (strcmp(argv[1], "-exit") == 0 && argc > 1)
        {
            printf("Gracias por usar este programa");
        }
        else 
        {
        clean();
        printf("Comando no reconocido");
        }
    }
    return 0;
} 


/* int main()
{
    define_data();
    tophero("Black Cat", "power", size_fil);
    printf("%d", heroe_id);
    return 0;
} */


/* int main()
{
    int i;
    int id;
    define_data();
    
    //int * values_power = type_caract_list("power");

    //int * sort_intelligence;
    //sort_intelligence = id_sort(sh_data.id, sh_data.intelligence, size_fil);
    //sort_intelligence = inverse_list(sort_intelligence, size_fil);
    //printf("%d\n", size_fil);
    
    for(i=0;i<size_fil; i++)
    {
        printf("%d\n",  sh_data.power[i]);
        //printf("%d, ", sort_intelligence[i]);
        //id = (sort_intelligence[i] - 1);
        //printf("%d\n", sh_data.intelligence[id]);
    }
    
    return 0;
} */

/* int main()
{
    int i;
    define_data();
    //heroe("A-Bomb", size_fil);
    //int * data = type_caract_list("combat");

    //for(i=0;i<size_fil;i++) printf("%d\n", data[i]);
    //int rank_value = rank_heroe(1, "combat", size_fil);

    //printf("%d", rank_value);
    //int pos_test = id_heroe("Adam Strange", size_fil);
    heroe("Black Cat", size_fil);
    //printf("%d", pos_test);
} */