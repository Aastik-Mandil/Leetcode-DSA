class MyCalendar {
    vector<vector<int>> v;

    bool isOccupied(int left, int right) {
        int n = v.size();
        for(int i=n-1; i>=0; i--){
            if(v[i][0] > left && v[i][1] < right){
                return true;
            }
            else if(v[i][0] > left && v[i][0] < right && v[i][1] > right){
                return true;
            }
            else if(v[i][0] == left && v[i][0] < right && v[i][1] > right){
                return true;
            }
            else if(v[i][0] < left && v[i][1] > right){
                return true;
            }
            else if(v[i][0] >= left && v[i][1] <= right){
                return true;
            }
            else if(v[i][0] < left && v[i][1] > left && v[i][1] == right){
                return true;
            }
            else if(v[i][0] < left && v[i][1] > left && v[i][1] < right){
                return true;
            }
        }
        return false;
    }
    void addRange(int left, int right) {
        v.push_back({left, right});
    }

public:
    MyCalendar() {
        v.clear();
    }
    
    bool book(int startTime, int endTime) {
        if(isOccupied(startTime, endTime)){
            return false;
        }
        addRange(startTime, endTime);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
// PROBLEM:- https://leetcode.com/problems/my-calendar-i/description/
