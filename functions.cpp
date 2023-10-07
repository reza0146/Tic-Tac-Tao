#include "functions.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

const int kValidValues[] = {11, 21, 31, 12, 22, 32, 13, 23, 33};

std::string ViewVec(std::vector<std::vector<int>> vector2d) {
  std::string vec_string;

  for(int i = 0; i < vector2d.size(); i++) {
    for (int j = 0; j < vector2d[0].size(); j++) {
      vec_string += std::to_string(vector2d[i][j]) + " ";
    }
    vec_string += "\n";
  } 

  return vec_string;
}

std::string ViewVec(std::vector<int> vec) {
  std::string vec_string;
  
  for (int num : vec) {
    vec_string += std::to_string(num) + " "; 
  }

  vec_string += "\n";
  return vec_string;
}

std::vector<int> MainDiagonal(std::vector<std::vector<int>> vector2d) {
  std::vector<int>  diag(vector2d.size(), 0);

  for (int i = 0; i < vector2d.size(); i++) {
    diag[i] = vector2d[i][i];
  }

  return diag;
}

std::vector<int> AntiDiagonal(std::vector<std::vector<int>> vector2d) {
  std::vector<int> anti_diag(vector2d.size(), 0);

  for (int i = 0; i < vector2d.size(); i++) {
    anti_diag[i] = vector2d[vector2d.size()-1-i][i];
  }

  return anti_diag;
}

std::vector<std::vector<int>> TransposeVec(std::vector<std::vector<int>> vector2d) {
  int temp;

  for(int i = 0; i < vector2d.size(); i++) {
    for (int j = i; j < vector2d[0].size(); j++) {
      if (i != j) {
        temp = vector2d[i][j];
        vector2d[i][j] = vector2d[j][i];
        vector2d[j][i] = temp;
      }
    }
  } 

  return vector2d;   
}

int SumVec(std::vector<int> vec) {
  int sum = 0;
  
  for (int num : vec) {
    sum += num;
  }
  
  return sum;
}

std::vector<int> SumRow(std::vector<std::vector<int>> vector2d) {
  std::vector<int> sum(vector2d.size());

  for (int i = 0; i < vector2d.size(); i++) {
    sum[i] = SumVec(vector2d[i]);
  } 

  return sum;
}

std::vector<int> SumColumn(std::vector<std::vector<int>> vector2d) {
  return SumRow(TransposeVec(vector2d));
}

void Greet() {
  std::cout << "====TIC TAC TAO====\n"
                "Welcome to the Game!\n"
                "To select a cell, input a two-digit number in the format <row#><column#>.\n"
                "Example: If you want to select the cell in the third row and the second column, enter 32.\nEnjoy!\n";
}

std::vector<std::vector<std::string>> InitializeStateStringVec() {
  std::vector<std::vector<std::string>> state_string_vec(5, std::vector<std::string>(5, "  "));

  for (int i = 0; i < state_string_vec.size(); i++) {
    for (int j = 0; j < state_string_vec[0].size(); j++) {
      if (i %2 == 0) { 
        state_string_vec[i][1] = "| ";
        state_string_vec[i][3] = "| ";
      } else {
        state_string_vec[i][j] = "--";
      }
    }
  }

  return state_string_vec;
}

std::string ViewStateString(std::vector<std::vector<std::string>> state_string_vec) {
  std::string state_string;

  for (auto vec : state_string_vec) {
    for (auto str : vec) {
      state_string += str;
    }
    state_string += "\n";
  }

  return state_string;
}

void UpdateState(std::vector<std::vector<std::string>> &state_string_vec_ref, std::vector<std::vector<int>> &game_state_ref, bool player1, int cell) {
  int row = cell / 10 - 1;
  int col = cell % 10 - 1;

  int state_value = (player1)? -1 : 2;
  std::string state_string = (player1)? "X " : "O "; 

  game_state_ref[row][col] = state_value;
  state_string_vec_ref[row*2][col*2] = state_string; 
}

bool CheckUserInputValidity(std::vector<std::vector<int>> game_state_vec, int cell) {
  int row = cell / 10 - 1;
  int col = cell % 10 - 1;

  if (std::find(std::begin(kValidValues), std::end(kValidValues), cell) == std::end(kValidValues)) {
    return false;
  } else if (game_state_vec[row][col] != 0) {
    return false;
  } else {
    return true;
  }
}

int CheckWinner(std::vector<std::vector<int>> game_state_ref) {  
  std::vector<int> search_vec;
  std::vector<int> row_sum = SumRow(game_state_ref);
  std::vector<int> column_sum = SumColumn(game_state_ref);
  int diag_sum = SumVec(MainDiagonal(game_state_ref));
  int anti_diag_sum = SumVec(AntiDiagonal(game_state_ref));
  
  search_vec.insert(search_vec.end(), row_sum.begin(), row_sum.end()); 
  search_vec.insert(search_vec.end(), column_sum.begin(), column_sum.end()); 
  search_vec.insert(search_vec.end(), diag_sum);
  search_vec.insert(search_vec.end(), anti_diag_sum);

  if (std::find(search_vec.begin(), search_vec.end(), -3) != search_vec.end()) {
    return 1;
  } else if (std::find(search_vec.begin(), search_vec.end(), 6) != search_vec.end()) {
    return 2;
  } else {
    return 0;
  }   
}