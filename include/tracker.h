#ifndef TRACKER_H
#define TRACKER_H

#include <global.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <linkedList.h>

/*
 * tracker
 * Takes in the linked list and performs operations.
 * @param  theList......Passes stored linked list
 * @return          	Returns head of list
 *                  	NULL on failure
*/
int tracker(Food *theList);

#endif