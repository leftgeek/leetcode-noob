/*
剑指 Offer 07. 重建二叉树
[难度：中等]
输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/

结果：
执行用时：32 ms, 在所有 C++ 提交中击败了26.65% 的用户
内存消耗：23.4 MB, 在所有 C++ 提交中击败了99.06% 的用户
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //先在前序遍历数组中取一个元素p，第一个元素是树的根，
 //然后在中序主序遍历数组中找到相应元素p，看它左边和右边是否还有别的元素。
 //左边的元素都位于节点p的左子树，而右边的元素都位于节点p的右子树
class Solution {
private:
    //对于一个指定的根元素，递归构建其左右子树
    void buildSubTree(TreeNode *root, vector<int> &preorder, vector<int> &inorder,
        int& preorder_root_index, int inorder_start_index, int inorder_end_index) {
        //先根据当前的根节点值，在inorder数组中找到它对应的位置inorder_root_index
        int inorder_root_index = inorder_start_index;

        for (int i = inorder_start_index; i <= inorder_end_index; i++) {
            if (inorder[i] == preorder[preorder_root_index]) {
                inorder_root_index = i;
                break;
            }
        }
        //处理左子树
        if (inorder_start_index < inorder_root_index) {
            //对于节点p的左侧有子树，那么p在前序遍历数组中的下一个元素就是它的左子树根
            root->left = new TreeNode(preorder[++preorder_root_index]);
            //构建左子树
            buildSubTree(root->left, preorder, inorder,
                preorder_root_index, inorder_start_index, inorder_root_index - 1);
        }
        //处理右子树
        if (inorder_root_index < inorder_end_index) {
            //如果节点p的右侧有子树，那么p在前序遍历数组中的下一个元素就是它的右子树根
            root->right = new TreeNode(preorder[++preorder_root_index]);
            buildSubTree(root->right, preorder, inorder,
                preorder_root_index, inorder_root_index + 1, inorder_end_index);
        }
     }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[0]);
        int preorder_root_index = 0;
        
        buildSubTree(root, preorder, inorder,
            preorder_root_index, 0, inorder.size() - 1);
        
        return root;
    }
};