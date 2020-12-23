class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int maxOnes = 0, currentOnes = 0, i = 0, j = 0, flips = K;
        
        while(i < A.size()){
            if(A[i] == 1){
                currentOnes++;
                i++;
            } else if (A[i] == 0){
                if(flips > 0){
                    currentOnes++;
                    i++;
                    flips--;
                } else {
                    maxOnes = max(maxOnes, currentOnes);
                    while(A[j] == 1){
                        currentOnes--;
                        j++;
                    }
                    currentOnes--;
                    flips++;
                    j++;
                }
            }
            
        }
        return max(maxOnes, currentOnes);
    }
};