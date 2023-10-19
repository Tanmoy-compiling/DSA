#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Create a vector of integers
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Search for the value 3 in the vector
    int valueToFind = 3;
    auto it = std::find(vec.begin(), vec.end(), valueToFind);

    // Check if the value was found
    if (it != vec.end()) {
        std::cout << "Value " << valueToFind << " found at position " << it - vec.begin() << std::endl;
    } else {
        std::cout << "Value " << valueToFind << " not found in vector" << std::endl;
    }

    return 0;
}