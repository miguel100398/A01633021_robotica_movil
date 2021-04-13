/*
 * Created by Muhammad Mohiuddin on 3/23/2021.
 * This file contains definitions for the random graph generator application
 * Read inline comments
*/

#ifndef RANDOMGRAPHGENERATOR3_RANDOMGRAPHGENERATOR_H
#define RANDOMGRAPHGENERATOR3_RANDOMGRAPHGENERATOR_H

#define MAX_LEN 1000     //Max number of persons
#define MIN_LEN 2        //Min number of persons
#define MAX_NUM_EDGES 10 //Max number of edges
#define MIN_NUM_EDGES 0  //Min number of edges

#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct { // struct definition for an edge representing a contact between two persons
    int idSrc;  // id of the source person
    int idDes; // id of the target person
    int weight; // weight of the edge, which is set to 1 for contact tracing application
}EdgeInt;
typedef struct { // struct definition of a vertex representing a person
    int id; // id of the vertex (person)
    int numOfoutEdges; // number of persons contacted by this person
    EdgeInt outEdges[MAX_NUM_EDGES+1]; // list of the persons contacted by this person
}VertexInt;
/**
 * 
 * @return Pointer of vertices generated
 * 
 */
VertexInt* genVertices(int len);   //Generates random number of vertices and returns a pointer of the vertices
/**
 *
 * @param vertices array of type VertexInt to store integer based vertex
 * @param len is the number of vertices(persons)
 */
void prepareGraph(VertexInt *vertices, int len); // prepareGraph function must be called before buildGraphRandom
/**
 *
 * @param vertices representing total number of people in the dataset
 * @param G represents a Graph
 */
void buildGraphRandom(VertexInt vertices[], Graph G); // call buildGraphRandom after invoking prepareGraph function
/**
 *
 * @param vertices
 * @param len--number of vertices(people)
 * @param region
 * This function prints vertices data, it also takes region as an integer and calls regionLookup function to get
 * name of the region as a string
 */
void printIntGraph(VertexInt vertices[], int len, int region);

/**
 *
 * @param file
 * @param vertices
 * @param len
 * This function is used to write vertices data to a file in an format identical to the requirements of dijkstra function
 * that read graph of a file. It is not a required function if no filing is used
 */
void writeGraphToFile(FILE* file, VertexInt vertices[], int len);

/**
 *
 * @param region as an integer
 * @return region name
 * This function is just a lookup function that returns a region name as a string given its number
 */
char* regionLookup(int region);
/**
 *
 * @param vertices array of type VertexInt to be free
 * @param len is the number of vertices(persons)
 */
void deleteVertices(VertexInt *vertices); //Free memory
#endif //RANDOMGRAPHGENERATOR3_RANDOMGRAPHGENERATOR_H