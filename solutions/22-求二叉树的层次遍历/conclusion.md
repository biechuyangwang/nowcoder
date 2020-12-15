# [求二叉树的层次遍历](https://www.nowcoder.com/practice/04a5560e43e24e9db4595865dc9c63a3)
[题解](./main_1.cpp)

二叉树的遍历(先序、中序、后序、层次)，详见[二叉树的遍历](../../ideas/遍历.md)
## 二叉树的层次遍历(带层数)
```cpp
vector<vector<int> > levelOrder(TreeNode* root){
	// write code here
	vector<vector<int>>res;
	queue<TreeNode*>q;
	q.push(root);
	while(!q.empty()){
		int sz = q.size();
		vector<int>tmp;
		while(sz--){
			TreeNode *cur = q.front();
			q.pop();
			tmp.push_back(cur->val);
			if(cur->left) q.push(cur->left);
			if(cur->right) q.push(cur->right);
		}
		res.push_back(tmp);
	}
	return res;
}
```

## 二叉树的层次遍历(不带层数)
```cpp
vector<int> levelOrder(TreeNode* root){
	// write code here
	vector<int>res;
	queue<TreeNode*>q;
	q.push(root);
	while(!q.empty()){
		TreeNode *cur = q.front();
		q.pop();
		res.push_back(cur->val);
		if(cur->left) q.push(cur->left);
		if(cur->right) q.push(cur->right);
	}
	return res;
}
```