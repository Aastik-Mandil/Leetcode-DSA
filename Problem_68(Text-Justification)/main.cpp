class Solution {
    string makeStr(vector<string> &words, int st, int ed, int size, int maxWidth){
        int extraSpace = maxWidth - size;
        if(ed-st == 1){
            string z = "";
            for(int i=0;i<extraSpace;i++){
                z.push_back(' ');
            }
            return words[st]+z;
        }
        string z = "";
        for(int i=0;i<(extraSpace/(ed-st-1));i++){
            z.push_back(' ');
        }
        int rem = extraSpace%(ed-st-1);
        string ans = words[st];
        for(int i=st+1;i<ed;i++){
            ans+=(rem > 0 ? (z+"  "+words[i]) : (z+" "+words[i]));
            rem--;
        }
        return ans;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int last = 0, size = 0;
        for(int i=0; i<words.size(); i++){
            if(size + (last == i ? 0 : 1) + words[i].size() > maxWidth){
                ans.push_back(makeStr(words, last, i, size, maxWidth));
                last = i;
                size = words[i].size();
            }
            else{
                if(last != i){
                    size++;
                }
                size += words[i].size();
            }
        }
        if(last < words.size()){
            string t = words[last];
            for(int i=last+1;i<words.size();i++){
                t+=" "+words[i];
            }
            while(t.size()<maxWidth){
                t.push_back(' ');
            }
            ans.push_back(t);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/text-justification/description/
