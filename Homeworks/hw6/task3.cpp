/**#include <iostream>
#include <queue>

struct Node {
public:
    int data;
    Node* left;
    Node* right;
    Node() = default;
    Node(int data) {
        left = nullptr;
        right = nullptr;
        this->data = data;
    }
};

class BST {
private:
    Node* root = nullptr;
    Node* insert(Node* root, int value);
    Node* delete_node(Node* root, int value);
    Node* minValue(Node* root);
public:
    void insert(int value) {
        root = insert(root, value);
    }

    Node* find_K(Node* root, int K, int& counter) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* left = find_K(root->right, K, counter);
        if (left) {
            return left;
        }

        if (++counter == K) {
            return root;
        }

        return find_K(root->left, K, counter);
    }

    void delete_K(int K) {
        int counter = 0;
        Node* nodeK = find_K(root, K, counter);
        delete_node(root, nodeK->data);
    }

    void BFS() {
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* front = q.front();
            std::cout << front->data << " ";

            q.pop();
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
    }
};

Node* BST::minValue(Node* root) {
    Node* current = root;

    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* BST::delete_node(Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data) {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->data) {
        root->right = delete_node(root->right, value);
    }
    else {
        if (root->left == NULL and root->right == NULL) {
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

Node* BST::insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int main() {
    int N;
    int K;
    std::cin >> N >> K;

    BST bst;
    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        bst.insert(temp);
    }
    bst.delete_K(K);

    bst.BFS();

    return 0;
}**/