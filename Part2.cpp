// Q2: Recursive Linear Search - Last Occurrence 


#include <iostream>
#include <vector>

template<typename T>
int recursiveLinearSearch(const std::vector<T>& vec, const T& target, int index) {
    if (index < 0) {
        return -1; // Element not found
    }
    if (vec[index] == target) {
        return index; // Found the target element
    }
    return recursiveLinearSearch(vec, target, index - 1);
}

int main() {
    std::vector<int> vec = { 2, 5, 3, 7, 9, 5, 8, 3, 5 };
    int target = 5;
    int lastIndex = recursiveLinearSearch(vec, target, vec.size() - 1);

    if (lastIndex != -1) {
        std::cout << "Last occurrence of " << target << " is at index: " << lastIndex << std::endl;
    }
    else {
        std::cout << "Element not found in the vector." << std::endl;
    }

    return 0;
}

