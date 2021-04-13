#ifndef RANDOMGRAPHGENERATOR3_RANDOMGRAPHGENERATOR_C
#define RANDOMGRAPHGENERATOR3_RANDOMGRAPHGENERATOR_C

#include "randomGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


VertexInt* genVertices(int len){
    if (len == 0) {
        len = rand()%(MAX_LEN-MIN_LEN+1) + MIN_LEN;  //Random number between MAX_LEN and MIN_LEN
    }
    //Declare VertexInt
    VertexInt* vertices = (VertexInt *) malloc((len+1)*sizeof(VertexInt));
    return vertices;
}

void deleteVertices(VertexInt *vertices){
    free(vertices);
}

//Vertices should be declared outside the function
void prepareGraph(VertexInt *vertices, int len){
    //Check len is inside bounds
    if ((len>MAX_LEN) || (len<MIN_LEN)){
        printf("Len: %0d is out of bounds Max: %0d Min: %0d", len, MAX_LEN, MIN_LEN);
        return;
    }
    //Check Vertices is not null
    if (vertices == NULL){
        printf("Vertices is NULL \n");
        return;
    }
    //Generate random vertices with random edges
    for (int i =1; i<=len; i++){
        vertices[i].id = i;       //Start with person 1
        vertices[i].numOfoutEdges = rand()%(MAX_NUM_EDGES-MIN_NUM_EDGES+1) + MIN_NUM_EDGES;  //Random number between MAX_NUM_EDGES and MIN_NUM_EDGES
        for (int j=1; j<=vertices[i].numOfoutEdges; j++){
            vertices[i].outEdges[j].idSrc  = vertices[i].id;
            vertices[i].outEdges[j].idDes  = (rand()%(len))+1;
            vertices[i].outEdges[j].weight = 1;
        }
    }
}

void buildGraphRandom(VertexInt vertices[], Graph G){
    //Check Graph is created
    char str_id[12];
    int numEdges, weight;
    char nodeID[MaxWordSize+1], adjID[MaxWordSize+1];
    if (G == NULL){
        printf ("Grapg is NULL");
        return;
    }
    for (int i = 1; i<= G->numV; i++){
        sprintf(str_id, "%0d", vertices[i].id);       //Convert id to string
        G -> vertex[i] = newGVertex(str_id);            //create a vertex node
    }
    for (int i=1; i<=G->numV; i++){
        sprintf(nodeID, "%0d", vertices[i].id);
        numEdges = vertices[i].numOfoutEdges;
        for (int j=1; j<=numEdges; j++){
            sprintf(adjID, "%0d", vertices[i].outEdges[j].idDes);
            weight = vertices[i].outEdges[j].weight;
            addEdge(nodeID, adjID, weight, G);
        }
    }

}


void printIntGraph(VertexInt vertices[], int len, int region){
    int tmp_id; 
    int tmp_numEdges;
    EdgeInt tmp_edge;
    //Print header
    printf("----------Contact tracing of %0d residents of %0s----------------\n", len, regionLookup(region));
    //Print first line of header row
    printf("Person's                # of direct             IDs of people\n");
    //Print second line of header row
    printf("ID                      contacts                contacted directly\n");
    for (int i=1; i<=len; i++){
        //Print person id and direct contacts
        tmp_id = vertices[i].id;
        tmp_numEdges = vertices[i].numOfoutEdges;
        printf("%0d\t\t\t%0d\t\t\t", tmp_id, tmp_numEdges);
        //Print id direct contacts
        for (int j=1; j<=tmp_numEdges; j++){
            tmp_edge = vertices[i].outEdges[j];
            printf("%0d ", tmp_edge.idDes);
        }
        //Print space
        printf("\n");
    }
}

void writeGraphToFile(FILE* file, VertexInt vertices[], int len){
    int tmp_id;
    int tmp_numEdges;
    int tmp_Des;
    int tmp_weight;
    EdgeInt tmp_edge;
    //Check if file is open
    if (file==NULL){
        printf("writeGraphToFile(): File is not open\n");
        return;
    }
    //Print number of vertices
    fprintf(file, "%0d\n", len);
    //Print names of vertices
    for (int i=1 ; i<=len; i++){
        tmp_id = vertices[i].id;
        fprintf(file, "%0d ", tmp_id);
    }
    //Print new line
    fprintf(file, "\n");
    //Print num edged and width
    for (int i=1; i<=len; i++){
        tmp_id = vertices[i].id;
        tmp_numEdges = vertices[i].numOfoutEdges;
        //Print parent and number of edges
        fprintf(file, "%0d %0d ", tmp_id, tmp_numEdges);
        //Print weights
        for (int j=1; j<=tmp_numEdges; j++){
            tmp_edge = vertices[i].outEdges[j];
            tmp_Des = tmp_edge.idDes;
            tmp_weight = tmp_edge.weight;
            fprintf(file, "%0d %0d ", tmp_Des, tmp_weight);
        }
        //Print new line
        fprintf(file, "\n");
    }
}

char* regionLookup(int region){
    switch (region)
    {
    case 0:
        return "Exit";
        break;
    case 1:
        return "Durhan";
        break;
    case 2:
        return "Peel";
        break;
    case 3:
        return "York";
        break;
    default:
        return "Greater Toronto Area (GTA)";
        break;
    }
}

#endif //RERANDOMGRAPHGENERATOR3_RANDOMGRAPHGENERATOR_H