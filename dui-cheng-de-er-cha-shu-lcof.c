/*
剑指 Offer 28. 对称的二叉树
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/

执行用时：4 ms, 在所有 C 提交中击败了85.18% 的用户
内存消耗：6.6 MB, 在所有 C 提交中击败了71.19% 的用户
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//把一棵树分成左右两个子树
//那么要求这两个子树是镜像对称的，就是要求它们对称的节点的数值相等
bool is_symmetric_children(struct TreeNode *A, struct TreeNode *B){
    if ((!A) && (!B)){
        return true;
    } else if (!(A && B)){
        return false;
    }
    //递归地判断A的根节点以及左右两个儿子节点
    //是否和B的根节点以及右左两个儿子节点数值相等
    if ((A->val == B->val)
        && is_symmetric_children(A->left, B->right)
        && is_symmetric_children(A->right, B->left)){
        return true;
    } else {
        return false;
    }
}

bool isSymmetric(struct TreeNode* root){
    if (!root){
        return true;
    } else {
        return is_symmetric_children(root->left, root->right);
    }
}