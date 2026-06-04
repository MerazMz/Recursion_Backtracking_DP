class Solution {
public:
    int count = 0;
    void findPeakValley(int n){
        string temp = to_string(n);
        for(int i=1;i<temp.size()-1;i++){
            if(temp[i]>temp[i-1] and temp[i]>temp[i+1]){
                count++;
            }
            if(temp[i]<temp[i-1] and temp[i]<temp[i+1]){
                count++;
            }
        }

    }
    int totalWaviness(int num1, int num2) {
        for(int i=num1;i<=num2;i++){
            findPeakValley(i);
        }
        return count;
    }
};