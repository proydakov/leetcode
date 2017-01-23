#pragma once

class MinStack {
public:
    MinStack() {
    }
    
    void push(int x) {
        items_.push(x);
        if(mins_.empty() || x <= mins_.top()) {
            mins_.push(x);
        }
    }
    
    void pop() {
        int item = items_.top();
        items_.pop();
        if(item == mins_.top()) {
            mins_.pop();
        }
    }
    
    int top() {
        return items_.top();
    }
    
    int getMin() {
        return mins_.top();
    }

private:
    std::stack<int> items_;
    std::stack<int> mins_;
};
