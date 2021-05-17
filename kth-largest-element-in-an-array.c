/*
215. 数组中的第K个最大元素
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
执行用时：8 ms, 在所有 C 提交中击败了94.59% 的用户
内存消耗：6 MB, 在所有 C 提交中击败了81.96% 的用户

利用快速排序的partition思想，将第k个元素作为枢纽元素，
然后将小于它的元素放到它的左边，大于它的元素放到它的右边
*/
int findKthLargest(int* nums, int numsSize, int k){
    int i, j;

    i = 0;
    j = numsSize - 1;

    while (i != j){
        //当nums[k-1]处的处的枢纽元素与nums[i]交换后(因为j移到了k-1)，j需要重新开始比较
        //反之亦然
        if (i == k - 1){//因为i右移到了枢纽点
            i = 0;
        } else if (j == k - 1){//因为j左移到了枢纽点
            j = numsSize - 1;
        }

        while (nums[i] >= nums[k - 1] && i < k - 1){
            i++;
        }
        while (nums[j] <= nums[k - 1] && j > k - 1){
            j--;
        }
        if (i < j) {
            //swap nums[i],nums[j]
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }

    return nums[k - 1];
}