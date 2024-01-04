#include "iostream"
#include "vector"

int leftBinarySearch(const std::vector<int>& arr, int value) {
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        if (arr[left] < value) {
            left = left + (right - left + 1) / 2;
        } else if (arr[left] >= value) {
            int temp = left;
            left = left - (right - left + 1) / 2;
            if (left < 0) {
                left = 0;
                break;
            }
            right = temp;
        }
    }

    if (arr[left] == value) {
        return left + 1;
    }

    return -1;
}

int rightBinarySearch(const std::vector<int>& arr, int value) {
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        if (arr[right] > value) {
            right = right - (right - left + 1) / 2;
        } else if (arr[right] <= value) {
            int temp = right;
            right = right + (right - left + 1) / 2;
            if (right > arr.size() - 1) {
                right = arr.size() - 1;
                break;
            }
            left = temp;
        }
    }
    if (arr[right] == value) {
        return right + 1;
    }

    return -1;
}


int main() {

    int n, m, value;
    std::cin >> n;
    std::vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cin >> m;
    for(int i = 0; i < m; i++) {
        std::cin >> value;
        std::cout << leftBinarySearch(arr, value) << " " << rightBinarySearch(arr, value) << std::endl;

    }

    return 0;
}