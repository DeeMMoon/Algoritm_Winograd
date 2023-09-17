#include "winograd.h"

void printMatrixAndInputN(std::vector<std::vector<int> > matrix1, std::vector<std::vector<int> > matrix2){
	std::cout << "Your first matrix:" << std::endl;
	showMatrix(matrix1);
	std::cout << "Your second matrix:" << std::endl;
	showMatrix(matrix2);
	if(checkMatrix(matrix1, matrix2)){
		int N = inputN();
		for(int i = 0; i < N; i++){
			showMatrix(multiplyMatrices(matrix1, matrix2));
			std::cout<<std::endl;
		}
	}
}

int main(){
	char input = '0';
	while(input != '3'){
		showInterface();
		std::cin >> input;
		switch(input){
			case '1': {
				std::cout << "Input first matrix:" << std::endl;
				std::vector<std::vector<int> > matrix1 = inputMatrix(1);
				std::cout << "Input second matrix:" << std::endl;
				std::vector<std::vector<int> > matrix2 = inputMatrix(2);
				printMatrixAndInputN(matrix1, matrix2);
				break;
			}
			case '2': {
				std::cout << "Input information for first matrix:" << std::endl;
				std::vector<std::vector<int> > matrix1 = generateRandomMatrix();
				std::cout << "Input information for second matrix:" << std::endl;
				std::vector<std::vector<int> > matrix2 = generateRandomMatrix();
				printMatrixAndInputN(matrix1, matrix2);
				break;
			}
			case '3': {
				std::cout << "Good Bye!" << std::endl;
				return 0;
			}
			default: {
				std::cout << "Incorrect input, try again!" << std::endl;
        		break;
			}
		}
	}
}