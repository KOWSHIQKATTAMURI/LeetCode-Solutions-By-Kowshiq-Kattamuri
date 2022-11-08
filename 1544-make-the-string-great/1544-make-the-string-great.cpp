class Solution {
public:
    string makeGood(string s){
        string kow = "";
        for(int i = 0; i < s.length(); i++){
            if(kow.length() == 0){
                kow.push_back(s[i]);
            }
            else{
                if(kow.back() - 32 == s[i] or kow.back() + 32 == s[i])
                    kow.pop_back();
                else{
                    kow.push_back(s[i]);
                }
            }
        }
        return kow;
    }
};