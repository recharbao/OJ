/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 


 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int begin = 0;
        int end = mountainArr.length() - 1;
        int mid = 0;
        int peak = 0;
        while(begin < end){
            mid = begin + (end - begin + 1) / 2;
            int leftValue = mountainArr.get(mid - 1);
            int midValue = mountainArr.get(mid);
    
            if((leftValue < midValue && midValue < mountainArr.get(mid + 1)) || leftValue < midValue && midValue > mountainArr.get(mid + 1)){
                begin = mid;
            }else if((mid == mountainArr.length() - 1) || (leftValue > midValue && midValue > mountainArr.get(mid + 1))){
                end = mid - 1;
            }
        }
        begin = 0;
        peak = end;
       
        while(begin < end){
            mid = begin + (end - begin + 1) / 2;
            int midValue = mountainArr.get(mid);
            if(midValue <= target){
                begin = mid;
            }else if(midValue > target){
                end = mid - 1;
            }
        }
        if(mountainArr.get(begin) == target){
            return begin;
        }

        begin = peak;
        end = mountainArr.length() - 1;
        while(begin < end){
            mid = begin + (end - begin + 1) / 2;
            int midValue = mountainArr.get(mid);
            if(midValue >= target){
                begin = mid;
            }else if(midValue < target){
                end = mid - 1;
            }
        }
        if(mountainArr.get(begin) == target){
            return begin;
        }
        return -1;
    }
}