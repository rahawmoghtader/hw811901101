
#include <iostream>

using namespace std;

class Node {

private:
    int key;
    Node* left;
    Node* right;

public:
    Node(int key) {
        this->key = key;
        left = nullptr;
        right = nullptr;
    }

    int getKey() const {
        return key;
    }

    Node *getLeft() const {
        return left;
    }

    void setLeft(Node *left) {
        Node::left = left;
    }

    Node *getRight() const {
        return right;
    }

    void setRight(Node *right) {
        Node::right = right;
    }

};


Node* newNode(int key) {
    return new Node(key);
}


Node* insertRec(Node* root, int key) {
    if (root == nullptr) {
        return newNode(key);
    }

    if (key < root->getKey()) {
        root->setLeft(insertRec(root->getLeft(),key));
    } else if (key > root->getKey()) {
        root->setRight(insertRec(root->getRight(), key));
    }

    return root;
}

Node* insert(Node* root, int key) {
    return insertRec(root, key);
}

bool search(Node* root, int key) {
    if (root == nullptr || root->getKey() == key) {
        return root != nullptr;
    }

    if (key > root->getKey()) {
        return search(root->getRight(), key);
    }

    return search(root->getLeft(), key);
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->getLeft());
        std::cout << root->getKey() << " ";
        inorderTraversal(root->getRight());
    }
}


int main() {
    Node *root = nullptr;

    while (true) {


        cout << "Enter number of what you want to do: \n"
            << "1. Add to tree \n"
            << "2. Search in tree \n"
            << "3. Exit \n";

        char selected;
        cin >> selected;

        int key;
        switch (selected) {
            case '1':

                cout << "Enter the Key: ";
                cin >> key;
                root = insert(root, key);
                break;

            case '2':
                cout << "Enter the Key: ";
                cin >> key;
                if (search(root, key)) {
                    cout  << key << " is found" << endl;
                } else {
                    cout << key << " is not found" << endl;
                }
                break;

            case '3':
                exit(0);

            default:
                cout << "wrong Number...";
        }
    }
}



















