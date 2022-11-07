class Solution {
public:
    int maximum69Number(int num){
        string kow = to_string(num);
        for(int i = 0; i < kow.length(); i++){
            if(kow[i] == '6'){
                kow[i] = '9';
                break;
            }
        }
        int x;
        stringstream ss;
        ss << kow;
        ss >> x;
        return x;
    }
};