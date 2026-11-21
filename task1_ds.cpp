#include <iostream>
using namespace std;

// ==========================================
// 1. SINGLY LINKED LIST IMPLEMENTATION
// ==========================================
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at the end
    // Time Complexity: O(n) | Space Complexity: O(1)
    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete first occurrence of value
    // Time Complexity: O(n) | Space Complexity: O(1)
    void deleteNode(int val) {
        if (!head) return;
        if (head->data == val) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        ListNode* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next) {
            ListNode* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Search for a value
    // Time Complexity: O(n) | Space Complexity: O(1)
    bool search(int val) {
        ListNode* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    // Display list
    // Time Complexity: O(n) | Space Complexity: O(1)
    void display() {
        ListNode* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ==========================================
// 2. BINARY SEARCH TREE (BST) IMPLEMENTATION
// ==========================================
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insertRec(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->data)
            node->left = insertRec(node->left, val);
        else if (val > node->data)
            node->right = insertRec(node->right, val);
        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    TreeNode* deleteRec(TreeNode* node, int val) {
        if (!node) return node;
        if (val < node->data)
            node->left = deleteRec(node->left, val);
        else if (val > node->data)
            node->right = deleteRec(node->right, val);
        else {
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }

    bool searchRec(TreeNode* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return searchRec(node->left, val);
        return searchRec(node->right, val);
    }

    void inorderRec(TreeNode* node) {
        if (!node) return;
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

public:
    BST() : root(nullptr) {}

    // Time Complexity: O(h) where h is tree height (O(log n) avg, O(n) worst) | Space: O(h)
    void insert(int val) { root = insertRec(root, val); }

    // Time Complexity: O(h) | Space: O(h)
    void deleteNode(int val) { root = deleteRec(root, val); }

    // Time Complexity: O(h) | Space: O(h)
    bool search(int val) { return searchRec(root, val); }

    // Time Complexity: O(n) | Space: O(h)
    void displayInorder() {
        inorderRec(root);
        cout << "\n";
    }
};

// ==========================================
// DRIVER PROGRAM
// ==========================================
int main() {
    cout << "--- SINGLY LINKED LIST DEMO ---\n";
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    cout << "Initial List: ";
    list.display();

    cout << "Search 20: " << (list.search(20) ? "Found" : "Not Found") << "\n";
    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();

    cout << "\n--- BINARY SEARCH TREE DEMO ---\n";
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    cout << "Inorder Traversal: ";
    tree.displayInorder();

    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << "\n";
    tree.deleteNode(30);
    cout << "After deleting 30 (Inorder): ";
    tree.displayInorder();

    return 0;
}
