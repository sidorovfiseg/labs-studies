//
// Created by egor on 12.12.23.
//

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

std::vector<int> kms(const std::string& pattern, const std::string& text) {
    int pl = pattern.length();
    std::vector<int> answer;
    std::vector<int> pi = prefix(pattern + "#" + text);

    for (int i = 0; i < text.length(); i++) {
        if (pi[pl + i + 1] == pl)
            answer.push_back(i - pl);
    }
    return answer;
}

int main() {
    std::string text;
    std::string pattern;

    std::cin >> text;
    std::cin >> pattern;
    std::vector<int> v = kms(pattern, text);
    std::cout << v.size() << std::endl;
    for (int i : v) {
        std::cout << i + 1 << " ";
    }
}


