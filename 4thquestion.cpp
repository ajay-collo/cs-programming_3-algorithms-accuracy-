#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
private:
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root, TreeNode*& head) {
        if (root == nullptr) return;

        inorder(root->left, head);

        if (prev == nullptr) {
            head = root; // First node becomes the head of the linked list
        } else {
            prev->left = nullptr;
            prev->right = root;
        }
        prev = root;

        inorder(root->right, head);
    }

public:
    TreeNode* flattenBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* head = nullptr;
        prev = nullptr;
        inorder(root, head);
        if (prev != nullptr) {
            prev->left = nullptr;
            prev->right = nullptr;
        }
        return head;
    }
};

void printList(TreeNode* head) {
    TreeNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->right;
    }
    cout << "nullptr" << endl;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    TreeNode* head = sol.flattenBST(root);

    cout << "Converted Linked List: ";
    printList(head);

    return 0;
}
