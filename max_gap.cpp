/*Given an integer array nums, return the maximum difference between two successive elements in its sorted form. 
If the array contains fewer than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
 
Constraints:
1 <= nums.length <= 105
0 <= nums[i] <= 109*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        //If less than 2 elements, no gap exists
        if (n < 2) return 0;

        //Find the minimum and maximum values
        int minVal = nums[0], maxVal = nums[0];
        for (int num: nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }

        //If all numbers are the same, then gap is 0
        if (minVal == maxVal) return 0;

        // Find bucket size
        // If numbers were evenly spaced, this would be the gap
        int bucketSize = (maxVal - minVal) / (n - 1);

        // Avoid bucket size being 0 (happens when numbers are close)
        if (bucketSize == 0) bucketSize = 1;

        //Compute number of buckets needed
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        // Create buckets
        // Each bucket stores ONLY: minimum value in that bucket, maximum value in that bucket, whether the bucket is used

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> used(bucketCount, false);

        //Place each number into its bucket
        for (int num : nums) {
            int idx = (num - minVal) / bucketSize; // find bucket index

            //Update bucket's min and max
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
            used[idx] = true;
        }

        // Compute the maximum gap
        int maxGap = 0;
        int prevMax = minVal;  //Max of previous non-empty bucket

        for (int i = 0; i < bucketCount; i++) {

            //Skip empty buckets
            if (!used[i]) continue;

            // Max gap will be between buckets, not inside one
            // So we compare: current bucket's min - previous bucket's max
            maxGap = max(maxGap, bucketMin[i] - prevMax);

            //Update previous max
            prevMax = bucketMax[i];
        }

        return maxGap;
    }
};
