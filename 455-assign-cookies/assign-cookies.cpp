#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        // Sort the children's greed factors and the cookies' sizes.
        // This is the key step for the greedy approach to work.
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int contentChildren = 0;
        int cookieIndex = 0;
        int childIndex = 0;

        // Iterate through both sorted arrays.
        while (childIndex < g.size() && cookieIndex < s.size()) {
            // If the current cookie can satisfy the current child,
            // assign it and move on to the next child and cookie.
            if (s[cookieIndex] >= g[childIndex]) {
                contentChildren++;
                childIndex++;
                cookieIndex++;
            } else {
                // If the current cookie is too small, it can't satisfy
                // the current or any subsequent child (since they have
                // higher or equal greed factors). So, we move to the next cookie.
                cookieIndex++;
            }
        }

        return contentChildren;
    }
};