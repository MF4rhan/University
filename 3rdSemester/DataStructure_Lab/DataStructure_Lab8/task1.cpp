#include <iostream>
#include <string>

using namespace std;

// node structure for the bst
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
    int rejected_count;

    // helper function for inorder traversal
    void inorderHelper(Node* curr_node)
    {
        if (curr_node != nullptr)
        {
            inorderHelper(curr_node->left);
            cout << curr_node->data << " ";
            inorderHelper(curr_node->right);
        }
    }

    // helper function for postorder traversal
    void postorderHelper(Node* curr_node)
    {
        if (curr_node != nullptr)
        {
            postorderHelper(curr_node->left);
            postorderHelper(curr_node->right);
            cout << curr_node->data << " ";
        }
    }

    // helper function to count nodes
    int countNodesHelper(Node* curr_node)
    {
        if (curr_node == nullptr)
        {
            return 0;
        }
        return 1 + countNodesHelper(curr_node->left) + countNodesHelper(curr_node->right);
    }

    // helper function to calculate tree height
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

    // helper function to delete all nodes
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
    BinaryTree(Node* root_node = nullptr) : root(root_node), rejected_count(0)
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
        insertNode(val, false);
    }

    // insert a code and report depth or duplicate
    void insertNode(int val, bool show_msg = true)
    {
        if (root == nullptr)
        {
            root = new Node(val);
            if (show_msg)
            {
                cout << val << " inserted at depth 0" << endl;
            }
            return;
        }

        Node* curr_node = root;
        int depth = 0;

        while (curr_node != nullptr)
        {
            if (val == curr_node->data)
            {
                if (show_msg)
                {
                    cout << val << " duplicate, rejected" << endl;
                    rejected_count++;
                }
                return;
            }

            depth++;
            if (val < curr_node->data)
            {
                if (curr_node->left == nullptr)
                {
                    curr_node->left = new Node(val);
                    if (show_msg)
                    {
                        cout << val << " inserted at depth " << depth << endl;
                    }
                    return;
                }
                curr_node = curr_node->left;
            }
            else
            {
                if (curr_node->right == nullptr)
                {
                    curr_node->right = new Node(val);
                    if (show_msg)
                    {
                        cout << val << " inserted at depth " << depth << endl;
                    }
                    return;
                }
                curr_node = curr_node->right;
            }
        }
    }

    // search for a code and print visited path
    bool searchNode(int val)
    {
        cout << "SEARCH " << val << ": path";
        Node* curr_node = root;
        bool found = false;

        while (curr_node != nullptr)
        {
            cout << " " << curr_node->data;
            if (curr_node->data == val)
            {
                found = true;
                break;
            }
            else if (val < curr_node->data)
            {
                curr_node = curr_node->left;
            }
            else
            {
                curr_node = curr_node->right;
            }
        }

        if (found)
        {
            cout << ", found" << endl;
        }
        else
        {
            cout << ", not found" << endl;
        }

        return found;
    }

    // display inorder traversal
    void printInorder()
    {
        cout << "Inorder: ";
        inorderHelper(root);
        cout << endl;
    }

    // display postorder traversal
    void printPostorder()
    {
        cout << "Postorder: ";
        postorderHelper(root);
        cout << endl;
    }

    // count total nodes in tree
    int countNodes()
   {
        return countNodesHelper(root);
    }

    // get tree height
    int getHeight()
    {
        return getHeightHelper(root);
    }

    // display final summary
    void displaySummary()
    {
        cout << "Nodes " << countNodes() << ", Height " << getHeight() << ", Rejected " << rejected_count << endl;
    }
};

int main()
{
    BinaryTree tree;

    // insert initial product codes
    tree.insertInitial(50);
    tree.insertInitial(30);
    tree.insertInitial(70);
    tree.insertInitial(20);
    tree.insertInitial(40);
    tree.insertInitial(60);
    tree.insertInitial(80);

    // perform operations
    tree.insertNode(65);
    tree.insertNode(35);
    tree.insertNode(60);
    tree.insertNode(90);

    tree.searchNode(35);
    tree.searchNode(75);
    tree.searchNode(65);

    // display traversals and summary
    tree.printInorder();
    tree.printPostorder();
    tree.displaySummary();

    return 0;
}
