class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        int o=0;
        int c = 0;
        dfs(path, n,res,o,c);
        return res;
    }

    void dfs(string &path, int &n, vector<string> &res, int &o, int &c){
        if(o == n && c == n){
            res.push_back(path);
            return;
        }
        else if(c > o){
            return;
        }

        if(o < n){
            path += '(';
            o++;
            dfs(path, n, res,o,c);
            path.pop_back();
            o--;
        }
        if(c < o){
            path += ')';
            c++;
            dfs(path, n, res,o,c);
            c--;
            path.pop_back();
        }

    }
};
