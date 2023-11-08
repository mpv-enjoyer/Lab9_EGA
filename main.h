#pragma once
#include <random>
#include <vector>
#include <iostream>
#include <ctime>
#include <fstream>

// Функции для вычисления точного оптимального значения
void print_optimal(std::vector<std::vector<float>>& distance);
void optimal_internal(std::vector<bool> used, std::vector<int> trace, float overall_distance, std::vector<std::vector<float>>& distance);
bool is_optimal(float input, bool RESET = false);
std::vector<int> get_current_optimal_trace(std::vector<int> trace_input = {});
// ...

// Разное
std::string to_string(std::vector<int> input);
int randomint(int included_min, int included_max);
float randomfloat(float included_min, float included_max);
void print_step(int step, std::vector<int> trace, int selected_town_in, int selected_town_out, float overall_distance, float distance);
void print_step(int step, std::vector<int> trace, int selected_town, float distance, float overall_distance);
// ...

std::vector<int> method_city(int N, std::vector<std::vector<float>>& distance, int step, int start_from, bool enable_dumb_insert = true);
std::vector<int> method_neighbour(int N, std::vector<std::vector<float>>& distance);