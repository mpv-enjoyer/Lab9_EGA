#include "main.h"

// Код функций для вычисления точного оптимального значения
void print_optimal(std::vector<std::vector<float>>& distance)
{
    for (int i = 0; i < distance.size(); i++)
    {
        std::vector<bool> used;
        for (int j = 0; j < distance.size(); j++)
        {
            if (i == j) used.push_back(1);
            else used.push_back(0);
        }
        optimal_internal(used, { i }, 0, distance);
    }
}
bool is_optimal(float input, bool RESET)
{
    static int current_optimal = __INT_MAX__;
    if (RESET) 
    {
        current_optimal = __INT_MAX__;
        return 0;
    }
    if (input < current_optimal) 
    {
        current_optimal = input;
        return true;
    }
    return false;
}
void optimal_internal(std::vector<bool> used, std::vector<int> trace, float overall_distance, std::vector<std::vector<float>>& distance)
{
    bool is_done = true;
    for (int i = 0; i < distance.size(); i++)
    {
        if (used[i]) continue;
        std::vector<bool> new_used = used;
        new_used[i].flip();
        std::vector<int> new_trace = trace;
        new_trace.push_back(i);
        is_done = false;
        optimal_internal(new_used, new_trace, overall_distance + distance[trace[trace.size() - 1]][i], distance);
    }
    if (is_done && is_optimal(overall_distance + distance[trace[trace.size() - 1]][trace[0]]))
    {
        std::cout << to_string(trace) << " " << overall_distance + distance[trace[trace.size() - 1]][trace[0]] <<"\n";
    }
}

// Разное
std::string to_string(std::vector<int> input)
{
    std::string output = "[ ";
    for (int i = 0; i < input.size(); i++)
    {
        output.append(std::to_string(input[i]) + " ");    
    }
    output.append("]");
    return output;
}
int randomint(int included_min, int included_max)
{
    static std::default_random_engine rng(time(NULL));
    std::uniform_int_distribution<int> dist(included_min, included_max); 
    dist(rng);
    return dist(rng); 
}
float randomfloat(float included_min, float included_max)
{
    static std::default_random_engine rng(time(NULL));
    std::uniform_real_distribution<float> dist(included_min, included_max); 
    dist(rng);
    return dist(rng); 
}
void print_step(int step, std::vector<int> trace, int selected_town_in, int selected_town_out, float overall_distance, float distance)
{
    std::cout << "STEP " << step << ") Trace " << to_string(trace) << " Select " << selected_town_in << "-->" << selected_town_out
    << " Distance " << distance << " Overall Distance " << overall_distance << "\n";
}
void print_step(int step, std::vector<int> trace, int selected_town, float distance, float overall_distance)
{
    std::cout << "STEP " << step << ") Trace " << to_string(trace) << " Select " << selected_town 
    << " Distance " << distance << " Overall Distance " << overall_distance << "\n";
}
// ...