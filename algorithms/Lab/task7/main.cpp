#include "iostream"
#include "string"
#include "vector"

std::vector<int> prefix(const std::string& text) {
    std::vector<int> pi(text.length());
    pi[0] = 0;
    int k;
    for (int i = 1; i < text.length(); i++) {
        k = pi[i - 1];
        while (k > 0 && text[i] != text[k]) {
            k = pi[k - 1];
        }
        if (text[i] == text[k])
            k++;
        pi[i] = k;

    }
    return pi;
}


int main() {
    std::string text;
    std::cin >> text;
    std::vector<int> v = prefix(text);
    for (int i : v) {
        std::cout << i << " ";
    }
}