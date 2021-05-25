/*
剑指 Offer 32 - III. 从上到下打印二叉树 III
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/submissions/

执行用时：8 ms, 在所有 C 提交中击败了62.28% 的用户
内存消耗：11.3 MB, 在所有 C 提交中击败了17.96% 的用户
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
    int **output_array;
    int level = 0;
    int level_index = 0;
    int level_size = 1;
    int queue_index = 0;
    int queue_size = 1;
    int i;

    if (!root){
        *returnColumnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }
    node_queue[0] = root;
    output_array = (int **)malloc(sizeof(int *));
    *returnColumnSizes = (int *)malloc(sizeof(int));
    while (queue_index < queue_size){
        root = node_queue[queue_index++];
        if (root->left){
            node_queue[queue_size++] = root->left;
        }
        if (root->right){
            node_queue[queue_size++] = root->right;
        }

        level_index++;
        if (level_index == level_size){
            //next level
            output_array = (int **)realloc(output_array,
                (level + 1) * sizeof(int *));
            output_array[level] = (int *)malloc(level_size * sizeof(int));
            
            *returnColumnSizes = (int *)realloc(*returnColumnSizes,
                (level + 1) * sizeof(int));
            *(*returnColumnSizes + level) = level_size;
            if (level % 2 == 0){
                //从左到右将node_queue[level]中的元素输出到output_array[]中
                for (i = 0; i < level_size; i++){
                    *(output_array[level] + i) = node_queue[queue_index - level_size + i]->val;
                }
            } else {
                //从右到左将node_queue[level]中的元素输出到output_array[]中
                for (i = level_size; i > 0; i--){
                    *(output_array[level] + level_size - i) = node_queue[queue_index - level_size + i - 1]->val;
                }
            }
            level++;
            level_index = 0;
            level_size = queue_size - queue_index;
        }
    }

    *returnSize = level;
    return output_array;
}