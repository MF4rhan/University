#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
    Node* root;

    Node* insertNodeHelper(Node* root, int data)
    {
        if (root == nullptr)
        {
            return new Node(data);
        }
        else if (data < root->data)
        {
            root->left = insertNodeHelper(root->left, data);
        }
        else
        {
            root->right = insertNodeHelper(root->right, data);
        }
        return root;
    }

    void displayHelper(Node* root)
    {
        if (root != nullptr)
        {
            displayHelper(root->left);
            cout << root->data << " ";
            displayHelper(root->right);
        }
    }

    Node* searchNodeHelper(Node* root, int data)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->data == data)
        {
            return root;
        }
        else if (data < root->data)
        {
            return searchNodeHelper(root->left, data);
        }
        else
        {
            return searchNodeHelper(root->right, data);
        }
    }

    Node* extractMin(Node*& node)
    {
        if (node->left == nullptr)
        {
            Node* minNode = node;
            node = node->right;
            return minNode;
        }
        return extractMin(node->left);
    }

    Node* deleteNodeHelper(Node* root, int data)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (data < root->data)
        {
            root->left = deleteNodeHelper(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = deleteNodeHelper(root->right, data);
        }
        else
        {
            // Case 1: 0 children
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }

            // Case 2: 1 child
            if (root->left == nullptr)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == nullptr)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: 2 children (pointer re-linking)
            Node* successor = extractMin(root->right);
            successor->left = root->left;
            successor->right = root->right;
            delete root;
            return successor;
        }
        return root;
    }

    void destroyTree(Node* node)
    {
        if (node != nullptr)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree()
    {
        destroyTree(root);
    }

    void insertNode(int data)
    {
        root = insertNodeHelper(root, data);
    }

    void display()
    {
        displayHelper(root);
        cout << endl;
    }

    bool searchNode(int data)
    {
        Node* temp = searchNodeHelper(root, data);
        if (temp == nullptr)
        {
            cout << "Value " << data << " not found in tree.\n";
            return false;
        }
        cout << "Value found: " << temp->data << endl;
        return true;
    }

    void deleteNode(int data)
    {
        root = deleteNodeHelper(root, data);
    }
};

int main()
{
    BinaryTree* tree = new BinaryTree();

    tree->insertNode(9);
    tree->insertNode(2);
    tree->insertNode(1);
    tree->insertNode(5);
    tree->insertNode(6);
    tree->insertNode(3);
    tree->insertNode(4);
    tree->insertNode(8);
    tree->insertNode(7);

    cout << "Original tree (in-order): ";
    tree->display();

    cout << "\nDeleting leaf node (1):" << endl;
    tree->deleteNode(1);
    tree->display();

    cout << "\nDeleting node with one child (3):" << endl;
    tree->deleteNode(3);
    tree->display();

    cout << "\nDeleting node with two children (5):" << endl;
    tree->deleteNode(5);
    tree->display();

    delete tree;
    return 0;
}