/*
* author： 李俊
* time：2020/12/18
*
* 二叉树的之字形层次遍历
*/

/*
* 注意事项
*/

/*
* 带level的层次遍历
*/

#include<bits/stdc++.h>
using namespace std;

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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        // write code here
        vector<vector<int>>res;
        if(!root) return res;
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
};

int main(){
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node9 = new TreeNode(9);
	TreeNode *node20 = new TreeNode(20);
	TreeNode *node15 = new TreeNode(15);
	TreeNode *node7 = new TreeNode(7);
	node3->left = node9;
	node3->right = node20;
	node9->left = node15;
	node9->right = node7;
	TreeNode *input = node3;

	Solution ss;
    auto res = ss.zigzagLevelOrder(input);

	for(auto v : res){
		for(auto val : v) cout << val << " ";
		cout << endl;
	}

	return 0;
}

/*
* output 1:
* 3
* 20 9
* 15 7
*/