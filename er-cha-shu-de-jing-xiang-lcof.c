/*
剑指 Offer 27. 二叉树的镜像
请完成一个函数，输入一个二叉树，该函数输出它的镜像。
https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/

执行用时：0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗：5.7 MB, 在所有 C 提交中击败了52.28% 的用户
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* mirrorTree(struct TreeNode* root){
  if (!root || ((!root->left) && (!root->right))){
    return root;
  }
  struct TreeNode *tmp_node;
  if (root->left){
    mirrorTree(root->left);
  }
  if (root->right){
    mirrorTree(root->right);
  }
  tmp_node = root->left;
  root->left = root->right;
  root->right = tmp_node;

  return root;
