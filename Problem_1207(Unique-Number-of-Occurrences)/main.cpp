class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int &val: arr){
            mp[val]++;
        }

        unordered_set<int> st;
        for(auto itr=mp.begin(); itr!=mp.end(); itr++){
            st.insert(itr->second);
        }

        return mp.size() == st.size();
    }
};
// PROBLEM:- https://leetcode.com/problems/unique-number-of-occurrences/description
