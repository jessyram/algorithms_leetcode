/* Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of 
the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 
Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        //counters for how often each int appears
        int count_for_0 = 0; 
        int count_for_1 = 0;
        int count_for_2 = 0; 


        for (int i = 0; i < nums.size(); i++) {
            //goes through the array and counts how many times the integers appear
            if (nums[i] == 0) //for ex: if it's 0, increases the 0 counter
            count_for_0++;

            else if (nums[i] == 1) 
            count_for_1++; //if it's 1, it increases the 1 counter

            else count_for_2++; //else, if it's not 0 or 1 (in this case, 2)
        }
        
        //now rewrite the array
    
        int i = 0; //index for array 
       
        //inserts the 0s first
        while (count_for_0--) {
            nums[i++] = 0; //increases the index
        }

        //inserts the 1s
        while (count_for_1--) {
            nums[i++] = 1;
        }

       //inserts the 2s
        while (count_for_2--) {
            nums[i++] = 2;
        }
    }
};
