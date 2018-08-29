/*
Input: [4,2,4,0,0,3,0,5,1,0]
Output: [1,3,12,0,0]
*/

void moveZeroes(int* nums, int numsSize) {
    int i = 0;
    int j = 0;

    while (j < numsSize){
        if(nums[j] == 0) {
            j++;
        } else {
            if(i<j) {
                nums[i] = nums[j];
            }
            i++;
            j++;
        }
    }

    while (i < j){
        nums[i] =0;
        i++;
    } 
    
}