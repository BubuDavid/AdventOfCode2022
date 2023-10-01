#include <stdio.h>
#include <stdlib.h>

int max(int, int);
int sum(int*, int);
void printArray(int*, int);
int part1(int*, int);
void insertInHeap(int*, int, int);
int part2(int*, int);

int main(int argc, char *argv[]) {
    // Read the file
    FILE* fPointer = fopen("./input_puzzle.txt", "r");
    // Check if everything is good with the file
    if (fPointer == NULL) {
        printf("Failed to open the file\n");
        exit(1);
    }

    // Count lines of file
    int totalLines = 0;
    char* line = malloc(10); // This is not actually needed here but it's okay
    while (fgets(line, 10, fPointer)) {
        totalLines++;
    }
    // Alocate memory for that lines
    // printf("Memory for %d numbers\n", totalLines);

    int* candies = (int*)malloc(totalLines * sizeof(int));
    if (candies == NULL) {
        printf("Failed to allocate memory for candies");
        exit(1);
    }
    // Restart the fPointer
    fseek(fPointer, 0, SEEK_SET);
    int i = 0;
    while (fgets(line, 10, fPointer)) {
        candies[i] = atoi(line);
        i++;
    }
     // printArray(candies, totalLines);

    // Part 1
    printf("Part1: %d\n", part1(candies, totalLines));
    // Part 2
    printf("Part2: %d\n", part2(candies, totalLines));

    free(candies);
    free(line);
    
    fclose(fPointer);

    return 0;
}

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return;
}

int part1(int* candies, int n) {
    int suma = 0, maxi = 0;
    for (int i = 0; i < n; i++) {
        if (!candies[i] || i == n - 1) {
            maxi = max(maxi, suma);
            suma = 0;
        } else suma += candies[i];
    }

    return maxi;
}

int part2(int* candies, int n) {
    int suma = 0;
    int heap[] = {0, 0, 0};

    for (int i = 0; i < n; i++) {
        if (i == n - 1 || !candies[i]) {
            if (i == n - 1) {
                suma += candies[i];
            }
            insertInHeap(heap, 3, suma);
            suma = 0;
        } else suma += candies[i];
    }

    return sum(heap, 3);
}

void insertInHeap(int* heap, int n, int number){
    int saved, tempSaved;
    for (int i = 0; i < n; i++) {
        if (number > heap[i]) {
            saved = heap[i];
            heap[i] = number;
            if (i == n - 1) return;
            for (int j = i + 1; j < n; j++) {
                tempSaved = heap[j];
                heap[j] = saved;
                saved = tempSaved;
            }
            return;
        }
    }
    return;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int sum(int* a, int n) {
    int suma = 0;
    for(int i = 0; i < n; i++) suma += a[i];
    return suma;
}
