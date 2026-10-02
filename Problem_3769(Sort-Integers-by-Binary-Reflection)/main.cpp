typedef vector<int> P;

class Solution {
    unordered_map<int, int> mp;

    int solve(int n){
        string s = "";
        while(n>0){
            s.push_back((n%2) + '0');
            n /= 2;
        }
        int val = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                val += pow(2, s.size() - 1 - i);
            }
        }
        return val;
    }
public:
    vector<int> sortByReflection(vector<int>& nums) {
        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            if(mp.find(num) == mp.end()){
                mp[num] = solve(num);
            }
            pq.push({mp[num], num});
        }

        vector<int> ans;
        while(pq.size() > 0){
            P p = pq.top();
            ans.push_back(p[1]);
            pq.pop();
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/sort-integers-by-binary-reflection/description/
