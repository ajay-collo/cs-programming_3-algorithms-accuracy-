#include <iostream>
#include <vector>

int find_linear(int n) {
    if (n == 1) {
        return 1;
    }
    return n + find_linear(n - 1);
}

int binary_search(const std::vector<int>& arr, int low, int high, int key) {
    if (low > high) {
        return -1;
    }
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == key) {
        return mid;
    } else if (arr[mid] > key) {
        return binary_search(arr, low, mid - 1, key);
    } else {
        return binary_search(arr, mid + 1, high, key);
    }
}

void merge(std::vector<int>& arr, int low, int mid, int high) {
    std::vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
    std::vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);

    size_t i = 0, j = 0;
    int k = low;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void merge_sort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    std::cout << find_linear(5) << std::endl;

    std::vector<int> data = {2, 4, 6, 8, 10, 12, 14};
    std::cout << binary_search(data, 0, data.size() - 1, 10) << std::endl;

    std::vector<int> unsorted = {38, 27, 43, 3, 9, 82, 10};
    merge_sort(unsorted, 0, unsorted.size() - 1);
    
    for (int val : unsorted) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}