// package Learn;

// class Solution {
//     public int findDuplicate(int[] nums) {
//         int tp = nums.length - 1;
//         nums[tp] = -nums[tp];
//         while (nums[tp] < 0) {
//             System.out.println(nums[tp]);
//             tp = -nums[tp] - 1;
//             nums[tp] = -nums[tp];
//         }
//         for (int i = 0; i < nums.length; i++) if (nums[i] < 0) nums[i] = -nums[i];
//         return tp + 1;
//     }
// }