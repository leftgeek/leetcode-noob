/*
剑指 Offer 26. 树的子结构
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。
https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/

执行用时：36 ms, 在所有 C 提交中击败了70.19% 的用户
内存消耗：19.2 MB, 在所有 C 提交中击败了13.04% 的用户

用先序遍历的方式遍历原始树A的各个节点，一旦某个节点的值和目标子树B的根节点树值相等，就从它开始，递归地比较它们的左子树和右子树。
如果遍历失败，就说明原始树A的当前的结点为根无法和子树B匹配。
于是就继续遍历树A的子左树（按照原先的先序遍历方式）。

只有判断相等的情况下才会继续深入递归对比，否则直接返回失败

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//递归地比较以A和B为根的两个树是否相等
//A和B已经判断相等，现在判断它们的孩子结点是否相等
static bool is_same_structure_children(struct TreeNode *A, struct TreeNode *B){
    bool result = true;
    //以B为基准来判断
    //依次判断B的左右子结点值是否和A的相等
    if (B->left){
        if (!A->left || (A->left->val != B->left->val)){
            return false;
        } else {
            result = is_same_structure_children(A->left, B->left);
        }
    }
    if (result && B->right){
        if (!A->right || (A->right->val != B->right->val)){
            return false;
        } else {
            result = is_same_structure_children(A->right, B->right);
        }
    }
    return result;
}

bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
    bool result = false;
    if (!A || !B){
        return false;
    }
    //从根节点开始比较，一旦发现根节点相等，就递归地比较子结点
    if (A->val == B->val){
        result = is_same_structure_children(A, B);
        if (result){
            return result;
        }
    }
    if (!result){
        //以节点A为根的子结构和B并不相等，尝试A的左右儿子为根的子结构
        result = isSubStructure(A->left, B);
        if (!result){
            result = isSubStructure(A->right, B);
        }
    }

    return result;
}