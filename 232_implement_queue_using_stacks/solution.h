#pragma once

#include <stack>

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        input_.emplace(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        translate();
        int top = output_.top();
        output_.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        translate();
        int top = output_.top();
        return top;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return input_.empty() && output_.empty();
    }

private:
    /** Input stack to output. */
    inline void translate() {
        if(!output_.empty()) {
            return;
        }
        while(!input_.empty()) {
            int top = input_.top();
            input_.pop();
            output_.emplace(top);
        }
    }

private:
    std::stack<int> input_;
    std::stack<int> output_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
