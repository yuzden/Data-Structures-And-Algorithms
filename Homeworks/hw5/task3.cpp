/**#include <iostream>

struct Node {
    long data;
    Node* previous = nullptr;

    Node(long data, Node* previous = nullptr) {
        this->data = data;
        this->previous = previous;
    }
};

class Queue {
private:
    Node* front = nullptr;
    Node* back = nullptr;
    Node* min = nullptr;
public:
    Queue() = default;

    void push(long number) {
        if (isEmpty()) {
            front = new Node(number);
            back = front;
            min = front;
        }
        else {
            back->previous = new Node(number);
            back = back->previous;
            if (back->data < min->data) {
                min = back;
            }
        }
    }

    void pop() {
        if (!isEmpty()) {
            Node* oldFront = front;
            front = front->previous;

            if (oldFront == min) {
                Node* temp = front;
                min = temp;
                while (temp != nullptr) {
                    if (temp->data < min->data) min = temp;
                    temp = temp->previous;
                }
            }
            delete oldFront;
        }
    }

    long get_min() const {
        return  min->data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    long  N;
    long d;
    std::cin >> N;
    std::cin >> d;
    long sum = 0;
    Queue q;

    for (auto i = 0; i < N; i++) {
        long temp;
        std::cin >> temp;
        q.push(temp);
        if (i >= d || i == d - 1) {
            sum += q.get_min();
            q.pop();
        }
    }
    std::cout << sum;

    return 0;
}**/