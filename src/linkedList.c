#include <stdio.h>
#include <stdlib.h>
#include <linkedList.h>
#include <string.h>


Food * createRecord(char * name, char * group, int calories, char theType) {
	Food *element;

	element = malloc(sizeof(*element));
	
	element->name = malloc(51);
	strcpy(element->name, name);

	element->foodGroup = malloc(strlen(group) + 1);
	strcpy(element->foodGroup, group);

	element->calories = calories;

	element->type = theType;

	element->next = NULL;

	return element;
}

char * printRecord(Food * toPrint) {
	char *message;

	if (toPrint != NULL) {
		message = malloc(150);
		sprintf(message, "%s (%s):%d[%c]", toPrint->name, toPrint->foodGroup, toPrint->calories, toPrint->type);
	} else {
		message = malloc(150);
		sprintf(message, "ERROR: Empty list.");
	}	
	return message;
}

void destroyRecord(Food * toDie) {
	if (toDie != NULL) {
		free(toDie->name);
		free(toDie->foodGroup);
		free(toDie);
	}
}

Food * addToFront(Food * theList, Food * toBeAdded) {

	if (theList == NULL) {
		return toBeAdded;
	}

	toBeAdded->next = theList;
	return toBeAdded;
}

Food * addToBack(Food * theList, Food * toBeAdded) {
	Food *temp;

	if (theList == NULL) {
		return toBeAdded;
	}

	if (toBeAdded == NULL) {
		return theList;
	}

	temp = theList;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = toBeAdded;
	return theList;
}

Food * removeFromFront(Food * theList) {
	Food *temp;

	if (theList == NULL) {
		return NULL;
	}

	temp = theList->next;

	return temp;
}

Food * removeFromBack(Food * theList) {
	Food *temp;
	Food *prev;

	if (theList == NULL || theList->next == NULL) {
		return NULL;
	}

	temp = theList;
	do {
		prev = temp;
		temp = temp->next;
	} while (temp->next != NULL);

	prev->next = NULL;
	return theList;
}

Food * getLastItem(Food * theList) {
	Food *temp;

	if (theList == NULL) {
		return NULL;
	}

	temp = theList;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	return temp;
}

Food * getFirstItem(Food * theList) {

	return theList;
}

int isEmpty(Food * theList) {

	return theList == NULL;
}

void printList(Food * theList) {
	while (theList != NULL) {
		printf("%s\n", printRecord(theList));
		theList = theList->next;
	}
}

void destroyList(Food * theList) {
    while (theList != NULL) {
		destroyRecord(theList);
		theList = theList->next;
	}
}

