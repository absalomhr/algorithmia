class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, char> seenMap;
        int head = 0, tail = 0, maxSub = 0, currSub = 0;
        while(head < s.size()){          
            if(seenMap.find(s[head]) == seenMap.end()){
                seenMap[s[head]] = 1;
                currSub++;
                head++;
            } else{
                if(seenMap[s[head]] == 0){
                    seenMap[s[head]] = 1;
                    currSub++;
                    head++;
                } else{
                    maxSub = max(maxSub, currSub);
                    while(true){
                        currSub--;
                        seenMap[s[tail]] = 0;
                        if(s[tail] == s[head]){
                            tail++;
                            break;
                        }
                        tail++;
                    }
                }
            }
        }
        return max(maxSub, currSub);
    }
};