class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> tmp = nums;
        tmp.insert(tmp.begin(), nums.begin(), nums.end());
        return tmp;
    }
};