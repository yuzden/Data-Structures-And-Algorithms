#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class List {
private:
    Node* head;
    Node* tail;
    Node* mid;
    int counter = 0;
public:
    List() {
        head = nullptr;
        tail = nullptr;
        mid = nullptr;
    }

    void add_node(int x) {
        if (head == nullptr) {
            head = new Node(x);
            tail = head;
            counter = 1;
            mid = head;
        }
        else {
            Node* curr = new Node(x);
            curr->prev = tail;
            tail->next = curr;
            tail = curr;
            counter++;
            if (counter % 2 == 0) {
                mid = mid->next;
            }
        }
    }

    void gun() {
        if (head == nullptr || tail == nullptr) return;

        if (head->next == nullptr || counter == 1) {
            Node* temp = head;
            head = nullptr;
            tail = head;
            mid = head;
            delete temp;

            counter = 0;
            return;
        }

        if (counter == 2) {
            Node* temp = tail;
            head->next = nullptr;
            tail = head;
            mid = head;
            delete temp;
            counter--;
            return;
        }

        counter--;
        if (counter % 2 != 0 && counter > 2) {
            mid = mid->prev;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    void Milen() {
        if (counter < 2) return;
        if (counter == 2) {
            Node* temp = head;
            head->prev = head->next;
            head->next = nullptr;
            tail->prev = nullptr;
            tail->next = head;
            head = tail;
            tail = temp;
            mid = tail;
        }

        if (counter > 2) {
            if (counter % 2 == 0) {
                Node* middle = head;
                tail->next = head;
                head->prev = tail;
                head = mid;
                tail = mid->prev;
                head->prev = nullptr;
                tail->next = nullptr;
                mid = middle;
            }
            else {
                Node* midlle = tail;
                tail->next = head;
                head->prev = tail;
                head = mid;
                tail = mid->prev;
                head->prev = nullptr;
                tail->next = nullptr;
                mid = midlle;
            }
        }
    }

    void print_data() {
        if (counter == 0) {
            std::cout << 0 << '\n';
            return;
        }
        std::cout << counter << '\n';
        for (int i = 0; i < counter; i++) {
            std::cout << head->data << " ";
            head = head->next;
        }
      //  std::cout << '\n' << mid->data;
    }
};

int main() {
    long N;
    std::cin >> N;
    List list;
    for (int i = 0; i < N; i++) {
        std::string temp;
        std::cin >> temp;

        if (temp == "milen") {
            list.Milen();
        }
        else if (temp == "gun") {
            list.gun();
        }
        else {
            int x;
            std::cin >> x;
            list.add_node(x);
        }
    }

    list.print_data();

    return 0;
}