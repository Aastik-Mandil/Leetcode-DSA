class Spreadsheet {
    vector<vector<int>> v;

    pair<int, int> getPosition(string s){
        int col = s[0]-'A';
        int row = stoi(s.substr(1, s.size()));
        return {row-1, col};
    }
    bool isCell(string s){
        return s[0] >= 'A' && s[0] <= 'Z';
    }
public:
    Spreadsheet(int rows) {
        for(int i=0; i<rows; i++){
            vector<int> z(26, 0);
            v.push_back(z);
        }
    }
    
    void setCell(string cell, int value) {
        pair<int, int> p = getPosition(cell);
        v[p.first][p.second] = value;
    }
    
    void resetCell(string cell) {
        pair<int, int> p = getPosition(cell);
        v[p.first][p.second] = 0;
    }
    
    int getValue(string formula) {
        int idx = formula.find('+');
        string left = formula.substr(1, idx-1);
        string right = formula.substr(idx+1, formula.size());
        int a, b;
        if(isCell(left)){
            pair<int, int> p = getPosition(left);
            a = v[p.first][p.second];
        }
        else{
            a = stoi(left);
        }
        if(isCell(right)){
            pair<int, int> p = getPosition(right);
            b = v[p.first][p.second];
        }
        else{
            b = stoi(right);
        }
        return a + b;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
// PROBLEM:- https://leetcode.com/problems/design-spreadsheet/description/
