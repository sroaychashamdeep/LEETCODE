
class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int need = 0;

        for (char c : s) {
            if (c == '(') {
                // An opening '(' requires two closing ')'
                if (need % 2 == 1) {
                    insertions++;
                    need--;
                }
                need += 2;
            } 
            else {
                need--;

                // No opening '(' available to match ')'
                if (need < 0) {
                    insertions++;
                    need = 1;
                }
            }
        }

        return insertions + need;
    }
};
