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
        int prevBigNum[3] = {0};
        int acc = 0;
	int amountGreater = 0;
	int indexToReplace = -1;

        while(fgets(line, MAX_LINE_LENGTH, file)) {
                if (strcmp(line, "\n") == 0) {
			printf("%s\n", "BREAK");
			for (int i = 0; i < 3; ++i) {
                        	if ((acc - prevBigNum[i]) > amountGreater) {
                               		indexToReplace = i;
				       	amountGreater = acc - prevBigNum[i];	
				}
			}
			if (indexToReplace >= 0) {
				// printf("%i, %i\n", prevBigNum[indexToReplace], acc);
				prevBigNum[indexToReplace] = acc;
			}	
                        acc = 0;
			amountGreater = 0;
			indexToReplace = -1;
                } else {
			printf("%i\n", atoi(line));
                        acc += atoi(line);
                }
        }

	int result = 0;

	for (int j = 0; j < 3; ++j) {
		result += prevBigNum[j];
	}

        printf("%i\n", result);
        fclose(file);
        return 0;
}
