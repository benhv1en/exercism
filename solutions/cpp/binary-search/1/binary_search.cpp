#include "binary_search.h"
#include <stdexcept>
#include <iostream>
namespace binary_search {
// TODO: add your solution here
size_t BinarySearch(std::vector<int> data, int start, int end, int number) {
        if (start > end) {
            throw std::domain_error("Not found");
            return -1;
        }
        int middle = (start + end) / 2;
        if (number == data[middle]) return middle;
        else if (number < data[middle]) return BinarySearch(data, start, middle - 1, number);
        else return BinarySearch(data, middle + 1, end, number);
}
size_t find(std::vector<int> data, int number) {
    try {
        return BinarySearch(data, 0, data.size() - 1, number);
    }
    catch (std::domain_error& error) {
        std::cout << error.what() << "\n";
    }
    return BinarySearch(data, 0, data.size() - 1, number);
}    
}  // namespace binary_search
