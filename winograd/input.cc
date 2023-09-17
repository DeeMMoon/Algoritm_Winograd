#include "winograd.h"

std::vector<std::vector<int> > generateRandomMatrix(){
    long rows, cols;
	std::string strRows, strCols;
	while(true){
		std::cout << "Input count of rows:" << std::endl;
		std::cin >> strRows;
		if (strRows.length() > 10 || !isNumeric(strRows)){
			std::cout << "Error: incorrect input. Try input this line again.\n";
			continue;
		}
		rows = std::atoi(const_cast<char *>(strRows.c_str()));
		if (rows <= 0 || rows > 2147483647){
			std::cout << "Error: incorrect input. Try input this line again.\n";
			continue;
		}
		std::cout << "Input count of cols:" << std::endl;
		std::cin >> strCols;
		if (strRows.length() > 10 || !isNumeric(strCols)){
			std::cout << "Error: incorrect input. Try input this line again.\n";
			continue;
		}
		cols = std::atoi(const_cast<char *>(strCols.c_str()));
		if (cols <= 0 || cols > 2147483647){
			std::cout << "Error: incorrect input. Try input this line again.\n";
			continue;
		}
		std::vector<std::vector<int> > matrix(rows, std::vector<int>(cols, 0));
    	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
				matrix[i][j] = rand() % 210 - 100;
			}
		}
    	return matrix;
	}
}

std::vector<std::vector<int> > inputMatrix(int count_input) {
	std::vector<std::vector<int> > matrix;
	std::string input;
	int value;
	int numRows = 0;
	int numCols = 0;
	std::cout << "Input matrix values. If you want to end then input empty line:\n";
	if (count_input == 1)
		std::cin.ignore();
	while (true) {
		std::getline(std::cin, input);

		if (input.empty())
			break;
		std::vector<int> row;
		std::istringstream iss(input);
		while (iss >> value) {
			row.push_back(value);
		}
		if (!iss.eof()) {
			std::cout << "Error: incorrect input. Try input this line again.\n";
			continue;
		}
		if (numRows > 0 && (int)row.size() != numCols) {
			std::cout << "Error: matrix rows must be the same length. Try input this line again.\n";
			continue;
		}
		matrix.push_back(row);
		numRows++;
		numCols = row.size();
	}
	if (matrix.empty()) {
		std::cout << "Error: matrix can't be empty.\n";
		return inputMatrix(2);
	}
	return matrix;
}

int inputN(){
	std::string strN;
	long N = 0;
	std::cout << "Input the number of runs" << std::endl;
	while(true){
		std::cin >> strN;
		if (!isNumeric(strN) || strN.length() > 10){
			std::cout << "Incorrect input. Try again!" << std::endl;
			continue;
		}
		N = std::atoi(const_cast<char *>(strN.c_str()));
		if (N < 0 || N > 2147483647){
			std::cout << "Incorrect input. Try again!" << std::endl;
			continue;
		}
		return (N);
	}
}