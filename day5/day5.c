#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#define LINESIZE 50

struct instructions {
	int nBlocks;
	int from; 
	int to;
};

char *stripString(char*);
bool isSpaceString(char*);
char *appendString(char*, char);
int lenString(char*);
int max(int, int);

int main(int argc, char *argv[]) {
	// Define and declare important variables
	char *line = (char*)malloc(LINESIZE * sizeof(char));
	int bSize = 0, iSize = 0;
	int maxLineSize = 0;
	bool isInstruction = false;
	// Open the file
	FILE *inputFile = fopen("test_input.txt", "r");

	// Get the file number of lines to our dynamically allocated matrices
	while (fgets(line, LINESIZE, inputFile)) {
		if (line[1] == '1') {
			isInstruction = true;
			continue;
		}
		if (!isInstruction) {
			bSize++;
			maxLineSize = max(maxLineSize, lenString(line));
		}
		else iSize++;
	}
	iSize--;

	// Define space for data
	char **queues = (char**)malloc(maxLineSize * sizeof(char*));
	struct instructions *instrucs = (struct instructions*)malloc(iSize * sizeof(struct instructions));
	for (int i = 0; i < maxLineSize; i++)
		queues[i] = (char*)malloc(bSize * sizeof(char));
	fseek(inputFile, 0, SEEK_SET);
	isInstruction = false;
	// Store the data 
	while (fgets(line, LINESIZE, inputFile)) {
		if (!isInstruction) {
			for (int i = 1, counter = 0; i < maxLineSize; i += 4, counter++) {
				if (!isSpaceString(&line[i])) {
					queues[counter] = appendString(queues[counter], line[i]);
				}
			}
		} else {
			
		}
	}

	// Freeing the space
	for (int i = 0; i < maxLineSize; i++)
		free(queues[i]);
	free(queues);
	free(line);
	fclose(inputFile);
	return 0;
}

char *appendString(char *str1, char c) {
	char *ans;
	return ans;
}

char *stripString(char *str) {
	char *end;

	// Trim leading space
	while(isSpaceString(str)) str++;
	
	// All spaces
	if (*str == 0)
		return str;

	// Trim trailing space
	end = str + lenString(str) - 1;
	while (end > str && isSpaceString(end)) end--;
	// Write the null terminator character
	end[1] = '\0';

	return str;
}

int lenString(char *str) {
	int len = 0;
	while (*str != '\0') {
		str++;
		len++;
	}
	return len;
} 

bool isSpaceString(char *str) {
	return *str == ' ' || *str == '\n';
}

int max(int a, int b) {
	return a > b ? a : b;
}
