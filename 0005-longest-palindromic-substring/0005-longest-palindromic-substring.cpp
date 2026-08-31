class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, len = 1;

        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i, start, len);       // odd length
            expand(s, i, i + 1, start, len);   // even length
        }

        return s.substr(start, len);
    }

    void expand(string& s, int l, int r, int& start, int& len) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > len) {
                start = l;
                len = r - l + 1;
            }
            l--;
            r++;
        }
    }
};