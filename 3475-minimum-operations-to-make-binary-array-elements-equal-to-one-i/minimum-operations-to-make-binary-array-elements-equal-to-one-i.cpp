class Solution {
public:
    int minOperations(vector<int>& nums) {
         int n = nums.size();
int k=3;
        int flips = 0;
        
        int flipCountFromPastForCurri = 0;

        for(int i = 0; i < n; i++) {

            if(i >= k && nums[i-k] == 2) { //Was it flipped
                flipCountFromPastForCurri--;
            }
            
            if(flipCountFromPastForCurri % 2 == nums[i]) {
                if(i+k > n){
                    return -1;
                }
                flipCountFromPastForCurri++;
                nums[i] = 2; //Marking as flipped
                flips++;
            }
        }

        return flips;

    }
};