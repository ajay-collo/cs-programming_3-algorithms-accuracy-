#include <iostream>
#include <vector>

// Structure to represent a Task
struct Task {
    int id;
    int time;
};

// Function implementing the exact pseudocode logic
std::vector<Task> task_study(const std::vector<Task>& Tasks, int n, int ava_time) {
    std::vector<Task> best_set;
    int best_count = 0;

    int total_subsets = 1 << n; // 2^n subsets

    // Loop for each Subset S (2^n combinations)
    for (int mask = 0; mask < total_subsets; ++mask) {
        std::vector<Task> current_subset;
        int total_time = 0;

        // Loop for each task in current subset S
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) { // If the i-th task is included in this subset
                current_subset.push_back(Tasks[i]);
                total_time += Tasks[i].time;
            }
        }

        // Check feasibility: total_time <= ava_time
        if (total_time <= ava_time) {
            // Maximizing count: if |S| > best_count
            if (current_subset.size() > best_count) {
                best_count = current_subset.size();
                best_set = current_subset;
            }
        }
    }

    return best_set;
}

int main() {
    // Example test setup
    std::vector<Task> Tasks = {
        {1, 3},  // Task 1: 3 hours
        {2, 1},  // Task 2: 1 hour
        {3, 4},  // Task 3: 4 hours
        {4, 2}   // Task 4: 2 hours
    };
    int n = Tasks.size();
    int ava_time = 5;

    std::vector<Task> result = task_study(Tasks, n, ava_time);

    std::cout << "Maximum tasks completed: " << result.size() << "\n";
    std::cout << "Selected Tasks (IDs): ";
    for (const auto& task : result) {
        std::cout << task.id << " ";
    }
    std::cout << "\n";

    return 0;
}