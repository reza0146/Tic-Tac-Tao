#include <iostream>

#include "functions.hpp"

int main() {

    std::vector<std::vector<int>> game_state(3, std::vector<int>(3)); // initialize a 3x3 vector filled with zeros.
    std::vector<std::vector<std::string>> state_string_vec = InitializeStateStringVec(); 
    
    game_state = {{1,0,2},
        {5,7,3},
        {-1,2,5}};


    
    std::cout << "O " << "| " << "X " << "| " << "O " << "\n";
    std::cout << "--" << "--" << "--" << "--" << "--" << "\n";
    std::cout << "O " << "| " << "X " << "| " << "O " << "\n";
    std::cout << "--" << "--" << "--" << "--" << "--" << "\n";
    std::cout << "O " << "| " << "X " << "| " << "O " << "\n";
}