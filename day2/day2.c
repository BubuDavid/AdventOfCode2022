#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int part1(char *, char *, int);
int part2(char *, char *, int);

int main(int argc, char *argv[]) {
    // Open the file
    FILE *inputFile = fopen("./puzzle_input.txt", "r");
    // Check if the file is okay
    if (inputFile == NULL) {
        printf("Couldn't open the file");
        exit(1);
    }
    // Read the file and get the number of lines
    char *line = (char*)malloc(6 * sizeof(char));
    int totalLines = 0;
    while (fgets(line, 6, inputFile))
        totalLines++;
    
    // Define the size of everything
    char *p1, *p2;
    p1 = (char*)malloc((totalLines + 1) * sizeof(char));
    p2 = (char*)malloc((totalLines + 1) * sizeof(char));
    int nLine = 0;
    // Store the data of the file
    fseek(inputFile, 0, SEEK_SET);
    while (fgets(line, 6, inputFile)) {
        // printf("Getting %s\n", line);
        p1[nLine] = line[0];
        p2[nLine] = line[2];
        nLine++;
    }

    int ans1 = part1(p1, p2, totalLines);
    int ans2 = part2(p1, p2, totalLines);

    printf("Part 1: %d\n", ans1);
    printf("Part 2: %d\n", ans2);

    // Close the file
    fclose(inputFile);
    return 0;
}

int part1(char *p1, char *p2, int totalLines) {
    int totalPoints = 0;
    for (int i = 0; i < totalLines; i++) {
        // Points for choosing
        if (p2[i] == 'X') {
            totalPoints += 1; 
        } else if (p2[i] == 'Y') {
            totalPoints += 2; 
        } else totalPoints += 3; 
        // Points for result of the game
        if (p1[i] == 'A') {
            if (p2[i] == 'X') totalPoints += 3;
            else if (p2[i] == 'Y') totalPoints += 6;
        } else if (p1[i] == 'B') {
            if (p2[i] == 'Y') totalPoints += 3;
            else if (p2[i] == 'Z') totalPoints += 6;
        } else {
            if (p2[i] == 'X') totalPoints += 6;
            else if (p2[i] == 'Z') totalPoints += 3;
        }
    }
    return totalPoints;
}

int part2(char *p1, char *p2, int totalLines) {
    int totalPoints = 0;
    for (int i = 0; i < totalLines; i++) {
        if (p1[i] == 'A') {
            if (p2[i] == 'X') totalPoints += 3; 
            if (p2[i] == 'Y') totalPoints += 4; 
            if (p2[i] == 'Z') totalPoints += 8; 
        } else if (p1[i] == 'B') {
            if (p2[i] == 'X') totalPoints += 1; 
            if (p2[i] == 'Y') totalPoints += 5; 
            if (p2[i] == 'Z') totalPoints += 9; 
        } else {
            if (p2[i] == 'X') totalPoints += 2; 
            if (p2[i] == 'Y') totalPoints += 6; 
            if (p2[i] == 'Z') totalPoints += 7; 
        }
    }

    return totalPoints;
}
