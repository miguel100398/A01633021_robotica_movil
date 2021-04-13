#ifndef MENU_C
#define MENU_C

#include "menu.h"

void print_dataSetMessage(){
    printf("----------------------------This application helps in contact tracing to monitor Covid-19 spread------------------\n");
    printf("-------It displays contact database of the population and determines if any two persons have been in contact------\n");
    printf("Select the population data set\n");
    printf("Enter 1 for Durhan region\n");
    printf("Enter 2 for Peel region\n");
    printf("Enter 3 for York region\n");
    printf("Enter 4 or higher integer for Greater Toronto Area\n");
}

int get_region(int* region){
    scanf("%d", region);
    if (*region == 0){
        printf("Exit program\n");
        return 0;
    }
    return 1;
}

int get_peopleTracked(int* len){
    printf("Enter total number of people to be traced/tracked (it must be an integer between 2 to 1000 or enter '0' to end\n");
    scanf("%d", len);
    if (*len == 0){
        printf("Exit program\n");
        return 0;
    }
    if ((*len<2) || (*len>1000)){
        printf("Invalid total number of people, exit program\n");
        return 0;
    }
    return 1;
}

void print_queryMessage(){
    printf("---------Query for contact tracing between two individuals:---------\n");
}

int get_sourcePerson(int* src, int len){
    printf("Enter source person's ID (1 to %0d)\n", len);
    scanf("%d", src);
    if ((*src<1) || (*src>len)){
        printf("Invalid source ID %0d, exit program\n", *src);
        return 0;
    }
    return 1;
}

int get_targetPerson(int* target, int src, int len){
    printf("Enter target person's ID (1 to %0d excluding %0d) or 0 to change the population data set\n", len, src);
    scanf("%d", target);
    if (*target==0){
        return 1;
    }
    if ((*target<1) || (*target>len) || (*target==src)){
        printf("Invalid target ID %0d, exit program\n", *target);
        return 0;
    }
    return 2;
}

void print_contactTrace(Graph graph, int src, int target){
    printf("Contact trace from person ID %0d to person ID %0d\n", src, target);
    //Calculate distances
    Dijkstra(graph, src, 0);
    followPath(graph, target);
    printf("\n");
}

int get_nextQuery(){
    int query;
    printf("Next query:\n");
    printf("Enter 1 to check for another pair of persons or 2 to change population data set or 0 to exit\n");
    scanf("%d", &query);
    if (query==0){
        printf("Exit program\n");
        return 0;
    } else if (query==1){
        return 1;
    } else if (query==2){
        return 2;
    } else{
        printf("Invalid input, Exit program \n");
        return 0;
    }
}

#endif //MENU_C