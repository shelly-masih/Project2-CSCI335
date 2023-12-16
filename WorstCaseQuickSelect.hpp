#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> worstCaseQuickSelect() {
    const int size = 20000;
    std::vector<int> worstCaseVector(size);
    
    // Generate a sorted vector from 1 to 20000
    for (int i = 1; i <= size; ++i) {
        worstCaseVector[i - 1] = i;
    }
    
    // Shuffle the vector to make it harder for quickselect
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(worstCaseVector.begin(), worstCaseVector.end(), g);
    
    return worstCaseVector;
}

int main() {
    // Generate worst-case vector
    std::vector<int> worstCaseVector = worstCaseQuickSelect();

    // Call your QuickSelect function and measure its duration
    int duration;
    int result = quickSelect(worstCaseVector, duration);

    // Print the result and duration
    std::cout << "Result: " << result << std::endl;
    std::cout << "Duration: " << duration << " milliseconds" << std::endl;

    return 0;
}
