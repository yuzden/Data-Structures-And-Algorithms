/**#include <iostream>
#include <vector>

struct Node {
    long data;
    Node* previous = nullptr;

    Node(long data, Node* previous = nullptr) {
        this->data = data;
        this->previous = previous;
    }
};

class Stack {
private:
    Node* top = nullptr;
public:
    Stack() = default;

    void push(long number) {
        if (isEmpty()) {
            top = new Node(number);
        }
        else {
            Node* newTop = new Node(number, top);
            top = newTop;
        }
    }

    void pop() {
        if (!isEmpty()) {
            Node* oldTop = top;
            top = top->previous;
            delete oldTop;
        }
        else {
            return;
        }
    }

    void battle(long& num) {
        if (!isEmpty()) {
            if (top->data < 0 && num > 0) {
                this->push(num);
                return;
            }

            if (top->data > 0 && num > 0) {
                this->push(num);
                return;
            }

            if (top->data < 0 && num < 0) {
                this->push(num);
                return;
            }

            if (top->data > 0 && num < 0) {
                if (top->data > abs(num)) {
                    return;
                }
                else if (top->data < abs(num)) {
                    this->pop();
                    this->battle(num);
                }
                else if (top->data == abs(num)) {
                    this->pop();
                }
            }
        }
        else {
            this->push(num);
        }
    }

    long peek() const {
        if (!isEmpty()) {
            return top->data;
        }
        else {
            return 0;
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

int main() {
    int N;
    std::cin >> N;
    Stack S;

    long temp;
    std::cin >> temp;
    S.push(temp);

    for (auto i = 1; i < N; i++) {
        std::cin >> temp;
        S.battle(temp);
    }

    if (S.peek() == 0) {
        std::cout << '\n';
        return 0;
    }

    std::vector <long>output;
    while (!S.isEmpty()) {
        output.push_back(S.peek());
        S.pop();
    }

    long size = output.size() - 1;
    for (auto i = size; i >= 0; i--) {
        std::cout << output[i] << " ";
    }
    return 0;
}**/