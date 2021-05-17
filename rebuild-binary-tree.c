/*
剑指 Offer 07. 重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//前序遍历的第一个结果一定是根节点，然后依次看它的下一个元素是否是左儿子
//如果不是左儿子，那就看是不是右儿子
//如果不是右儿子，那就回到上层去看是不是父节点的右儿子，
//如果是该节点的左儿子，那么它在中序遍历中的结果就一定紧挨着该元素的左边
//于是就判断在中序遍历的结果中，该元素的左边值是不是和它在前序遍历结果中的右边值相等
//然后再以下一个元素为当前元素，重复上述处理过程
//中序遍历结果中，任意一个元素，它左边的元素在二叉树中一定是在它的左侧，它右边的元素在二叉树中一定是在它的右侧
//因此判断一个元素是当前节点的右儿子，还是父节点的右儿子方法：如果一个元素是当前节点的右儿子，那么在中序遍历结果中它就一定位于父节点和子节点之间
//否则它就是父节点的右儿子

//返回一个元素在中序遍历结果数组中的位置
int find_position_in_inorder(int *inorder, int inorderSize, int target){
  int i;
  for (i = 0; i < inorderSize; i++){
    if (inorder[i] == target){
      break;
    }
  } 
  return i;
}

//往一个节点插入孩子，这个孩子要么是它的
//head_position:head节点在中序遍历数组中的位置
//递归地插入一个节点，如果该节点（target_node）在中序遍历结果数组中的位置target_position
//在树中的一个节点head对应的位置head_position的左边，那它就插入在树的左边，否则就插入在树的右边
void insert_child(struct TreeNode *head, struct TreeNode *target_node,
  int *inorder, int inorderSize, int target_position){
    //直接看head在不在target_position的左边/右边，而不用扫描全部
  int head_position = find_position_in_inorder(inorder, target_position, head->val);
  //如果head_position=target_position，说明没找到,否则head_position<target_position就说明在左边找到了
  if (head_position >= target_position){
    if (head->left){
      insert_child(head->left, target_node, inorder, inorderSize, target_position);
    } else {
      head->left = target_node;
    }
  } else {
    if (head->right){
      insert_child(head->right, target_node, inorder, inorderSize, target_position);
    } else {
      head->right = target_node;
    }
  }
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
  //如果一个元素为父节点的右儿子，那么意味着在中序遍历结果中父节点左侧的数据都处理完了。
  //此时中序遍历结果中只需要看父节点右侧的数据，在其中进行搜索
  struct TreeNode *result_tree = NULL;
  int i, j;
  //int parent_position;//parent元素在中序遍历结果数组中的位置
  int current_position;
  //int saved_positions[5000];

  if ((preorderSize <= 0) || (inorderSize == 0)){
    return NULL;
  }
  result_tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  result_tree->val = preorder[0];
  result_tree->left = NULL;
  result_tree->right = NULL;

  for (i = 1; i < preorderSize; i++){
    struct TreeNode *current_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    current_node->val = preorder[i];
    current_node->left = NULL;
    current_node->right = NULL;
    //当前元素在中序遍历结果数组中的位置
    //不需要从0开始查找，只需要从上次处理完的parent_position的位置开始查找？
    //current_position = find_position_in_inorder(inorder + last_parent_position,
    //  inorderSize - parent_position, preorder[i]); 
    current_position = find_position_in_inorder(inorder,
      inorderSize, preorder[i]); 
    //每查找一个节点的位置，就记录它的位置，防止后面重复查找
    insert_child(result_tree, current_node, inorder, inorderSize, current_position); 
  }

  return result_tree;
}