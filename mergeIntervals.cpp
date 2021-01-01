class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int index = 0, r = 1, l_tail = intervals[0][0], l_head = intervals[0][1];
        vector<vector<int>> overlapping_inter;
        
        overlapping_inter.push_back({l_tail,  l_head});
        
        while(r < intervals.size()){
            if(intervals[r][0] <= overlapping_inter[index][1]){
                if(intervals[r][1] > overlapping_inter[index][1])
                    overlapping_inter[index][1] = intervals[r][1];
                r++;
            } else {
                overlapping_inter.push_back({intervals[r][0],  intervals[r][1]});
                index++;
                r++;
            }
        }
        return overlapping_inter;
    }
};