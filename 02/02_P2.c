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

	char ansMap[3][2] = {"CB", "AC", "BA"};
        while(fgets(line, MAX_LINE_LENGTH, file)) {
                if (strcmp(line, "\n") != 0) {
			if (line[2] == 88) {
				acc += ansMap[line[0] - 65][0] - 64;
			} else if (line[2] == 89) {
				acc += line[0] - 61;
			} else if (line[2] == 90) {
				acc += ansMap[line[0] - 65][1] - 58;
			}
		}	
	}
        printf("%i\n", acc);
	fclose(file);
        return 0;
}
