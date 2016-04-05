#include <parser.h>

Food* fileToList(const char* path) {
    FILE* foodList;
    Food* head;
    Food* temp;
    char *cursor;
	char foodInfo[MAX_LINE_LENGTH];
	char *name;
    char *foodGroup;
    char *calorieChar;
    int calories;
    char *type;
    int totalCal;

    foodList = fopen(path, "r");
    if (foodList == NULL)
        return NULL;

    head = NULL;

    while ((cursor = fgets(foodInfo, MAX_LINE_LENGTH, foodList)) != NULL) {

    	name = strtok(cursor, ",");
    	if (name == NULL) {
    		name = "N/A";
    	} else {
    		foodGroup = strtok(NULL, ",");
    	}
    	if (foodGroup == NULL) {
    		foodGroup = "N/A";
    	} else {
    		calorieChar = strtok(NULL,",");
    		calories = atoi(calorieChar);
    	}
    	if (calories < 0) {
    		calories = 0;
    		type = strtok(NULL," ");
    	} else {
    	   	type = strtok(NULL," ");
    	}
    	if (type == NULL) {
    		type = "N/A";
    	}
    	
    	if (head == NULL) {
    		head = createRecord(name, foodGroup, calories, type[0]);
    	} else {
    		temp = createRecord(name, foodGroup, calories, type[0]);
    		if (type[0] == 'h') {
    			head = addToFront(head, temp);
    		} else if (type[0] == 'j') {
    			head = addToBack(head, temp);
    		} else {
    			printf("ERROR: A food item element is missing a type.\n");
    			return NULL;
    		}
    	}
    }

    fclose(foodList);
    return head;
}
