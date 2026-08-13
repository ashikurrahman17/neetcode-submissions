class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<int, int> mp;
        for(int i=0; i<points.size(); i++){
            int d = pow(points[i][0], 2) + pow(points[i][1], 2);
            mp.insert({d, i});
        }
        vector<vector<int>> ans;
        int i=0;
        for(auto u:mp){
            if(i==k) break;
            int v = u.second;
            ans.push_back(points[v]);
            i++;
        }
        return ans;
    }
};
