#include <iostream>
#include <fstream>
#include <vector>

bool canInsertInHeap(std::vector<int>, int);
void insertInHeap(std::vector<int>&, int);
int part1(std::vector<int>);
int sum(std::vector<int>);
int part2(std::vector<int>);

int main (int argc, char *argv[]) {
    // Reading the file get the data
    std::ifstream inputFile("./input_puzzle.txt");
    
    std::string myText;
    std::vector<int> candies;
    int tempNumber; 
    while (getline(inputFile, myText)) {
        if (!(myText.empty())) {
            tempNumber = stoi(myText);
            candies.push_back(tempNumber);
        } else candies.push_back(-1);
    }

    // Part 1
    int answer1 = part1(candies);
    std::cout << "Answer for 1: " << answer1 << std::endl;
    // Part 2
    int answer2 = part2(candies);
    std::cout << "Answer for 2: " << answer2 << std::endl;

    return 0;
}

void printVector(std::vector<int> v) {
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";        
    }
    std::cout << std::endl;
}

// Return the max sum for each subset of candies.
int part1(std::vector<int> candies) {
    int maxi = 0, suma = 0;
    for (size_t i = 0; i < candies.size(); i++) {
        if (candies[i] == -1 || i == candies.size() - 1) {
            maxi = std::max(suma, maxi);
            suma = 0;
        }  
        else 
            suma += candies[i]; 
    }

    return maxi;
}

// The same as the part 1 but the top 3
int part2(std::vector<int> candies) {
    std::vector<int> heap = {0, 0, 0};
    int suma = 0;

    for (size_t i = 0; i < candies.size(); i++) {
        if (candies[i] == -1 || i == candies.size() - 1) {
            if (!suma && i == candies.size() - 1)
                suma = candies[i];
            if (canInsertInHeap(heap, suma)) {
                // std::cout << "inserting " << suma << std::endl;
                insertInHeap(heap, suma);
            } 
            // std::cout << suma << std::endl;
            printVector(heap);
            suma = 0;
        } else suma += candies[i];
    }
    
    // std::cout << suma << std::endl;
    return sum(heap);
}

void insertInHeap(std::vector<int>& heap, int n) {
    int saved, tempSaved;
    for (size_t i = 0; i < heap.size(); i++) {
        if (n > heap[i]) {
            saved = heap[i];
            heap[i] = n;
            if (i == heap.size() - 1) {
                return;
            }
            for (size_t j = i + 1; j < heap.size() - 1; j++) {
                tempSaved = heap[j];
                heap[j] = saved;
                saved = tempSaved;
            }
            heap[heap.size() - 1] = saved;
            return;
       } 
    }
}

bool canInsertInHeap(std::vector<int> heap, int n) {
    for (size_t i = 0; i < heap.size(); i++) {
        if (n > heap[i]) {
           return true; 
        } 
    }

    return false;
}

int sum(std::vector<int> v) {
    int suma = 0;
    for (size_t i = 0; i < v.size(); i++) {
       suma += v[i]; 
    }
    return suma;
}
