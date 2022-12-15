#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 7

int main() {
	FILE* file = fopen("input.txt", "r");

	if (file == NULL) {
		printf("No input file \n");
		return 1;
	}

	char line[MAX_LINE_LENGTH];
	int prevBigNum;
	int acc;
	
	while(fgets(line, MAX_LINE_LENGTH, file)) {
		if (strcmp(line, "\n") == 0) {
			if (acc > prevBigNum) {
				prevBigNum = acc;
			}
			acc = 0;
		} else {
			acc += atoi(line);
		}
	}
	printf("%i\n", prevBigNum);
	fclose(file);
	return 0;
}
