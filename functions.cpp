#include "functions.hpp"

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

}

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

int SumVec(std::vector<int> vec) {
    
    int sum = 0;
    
    for (int num : vec) {
        sum += num;
    }
    
    return sum;
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
