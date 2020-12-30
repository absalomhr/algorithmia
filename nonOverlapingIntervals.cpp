class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int l = 0, r = 1, deletions = 0;
        sort(intervals.begin(), intervals.end());

        while(r < intervals.size()){
            if(intervals[l][1] <= intervals[r][0]){
                l = r;
                r++;
            } else if (intervals[l][1] <= intervals[r][1]){
                r++;
                deletions++;
            } else if (intervals[l][1] > intervals[r][1]) {
                l = r;
                r++;
                deletions++;
            }
        }
        return deletions;
    }
    
};