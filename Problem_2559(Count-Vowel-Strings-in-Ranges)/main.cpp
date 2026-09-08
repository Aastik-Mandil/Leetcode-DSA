class Solution {
    bool isVowel(char ch){
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(char &vowel: vowels){
            if(ch == vowel){
                return true;
            }
        }
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();

        // calculate that current word should start and end with vowel
        vector<int> v(n, 0);
        for(int i=0; i<n; i++){
            string word = words[i];
            if(isVowel(word[0]) && isVowel(word.back())){
                v[i] = 1;
            }
        }

        // calculate the prefix sum (for range queries)
        for(int i=1; i<n; i++){
            v[i] += v[i-1];
        }

        // create the output array
        vector<int> ans;
        for(vector<int> &query: queries){
            int st = query[0];
            int ed = query[1];
            int val = v[ed];
            if(st-1 >= 0){
                val -= v[st-1];
            }
            ans.push_back(val);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/count-vowel-strings-in-ranges/description/
