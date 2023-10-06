#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#define LINESIZE 50

char *stripString(char*);
bool isSpaceString(char*);
int lenString(char*);
int max(int, int);

int main(int argc, char *argv[]) {
	// Define and declare important variables
	char *line = (char*)malloc(LINESIZE * sizeof(char));
	int bSize = 0, iSize = 0;
	int maxLineSize = 0;
	bool inst = false;
	// Open the file
	FILE *inputFile = fopen("test_input.txt", "r");

	// Get the file number of lines to our dynamically allocated matrices
	while (fgets(line, LINESIZE, inputFile)) {
		if (line[1] == '1') {
			inst = true;
			continue;
		}
		if (!inst) {
			bSize++;
			maxLineSize = max(maxLineSize, lenString(line));
		}
		else iSize++;
	}
	iSize--;
	maxLineSize--;

	// Store the data

	
	return 0;
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
