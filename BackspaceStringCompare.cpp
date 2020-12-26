class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1, skipS = 0, skipT = 0;
        while(true){
            // Getting S ready for comparison
            if(i >= 0){
                while(S[i] == '#'){
                    skipS++;
                    i--;
                    while(skipS > 0  && i >= 0){
                        if(S[i] == '#'){
                            skipS++;
                            i--;
                        } else {
                            i--;
                            skipS--;
                        }
                        if(i < 0)
                            break;
                    }
                    if(i < 0)
                        break;
                }
            }

            // Getting T ready for comparison
            if(j >= 0){
                while(T[j] == '#'){
                    skipT++;
                    j--;
                    while(skipT > 0 && j >= 0){
                        if(T[j] == '#'){
                            skipT++;
                            j--;
                        } else {
                            j--;
                            skipT--;
                        }
                        if(j < 0)
                            break;
                    }
                    if(j < 0)
                        break;
                }
            }

            if(i < 0 && j < 0){
                break;
            }          
            if(i < 0){
                return false;
            }else if(j < 0){
                return false;
            }
            
            if (S[i] != T[j]){
                return false;
            }
            
            i--; j--;
        }
        return true;
    }
};