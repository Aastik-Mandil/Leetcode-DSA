class Solution {
public:
    string simplifyPath(string path) {
        string z = "";
        stack<string> st;
        for(char &ch: path){
            if(ch == '/'){
                if(z.size() == 0 || z == "."){
                }
                else if(z == ".."){
                    if(st.size() > 0){
                        st.pop();
                    }
                }
                else{
                    st.push(z);
                }
                z = "";
            }
            else{
                z.push_back(ch);
            }
        }
        if(z.size() == 0 || z == "."){
        }
        else if(z == ".."){
            if(st.size() > 0){
                st.pop();
            }
        }
        else{
            st.push(z);
        }
        string ans = "";
        while(st.size() > 0){
            ans = "/"+st.top()+ans;
            st.pop();
        }
        if(ans.size() == 0){
            return "/";
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/simplify-path/description
