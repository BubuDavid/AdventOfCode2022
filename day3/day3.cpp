#include <cctype>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

int getValue(char);
int part1(std::vector<std::string>);
int part2(std::vector<std::string>);

int main (int argc, char *argv[]) {
    // Open the file
    std::ifstream inputFile("./puzzle_input.txt");
    // Read the file
    std::string line;
    std::vector<std::string> ruckstacks;
    while ((std::getline(inputFile, line))) {
        ruckstacks.push_back(line);
    }    

    //Solving the problem
    std::cout << "Parte 1: " << part1(ruckstacks) << std::endl;
    std::cout << "Parte 2: " << part2(ruckstacks) << std::endl;

    inputFile.close();

    return 0;
}

int part1(std::vector<std::string> ruckstacks) {
    int answer = 0;
    size_t n = ruckstacks.size();
    for (size_t i = 0; i < n; i++) {
        std::set<char> seen;
        size_t nLine = ruckstacks[i].size();
        for (size_t j = 0; j < nLine / 2; j++) {
            seen.insert(ruckstacks[i][j]); 
            // std::cout << ruckstacks[i][j];
        }
        for (size_t j = nLine / 2; j < nLine; j++) {
            auto it = seen.find(ruckstacks[i][j]);
            // std::cout << ruckstacks[i][j] << std::endl;
            if (it != seen.end()) {
                // std::cout << "🔥 " << ruckstacks[i][j] << std::endl;
                answer += getValue(ruckstacks[i][j]); 
                break;
            }
        }
    }
    return answer;
}

int part2(std::vector<std::string> ruckstacks) {
    int answer = 0;
    int n = ruckstacks.size(), nLine;
    std::unordered_map <char, int> seen;
    std::set<char> memo;
    for (size_t i = 0; i < n; i++) {
        if (!(i % 3)) {
            seen.clear();
        }
        // std::cout << "🔥 Linea " << i << std::endl;
        memo.clear();
        for (size_t j = 0; j < nLine; j++) {
        nLine = ruckstacks[i].size();
            if (seen.find(ruckstacks[i][j]) == seen.end()) {
                seen.insert({ruckstacks[i][j], 1});
                // std::cout << "No he visto: " << ruckstacks[i][j] << std::endl;
                memo.insert(ruckstacks[i][j]);
            } else if (memo.find(ruckstacks[i][j]) == memo.end()) {
                seen[ruckstacks[i][j]]++; 
                memo.insert(ruckstacks[i][j]);
                // std::cout << "Ahora " << ruckstacks[i][j] << " vale: " << seen[ruckstacks[i][j]] << std::endl;
            }
            if (seen[ruckstacks[i][j]] == 3) {
                // std::cout << "Apoco de veras? " << ruckstacks[i][j] << std::endl;
                answer += getValue(ruckstacks[i][j]);
                break;
            }
        }
    }

    return answer;
}

int getValue(char c) {
    int value = c;
    if (isupper(c)) {
        value -= 'A'; 
        value += 27;
        return value;
    }
    value -= 'a';
    return ++value;
}
