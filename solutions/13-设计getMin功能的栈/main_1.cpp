/*
* author： 李俊
* time：2020/12/12
*
* 链表操作 
*/

/*
* 注意事项
*/

/*
* 多维vector的列表赋值
* vector<vector<int>>input = {{1,1,1},{1,2,2},{1,3,2},{2,1},{1,4,4},{2,2}};
*/

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
struct DListNode{
    int key, val;
    DListNode* pre;
    DListNode* next;
    DListNode(int k,int v): key(k), val(v), pre(nullptr), next(nullptr){};
    
};

const int MAXN = 1e9+7;
class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k){
        // write code here
		vector<int>res;
		if(k<1 || operators.size() ==0) return res;
		this->size = k;
		this->head = new DListNode(0,0);
		this->tail = new DListNode(0,0);
		this->head->next = this->tail;
		this->tail->pre = this->head;
		for(auto op : operators){  // 对操作列表遍历
			if(op[0]==1){
				set(op[1],op[2]);
			}else if(op[0]==2){
				int value = get(op[1]);
				res.push_back(value);
			}
		}
		return res;
    }
    
    void set(int key, int val){
    	if(ump.find(key)==ump.end()){
    		DListNode *node = new DListNode(key,val);
    		ump[key] = node;
    		if(this->size <=0) removeLast();
    		else this->size--;
    		insertFirst(node);
		}else{
			ump[key]->val = val;
			move2Head(ump[key]);
		}
	}

	int get(int key){
		int ret = -1;
		if(ump.find(key)!=ump.end()){
			ret = ump[key]->val;
			move2Head(ump[key]);
		}
		return ret;
	}

	void move2Head(DListNode* node){  // 将一个节点移到头结点(删除，然后头插)
		if(node->pre == this->head) return;
		node->pre->next = node->next;
		node->next->pre = node->pre;
		insertFirst(node);
	}

	void removeLast(){  // 移除尾部一个节点
		ump.erase(this->tail->pre->key);
		this->tail->pre->pre->next = this->tail;
		this->tail->pre = this->tail->pre->pre;
	}

	void insertFirst(DListNode* node){  // 头插一个节点
		node->pre = this->head;
		node->next = this->head->next;
		this->head->next->pre = node;
		this->head->next = node;
	}
private:
	int size = 0;
	DListNode *head;
	DListNode *tail;
	unordered_map<int, DListNode*>ump;
};

int main(){
	vector<vector<int>>input = {{1,1,1},{1,2,2},{1,3,2},{2,1},{1,4,4},{2,2}};
	int k = 3;
	vector<int>res;
	
	Solution s;
    res = s.LRU(input,k);
    for(auto val : res)
		cout << val << " ";
	cout << endl;
	return 0;
}

/*
* output 1:
* 1 -1
*/