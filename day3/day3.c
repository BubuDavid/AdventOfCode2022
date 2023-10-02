#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getLineSize(char*);
void initializeBucket(int [120]);
int getBucketIndex(char);
int part1(char**, int);
int part2(char**, int);

int main(int argc, char *argv[]) {
    // Open the file
    FILE *inputFile = fopen("./puzzle_input.txt", "r");

    // Read the file and count the lines in the file 
    char *line = (char*)malloc(150 * sizeof(char));
    int totalLines = 0;
    while (fgets(line, 150, inputFile))
        totalLines++;

    // Store the file in a variable
    // Array of strings or pointer to pointers of chars
    char **ruckstacks = malloc(totalLines * sizeof(char*));
    for (size_t i = 0; i < totalLines; i++) {
        ruckstacks[i] = malloc(150 * sizeof(char));
    } 
    // Again read the file but now store the data
    int nLine = 0;
    fseek(inputFile, 0, SEEK_SET);
    while (fgets(line, 150, inputFile)) {
        strcpy(ruckstacks[nLine], line);
        nLine++;
    }
    // Solutions
    printf("Part 1: %d\n", part1(ruckstacks, totalLines));
    printf("Part 2: %d\n", part2(ruckstacks, totalLines));

    fclose(inputFile);
    free(line);
    free(ruckstacks);

    
    return 0;
}

int part1(char **ruckstacks, int totalLines) {
    int answer = 0, lineSize;
    int bucket[120], bucketIndex;
    for (size_t i = 0; i < totalLines; i++) {
        initializeBucket(bucket);
        lineSize = getLineSize(ruckstacks[i]);
        for (size_t j = 0; j < lineSize / 2; j++) {
            bucketIndex = getBucketIndex(ruckstacks[i][j]);
            bucket[bucketIndex]++;
        }
        for (size_t j = lineSize / 2; j < lineSize; j++) {
            bucketIndex = getBucketIndex(ruckstacks[i][j]);
            if (bucket[bucketIndex]) {
                answer += bucketIndex;
                break;
            }
        }
    }

    return answer;
}

int part2(char **ruckstacks, int totalLines) {
    int answer = 0, bucket[120], lineSize, bucketIndex;
    int memo[120];
    for (size_t i = 0; i < totalLines; i++) {
        lineSize = getLineSize(ruckstacks[i]);
        initializeBucket(memo);
        if (!(i % 3)) {
            initializeBucket(bucket);
        }
        for (size_t j = 0; j < lineSize; j++) {
            bucketIndex = getBucketIndex(ruckstacks[i][j]);
            if (!(memo[bucketIndex])) {
                bucket[bucketIndex]++; 
                memo[bucketIndex]++;
            }
            if (bucket[bucketIndex] == 3) {
                answer += bucketIndex; 
                break;
            }
        }
    }
    return answer;
}

int getBucketIndex(char c) {
    int bucketIndex = c;
    if (isupper(c)) {
        bucketIndex -= 'A';
        bucketIndex += 27;
        return bucketIndex;
    }
    
    bucketIndex -= 'a';

    return ++bucketIndex;
}

int getLineSize(char *line) {
    int totalSize = 0;
    while (line[totalSize] != '\0')
        totalSize++;

    if (line[totalSize - 1] == '\n') totalSize--;

    return totalSize;
}

void initializeBucket(int bucket[120]) {
    for (size_t i = 0; i < 120; i++)
        bucket[i] = 0;
}
