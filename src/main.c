#include <stdio.h>
#include <stdlib.h>
#include <parser.h>
#include <tracker.h>
#include <global.h>

int main(int argc, char const *argv[]) {
	Food *head;

	if (argc != 2) {
		fprintf(stderr, "Error: Incorrect number of arguments.\n");
	    fprintf(stderr, "Expected usage: %s [food_list_path]", argv[0]);
	    return -1;
	}

	head = fileToList(argv[1]);

	if (head == NULL) {
	    fprintf(stderr, "ERROR: Failed to open data file or not list exists.\n");
	    return -1;
	}

	if (!tracker(head)) {
		fprintf(stderr, "ERROR: Error within list.\n");
		return -1;
	}
	return 0;
}