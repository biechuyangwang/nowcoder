/*
* author： 李俊
* time：2020/12/14
*
* 二叉树层次遍历
*/

/*
* 注意事项
*/

/*
* 分层的层次遍历
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e9+7;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
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
};

int main(){
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node3->right = node5;
	TreeNode *input = node1;
	
	Solution ss;
    auto res = ss.levelOrder(input);

    for(auto val : res)
		cout << val << " ";
	cout << endl;
	return 0;
}

/*
* output 1:
* 100
*/