#include <iostream>
#include <string>

using namespace std;

// node structure for bst
class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val = 0) : data(val), left(nullptr), right(nullptr)
    {
    }
};

// binary search tree class
class BinaryTree
{
private:
    Node* root;
    int del_no_child;
    int del_one_child;
    int del_two_children;

    // helper for inserting a node
    Node* insertNodeHelper(Node* curr_node, int val, int depth, bool show_msg)
    {
        if (curr_node == nullptr)
        {
            if (show_msg)
            {
                cout << val << " inserted at depth " << depth << endl;
            }
            return new Node(val);
        }

        if (val < curr_node->data)
        {
            curr_node->left = insertNodeHelper(curr_node->left, val, depth + 1, show_msg);
        }
        else if (val > curr_node->data)
        {
            curr_node->right = insertNodeHelper(curr_node->right, val, depth + 1, show_msg);
        }
        return curr_node;
    }

    // helper to find and remove minimum node
    Node* extractMin(Node*& node)
    {
        if (node->left == nullptr)
        {
            Node* min_node = node;
            node = node->right;
            return min_node;
        }
        return extractMin(node->left);
    }

    // helper to delete a node
    Node* deleteNodeHelper(Node* curr_node, int val, int depth)
    {
        if (curr_node == nullptr)
        {
            return nullptr;
        }

        if (val < curr_node->data)
        {
            curr_node->left = deleteNodeHelper(curr_node->left, val, depth + 1);
        }
        else if (val > curr_node->data)
        {
            curr_node->right = deleteNodeHelper(curr_node->right, val, depth + 1);
        }
        else
        {
            // case 1: 0 children
            if (curr_node->left == nullptr && curr_node->right == nullptr)
            {
                cout << curr_node->data << " depth " << depth << ", no child" << endl;
                del_no_child++;
                delete curr_node;
                return nullptr;
            }

            // case 2: 1 child
            if (curr_node->left == nullptr)
            {
                cout << curr_node->data << " depth " << depth << ", one child" << endl;
                del_one_child++;
                Node* temp_node = curr_node->right;
                delete curr_node;
                return temp_node;
            }
            if (curr_node->right == nullptr)
            {
                cout << curr_node->data << " depth " << depth << ", one child" << endl;
                del_one_child++;
                Node* temp_node = curr_node->left;
                delete curr_node;
                return temp_node;
            }

            // case 3: 2 children
            Node* successor = extractMin(curr_node->right);
            cout << curr_node->data << " depth " << depth << ", two children, replaced by " << successor->data << endl;
            del_two_children++;

            successor->left = curr_node->left;
            successor->right = curr_node->right;
            delete curr_node;
            return successor;
        }
        return curr_node;
    }

    // helper to find height
    int getHeightHelper(Node* curr_node)
    {
        if (curr_node == nullptr)
        {
            return -1;
        }
        int left_height = getHeightHelper(curr_node->left);
        int right_height = getHeightHelper(curr_node->right);
        if (left_height > right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }

    // helper to count nodes at each level
    void countLevelsHelper(Node* curr_node, int level, int level_counts[])
    {
        if (curr_node == nullptr)
        {
            return;
        }
        level_counts[level]++;
        countLevelsHelper(curr_node->left, level + 1, level_counts);
        countLevelsHelper(curr_node->right, level + 1, level_counts);
    }

    // helper to clean up tree
    void destroyTree(Node* curr_node)
    {
        if (curr_node != nullptr)
        {
            destroyTree(curr_node->left);
            destroyTree(curr_node->right);
            delete curr_node;
        }
    }

public:
    BinaryTree(Node* root_node = nullptr) : root(root_node), del_no_child(0), del_one_child(0), del_two_children(0)
    {
    }

    // destructor
    ~BinaryTree()
    {
        destroyTree(root);
    }

    // insert initial codes without printing
    void insertInitial(int val)
    {
        root = insertNodeHelper(root, val, 0, false);
    }

    // insert a code and report depth
    void insertNode(int val)
    {
        root = insertNodeHelper(root, val, 0, true);
    }

    // delete a code and report details
    void deleteNode(int val)
    {
        root = deleteNodeHelper(root, val, 0);
    }

    // print level order traversal
    void printLevelOrder()
    {
        if (root == nullptr)
        {
            return;
        }

        Node* queue[100];
        int front = 0;
        int rear = 0;

        queue[rear++] = root;

        cout << "Level order:";
        while (front < rear)
        {
            Node* curr_node = queue[front++];
            cout << " " << curr_node->data;

            if (curr_node->left != nullptr)
            {
                queue[rear++] = curr_node->left;
            }
            if (curr_node->right != nullptr)
            {
                queue[rear++] = curr_node->right;
            }
        }
        cout << endl;
    }

    // print level stats and deletion counts
    void displayLevelStats()
    {
        int height = getHeightHelper(root);
        if (height == -1)
        {
            return;
        }

        int level_counts[100] = {0};
        countLevelsHelper(root, 0, level_counts);

        cout << endl;
        cout << "Level widths:";
        int max_nodes = -1;
        int widest_level = 0;

        for (int i = 0; i <= height; i++)
        {
            cout << " " << level_counts[i];
            if (level_counts[i] > max_nodes)
            {
                max_nodes = level_counts[i];
                widest_level = i;
            }
        }
        cout << endl;

        cout << "Widest level " << widest_level << endl;
        cout << "Height " << height << endl;
        cout << "Deletion kinds: no child " << del_no_child << ", one child " << del_one_child << ", two children " << del_two_children << endl;
    }
};

int main()
{
    BinaryTree* tree = new BinaryTree();

    // insert initial product codes
    tree->insertInitial(40);
    tree->insertInitial(20);
    tree->insertInitial(60);
    tree->insertInitial(10);
    tree->insertInitial(30);
    tree->insertInitial(50);
    tree->insertInitial(70);
    tree->insertInitial(5);
    tree->insertInitial(15);
    tree->insertInitial(25);
    tree->insertInitial(35);

    // perform operations
    tree->insertNode(55);
    tree->deleteNode(20);
    tree->insertNode(12);
    tree->deleteNode(60);
    tree->deleteNode(5);

    // display level order and stats
    tree->printLevelOrder();
    tree->displayLevelStats();

    delete tree;
    return 0;
}

