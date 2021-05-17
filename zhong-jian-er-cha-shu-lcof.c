/*
剑指 Offer 07. 重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
执行用时：20 ms, 在所有 C 提交中击败了52.44% 的用户
内存消耗：7.5 MB, 在所有 C 提交中击败了97.64% 的用户
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int find_position_in_inorder(int *inorder, int inorderSize, int target){
  int i;
  for (i = 0; i < inorderSize; i++){
    if (inorder[i] == target){
      break;
    }
  }
  return i;
}
//对于每一个子树的根结点,去中序遍历结果中查找它的左子树和右子树结点数量
//然后分别将左子树和右子树连接到该子树的根结点的左儿子和右儿子处
//每连接一侧,就得到了该侧的根结点,然后本来就知道该侧的子树在中序遍历结果中的起始和结束范围
//只要该范围不是1,就继续以该侧的根结点为新的子树根结点,递归地向其中继续插入左子树和右子树
void insert_child(struct TreeNode *root, int *preorder, int *inorder, int inorderSize){
  //根据root结点在inorder数组中的位置,递归地将它左侧的结点插入到它的左子树中,右侧的结点插入到它的右子树中
  int root_position = find_position_in_inorder(inorder, inorderSize, root->val);
                     
  //preorder[0,root_position)就是左子树的范围
  //inorder[0,root_position)就是左子树的范围
  if (root_position > 0){
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->left = NULL; 
    node->right = NULL;
 
    node->val = preorder[0];
    root->left = node;
    if (root_position > 1){
      insert_child(node, preorder + 1, inorder, root_position);
    }
  }

  //inorder[root_position+1,inorderSize)就是右子树的范围
  //preorder[root_position + 1,inorderSize)就是右子树的范围
  if (inorderSize > root_position + 1){
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->left = NULL; 
    node->right = NULL;
 
    node->val = preorder[root_position];
    root->right = node;
    if (inorderSize > root_position + 2){
      insert_child(node, preorder + root_position + 1,
        inorder + root_position + 1, inorderSize - root_position - 1);
    }
  }
}
//前序遍历的结果中,父结点总是出现在子节点的前面
//中序遍历结果中,在父结点左侧的都是它的左子树,右侧的都是它的右子树
//每次先在前序遍历中找到一个子树的根节点,然后在中序遍历结果中确定它的左子树和右子树的结点范围
//然后在前序遍历结果中,根结点后面紧跟着的分别是该结点的所有左子树和右子树的结点
//如果左子树的结点数量为1,那就直接将它添加在根结点的左儿子处,否则就递归,继续处理该子树
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
  struct TreeNode *root = NULL;
  if (preorderSize <= 0 || inorderSize <= 0){
    return NULL;
  }

  root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  root->val = preorder[0];
  root->left = NULL;
  root->right = NULL;
  if (preorderSize > 1){
    insert_child(root, preorder + 1, inorder, inorderSize);
  }

  return root;
}