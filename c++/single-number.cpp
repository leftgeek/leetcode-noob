/*
136. 只出现一次的数字
[难度：简单]
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number

执行用时：12 ms, 在所有 C++ 提交中击败了90.19% 的用户
内存消耗：16.4 MB, 在所有 C++ 提交中击败了91.47% 的用户
*/

//利用异或算法的特点：a ^ b ^ a = b
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            result ^= *it;
        }

        return result;
    }
};