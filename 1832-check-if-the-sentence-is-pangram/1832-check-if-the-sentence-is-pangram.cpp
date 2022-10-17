class Solution {
public:
    bool checkIfPangram(string sentence){
        vector<int> kow(27, 0);
        for(int i = 0; i < sentence.length(); i++){
            kow[sentence[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(kow[i] == 0){
                return false;
            }
        }
        return true;
    }
};