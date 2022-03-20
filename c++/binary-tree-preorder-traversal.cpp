/*
144. 二叉树的前序遍历
[难度:简单]
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：8.2 MB, 在所有 C++ 提交中击败了26.57% 的用户
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //用栈，由于每次先遍历根，再遍历左孩子，最后遍历右孩子
 //为了能够遍历到右孩子，需要把遍历过的根节点添加到栈中
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode *> stk;
        TreeNode *curr_node = root;

        while (curr_node != nullptr) {
            vec.push_back(curr_node->val);
            if (curr_node->left == nullptr) {
                if (curr_node->right == nullptr) { //当前节点无孩子，则返回上一级
        pop_parent:
                    if (stk.empty()) {
                        curr_node = nullptr;
                    } else {
                        TreeNode *parent_node = stk.top();
                        if (curr_node == parent_node->left) {
                            curr_node = parent_node->right;
                            if (curr_node == nullptr) {
                                goto pop_parent;
                            }
                        } else {
                            curr_node = parent_node;
                            stk.pop(); //栈顶元素的左右孩子都遍历完毕，将它弹出
                            goto pop_parent;
                        }
                    }
                } else {
                    stk.push(curr_node);
                    curr_node = curr_node->right;
                }
            } else {
                stk.push(curr_node);
                curr_node = curr_node->left;
            }
        }

        return vec; 
    }
};