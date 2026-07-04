typedef pair<int, int> P;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<P> v;
        for(int i=0; i<nums.size(); i++){
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end(), [](P &p1, P &p2){
            return p1.first > p2.first;
        });

        vector<P> temp;
        for(int i=0; i<k; i++){
            temp.push_back(v[i]);
        }
        sort(temp.begin(), temp.end(), [](P &p1, P &p2){
            return p1.second < p2.second;
        });
        
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/
