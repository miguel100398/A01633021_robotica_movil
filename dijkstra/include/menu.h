#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include "dijkstra.h"

/**
 *
 */
void print_dataSetMessage();        //Prints Initial message to select data set
/**
 *
 * @param region Region to be used in data set
 * @return Status of value read from user, 1 legal value, 0 illegal value
 */
int get_region(int* region);        //Asks user to input region
/**
 *
 * @param len Number of people to be tracker
 * @return Status of value read from user, 1 legal value, 0 illegal value
 */
int get_peopleTracked(int* len);        //Asks user to input number of people to be tracked
/**
 *
 */
void print_queryMessage();              //Prints message to start a new query
/**
 * @param src source person's ID
 * @param len Number of people to be tracker
 * @return Status of value read from user, <=1 legal value, 0 illegal value
 */
int get_sourcePerson(int* src, int len);            //Asks user to introduce source person's ID
/**
 * @param target target person's ID
 * @param len Number of people to be tracker
 * @return Status of value read from user, <=1 legal value, 0 illegal value
 */
int get_targetPerson(int* target, int src, int len);        //Asks user to introduce target person's ID
/**
 * @param graph Graph to compute dijkstra algorithm
 * @param src Source person's ID
 * @param target target person's ID
 */
void print_contactTrace(Graph graph, int src, int target);  //Computes Dijkstra algorithm and prints contact trace from source to target
/**
 * 
 * @return Status of next query 0-> Exit program, 1-> start new query, 2-> Change data set
 * 
 */
int get_nextQuery();        //Asks user to start new query, change data set or end program


#endif //MENU_H