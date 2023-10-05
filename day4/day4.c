#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 15

struct Schedule {
	int start;
	int end;
};

char *stripString(char*);
char **splitString(char*, const char*, size_t*);
int part1(struct Schedule*, struct Schedule*, int);
int part2(struct Schedule*, struct Schedule*, int);

int main(int argc, char *argv[]) {
	// Open a file
	FILE *inputFile = fopen("./puzzle_input.txt", "r");
	// Read the file and count the lines 
	char *line = (char*)malloc(LINESIZE * sizeof(char));
	int totalLines = 0;
	while(fgets(line, LINESIZE, inputFile))
		totalLines++;

	struct Schedule *e1, *e2;
	e1 = (struct Schedule*)malloc((totalLines + 1) * sizeof(struct Schedule));
	e2 = (struct Schedule*)malloc((totalLines + 1) * sizeof(struct Schedule));
	// Read the file and store the data
	fseek(inputFile, 0, SEEK_SET);
	int i = 0;
	size_t nSplits = 0;
	char **splitted, **numbers;
	while(fgets(line, LINESIZE, inputFile)) {
		line = stripString(line);
		// printf("Original String: %s\n", line);
		splitted = splitString(line, ",", &nSplits);
		// printf("Splited with nSplits = %zu: \n%s 🔥 %s\n", nSplits, splitted[0], splitted[1]);
		numbers = splitString(splitted[0], "-", &nSplits);
		e1[i].start = atoi(numbers[0]);
		e1[i].end = atoi(numbers[1]);
		numbers = splitString(splitted[1], "-", &nSplits);
		e2[i].start = atoi(numbers[0]);
		e2[i].end = atoi(numbers[1]);
		// printf("=========================================\n");
		i++;
	}

	printf("Part 1: %d\n", part1(e1, e2, totalLines));
	printf("Part 2: %d\n", part2(e1, e2, totalLines));

	fclose(inputFile);
	free(line);
	free(e1);
	free(e2);
	free(splitted);
	free(numbers);

	return 0;
}

int part1(struct Schedule *e1, struct Schedule *e2, int N) {
	int ans = 0;
	for (size_t i = 0; i < N; i++) {
		int a = e1[i].start;
		int b = e1[i].end;
		int c = e2[i].start;
		int d = e2[i].end;
		if ((a <= c && d <= b) || (c <= a && b <= d)) {
			ans++;
		} 
	}

	return ans;
}

int part2(struct Schedule *e1, struct Schedule *e2, int N) {
	int ans = 0;
	for (size_t i = 0; i < N; i++)  {
		int a = e1[i].start;
		int b = e1[i].end;
		int c = e2[i].start;
		int d = e2[i].end;
		if (!(b < c || d < a)) {
			// printf("%d %d %d %d\n", a, b, c, d);
			ans++;
		}
	}

	return ans;
}


char **splitString(char *text, const char *sep, size_t *counter) {
	char **splitted;
	*counter = 0;
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

char *stripString(char *str) {
	char *end;

	// Trim leading space
	while(isspace((unsigned char) *str)) str++;
	
	// All spaces
	if (*str == 0)
		return str;

	// Trim trailing space
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char) *end)) end--;
	// Write the null terminator character
	end[1] = '\0';

	return str;
}
