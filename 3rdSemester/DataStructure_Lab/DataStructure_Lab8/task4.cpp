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

    // helper to search a value
    Node* searchNodeHelper(Node* curr_node, int val)
    {
        if (curr_node == nullptr)
        {
            return nullptr;
        }

        if (curr_node->data == val)
        {
            return curr_node;
        }
        else if (val < curr_node->data)
        {
            return searchNodeHelper(curr_node->left, val);
        }
        else
        {
            return searchNodeHelper(curr_node->right, val);
        }
    }

    // helper to find and remove minimum node
    Node* extractMin(Node*& curr_node)
    {
        if (curr_node->left == nullptr)
        {
            Node* min_node = curr_node;
            curr_node = curr_node->right;
            return min_node;
        }
        return extractMin(curr_node->left);
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

    // helper to find kth largest code
    void kthLargestHelper(Node* curr_node, int k, int& count, int& result)
    {
        if (curr_node == nullptr || count >= k)
        {
            return;
        }

        kthLargestHelper(curr_node->right, k, count, result);

        count++;
        if (count == k)
        {
            result = curr_node->data;
            return;
        }

        kthLargestHelper(curr_node->left, k, count, result);
    }

    // helper for postorder traversal
    void postorderHelper(Node* curr_node)
    {
        if (curr_node != nullptr)
        {
            postorderHelper(curr_node->left);
            postorderHelper(curr_node->right);
            cout << curr_node->data << " ";
        }
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

    // helper to count total nodes
    int countNodesHelper(Node* curr_node)
    {
        if (curr_node == nullptr)
        {
            return 0;
        }
        return 1 + countNodesHelper(curr_node->left) + countNodesHelper(curr_node->right);
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

    // find lowest common ancestor
    void findLca(int val1, int val2)
    {
        if (searchNodeHelper(root, val1) == nullptr || searchNodeHelper(root, val2) == nullptr)
        {
            cout << "LCA " << val1 << " " << val2 << ": LCA not possible" << endl;
            return;
        }

        Node* curr_node = root;
        while (curr_node != nullptr)
        {
            if (val1 < curr_node->data && val2 < curr_node->data)
            {
                curr_node = curr_node->left;
            }
            else if (val1 > curr_node->data && val2 > curr_node->data)
            {
                curr_node = curr_node->right;
            }
            else
            {
                cout << "LCA " << val1 << " " << val2 << " = " << curr_node->data << endl;
                return;
            }
        }
    }

    // find kth largest code
    void findKthLargest(int k)
    {
        int count = 0;
        int result = -1;
        kthLargestHelper(root, k, count, result);
        cout << "KTH " << k << " = " << result << endl;
    }

    // delete a code and report details
    void deleteNode(int val)
    {
        root = deleteNodeHelper(root, val, 0);
    }

    // print postorder traversal
    void printPostorder()
    {
        cout << "Postorder: ";
        postorderHelper(root);
        cout << endl;
    }

    // get tree height
    int getHeight()
    {
        return getHeightHelper(root);
    }

    // count total nodes
    int countNodes()
    {
        return countNodesHelper(root);
    }

    // display summary stats
    void displaySummary()
    {
        cout << "Height " << getHeight() << endl;
        cout << "Nodes " << countNodes() << endl;
        cout << "Deletion kinds: no child " << del_no_child 
             << ", one child " << del_one_child 
             << ", two children " << del_two_children << endl;
    }
};

int main()
{
    BinaryTree* tree = new BinaryTree();

    // insert initial product codes
    tree->insertInitial(50);
    tree->insertInitial(25);
    tree->insertInitial(75);
    tree->insertInitial(10);
    tree->insertInitial(35);
    tree->insertInitial(60);
    tree->insertInitial(90);
    tree->insertInitial(5);
    tree->insertInitial(30);
    tree->insertInitial(40);
    tree->insertInitial(55);
    tree->insertInitial(65);

    // perform operations
    tree->findLca(30, 40);
    tree->findLca(5, 40);
    tree->findLca(55, 90);
    tree->findLca(30, 99);

    tree->insertNode(62);
    tree->deleteNode(75);
    tree->findKthLargest(3);
    tree->deleteNode(25);
    tree->findKthLargest(8);
    tree->deleteNode(5);
    tree->deleteNode(35);

    // display traversals and summary
    tree->printPostorder();
    tree->displaySummary();

    delete tree;
    return 0;
}
