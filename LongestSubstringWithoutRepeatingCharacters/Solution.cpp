#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int longestLength = 1;
    unordered_map<char, char> bank;

    int LENGTH = s.length();
    for (int c = 0; c < LENGTH - 1; c++) {
        for (int i = c; i < LENGTH; i++) {
            if (bank.find(s[i]) != bank.end())
                break;
            else {
                bank.insert({s[i], s[i]});
            }
        }
        longestLength = (longestLength < bank.size()) ? bank.size() : longestLength;
        bank.empty();
    }

    return longestLength;
}

int main() {
    string str = "pwwkew";

    cout << lengthOfLongestSubstring(str) << endl;

    return 0;
}