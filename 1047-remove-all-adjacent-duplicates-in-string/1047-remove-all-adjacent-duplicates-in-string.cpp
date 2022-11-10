class Solution {
public:
    string removeDuplicates(string s){
        string kow;
        for(int i = 0; i < s.length(); i++){
            if(kow.empty() or kow.back() != s[i]){
                kow.push_back(s[i]);
            }else if(kow.back() == s[i]){
                kow.pop_back();
            }
        }
        return kow;
    }
};