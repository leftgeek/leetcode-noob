/*
剑指 Offer 04. 二维数组中的查找
(难度中等)
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof

结果：
执行用时：20 ms, 在所有 C++ 提交中击败了79.55% 的用户
内存消耗：12.7 MB, 在所有 C++ 提交中击败了63.96% 的用户
*/

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        //可以把它看成是一个向右倾斜的二分查找，即如果将左下角到右上角连成一条线的话，线的左边数据都比右边小
        int res = false;
        if ((matrix.size() == 0) || matrix[0].size() == 0) {
            return res;
        }
        
        int row_tail = matrix[0].size() - 1;   //当前查找行的末尾index
        int col_head = 0;   //当前查找列的起始index
        //我们要查找的target在二维数组左下角和maxtix[col_head][row_tail]限定的范围中

        while ((row_tail >= 0) && (col_head < matrix.size())) {
            if (target < matrix[col_head][row_tail]) {
                //此时row_tail所在的列可以排除掉
                row_tail--;
            } else if (target > matrix[col_head][row_tail]) {
                //此时col_head所在的行可以排除掉
                col_head++;
            } else {
                res = true;
                break;
            }
        }

        return res;
    }
}