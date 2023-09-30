#include <stdio.h>
#include <stdlib.h>

int max(int, int);

int main(int argc, char *argv[]) {
    // Read the file
    FILE* fPointer = fopen("./puzzle_input.txt", "r");

    // Check if everything is good with the file
    if ((fPointer == NULL)) {
        printf("Failed to open the file\n");
        exit(1);
    }

    // Read the file line by line
    char* line = malloc(100);
    int tempNumber, suma = 0, maxi = 0;
    while (fgets(line, 100, fPointer)) {
        tempNumber = atoi(line);
        if (!tempNumber) {
            maxi = max(maxi, suma);
            suma = 0;
        } else 
            suma += tempNumber;
    }
    printf("%d\n", maxi);

    fclose(fPointer);

    return 1;
}

int max(int a, int b) {
    return a > b ? a : b;
}
