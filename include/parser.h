#ifndef PARSER_H
#define PARSER_H

#include <global.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <linkedList.h>

/*
 * fileToList
 * Opens the input file and reads the contents into a linked list.
 * @param  path.........Passes through file path from the command line
 * @return          	Returns head of list
 *                  	NULL on failure
*/
Food* fileToList(const char* path);

#endif