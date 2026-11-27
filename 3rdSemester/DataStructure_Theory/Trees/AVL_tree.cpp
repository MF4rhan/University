#include <iostream>
#include <string>

using namespace std;

class avlNode
{
public:
    int key_val;
    avlNode *left_child;
    avlNode *right_child;
    int node_height;

    // Constructor using member initializer list (every new node starts as a leaf with height 1)
    avlNode(int new_val)
        : key_val(new_val), left_child(NULL), right_child(NULL), node_height(1)
    {
    }
};

// Helper 1: Returns the larger of two integers (replaces <algorithm>)
int getMax(int first_val, int second_val)
{
    if (first_val > second_val)
    {
        return first_val;
    }
    return second_val;
}

// Helper 2: Safely gets height (returns 0 if node is NULL)
int getHeight(avlNode *curr_node)
{
    if (curr_node == NULL)
    {
        return 0;
    }
    return curr_node->node_height;
}

// Helper 3: Balance Factor = Left Height - Right Height
int getBalanceFactor(avlNode *curr_node)
{
    if (curr_node == NULL)
    {
        return 0;
    }
    return getHeight(curr_node->left_child) - getHeight(curr_node->right_child);
}

// ROTATION 1: Right Rotation (Fixes LL Imbalance)
avlNode* rightRotate(avlNode *unbalanced_node)
{
    avlNode *new_root = unbalanced_node->left_child;
    avlNode *moved_subtree = new_root->right_child;

    // Perform rotation
    new_root->right_child = unbalanced_node;
    unbalanced_node->left_child = moved_subtree;

    // Update heights bottom-up (unbalanced_node is now below new_root)
    unbalanced_node->node_height = 1 + getMax(getHeight(unbalanced_node->left_child), getHeight(unbalanced_node->right_child));
    new_root->node_height = 1 + getMax(getHeight(new_root->left_child), getHeight(new_root->right_child));

    return new_root;
}

// ROTATION 2: Left Rotation (Fixes RR Imbalance)
avlNode* leftRotate(avlNode *unbalanced_node)
{
    avlNode *new_root = unbalanced_node->right_child;
    avlNode *moved_subtree = new_root->left_child;

    // Perform rotation
    new_root->left_child = unbalanced_node;
    unbalanced_node->right_child = moved_subtree;

    // Update heights bottom-up (unbalanced_node is now below new_root)
    unbalanced_node->node_height = 1 + getMax(getHeight(unbalanced_node->left_child), getHeight(unbalanced_node->right_child));
    new_root->node_height = 1 + getMax(getHeight(new_root->left_child), getHeight(new_root->right_child));

    return new_root;
}

// 1. INSERTION: Standard BST insert + AVL balancing
avlNode* insertNode(avlNode *curr_node, int new_val)
{
    // Step 1: Normal BST insertion
    if (curr_node == NULL)
    {
        return new avlNode(new_val);
    }

    if (new_val < curr_node->key_val)
    {
        curr_node->left_child = insertNode(curr_node->left_child, new_val);
    }
    else if (new_val > curr_node->key_val)
    {
        curr_node->right_child = insertNode(curr_node->right_child, new_val);
    }
    else
    {
        // Duplicate keys are not allowed in standard BST/AVL
        return curr_node;
    }

    // Step 2: Update height of this ancestor node
    curr_node->node_height = 1 + getMax(getHeight(curr_node->left_child), getHeight(curr_node->right_child));

    // Step 3: Check Balance Factor to see if this node became unbalanced
    int balance_factor = getBalanceFactor(curr_node);

    // Case 1: Left-Left (LL) -> Single Right Rotation
    if (balance_factor > 1 && new_val < curr_node->left_child->key_val)
    {
        return rightRotate(curr_node);
    }

    // Case 2: Right-Right (RR) -> Single Left Rotation
    if (balance_factor < -1 && new_val > curr_node->right_child->key_val)
    {
        return leftRotate(curr_node);
    }

    // Case 3: Left-Right (LR) -> Left Rotate child, then Right Rotate node
    if (balance_factor > 1 && new_val > curr_node->left_child->key_val)
    {
        curr_node->left_child = leftRotate(curr_node->left_child);
        return rightRotate(curr_node);
    }

    // Case 4: Right-Left (RL) -> Right Rotate child, then Left Rotate node
    if (balance_factor < -1 && new_val < curr_node->right_child->key_val)
    {
        curr_node->right_child = rightRotate(curr_node->right_child);
        return leftRotate(curr_node);
    }

    return curr_node;
}

// Helper 4: Finds the smallest value node in a subtree (Inorder Successor)
avlNode* getMinValueNode(avlNode *curr_node)
{
    avlNode *temp_node = curr_node;
    while (temp_node->left_child != NULL)
    {
        temp_node = temp_node->left_child;
    }
    return temp_node;
}

