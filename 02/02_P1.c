#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 4

int main() {
        FILE* file = fopen("input.txt", "r");

        if (file == NULL) {
                printf("No input file \n");
                return 1;
        }
	char line[MAX_LINE_LENGTH];
	int acc = 0;
	while(fgets(line, MAX_LINE_LENGTH, file)) {
		if (strcmp(line, "\n") != 0) {
			acc += line[2] - 87;
			if ((line[2] == 90 && line[0] == 66) || (line[2] == 89 && line[0] == 65) || (line[2] == 88 && line[0] == 67)) {
                        	acc += 6;
                	} else if ((line[2] - 23) == line[0]) {
                        	acc += 3;
                	}
		}
	}
	printf("%i\n", acc);
	fclose(file);
	return 0;
}
