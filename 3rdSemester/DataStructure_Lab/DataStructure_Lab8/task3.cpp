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

    // helper to insert a node
    Node* insertNodeHelper(Node* curr_node, int val)
    {
        if (curr_node == nullptr)
        {
            return new Node(val);
        }
        else if (val < curr_node->data)
        {
            curr_node->left = insertNodeHelper(curr_node->left, val);
        }
        else if (val > curr_node->data)
        {
            curr_node->right = insertNodeHelper(curr_node->right, val);
        }
        return curr_node;
    }

    // helper to extract maximum node from left subtree
    Node* extractMax(Node*& curr_node)
    {
        if (curr_node->right == nullptr)
        {
            Node* max_node = curr_node;
            curr_node = curr_node->left;
            return max_node;
        }
        return extractMax(curr_node->right);
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
            Node* predecessor = extractMax(curr_node->left);
            cout << curr_node->data << " depth " << depth << ", two children, replaced by " << predecessor->data << " (next smaller)" << endl;
            del_two_children++;

            predecessor->left = curr_node->left;
            predecessor->right = curr_node->right;
            delete curr_node;
            return predecessor;
        }
        return curr_node;
    }

    // helper to calculate tree height
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

    // helper for range query
    void rangeHelper(Node* curr_node, int low, int high, int& count, int& sum)
    {
        if (curr_node == nullptr)
        {
            return;
        }

        if (curr_node->data > low)
        {
            rangeHelper(curr_node->left, low, high, count, sum);
        }

        if (curr_node->data >= low && curr_node->data <= high)
        {
            count++;
            sum += curr_node->data;
        }

        if (curr_node->data < high)
        {
            rangeHelper(curr_node->right, low, high, count, sum);
        }
    }

    // helper for preorder traversal
    void preorderHelper(Node* curr_node)
    {
        if (curr_node != nullptr)
        {
            cout << curr_node->data << " ";
            preorderHelper(curr_node->left);
            preorderHelper(curr_node->right);
        }
    }

    // helper for inorder traversal
    void inorderHelper(Node* curr_node)
    {
        if (curr_node != nullptr)
        {
            inorderHelper(curr_node->left);
            cout << curr_node->data << " ";
            inorderHelper(curr_node->right);
        }
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

    // insert product code
    void insertNode(int val)
    {
        root = insertNodeHelper(root, val);
    }

    // delete a code and report details
    void deleteNode(int val)
    {
        root = deleteNodeHelper(root, val, 0);
    }

    // find floor value
    void findFloor(int val)
    {
        Node* curr_node = root;
        int floor_val = -1;
        bool found = false;

        while (curr_node != nullptr)
        {
            if (curr_node->data == val)
            {
                floor_val = curr_node->data;
                found = true;
                break;
            }
            else if (val < curr_node->data)
            {
                curr_node = curr_node->left;
            }
            else
            {
                floor_val = curr_node->data;
                found = true;
                curr_node = curr_node->right;
            }
        }

        cout << "FLOOR " << val << " = ";
        if (found)
        {
            cout << floor_val << endl;
        }
        else
        {
            cout << "none" << endl;
        }
    }

    // find ceil value
    void findCeil(int val)
    {
        Node* curr_node = root;
        int ceil_val = -1;
        bool found = false;

        while (curr_node != nullptr)
        {
            if (curr_node->data == val)
            {
                ceil_val = curr_node->data;
                found = true;
                break;
            }
            else if (val > curr_node->data)
            {
                curr_node = curr_node->right;
            }
            else
            {
                ceil_val = curr_node->data;
                found = true;
                curr_node = curr_node->left;
            }
        }

        cout << "CEIL " << val << " = ";
        if (found)
        {
            cout << ceil_val << endl;
        }
        else
        {
            cout << "none" << endl;
        }
    }

    // find count and sum in range
    void findRange(int low, int high)
    {
        int count = 0;
        int sum = 0;
        rangeHelper(root, low, high, count, sum);
        cout << "RANGE " << low << ".." << high << ": count " << count << ", sum " << sum << endl;
    }

    // print preorder traversal
    void printPreorder()
    {
        cout << "Preorder: ";
        preorderHelper(root);
        cout << endl;
    }

    // print inorder traversal
    void printInorder()
    {
        cout << "Inorder: ";
        inorderHelper(root);
        cout << endl;
    }

    // get tree height
    int getHeight()
    {
        return getHeightHelper(root);
    }

    // display summary stats
    void displaySummary()
    {
        cout << "Height " << getHeight() << endl;
        cout << "Deletion kinds: no child " << del_no_child  << ", one child " << del_one_child << ", two children " << del_two_children << endl;
    }
};

int main()
{
    BinaryTree* tree = new BinaryTree();

    // insert initial product codes
    tree->insertNode(45);
    tree->insertNode(25);
    tree->insertNode(65);
    tree->insertNode(15);
    tree->insertNode(35);
    tree->insertNode(55);
    tree->insertNode(85);
    tree->insertNode(30);
    tree->insertNode(40);
    tree->insertNode(60);
    tree->insertNode(75);
    tree->insertNode(95);

    // perform operations
    tree->findFloor(58);
    tree->findCeil(96);
    tree->findCeil(65);
    tree->deleteNode(25);
    tree->deleteNode(65);
    tree->deleteNode(15);
    tree->findCeil(65);
    tree->findRange(30, 60);

    // display traversals and summary
    tree->printPreorder();
    tree->printInorder();
    tree->displaySummary();

    delete tree;
    return 0;
}
