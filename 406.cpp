class Solution {
public:
    static bool cmp (pair<int, int> a , pair<int, int> b){
        if(a.first == b.first ) return a.second < b.second ;
        return a.first > b.first ;
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ans ;
        ans.clear() ;
        sort(people.begin() , people.end() , cmp) ;
        for(auto i : people)
            ans.insert( ans.begin() + i.second , i) ;
        return ans ;
    }
};
