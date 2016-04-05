#include <tracker.h>

int tracker(Food *theList) {
	Food *temp;
	int totalCal;
	double vegCal;
	int numVeg;
	double meatCal;
	int numMeat;
	double dairyCal;
	int numDairy;
	double grainsCal;
	int numGrains;
	double fatCal;
	int numFat;
	int numItems;

	totalCal = 0;
	vegCal = meatCal = dairyCal = grainsCal = fatCal = 0;
	numVeg = numMeat = numDairy = numGrains = numFat = 0;
	numItems = 0;
	temp = theList;

	while (temp->next != NULL)  {
		totalCal += temp->calories;

		if (!strcmp(temp->foodGroup, "vegfruit")) {
			numVeg += 1;
			vegCal += temp->calories;
		} else if (!strcmp(temp->foodGroup, "meat")) {
			numMeat += 1;
			meatCal += temp->calories;
		} else if (!strcmp(temp->foodGroup, "dairy")) {
			numDairy += 1;
			dairyCal += temp->calories;
		} else if (!strcmp(temp->foodGroup, "grains")) {
			numGrains += 1;
			grainsCal += temp->calories;
		} else if (!strcmp(temp->foodGroup, "fat")) {
			numFat += 1;
			fatCal += temp->calories;
		}

		numItems += 1;
		temp = temp->next;
	}

	totalCal += temp->calories;

	if (!strcmp(temp->foodGroup, "vegfruit")) {
		numVeg += 1;
		vegCal += temp->calories;
	} else if (!strcmp(temp->foodGroup, "meat")) {
		numMeat += 1;
		meatCal += temp->calories;
	} else if (!strcmp(temp->foodGroup, "dairy")) {
		numDairy += 1;
		dairyCal += temp->calories;
	} else if (!strcmp(temp->foodGroup, "grains")) {
		numGrains += 1;
		grainsCal += temp->calories;
	} else if (!strcmp(temp->foodGroup, "fat")) {
		numFat += 1;
		fatCal += temp->calories;
	}

	if (numVeg != 0) {
		vegCal = vegCal/numVeg;
	}
	if (numMeat != 0) {
		meatCal = meatCal/numMeat;
	}
	if (numDairy != 0) {
		dairyCal = dairyCal/numDairy;
	}
	if (numGrains != 0) {
		grainsCal = grainsCal/numGrains;
	}
	if (numFat != 0) {
		fatCal = fatCal/numFat;
	}

	numItems += 1;

	printf("%d\n", totalCal);
	printf("Average Vegetable/Fruit Calories: %.2lf\n", vegCal);
	printf("Average Meat Calories: %.2lf\n", meatCal);
	printf("Average Dairy Calories: %.2lf\n", dairyCal);
	printf("Average Grains Calories: %.2lf\n", grainsCal);
	printf("Average Fat Calories: %.2lf\n", fatCal);
	printf("Number of Food Items: %d\n", numItems);
	printList(theList);

	destroyList(theList);
	return 1;
}