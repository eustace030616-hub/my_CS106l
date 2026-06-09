#include <iostream>
#include <vector>

/* Returns highest temperature,
   or -1 if no temperatures given. */
int findPeakHeat(const std::vector<int>& temps) {
    // Write your implementation here.
    int size = 6;
    int biggest = 0;
    for (int i = 0; i <= size; i++) {
        if (temps[i] > biggest) {
            biggest = temps[i];
        } else {
            continue;
        }
    }
    return biggest;
}

int main() {
    // High temperatures forecast for the next 7 days.
    std::vector<int> weeklyForecast = {82, 95, 102, 99, 88, 79, 81};

    std::cout << "--- Weather Report ---" << std::endl;
    std::cout << "Max temp this week will be " << findPeakHeat(weeklyForecast) << std::endl;
    return 0;
}