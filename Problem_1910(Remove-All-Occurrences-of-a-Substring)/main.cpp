class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        while(true){
            string z = "";
            bool flag = false;
            for(int i=0; i<s.size();){
                if(s.substr(i, part.size()) == part){
                    flag = true;
                    i += part.size();
                    z += s.substr(i, s.size());
                    break;
                }
                else{
                    z.push_back(s[i]);
                    i++;
                }
            }
            ans = z;
            s = z;
            if(!flag){
                break;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
