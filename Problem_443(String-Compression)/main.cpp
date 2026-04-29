class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        vector<char> v;
        for(int i=1; i<chars.size(); i++){
            if(chars[i] == chars[i-1]){
                count++;
            }
            else{
                v.push_back(chars[i-1]);
                if(count > 1){
                    string val = to_string(count);
                    for(char &ch: val){
                        v.push_back(ch);
                    }
                    count = 1;
                }
            }
        }

        v.push_back(chars[chars.size()-1]);
        if(count > 1){
            string val = to_string(count);
            for(char &ch: val){
                v.push_back(ch);
            }
        }

        for(int i=0; i<v.size(); i++){
            if(i >= chars.size()){
                chars.push_back('\0');
            }
            chars[i] = v[i];
        }
        return v.size();
    }
};
// PROBLEM:- https://leetcode.com/problems/string-compression/description
