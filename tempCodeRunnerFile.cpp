#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>nums, int k) {
        priority_queue<int, vector<int>, greater<int>>minh;
        
        for(int i=0; i<nums.size(); i++){
            minh.push(nums[i]);
            
            if(minh.size() > k)
                minh.pop();
        }
        return minh.top();
}

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	int ak = findKthLargest(a, k);
    int bk = findKthLargest(b, k);
    vector<int >sum;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i] >= ak && b[j] >= bk){
                sum.push_back(a[i] + b[j]);
            }
        }
    }
    print(sum);
    return sum;
}

void print(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] <<" ";
    }
    cout <<endl;
}
int main(){
    vector<int>a = {1,2,3,4};
    vector<int>b = {4,3,2,1};

    kMaxSumCombination(a, b, 4, 1);

    return 0;
}