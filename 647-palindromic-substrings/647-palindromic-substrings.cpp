class Solution {
    public: int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i ++) {
            int left = i, right = i;
            count += process(s, i, i);
            if (i < s.length() - 1) {
                count += process(s, i, i + 1);
            }
        }
        return count;
    }
    private: int process(string s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length()) {
            if (s.at(left) != s.at(right)) {
                break;
            }
            count ++;
            left --;
            right ++;
        }
        return count;
    }
};