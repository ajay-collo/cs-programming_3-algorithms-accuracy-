#include <iostream>
#include <memory>

struct TreeNode {
    int val;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
    // Automatic cleanup when root goes out of scope
    auto root = std::make_unique<TreeNode>(10);
    root->left = std::make_unique<TreeNode>(5);
    root->right = std::make_unique<TreeNode>(15);

    std::cout << "Root value: " << root->val << "\n";
    return 0;
}