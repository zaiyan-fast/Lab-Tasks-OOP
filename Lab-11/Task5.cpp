#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;

// Custom exception for stack underflow
class StackUnderflowException : public runtime_error {
public:
    StackUnderflowException(const string& message) : runtime_error(message) {}
};

template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    // Push an element onto the stack
    void push(const T& item) {
        elements.push_back(item);
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            throw StackUnderflowException("Cannot pop from an empty stack");
        }
        elements.pop_back();
    }

    // Get the top element of the stack
    T& top() {
        if (isEmpty()) {
            throw StackUnderflowException("Cannot access top of an empty stack");
        }
        return elements.back();
    }

    const T& top() const {
        if (isEmpty()) {
            throw StackUnderflowException("Cannot access top of an empty stack");
        }
        return elements.back();
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Get the size of the stack
    size_t size() const {
        return elements.size();
    }
};

int main() {
    Stack<int> stack;

    try {
        // Test pushing elements
        cout << "Pushing elements: 10, 20, 30" << endl;
        stack.push(10);
        stack.push(20);
        stack.push(30);
        cout << "Stack size: " << stack.size() << endl;
        cout << "Top element: " << stack.top() << endl;

        // Test popping elements
        cout << "\nPopping elements:" << endl;
        while (!stack.isEmpty()) {
            cout << "Popped: " << stack.top() << endl;
            stack.pop();
        }

        // Test pop on empty stack
        cout << "\nAttempting to pop from empty stack:" << endl;
        stack.pop();
    }
    catch (const StackUnderflowException& e) {
        cout << "Caught expected exception: " << e.what() << endl;
    }

    try {
        // Test top on empty stack
        cout << "\nAttempting to access top of empty stack:" << endl;
        stack.top();
    }
    catch (const StackUnderflowException& e) {
        cout << "Caught expected exception: " << e.what() << endl;
    }

    // Test with strings
    Stack<string> stringStack;
    try {
        cout << "\nPushing strings: 'hello', 'world'" << endl;
        stringStack.push("hello");
        stringStack.push("world");
        cout << "Top string: " << stringStack.top() << endl;
        stringStack.pop();
        cout << "Popped one string, top now: " << stringStack.top() << endl;
    }
    catch (const StackUnderflowException& e) {
        cout << "Caught unexpected exception: " << e.what() << endl;
    }

    return 0;
}