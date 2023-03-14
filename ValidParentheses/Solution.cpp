#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool isValid(string);

int main() {
    
    string p = "{()}[]";
    cout << "Is string p valid? > " << isValid(p) << endl;

    return 0;
}

bool isValid(string s) {
    stack<char> buffer;
    for (char bracket : s) {
        if (bracket == '(' || bracket == '[' || bracket == '{')
            buffer.push(bracket);
        else if (!buffer.empty()) {
            if (bracket == ')' && buffer.top() == '(')
                buffer.pop();
            else if (bracket == ']' && buffer.top() == '[')
                buffer.pop();
            else if (bracket == '}' && buffer.top() == '{')
                buffer.pop();
            else
                return false;
        } else
            return false;
    }
    return buffer.empty();
}