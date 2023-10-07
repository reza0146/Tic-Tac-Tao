#ifndef TIC_TAC_TAO_FUNCTIONS_H_
#define TIC_TAC_TAO_FUNCTIONS_H_

#include <vector>
#include <string>
#include <algorithm>

std::string ViewVec(std::vector<std::vector<int>> vector2d);
std::string ViewVec(std::vector<int> vec);

std::vector<int> MainDiagonal(std::vector<std::vector<int>> vector2d);
std::vector<int> AntiDiagonal(std::vector<std::vector<int>> vector2d);
std::vector<std::vector<int>> TransposeVec(std::vector<std::vector<int>> vector2d);

int SumVec(std::vector<int> vec);
std::vector<int> SumRow(std::vector<std::vector<int>> vector2d);
std::vector<int> SumColumn(std::vector<std::vector<int>> vector2d);

void Greet();
std::vector<std::vector<std::string>> InitializeStateStringVec();
std::string ViewStateString(std::vector<std::vector<std::string>> state_string_vec);
void UpdateState(std::vector<std::vector<std::string>> &state_string_vec_ref, std::vector<std::vector<int>> &game_state_ref, bool player1, int cell);

bool CheckUserInputValidity(std::vector<std::vector<int>> game_state_vec, int cell);
int CheckWinner(std::vector<std::vector<int>> game_state_vec);

#endif