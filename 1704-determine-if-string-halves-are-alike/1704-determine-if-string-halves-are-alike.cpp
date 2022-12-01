class Solution {
public:
    bool halvesAreAlike(string s){
        int count_left = 0, count_right = 0;
        for(int i = s.length()/2 - 1, j = s.length()/2; i >= 0 and j < s.length(); i--, j++){
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'){
                count_left++;
            }
            if(s[j] == 'a' or s[j] == 'e' or s[j] == 'i' or s[j] == 'o' or s[j] == 'u' or s[j] == 'A' or s[j] == 'E' or s[j] == 'I' or s[j] == 'O' or s[j] == 'U'){
                count_right++;
            }
        }
        return count_left == count_right;
    }
};