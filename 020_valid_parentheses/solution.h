#pragma once

#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for(size_t i = 0; i < s.size(); i++) {
            char c = s[i];
            switch(c) {
                case ')':
                case ']':
                case '}':
                {
                    if(stack.empty()) {
                        return false;
                    }
                    char top = stack.top();
                    stack.pop();
                    char pair = getPair(top);
                    if(c != pair) {
                        return false;
                    }
                }
                    break;
                
                case '(':
                case '[':
                case '{':
                    stack.push(c);
                    break;
                
                default:
                    return false;
                    break;
            }
        }
        return stack.empty();
    }

private:
    char getPair(char c) {
        switch(c) {
            case '(':
                return ')';
            
            case '{':
                return '}';
                
            case '[':
                return ']';
        }
        return c;
    }
};
