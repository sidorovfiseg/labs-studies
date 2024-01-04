//
// Created by egor on 13.12.23.
//
#include "iostream"
#include "vector"

double findMin(std::vector<double>& arr) {
    double left = 0;
    double right = arr[0];
    while (right - left > 0.01) {
        arr[1] = (left + right) / 2;
        bool flag = true;
        for (int i = 2; i < arr.size(); i++) {
            arr[i] = 2 * arr[i - 1] - arr[i - 2] + 2;
            if (arr[i] < 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            right = arr[1];
        else
            left = arr[1];
    }

    return arr[arr.size() - 1];
}

int main() {
    
    int n;
    double A;

    
    std::cin >> n;
    std::vector<double> arr(n);
    std::cin >> arr[0];
    std::cout.precision(3);

    std::cout << findMin(arr);

    return 0;
}