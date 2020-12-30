# [二叉树的之字形层次遍历](https://www.nowcoder.com/practice/47e1687126fa461e8a3aff8632aa5559)
[题解](./main_1.cpp)

思路：  
```cpp
/*
* 层次遍历
*/
```
详见[原地hash](../../ideas/查找.md)

## 题解
```cpp
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    // write code here
    vector<vector<int>>res;
    if(!root) return res;  // 边界条件别忘了。
    queue<TreeNode *>q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        level++;
        int sz=q.size();
        vector<int>tmp;
        while(sz--){
            TreeNode *cur = q.front();
            tmp.push_back(cur->val);
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right) ;
        }
        if(level%2==0)
            reverse(tmp.begin(),tmp.end());
        res.push_back(tmp);
    }
    return res;
}
```