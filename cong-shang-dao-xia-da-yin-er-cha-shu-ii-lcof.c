/*
剑指 Offer 32 - II. 从上到下打印二叉树 II
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
执行用时：4 ms, 在所有 C 提交中击败了93.98% 的用户
内存消耗：11.2 MB, 在所有 C 提交中击败了20.78% 的用户
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    struct TreeNode *node_queue[1010];
    int **result_array = (int **)malloc(sizeof(int *));
    *returnColumnSizes = (int *)malloc(sizeof(int));
    int index = 0;
    int queue_size = 1;
    int level = 0; //层数
    int column = 0; //当前层已经遍历的元素数量
    int level_column = 1;   //每一层的元素总数量
    struct TreeNode *node;

    if (!root){
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    node_queue[0] = root;
    while (index < queue_size){
        //每次弹出一个元素，打印，再将它的子元素加入到队列中
        node = node_queue[index++];
        if (node->left){
            node_queue[queue_size++] = node->left;
        }
        if (node->right){
            node_queue[queue_size++] = node->right;
        }
        column++;
        if (column == level_column){
            //为该层结果数组分配空间
            int i;
            //level每增加一层，结果数组大小就得扩充
            *returnColumnSizes = (int *)realloc(*returnColumnSizes, (level + 1) * sizeof(int));
            *(*returnColumnSizes + level) = level_column;

            result_array = (int **)realloc(result_array, (level + 1) * sizeof(int *));
            result_array[level] = (int *)malloc(level_column * sizeof(int));
            for (i = 0; i < level_column; i++){
                *(result_array[level] + i) = node_queue[index - level_column + i]->val;
            }
            //next level
            level++;
            level_column = queue_size - index;
            column = 0;
        }
    }

    *returnSize = level;
    return result_array;
}