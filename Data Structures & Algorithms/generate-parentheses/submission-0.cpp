class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        int op = n;
        int cl = n;
        dfs(res,path,op, cl);

        return res;
    }

    void dfs(vector<string> &res, string &path, int &op, int&cl){
        if(op > cl){
            return;
        }

        if(op == 0 && cl ==0){
            res.push_back(path);
            return;
        }

        if(op <= cl ){
            if(op > 0){
                path.push_back('(');
                op--;
                dfs(res, path, op, cl);
                path.pop_back();
                op++;
            }
            if(cl >0){
                path.push_back(')');
                cl--;
                dfs(res, path, op, cl);
                cl++;
                path.pop_back();
            }
        }
    }
};
