/*
剑指 Offer 33. 二叉搜索树的后序遍历序列
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/

执行用时：4 ms, 在所有 C 提交中击败了63.77% 的用户
内存消耗：5.6 MB, 在所有 C 提交中击败了74.40% 的用户

思路：
二叉搜索树就是左元素值都比右元素值小，最后一个遍历的一定是树根。
并且从分块的角度来看，一定是左子树比右子树先遍历完。
而左子树的元素都小于根，右子树的元素都大于根
于是在从左到右扫描数组的时候，将扫描到的元素和根元素进行大小的对比。
一旦遇到大于根的元素，就说明从它开始就是根的右子树。
于是就相当于判断右子树的所有元素是否大于根。
而对于每一个子树而言，它的最后一个元素就是子树的根。
于是可以用同样的方法递归地判断该子树是否满足二叉搜索树的条件。
*/
//二叉搜索树的中序遍历结果就是由小到大排序后的结果
//可以先对数组元素进行排序，就得到了二叉搜索树的中序遍历结果
//然后问题就变成了，知道一棵二叉搜索树的中序遍历结果和后序遍历结果
//判断这棵二叉搜索树是否存在
bool verifyPostorder(int* postorder, int postorderSize){
    if (postorder == NULL || postorderSize < 1){
        return true;
    }
    bool result = true;
    int root = postorder[postorderSize - 1];
    //二叉搜索树的根的左子树元素都小于根元素
    //根的右子树元素都大于根元素
    int i;
    for (i = 0; i < postorderSize - 1; i++){
        if (postorder[i] > root){
            break;
        }
    }
    //从postorder[i]开始就是右子树的元素
    //递归判断左子树是否满足条件
    if (i > 1){
        result = verifyPostorder(postorder, i);
    }
    //此时的postorder[i]就是右子树的最小值
    i++;
    if (result && i < postorderSize - 1){//存在右子树
        int j = i;
        //左子树范围为0 ~ i-1
        //右子树范围为i ~ postorderSize - 1
        //判断右子树的所有元素是否都大于根即可
        for (; j < postorderSize - 1; j++){
           if (postorder[j] < root){
               result = false;
               break;
           } 
        }
        if (result){
            //递归地判断右子树是否满足条件
            result = verifyPostorder(postorder + i - 1, postorderSize - i);
        }
    }
    return result;
}