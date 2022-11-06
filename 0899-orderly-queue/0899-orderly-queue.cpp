class Solution {
public:
    string orderlyQueue(string s, int k){
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        string kow = s + s, x = s;
        for(int i = 0; i < s.length(); i++){
            string present = kow.substr(i, s.length());
            if(present < x){
                x = present;
            }
        }
        return x;
    }
};