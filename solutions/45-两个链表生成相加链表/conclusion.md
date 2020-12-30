# [两个链表生成相加链表](https://www.nowcoder.com/practice/c56f6c70fb3f4849bc56e33ff2a50b6b)
[题解](./main_1.cpp)


## 利用栈
```cpp
ListNode* addInList(ListNode* head1, ListNode* head2) {
    // write code here
    stack<int>s1;
    stack<int>s2;
    stack<int>s3;
    ListNode *p = head1;
    int len1=0,len2=0;
    while(p){
        s1.push(p->val);
        len1++;
        p = p->next;
    }
    p=head2;
    while(p){
        s2.push(p->val);
        len2++;
        p = p->next;
    }
    int flag = 0;
    int a,b,x;
    while(!s1.empty() && !s2.empty()){
        a = s1.top();
        b = s2.top();
        s1.pop();
        s2.pop();
        x = (a+b+flag)%10;
        flag = (a+b+flag)/10;
        s3.push(x);
    }
    while(!s1.empty()){
        a = s1.top();
        s1.pop();
        x = (a+flag)%10;
        flag = (a+flag)/10;
        s3.push(x);
        len1++;
    }
    while(!s2.empty()){
        b = s2.top();
        s2.pop();
        x = (b+flag)%10;
        flag = (b+flag)/10;
        s3.push(x);
        len2++;
    }
    if(len2>len1){
        head1 = head2;
    }
    if(flag==1){
        ListNode *node = new ListNode(1);
        s3.push(1);
        node->next = head1;
        head1 = node;
    }
    p=head1;
    while(!s3.empty()){
        p->val = s3.top();
        s3.pop();
        p = p->next;
    }
    return head1;
}
```

## 反转后相加
```cpp

```