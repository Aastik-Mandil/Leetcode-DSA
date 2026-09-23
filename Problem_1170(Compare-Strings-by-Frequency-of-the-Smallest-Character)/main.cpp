class Solution {
    int getLeastCharacterFreq(string s){
        int count = 1;
        char ch = s[0];
        for(int i=1; i<s.size(); i++){
            if(s[i] < ch){
                ch = s[i];
                count = 1;
            }
            else if(s[i] == ch){
                count++;
            }
        }
        return count;
    }
    int getCount(vector<int> &wordCount, int val){
        int l = 0, r = wordCount.size()-1;
        if(val < wordCount[0]){
            return r+1;
        }
        while(l<=r){
            int mid = l + ((r - l) / 2);
            if(wordCount[mid] > val){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return wordCount.size() - l;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        // calculate the frequency of the lexicographically smallest character in queries
        vector<int> queryCount;
        for(string &query: queries){
            queryCount.push_back(getLeastCharacterFreq(query));
        }

        // calculate the frequency of the lexicographically smallest character in words
        vector<int> wordCount;
        for(string &word: words){
            wordCount.push_back(getLeastCharacterFreq(word));
        }

        // sort the wordCount
        sort(wordCount.begin(), wordCount.end());

        // calculate the answer for each query by Binary Search
        vector<int> ans;
        for(int query: queryCount){
            ans.push_back(getCount(wordCount, query));
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/
