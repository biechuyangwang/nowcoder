/*
* author： 李俊
* time：2020/12/21
*
* 将升序数组转化为平衡二叉搜索树
*/

/*
* 注意事项
*/

/*
* 先序遍历建树过程
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
     * @param num int整型vector 
     * @return TreeNode类
     */
    TreeNode* pre_Order(vector<int>& num, int start, int end){
        if(start > end) return nullptr;
        int mid = (start+end+1)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = pre_Order(num, start, mid-1);
        root->right = pre_Order(num, mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& num) {
        // write code here
        TreeNode *res = pre_Order(num, 0, num.size()-1);
        return res;
    }
};

int main(){
	vector<int>input = {-1,0,1,2};
	Solution ss;
    auto res = ss.sortedArrayToBST(input);
    cout << res->val << " " << res->left->val << " " << res->right->val << res->left->left->val << endl;
	return 0;
}

/*
* output 1:
* 1,0,2，-1
*/