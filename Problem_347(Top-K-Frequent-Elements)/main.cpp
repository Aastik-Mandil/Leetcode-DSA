class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp; // {val -> count}
        set<pair<int,int>> st; // {count, val}
        for(int &num: nums){
            if(mp[num] == 0){
                mp[num]++;
                st.insert({mp[num], num});
            }
            else{
                st.erase({mp[num], num});
                mp[num]++;
                st.insert({mp[num], num});
            }

            if(st.size() > k){
                st.erase(st.begin());
            }
        }
        vector<int> ans;
        for(auto itr=st.begin(); itr!=st.end();itr++){
            int val = itr->second;
            ans.push_back(val);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/top-k-frequent-elements/description/
