/*
剑指 Offer 03. 数组中重复的数字

找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
*/
class Solution {
public:
    /*
        思路：利用数组长度为n，且所有数字都在0~n-1的特点
        建立一个大小为n的数组，将相应数值直接存放到数组的相应索引位置处(等值hash)
        遇到hash冲突的就说明是出现了重复数值
    */
    int findRepeatNumber(vector<int>& nums) {
        int res = -1;
        int i;
        vector<int> tmp_vec(nums.size(), -1);

        for (i = 0; i < nums.size(); i++) {
            if (tmp_vec[nums[i]] >= 0) {
                res = nums[i];
                break;
            } else {
                tmp_vec[nums[i]] = nums[i];
            }
        }

        return res;
    }
}
