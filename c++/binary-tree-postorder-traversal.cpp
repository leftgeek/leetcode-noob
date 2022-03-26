/*
145. 二叉树的后序遍历
[难度:简单]
给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
进阶：递归算法很简单，你可以通过迭代算法完成吗？
https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
运行结果：
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：8.1 MB, 在所有 C++ 提交中击败了86.19% 的用户
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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
        stack<TreeNode *> path_stack;

        while (root != nullptr) {
            if (root->left != nullptr) {
                path_stack.push(root);
                root = root->left;
            } else if (root->right != nullptr) {
                path_stack.push(root);
                root = root->right;
            } else {
pop_stack:
                results.push_back(root->val);
                if (!path_stack.empty()) {
                    TreeNode *parent = path_stack.top();
                    if ((root == parent->left) && (parent->right != nullptr)) {
                        root = parent->right;
                    } else {
                        //parent的所有子节点已经遍历完毕，从栈中弹出并打印parent
                        root = parent;
                        path_stack.pop();
                        goto pop_stack;
                    }
                } else {
                    root = nullptr;
                }
            }
        }

        return results;
    }
};