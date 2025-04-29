//Program to process a given string and remove "+" symbol
#include <iostream>
#include <Stack.h>

std::string processString(const std::string &input) {
    std::stack<char> s;

    for (char ch : input) {
        if (ch == '+') {
            if (!s.empty()) {
                s.pop(); 
            }
        } else {
            s.push(ch); 
        }
    }

    
    std::string result;
    while (!s.empty()) {
        result = s.top() + result; 
        s.pop();
    }

    return result;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    std::string output = processString(input);
    std::cout << "Output: " << output << std::endl;

    return 0;
}
