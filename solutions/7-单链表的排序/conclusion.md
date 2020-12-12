# [单链表的排序](https://www.nowcoder.com/practice/f23604257af94d939848729b1a5cda08)
[题解](./main_1.cpp)

扩展：
[链表]()

## 1 借助辅助空间
利用辅助空间排序，然后通过只改变节点的值来实现链表排序。
```cpp
ListNode* sortInList(ListNode* head) {
    ListNode *p = head;
    vector<int>input;
    while(p){
        input.push_back(p->val);
        p = p->next;
    }
    sort(input.begin(),input.end());
    p = head;
    int i=0;
    while(p){
        p->val = input[i++];
        p = p->next;
    }
    return head;
}
```

## 2 正常链表操作(可能会超时)——冒泡排序

```cpp
ListNode* sortInList(ListNode* head) {
    // write code here
    if(head==nullptr) return head;
    ListNode *vhead = new ListNode(0);
    vhead->next = head;
    ListNode *pre = vhead, *cur=head, *p=head;
    while(p->next!=nullptr){
        pre = vhead;
        cur = head;
        while(cur->next!=nullptr){
            if(cur->val > cur->next->val){  // 使用pre指针辅助交换cur和cur->next
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = cur;
            }
            pre = cur;
            cur = cur->next;
        }
        p = p->next;
    }
    return head;
}
```