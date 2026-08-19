class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int l = 0;
        unordered_set<char> mySet;

        for (int i = 0; i < s.size(); i++) {

            while (mySet.count(s[i])) {
                mySet.erase(s[l]);
                l++;
            }

            mySet.insert(s[i]);

            longest = max(longest, (int)mySet.size());
        }

        return longest;
    }
};