class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> ans = {-1, -1};

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int position = 1;

        int firstCritical = -1;
        int lastCritical = -1;

        int minDistance = INT_MAX;
        int maxDistance = -1;

        while (curr->next != nullptr) {

            int prevVal = prev->val;
            int currVal = curr->val;
            int nextVal = curr->next->val;

            // Check if current node is a critical point
            if ((currVal > prevVal && currVal > nextVal) ||
                (currVal < prevVal && currVal < nextVal)) {

                // First critical point
                if (firstCritical == -1) {
                    firstCritical = position;
                }
                else {
                    // Distance from previous critical point
                    int distance = position - lastCritical;

                    minDistance = min(minDistance, distance);
                }

                // Update last critical point
                lastCritical = position;

                // Maximum distance
                maxDistance = position - firstCritical;
            }

            prev = curr;
            curr = curr->next;
            position++;
        }

        if (firstCritical == -1 || firstCritical == lastCritical)
            return ans;

        ans[0] = minDistance;
        ans[1] = maxDistance;

        return ans;
    }
};