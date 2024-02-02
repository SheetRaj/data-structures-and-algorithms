#include <iostream>
#include <climits>
#include <algorithm>

template <typename T>
class TreeNode {
public:
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T value) : val(value), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode<int>* root, int& ans, int& c) {
    if (root == nullptr)
        return;

    inorder(root->left, ans, c);
    inorder(root->right, ans, c);

    int l = 0, r = 0;

    if (root->left == nullptr && root->right == nullptr)
        c++;

    if (root->left != nullptr)
        l = root->left->val;

    if (root->right != nullptr)
        r = root->right->val;

    ans = std::max(ans, root->val + l + r);
    root->val = root->val + std::max(l, r);
    ans = std::max(root->val, ans);
}

long long int findMaxSumPath(TreeNode<int>* root) {
    int ans = -1, c = 0;
    inorder(root, ans, c);

    if (c == 1)
        return -1;

    return ans;
}

int main() {
    // Example usage:
    TreeNode<int>* root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(10);
    root->left->left = new TreeNode<int>(20);
    root->left->right = new TreeNode<int>(1);
    root->right->right = new TreeNode<int>(-25);
    root->right->right->left = new TreeNode<int>(3);
    root->right->right->right = new TreeNode<int>(4);

    // Output: 42
    std::cout << "Maximum Path Sum: " << findMaxSumPath(root) << std::endl;

    // Clean up memory (delete tree nodes)
    delete root->right->right->right;
    delete root->right->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root;

    return 0;
}
