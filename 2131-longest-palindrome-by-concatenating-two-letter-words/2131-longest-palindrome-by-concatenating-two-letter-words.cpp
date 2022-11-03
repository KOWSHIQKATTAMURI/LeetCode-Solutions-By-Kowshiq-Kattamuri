class Solution {
public:
    int longestPalindrome(vector<string>& words){
        if(words.size() == 0){
            return 0;
        }
        int ans = 0;
        vector<vector<int>> kow(26, (vector<int>(26, 0)));
        for(string s : words){
            int a = s[0] - 'a', b = s[1] - 'a';
            if(kow[b][a]){
                ans += 4;
                kow[b][a]--;
            }else{
                kow[a][b]++;
            }
        }
        for(int i = 0; i < 26; i++){
            if(kow[i][i]){
                ans += 2;
                break;
            }
        }
        return ans;
    }
};