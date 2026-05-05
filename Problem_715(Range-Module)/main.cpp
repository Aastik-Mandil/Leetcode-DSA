class RangeModule {
    vector<vector<long long>> v;

    void merge(){
        for(int i=0; i<(v.size()-1);){
            if(i+1 < v.size() && v[i][1] >= v[i+1][0]){
                v[i][0] = min(v[i][0], v[i+1][0]);
                v[i][1] = max(v[i][1], v[i+1][1]);
                v.erase(v.begin()+i+1);
            }
            else{
                i++;
            }
        }
    }
public:
    RangeModule() {
        v.clear();
    }
    
    void addRange(int left, int right) {
        v.push_back({left, right});
        sort(v.begin(), v.end());
        merge();
    }
    
    bool queryRange(int left, int right) {
        for(int i=0; i<v.size(); i++){
            if(v[i][0] <= left && v[i][1] >= right){
                return true;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        int n = v.size();
        for(int i=n-1; i>=0; i--){
            if(v[i][0] > left && v[i][1] < right){
                v.erase(v.begin()+i);
            }
            else if(v[i][0] > left && v[i][0] < right && v[i][1] > right){
                v[i][0] = right;
            }
            else if(v[i][0] == left && v[i][0] < right && v[i][1] > right){
                v[i][0] = right;
            }
            else if(v[i][0] < left && v[i][1] > right){
                v.insert(v.begin()+i+1, {right, v[i][1]});
                v[i][1] = left;
            }
            else if(v[i][0] >= left && v[i][1] <= right){
                v.erase(v.begin()+i);
            }
            else if(v[i][0] < left && v[i][1] > left && v[i][1] == right){
                v[i][1] = left;
            }
            else if(v[i][0] < left && v[i][1] > left && v[i][1] < right){
                v[i][1] = left;
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// PROBLEM:- https://leetcode.com/problems/range-module/description/
