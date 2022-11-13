class Solution {
public:
    string reverseWords(string s){
        stack<string> kow;
        stringstream ss(s);
        string word, x;
        while(ss >> word){
            kow.push(word);
        }
        while(!kow.empty()){
            x = x + kow.top();
            kow.pop();
            x = x + " ";
        }
        x.pop_back();
        return x;
    }
};