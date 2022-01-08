/*
https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
剑指 Offer 05. 替换空格
难度：简单
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

执行结果：
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了82.36% 的用户
*/

class Solution {
public:
    string replaceSpace(string s) {
        char tmp_str[30001];
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                tmp_str[j++] = '%';
                tmp_str[j++] = '2';
                tmp_str[j++] = '0';
            } else {
                tmp_str[j++] = s[i];
            }
        }
        tmp_str[j] = '\0';

        string result(tmp_str);
        return result;
    }
}