#include <iostream>
#include <vector>

// Function to partition the array into two segments.
// Elements less than the pivot go to the left, and elements greater go to the right.
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            std::swap(arr[i], arr[j]);
        }
    }

    // Swap arr[i + 1] and arr[high] (pivot)
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform Quick Sort on the array.
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array into two segments.
        int pi = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    std::cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Perform Quick Sort
    quickSort(arr, 0, n - 1);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
