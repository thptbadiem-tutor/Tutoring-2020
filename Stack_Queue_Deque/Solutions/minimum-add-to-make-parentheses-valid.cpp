class Solution {
public:
    int minAddToMakeValid(string S) {
        int result = 0, open = 0;
        stack<int> parenthesis;
        for (int i = 0; i < S.length(); ++ i) {
            if (S[i] == '(') {
                parenthesis.push(i);
                ++ open; 
            } else {
                if (open) {
                    -- open;
                    parenthesis.pop();
                } else {
                    ++ result;
                }
            }
        } 
        //result += open;
        while (!parenthesis.empty()) {
            ++ result;
            parenthesis.pop();
        }
        return result;
    }
};