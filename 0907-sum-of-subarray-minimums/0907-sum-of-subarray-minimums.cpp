class Solution {
public:
    int sumSubarrayMins(vector<int>& arr){
        int mod = 1e9 + 7;
        int ans = 0;
        stack<pair<int, int>> x;
        vector<int> kow(arr.size(), 0);
        for(int i = 0; i < arr.size(); i++){
            while(!x.empty() && x.top().first >= arr[i]){
                x.pop();
            }
            if(x.empty()){
                kow[i] = (arr[i] * (i + 1))%mod;
            } 
            else{
                kow[i] = ((arr[i] * (i - x.top().second))%mod + kow[x.top().second])%mod;
            }
            x.push(pair(arr[i], i));
		}
        for(auto i : kow){
            ans = (ans + i)%mod;
        }
        return ans;
    }
};