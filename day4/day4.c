#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define LINESIZE 15
//
// struct Schedule {
// 	int start;
// 	int end;
// };

char **splitString(char*, const char*, size_t*);

int main(int argc, char *argv[]) {
	// // Open a file
	// FILE *inputFile = fopen("./test_input.txt", "r");
	// // Read the file and count the lines 
	// char *line = (char*)malloc(LINESIZE * sizeof(char));
	// int totalLines = 0;
	// while(fgets(line, LINESIZE, inputFile))
	// 	totalLines++;
	//
	// struct Schedule *e1, *e2;
	// e1 = (struct Schedule*)malloc((totalLines + 1) * sizeof(struct Schedule));
	// e2 = (struct Schedule*)malloc((totalLines + 1) * sizeof(struct Schedule));
	// // Read the file and store the data
	// fseek(inputFile, 0, SEEK_SET);
	// int i = 0;
	// while(fgets(line, LINESIZE, inputFile)) {
	// }
	//
	//
	// fclose(inputFile);
	// free(line);
	// free(e1);
	// free(e2);
	//
	// return 0;

	return 0;
}

char **splitString(char *text, const char *sep, size_t *counter) {
	char **splitted;
	splitted = (char**)malloc(3 * sizeof(char*));
	if (splitted == NULL) {
		printf("Memory could not be allocated for splitted\n");
		exit(1);
	}

	char *token = strtok(text, sep);
	if (token == NULL) {
		printf("Memory could not be allocated for token\n");
		exit(1);
	}

	while(token != NULL) {
		splitted[*counter] = (char*)malloc(4 * sizeof(char));
		if (splitted[*counter] == NULL) {
			printf("Memory could not be allocated for splitted[*%zu]\n", *counter);
			exit(1);
		}
		splitted[*counter] = token;
		*counter = *counter + 1;
		token = strtok(NULL, sep);
	}

	return splitted;
}
