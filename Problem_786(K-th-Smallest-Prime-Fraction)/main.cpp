typedef vector<int> v;

struct CompareTask {
    bool operator()(v &a, v &b){
        return (a[0] * 1.0)/(a[1] * 1.0) < (b[0] * 1.0)/(b[1] * 1.0);
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<v, vector<v>, CompareTask> pq;
        int n = arr.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                pq.push({arr[i], arr[j]});
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};
// PROBLEM:- https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
