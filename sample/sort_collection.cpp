#include<bits/stdc++.h>
using namespace std;

template<typename T>
void bubble_sort(vector<T>&input){
	int i,j;
	for(i=0;i<input.size()-1;++i){
		for(j=0;j<input.size()-i-1;++j){
			if(input[j]>input[j+1])
				swap(input[j], input[j+1]);
		}
	}
}

template<typename T>
void selection_sort(vector<T>&input){
    int i,j;
    for(i=0;i<input.size()-1;++i){
        int min_idx = i;
        for(j=i+1;j<input.size();++j){
            if(input[j] < input[min_idx])
                min_idx = j;
        }
        swap(input[i],input[min_idx]);
    }
}

template<typename T>
void insertion_sort(vector<T>&input){
    int i;
    for(i=1;i<input.size();++i){
        int cur = input[i];
        int j = i - 1;
        while(j>=0 && cur<input[j]){
            input[j+1]=input[j];
            j--;
        }
        input[j+1]=cur;
    }
}

template<typename T>
void shell_sort(vector<T>&input){
    int h = 1;
    while(h < input.size()/3) h = 3*h+1;
    while(h>=1){
        for(int i=h;i<input.size();++i){
            for(int j=i;j>=h&&input[j]<input[j-h];j-=h){
                swap(input[j],input[j-h]);
            }
        }
        h = h/3;
    }
}

template<typename T>
void merge_sort_recursive(vector<T>&input, vector<T>&output, int start, int end){
    if(start >= end) return;
    int len = end - start, mid = (len >> 1) + start;
    merge_sort_recursive(input, output, start, mid);
    merge_sort_recursive(input, output, mid+1, end);
    int k = start;
    int start1 = start, start2 = mid+1;
    int end1 = mid, end2 = end;
    while(start1 <= end1 && start2 <= end2)
        output[k++] = input[start1] < input[start2] ? input[start1++] : input[start2++];
    while(start1 <= end1)
        output[k++] = input[start1++];
    while(start2 <= end2)
        output[k++] = input[start2++];
    for(k=start;k<=end;++k) input[k] = output[k];
}

template<typename T>
void merge_sort_1(vector<T>&input){
    vector<T>output(input.size());
    merge_sort_recursive(input, output, 0, input.size()-1);
}

template<typename T>
void merge(vector<T>&input, int start, int mid, int end){
    // 最后一个元素是不拷贝的
    vector<T>left_input(input.begin()+start, input.begin()+mid+1);
    vector<T>right_input(input.begin()+mid+1, input.begin()+end+1);
    int start1=0, start2=0;
    int end1 = left_input.size(), end2 = right_input.size();
    int k=start;
    while(start1 < end1 && start2 < end2)
        input[k++] = left_input[start1] < right_input[start2] ? left_input[start1++] : right_input[start2++];
    while(start1 < end1)
        input[k++] = left_input[start1++];
    while(start2 < end2)
        input[k++] = right_input[start2++];
}

template<typename T>
void merge_sort_2(vector<T>&input, int start, int end){
    if(start >= end) return;
    int mid = (start+end)/2;
    merge_sort_2(input, start, mid);
    merge_sort_2(input, mid+1, end);
    merge(input, start, mid, end);
}

template<typename T>
void merge_sort_3(vector<T>&input){
	int len = input.size();
	vector<T>temp(len);
	for(int seg=1;seg<len;seg+=seg){
		for(int start=0;start<len;start+=seg+seg){
			int low = start, mid = min(start+seg,len), high = min(start+seg+seg,len);
			int k = start;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while(start1 < end1 && start2 < end2)
				temp[k++] = input[start1] < input[start2] ? input[start1++] : input[start2++];
			while(start1 < end1)
				temp[k++] = input[start1++];
			while(start2 < end2)
				temp[k++] = input[start2++];
		}
		for(int i=0;i<input.size();++i) input[i] = temp[i];
	}
}

template<typename T>
int paritition(vector<T>&input, int start, int end){
	T pivot = input[end];
	int i = start;
	for(int j=start;j<end;++j){
		if(input[j]<pivot) swap(input[i++], input[j]);   // 遍历一遍，表征pivot作为分界点 
	}
	swap(input[i],input[end]);
	return i; 
}

template<typename T>
void quick_sort(vector<T>&input, int start, int end){
	if(start < end){
		int pivot_idx = paritition(input, start, end);  
		quick_sort(input, start, pivot_idx-1);
		quick_sort(input, pivot_idx+1, end);
	}
}


class cmp_heap{
public:
	template<typename T>
    bool operator()(T &x, T &y){
        return x > y;
    }
};

template<typename T>
void heap_sort_1(vector<T>&input){
    priority_queue<T, vector<T>, cmp_heap> pq;
    for(T val : input){
        pq.push(val);
    }
    int i = 0;
    while (!pq.empty()) {
        input[i++] = pq.top();
        pq.pop();
    }
}

template<typename T>
void max_heapify(vector<T>&input, int start, int end){  // 调整start~end之间，使满足堆结构
    int dad = start;
    int son = dad*2+1;
    while(son <= end){
        if(son+1<=end && input[son] < input[son+1]) son++;
        if(input[dad] > input[son]) return;
        else{
            swap(input[dad],input[son]);
            dad = son;
            son = dad*2+1;
        }
    }
}

template<typename T>
void heap_sort_2(vector<T>&input){
    int len = input.size();
    for(int i=len/2-1;i>=0;--i) max_heapify(input, i, len-1);  // 初始化堆
    for(int i=len-1;i>0;--i){
        swap(input[0], input[i]);  // 最大的放在已排序的最前面
        max_heapify(input, 0, i-1);  // 调整堆
    }
}

void counting_sort(vector<int>&input){
    vector<int>temp(input.size());
    vector<int>count_arr(100);  // 假设已经映射到0-9
    for(int i=0;i<input.size();++i) count_arr[input[i]]++;
    for(int i=1;i<100;++i) count_arr[i] += count_arr[i-1];
    for(int i=input.size();i>0;--i) temp[--count_arr[input[i-1]]] = input[i-1];
    for(int i=0;i<input.size();++i) input[i] = temp[i];
}

int main(){
	vector<int>input = {4,2,1,3,8,7,6};
//	bubble_sort(input);
//	selection_sort(input);
//	insertion_sort(input);
//	shell_sort(input);
//	merge_sort_1(input);
//	merge_sort_2(input, 0, input.size()-1);
//	merge_sort_3(input);
//	quick_sort(input, 0, input.size()-1);
//	heap_sort_1(input); 
//	heap_sort_2(input);
	counting_sort(input);
	for(auto &i : input) cout << i << endl;
	return 0;
}