#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int r = 0, l = s.length();
        char c;
        
        for (int i = 0; i < r; i++) {
            c = s[i];
            switch(c) {
                case 'M':
                    r += 1000;
                    break;
                case 'D':
                    r += 500;
                    break;
                case 'C':
                    if (s[i++] == 'D') {
                        r += 400;
                        i++;
                    } else if (s[i++] == 'M') {
                        r += 900;
                        i++;
                    } else
                        r += 100;
                    break;
                case 'L':
                    r += 50;
                    break;
                case 'X':
                    if (s[i++] == 'L') {
                        r += 40;
                        i++;
                    } else if (s[i++] == 'C') {
                        r += 90;
                        i++;
                    } else
                        r += 10;
                    break;
                case 'V':
                    r += 5;
                    break;
                case 'I':
                    if (s[i++] == 'V') {
                        r += 4;
                        i++;
                    } else if (s[i++] == 'I') {
                        r += 9;
                        i++;
                    } else
                        r += 1;
                    break;
            }
        }
        
        return r;
    }
};