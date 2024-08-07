#include<iostream>
using namespace std;

class Stack {

    public:
        int *arr;
        int size;
        int top;

    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    } 

    void push(int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if(top >= 0 && top < size) {
            top--;
        }
        else {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek() {
        if(top >= 0 && top < size) {
            return arr[top];
        }
        else {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool empty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    cout << "top ele: " << st.peek() << endl;

    st.pop();
    cout << "top ele: " << st.peek() << endl;
    st.pop();
    cout << "top ele: " << st.peek() << endl;
    st.pop();
    cout << "top ele: " << st.peek() << endl;

    if(st.empty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}