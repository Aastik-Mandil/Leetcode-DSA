typedef pair<int, string> P;

struct Comp{
    bool operator()(P &a, P &b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // store the frequency of word
        unordered_map<string, int> mp;
        for(string &word: words){
            mp[word]++;
        }

        // store only k element
        priority_queue<P, vector<P>, Comp> pq; // {freq, word}
        for(auto itr=mp.begin(); itr!= mp.end(); itr++){
            pq.push({itr->second, itr->first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<string> ans(k);
        while(pq.size() > 0){
            string word = pq.top().second;
            pq.pop();
            ans[pq.size()] = word;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/top-k-frequent-words/description/
