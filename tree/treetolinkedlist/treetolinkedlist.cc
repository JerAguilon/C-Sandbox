#include<iostream>

using namespace std;

struct BinaryTreeNode {
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

BinaryTreeNode* merge(BinaryTreeNode* leftHalf, BinaryTreeNode* rightHalf) {
    if (leftHalf == nullptr) return rightHalf;
    if (rightHalf == nullptr) return leftHalf;

    BinaryTreeNode* leftTail = leftHalf->left;
    BinaryTreeNode* rightTail = rightHalf->left;

    leftTail->right = rightHalf;
    rightHalf->left = leftTail;

    rightTail->right=leftHalf;
    leftHalf->left = rightTail;
    return leftHalf;
}

BinaryTreeNode* convert_to_linked_list(BinaryTreeNode* root) {
    if (root == nullptr) return root;

    BinaryTreeNode* leftSolved = convert_to_linked_list(root->left);
    BinaryTreeNode* rightSolved = convert_to_linked_list(root->right);

    root->left = root;
    root->right = root;

    BinaryTreeNode* result = merge(leftSolved, root);
    result = merge(result, rightSolved);
    
    return result;
}
