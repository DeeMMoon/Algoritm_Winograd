#ifndef GENETIC_H
#define GENETIC_H

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <random>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stdlib.h>
#include <limits>

std::vector<std::vector<int> > generateRandomMatrix();
std::vector<std::vector<int> > inputMatrix(int count_input);
int inputN();

bool isNumeric(std::string const &str);
void showMatrix(const std::vector<std::vector<int> >& matrix);
int getRows(const std::vector<std::vector<int> >& matrix);
int getCols(const std::vector<std::vector<int> >& matrix);
int checkMatrix(std::vector<std::vector<int> > matrix1, std::vector<std::vector<int> > matrix2);
void showInterface();
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2);

#endif