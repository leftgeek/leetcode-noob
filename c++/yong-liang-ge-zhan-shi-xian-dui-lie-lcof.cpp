/*
剑指 Offer 09. 用两个栈实现队列
[难度：简单]
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof

执行用时：320 ms, 在所有 C++ 提交中击败了27.30% 的用户
内存消耗：101 MB, 在所有 C++ 提交中击败了73.59% 的用户
*/

/*
两个栈a和b
在appendTail时，将新元素压入栈a
在deleteHead时，弹出栈b的栈顶元素，如果栈b为空，则将栈a的所有元素依次弹出并压入到栈b中进行补充
*/
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stack_append_.push(value);
    }
    
    int deleteHead() {
        int res = -1;

        if (stack_delete_.empty()) {
            //将stack_append_栈中的所有元素弹出并依次压入stack_delete_栈中
            while (!(stack_append_.empty())) {
                stack_delete_.push(stack_append_.top());
                stack_append_.pop();
            }
        }
        if (!stack_delete_.empty()) {
            res = stack_delete_.top();
            stack_delete_.pop();
        }

        return res;
    }

private:
    std::stack<int> stack_append_;
    std::stack<int> stack_delete_;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */