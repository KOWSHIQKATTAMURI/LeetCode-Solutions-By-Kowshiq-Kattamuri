class Solution {
public:
    bool closeStrings(string word1, string word2){
        if(word1.length() != word2.length()){
            return false;
        }
        vector<int> first(26, 0), second(26, 0);
        bitset<26> b1, b2;
        for(int i = 0; i < word1.length(); i++){
            first[word1[i] - 'a']++;
            b1[word1[i] - 'a'] = true;
            second[word2[i] - 'a']++;
            b2[word2[i] - 'a'] = true;
        }
        if(b1 != b2){
            return false;
        }
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        return first == second;
    }
};