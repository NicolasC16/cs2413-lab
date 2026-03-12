#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int absVal(int x) {
    return (x < 0) ? -x : x;
}

int checkAVL(struct TreeNode* node, long min, long maxVal) {

    if (node == NULL)
        return 0;

    if (node->val <= min || node->val >= maxVal)
        return -1;

    int leftHeight = checkAVL(node->left, min, node->val);
    if (leftHeight == -1)
    return -1;

    int rightHeight = checkAVL(node->right, node->val, maxVal);
    if (rightHeight == -1)
    return -1;

    if (absVal(leftHeight - rightHeight) > 1)
    return -1;

    return max(leftHeight, rightHeight) + 1;
}

bool isAVL(struct TreeNode* root) {
    return checkAVL(root, -2147483649L, 2147483648L) != -1; 
}
