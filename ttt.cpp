#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "functions.hpp"

int main() {
  std::vector<std::vector<int>> game_state(3, std::vector<int>(3)); // initialize a 3x3 vector filled with zeros.
  std::vector<std::vector<std::string>> state_string_vec = InitializeStateStringVec();

  int user_input = 0; 
  bool player1 = true;

  int winner = 0;
  int i = 0;
  
  Greet();

  std::cout << ViewStateString(state_string_vec);

  while (i < 9 && winner == 0) {
    std::cout << ((player1)? "Player 1: " : "Player 2: ");
    std::cin >> user_input;
   
    if (CheckUserInputValidity(game_state, user_input)) {
      UpdateState(state_string_vec, game_state, player1, user_input);
      player1 = !player1;
      winner = CheckWinner(game_state);
      i++;
    } else {
      std::cout << "Invalid Input\n";
    }

    std::cout << ViewStateString(state_string_vec);
  }

  if (i == 9) {
    std::cout << "TIE!\n";
  } else {
    std::cout << ((winner == 1)? "Player 1 " : "Player 2 ") << "Won!";
  }
}