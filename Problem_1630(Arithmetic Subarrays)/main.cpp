class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int n = l.size();
        for(int i=0; i<n; i++){
            int st = l[i];
            int ed = r[i];
            if(ed-st+1 < 2){
                ans.push_back(false);
                continue;
            }
            priority_queue<int,vector<int>> pq;
            for(int i=st; i<=ed; i++){
                pq.push(nums[i]);
            }

            int top = pq.top();
            pq.pop();
            int last = pq.top();
            pq.pop();
            int d = top - last;
            bool flag = true;
            while(pq.size() > 0 && flag){
                if(last - pq.top() != d){
                    flag = false;
                }
                last = pq.top();
                pq.pop();
            }
            ans.push_back(flag);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/arithmetic-subarrays/description/?envType=problem-list-v2&envId=array
