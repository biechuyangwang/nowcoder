# [链表每k个节点翻转](https://www.nowcoder.com/practice/b49c3dc907814e9bbfa8437c251b028e)
[题解](./main_1.cpp)

## 思路
```cpp
/*
* 递归处理
*/
```

## 题解
```cpp
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverse(ListNode* first, ListNode* last){  // last是不在k范围内
        ListNode* pre = nullptr;
        while(first!=last){
            ListNode* tmp = first->next;
            first->next = pre;
            pre = first;
            first = tmp;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if(!head) return nullptr;
        ListNode* node = head;
        for(int i=0;i<k;++i){
            if(!node) return head;  // 链表长度小于k不处理
            node = node->next;
        }
        ListNode *newHead = reverse(head,node);  // 正常的链表反转
        head->next = reverseKGroup(node, k);  // 递归处理每一段
        return newHead;  // 第一段的表头
    }
};
```
