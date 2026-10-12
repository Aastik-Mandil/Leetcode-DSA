typedef pair<int, char> P;

class Solution {
public:
    string frequencySort(string s) {
        // calculate the frequency for each character
        unordered_map<char, int> mp;
        for(char &ch: s){
            mp[ch]++;
        }

        // store it into max-heap
        priority_queue<P, vector<P>> pq; // {freq, char}
        for(auto itr=mp.begin(); itr!=mp.end(); itr++){
            pq.push({itr->second, itr->first});
        }

        // create the result based on the condition
        string ans = "";
        while(pq.size() > 0){
            int cnt = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            while(cnt--){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/sort-characters-by-frequency/description/
