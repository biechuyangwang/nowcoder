# [链表中环的入口节点](https://www.nowcoder.com/practice/6e630519bf86480296d0f1c868d425ad)
[题解](./main_1.cpp)

## 思路
```cpp
/*
* 快慢指针
* 环的长度为b
* fast=slow=head;
* 相遇点为t
* 一个指针放在t，一个放在起点，以相同的速度前进，经过t时间， 一定在t点相遇
* 但是在此之前一定会在环的入口先相遇，这样就找到环的入口了。
*/
```
## 题解
```cpp
ListNode *detectCycle(ListNode *head) {
    if(head==nullptr) return nullptr;
    ListNode *slow=head,*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){  // 仅用考虑fast 
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            fast = head;
            while(fast!=slow){
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        } 
    }
    return nullptr;
}
```
