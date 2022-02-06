/*
137. 只出现一次的数字 II
[难度：中等]
给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

进阶：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

https://leetcode-cn.com/problems/single-number-ii/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：9.3 MB, 在所有 C++ 提交中击败了61.29% 的用户
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        //拼凑出结果的每个bit
        for (int bit = 0; bit < 32; bit++) {
            int bit_val = 0;
            //计算结果的每个bit，累加所有元素的对应bit，每次加到3就清零
            for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
                bit_val += ((*it) >> bit) & 1;
                if (bit_val == 3) {
                    bit_val = 0;
                }
            }
            result |= bit_val << bit;
        }

        return result;
    }
};