// 2. DELETION: Standard BST delete + AVL balancing
avlNode* deleteNode(avlNode *curr_node, int target_val)
{
    // Step 1: Normal BST deletion
    if (curr_node == NULL)
    {
        return curr_node;
    }

    if (target_val < curr_node->key_val)
    {
        curr_node->left_child = deleteNode(curr_node->left_child, target_val);
    }
    else if (target_val > curr_node->key_val)
    {
        curr_node->right_child = deleteNode(curr_node->right_child, target_val);
    }
    else
    {
        // Found the node to delete
        // Case A: Node has 0 or 1 child
        if (curr_node->left_child == NULL || curr_node->right_child == NULL)
        {
            avlNode *child_node = (curr_node->left_child != NULL) ? curr_node->left_child : curr_node->right_child;

            if (child_node == NULL)
            {
                // 0 children (Leaf node)
                delete curr_node;
                return NULL;
            }
            else
            {
                // 1 child: Copy child contents and delete child
                *curr_node = *child_node;
                delete child_node;
            }
        }
        else
        {
            // Case B: Node has 2 children -> Replace with Inorder Successor
            avlNode *successor_node = getMinValueNode(curr_node->right_child);
            curr_node->key_val = successor_node->key_val;
            curr_node->right_child = deleteNode(curr_node->right_child, successor_node->key_val);
        }
    }

    // Step 2: Update height
    curr_node->node_height = 1 + getMax(getHeight(curr_node->left_child), getHeight(curr_node->right_child));

    // Step 3: Check Balance Factor and rebalance if needed
    int balance_factor = getBalanceFactor(curr_node);

    // Left-Left (LL)
    if (balance_factor > 1 && getBalanceFactor(curr_node->left_child) >= 0)
    {
        return rightRotate(curr_node);
    }

    // Left-Right (LR)
    if (balance_factor > 1 && getBalanceFactor(curr_node->left_child) < 0)
    {
        curr_node->left_child = leftRotate(curr_node->left_child);
        return rightRotate(curr_node);
    }

    // Right-Right (RR)
    if (balance_factor < -1 && getBalanceFactor(curr_node->right_child) <= 0)
    {
        return leftRotate(curr_node);
    }

    // Right-Left (RL)
    if (balance_factor < -1 && getBalanceFactor(curr_node->right_child) > 0)
    {
        curr_node->right_child = rightRotate(curr_node->right_child);
        return leftRotate(curr_node);
    }

    return curr_node;
}

// 3. SEARCH: Standard BST search in O(log n)
bool searchNode(avlNode *curr_node, int target_val)
{
    if (curr_node == NULL)
    {
        return false;
    }
    if (curr_node->key_val == target_val)
    {
        return true;
    }
    if (target_val < curr_node->key_val)
    {
        return searchNode(curr_node->left_child, target_val);
    }
    return searchNode(curr_node->right_child, target_val);
}

// 4. TRAVERSALS
// In-Order (Left, Root, Right) -> Always prints sorted ascending order
void inOrderTraversal(avlNode *curr_node)
{
    if (curr_node != NULL)
    {
        inOrderTraversal(curr_node->left_child);
        cout << curr_node->key_val << " ";
        inOrderTraversal(curr_node->right_child);
    }
}

// Pre-Order (Root, Left, Right) -> Shows the exact root and tree shape
void preOrderTraversal(avlNode *curr_node)
{
    if (curr_node != NULL)
    {
        cout << curr_node->key_val << " ";
        preOrderTraversal(curr_node->left_child);
        preOrderTraversal(curr_node->right_child);
    }
}

int main()
{
    avlNode *tree_root = NULL;

    // Insertions that trigger LL, RR, LR, and RL rotations
    tree_root = insertNode(tree_root, 10);
    tree_root = insertNode(tree_root, 20);
    tree_root = insertNode(tree_root, 30); // Triggers RR -> Left Rotation (20 becomes root)
    tree_root = insertNode(tree_root, 40);
    tree_root = insertNode(tree_root, 50); // Triggers RR -> Left Rotation
    tree_root = insertNode(tree_root, 25); // Triggers RL -> Right-Left Rotation (30 becomes root)

    cout << "Pre-Order (shows tree structure): ";
    preOrderTraversal(tree_root);
    cout << endl;

    cout << "In-Order (always sorted): ";
    inOrderTraversal(tree_root);
    cout << endl;

    // Search test
    int search_val = 25;
    if (searchNode(tree_root, search_val))
    {
        cout << "Search " << search_val << ": Found" << endl;
    }
    else
    {
        cout << "Search " << search_val << ": Not Found" << endl;
    }

    // Deletion test (deleting 10 causes imbalance and triggers rotation)
    tree_root = deleteNode(tree_root, 10);
    cout << "\nAfter deleting 10:" << endl;
    cout << "Pre-Order: ";
    preOrderTraversal(tree_root);
    cout << endl;

    cout << "In-Order: ";
    inOrderTraversal(tree_root);
    cout << endl;

    return 0;
}