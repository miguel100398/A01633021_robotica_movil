#ifndef RANDOM_DIJKSTRA_C
#define RANDOM_DIJKSTRA_C

#include <stdio.h>
#include "dijkstra.h"
#include <stdlib.h>
#include "randomGraph.h"
#include <time.h>
#include "menu.h"

int main(){
    int len;        //Len of Graph
    int region;
    int exit;
    int exit_query;
    int source_person;
    int target_person;
    int return_query;
    VertexInt* vertices;
    Graph newGraph(int);
    Graph graph;
    exit = 0;
    //Random seed
    srand(time(NULL));
    while (!exit){
        exit_query = 0;
        //Print initial message
        print_dataSetMessage();
        //Wait for region
        if (!get_region(&region)){
            exit = 1;
            exit_query = 1;
        }
        //Wait for len
        if (!get_peopleTracked(&len)){
            exit = 1;
            exit_query = 1;
        }
        //Create vertices
        vertices = genVertices(len);
        //Randomize vertices
        prepareGraph(vertices, len);
        //Create graph
        graph = newGraph(len);
        //Build graph
        buildGraphRandom(vertices, graph);
        //Print vertices
        printIntGraph(vertices, len, region);
        while (!exit_query){
            print_queryMessage();
            if (!get_sourcePerson(&source_person, len)){        
                exit_query = 1;     //Exit program
                exit = 1;
                break;
            }
            return_query = get_targetPerson(&target_person, source_person, len);
            if (!return_query){
                exit_query = 1;     //Exit program
                exit = 1;
                break;
            } else if (return_query==1){
                exit_query = 1;     //Return to data set
                break;
            }
            print_contactTrace(graph, source_person, target_person);
            return_query = get_nextQuery();
            if (!return_query){
                //Exit program
                exit_query = 1;
                exit = 1;
                break;
            } else if (return_query==2){
                //Change data set
                exit_query = 1;
                break;
            }

        }
        //Delete vertices
        deleteVertices(vertices);
    }
    printf("Finish program\n");
    return 0;

}

#endif //RANDOM_DIJKSTRA_C