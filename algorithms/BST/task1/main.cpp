#include <iostream>
#include "vector"

void printPreOrder(const std::vector<long>& v, int start, int end) {
    if (start <= end) {
        int half = start + (end - start) / 2;
        std::cout << v[half] << " ";
        printPreOrder(v, start, half - 1);
        printPreOrder(v, half + 1, end);
    }
}

int main() {

    int n;
    std::cin >> n;
    std::vector<long> vector(n);

    for (int i = 0; i < n; i++) {
        std::cin >> vector[i];
    }

    printPreOrder(vector, 0, vector.size() - 1);
    return 0;
}

