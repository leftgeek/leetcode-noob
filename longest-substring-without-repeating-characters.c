/*
3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度

    0 <= s.length <= 5 * 104
    s 由英文字母、数字、符号和空格组成

https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/submissions/

执行用时：0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗：5.8 MB, 在所有 C 提交中击败了51.07% 的用户
*/
#define MAX_SIZE 128
//ascii为8位,因此可以用2^7大小的数组作为hash表
int lengthOfLongestSubstring(char * s){
    int length = strlen(s);
    if (!length){
        return 0;
    }

    int i, j;
    int pos;
    int max_sub_str_len = 0;    //已知最长子串的长度
    int sub_str_len = 0;    //当前子串的长度
    int sub_str_start = 1;  //子串的起始位置
    int dict[MAX_SIZE];//以数组下标为key，字符串中的位置为value的hash表
    memset(dict, 0, MAX_SIZE * sizeof(int));//清零0，字符串的位置从1开始而不是0

    for (i = 0; i < length; i++){
        //对于每一个字符，判断它是否存在于hash表中
        pos = dict[s[i]];
        if (pos >= sub_str_start){//只有pos大于sub_str_start的串才是有效的
            if (sub_str_len > max_sub_str_len){
                max_sub_str_len = sub_str_len;
            }
            //既然当前字符与pos处的字符重复，
            //那么从pos+1开始的字符到i就不重复，
            //于是新的子串从pos+1开始
            sub_str_start = pos + 1;
            sub_str_len = i + 1 - pos;
        } else {
            sub_str_len++;//无重复字符，子串长度增加 
        }
        //当前字符以及对应的位置加入hash表
        dict[s[i]] = i + 1;
    }
    if (max_sub_str_len < sub_str_len){
        max_sub_str_len = sub_str_len;
    }

    return max_sub_str_len;
}