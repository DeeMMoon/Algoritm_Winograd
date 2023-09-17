#include "winograd.h"

bool isNumeric(std::string const &str) {
  auto it = str.begin();
  while (it != str.end() && std::isdigit(*it)) {
    it++;
  }
  return !str.empty() && it == str.end();
}

void showMatrix(const std::vector<std::vector<int> >& matrix) {
	for (const auto& row : matrix) {
		for (const auto& element : row) {
			std::cout << element << " ";
		}
	std::cout << std::endl;
	}
}

int getRows(const std::vector<std::vector<int> >& matrix) {
	if (matrix.empty())
		return 0; 
	return matrix.size();
}

int getCols(const std::vector<std::vector<int> >& matrix) {
	if (matrix.empty())
		return 0; 
	return matrix[0].size();
}

int checkMatrix(std::vector<std::vector<int> > matrix1, std::vector<std::vector<int> > matrix2) {
	int row2 = getRows(matrix2);
	int col1 = getCols(matrix1);
	if (row2 == col1)
		return(1);
	else {
		std::cout << "I can't do matrix multiplication. The number of columns in the first matrix must be equal to the number of rows in the second matrix. Try again!" << std::endl;
		return (0);
	}
}

void showInterface(){
	std::cout << "Choose your iput:" << std::endl;
	std::cout << "1. Input 2 matrix" << std::endl;
	std::cout << "2. Input matrix size and fill random" << std::endl;
	std::cout << "3. Exit" << std::endl;
}