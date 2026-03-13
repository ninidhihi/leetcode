class Solution {
public:
    
    bool can(long long time, int h, vector<int>& wt){
        long long total = 0;

        for(long long t : wt){
            long long left = 0, right = h;

            while(left <= right){
                long long mid = (left + right) / 2;

                long long need = t * mid * (mid + 1) / 2;

                if(need <= time){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }

            total += right;
            if(total >= h) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long low = 0;
        long long high = 1LL * workerTimes[0] * mountainHeight * (mountainHeight + 1) / 2;

        for(int t : workerTimes){
            high = max(high, 1LL * t * mountainHeight * (mountainHeight + 1) / 2);
        }

        long long ans = high;

        while(low <= high){
            long long mid = (low + high) / 2;

            if(can(mid, mountainHeight, workerTimes)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};