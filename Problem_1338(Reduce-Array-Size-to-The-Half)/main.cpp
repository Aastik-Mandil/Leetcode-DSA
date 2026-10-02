bool cond(pair<int,int> &a, pair<int,int> &b){
    return a.first > b.first;
}

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mp;
        vector<pair<int,int>> v;
        for(int &num: arr){
            if(mp[num] != 0){
                pair<int,int> p = {mp[num], num};
                auto itr = find(v.begin(), v.end(), p);
                v.erase(itr);
            }
            mp[num]++;
            v.push_back({mp[num], num});
        }

        sort(v.begin(), v.end(), cond);

        int total = 0;
        for(int i=0; i<v.size(); i++){
            total += v[i].first;
            if(total >= (n/2)){
                return i+1;
            }
        }
        return v.size();
    }
};
// PROBLEM:- https://leetcode.com/problems/reduce-array-size-to-the-half/description/
