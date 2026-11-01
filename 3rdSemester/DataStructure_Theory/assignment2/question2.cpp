#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr)
    {
    }
};

class BST
{
private:
    Node* root;

    // helper to insert a key recursively; ignores duplicates
    Node* insert_helper(Node* current, int key)
    {
        if (current == nullptr)
        {
            return new Node(key);
        }
        if (key < current->key)
        {
            current->left = insert_helper(current->left, key);
        }
        else if (key > current->key)
        {
            current->right = insert_helper(current->right, key);
        }
        return current;
    }

    // helper to search for a key recursively
    bool search_helper(Node* current, int key)
    {
        if (current == nullptr)
        {
            return false;
        }
        if (current->key == key)
        {
            return true;
        }
        if (key < current->key)
        {
            return search_helper(current->left, key);
        }
        return search_helper(current->right, key);
    }

    // helper to find the node with the minimum value
    Node* find_min_node(Node* current)
    {
        while (current != nullptr && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    // helper to find the node with the maximum value
    Node* find_max_node(Node* current)
    {
        while (current != nullptr && current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }

    // helper to delete a key handling leaf, 1-child, and 2-child cases
    Node* delete_helper(Node* current, int key)
    {
        if (current == nullptr)
        {
            return nullptr;
        }

        if (key < current->key)
        {
            current->left = delete_helper(current->left, key);
        }
        else if (key > current->key)
        {
            current->right = delete_helper(current->right, key);
        }
        else
        {
            // case 1: Leaf node aka no children
            if (current->left == nullptr && current->right == nullptr)
            {
                delete current;
                return nullptr;
            }

            // case 2: one child
            if (current->left == nullptr)
            {
                Node* temp = current->right;
                delete current;
                return temp;
            }
            else if (current->right == nullptr)
            {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            // case 3: two children
            // find inorder successor, which is the smallest node in right subtree
            Node* successor = find_min_node(current->right);
            current->key = successor->key;
            current->right = delete_helper(current->right, successor->key);
        }
        return current;
    }

    // helper to compute height (edges: empty is -1, single node is 0)
    int height_helper(Node* current)
    {
        if (current == nullptr)
        {
            return -1;
        }
        int left_height = height_helper(current->left);
        int right_height = height_helper(current->right);
        if (left_height > right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }

    // helper to free allocated memory
    void destroy_tree(Node* current)
    {
        if (current != nullptr)
        {
            destroy_tree(current->left);
            destroy_tree(current->right);
            delete current;
        }
    }

public:
    BST() : root(nullptr)
    {
    }

    ~BST()
    {
        destroy_tree(root);
    }

    void insert(int key)
    {
        root = insert_helper(root, key);
    }

    bool search(int key)
    {
        return search_helper(root, key);
    }

    void delete_node(int key)
    {
        root = delete_helper(root, key);
    }

    int find_min()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty\n";
            return -1;
        }
        return find_min_node(root)->key;
    }

    int find_max()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty\n";
            return -1;
        }
        return find_max_node(root)->key;
    }

    int height()
    {
        return height_helper(root);
    }

    // Inorder successor without using parent pointers
    int inorder_successor(int key)
    {
        Node* current = root;
        Node* target = nullptr;
        Node* successor = nullptr;

        // find target node while tracking the deepest node we turned left from
        while (current != nullptr)
        {
            if (key < current->key)
            {
                successor = current;
                current = current->left;
            }
            else if (key > current->key)
            {
                current = current->right;
            }
            else
            {
                target = current;
                break;
            }
        }

        if (target == nullptr)
        {
            cout << "Key not found\n";
            return -1;
        }

        // case A: Right subtree exists -> min value in right subtree
        if (target->right != nullptr)
        {
            return find_min_node(target->right)->key;
        }

        // case B: No right subtree -> lowest ancestor where target is in left subtree
        if (successor != nullptr)
        {
            return successor->key;
        }

        cout << "No inorder successor exists\n";
        return -1;
    }
};