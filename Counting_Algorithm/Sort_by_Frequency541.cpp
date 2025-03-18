class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> frequent;
        int maxVal = 0;
        for(char x : s){
            frequent[x]++;
            maxVal = max(maxVal, frequent[x]);
        }
        vector<vector<char>> bucket(maxVal + 1); 
        for(const auto& [ch, fre] : frequent){
            bucket[fre].push_back(ch);
        }

        string result;
        for(int i = maxVal ; i > 0; i--){
            for(char x : bucket[i]){
                result.append(i,x);
            }
        }

        return result;

    }
};
