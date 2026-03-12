#include <stddef.h>  // NULL

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) {
 
    while (root != NULL) {

        if (target == root->val){
            return root;
        }
        else if (target < root->val){
            root = root->left;
        }
        else{
            root = root ->right;
        }
    }

    return NULL;

}
