#ifndef TASK1_H
#define TASK1_H

#include <vector>
#include <fstream>

void ReadData(std::ifstream& input, int& num_artifact, int& min_weight, std::vector<int>& weight, std::vector<int>& nalog);

int CalculateMaxWeight(const std::vector<int>& weight);

std::vector<std::vector<int>> SolveKnapsack(int num_artifact, int max_weight, const std::vector<int>& weight, const std::vector<int>& nalog);

void FindAndPrintSolution(const std::vector<std::vector<int>>& list_artifacts, int num_artifact, int min_weight, int max_weight, std::vector<int>& weight, std::vector<int>& nalog);

void FindAnswer(const std::vector<std::vector<int>>& dp, int k, int s, std::vector<int>& weight, std::vector<int>& nalog);

#endif // TASK1_H