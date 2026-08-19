class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> res;

        vector<vector<string>> results;

        for(auto &str: strs){
            vector<int> alphabet(26,0);
            for(int i = 0; i < str.size(); i++){
                alphabet[str[i]-'a']++;
            }
            
            string key;
            key += to_string(alphabet[0]);
            for(int i =1; i < 26; i++){
                key += ',' + to_string(alphabet[i]);
            }

            res[key].push_back(str);
        }

        for(auto [key, value]: res){
            results.push_back(value);
        }

        return results;

    }
};
