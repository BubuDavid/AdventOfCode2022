#include <iostream>
#include <fstream>
#include <string>

int part1(std::string, std::string);
int part2(std::string, std::string);

int main (int argc, char *argv[]) {
    // Open the file
    std::ifstream inputFile("./puzzle_input.txt");
    std::string line;
    // Define all for storing stuff
    std::string p1, p2; 
    // Read the file
    while (std::getline(inputFile, line)) {
        p1.push_back(line[0]);
        p2.push_back(line[2]);
    }
    
    // Solving
    std::cout << "Part 1: " << part1(p1, p2) << std::endl;
    std::cout << "Part 2: " << part2(p1, p2) << std::endl;

    return 0;
}

int part1(std::string p1, std::string p2) {
    int totalPoints = 0;
    for (size_t i = 0; i < p1.size(); i++) {
        if (p1[i] == 'A') {
            if (p2[i] == 'X') totalPoints += 4; 
            if (p2[i] == 'Y') totalPoints += 8; 
            if (p2[i] == 'Z') totalPoints += 3; 
        } else if (p1[i] == 'B') {
            if (p2[i] == 'X') totalPoints += 1; 
            if (p2[i] == 'Y') totalPoints += 5; 
            if (p2[i] == 'Z') totalPoints += 9; 
        } else {
            if (p2[i] == 'X') totalPoints += 7; 
            if (p2[i] == 'Y') totalPoints += 2; 
            if (p2[i] == 'Z') totalPoints += 6; 
        }
    }

    return totalPoints;
}

int part2(std::string p1, std::string p2) {
    int totalPoints = 0;
    for (size_t i = 0; i < p1.size(); i++) {
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
