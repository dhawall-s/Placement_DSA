class Solution {
  public:
    int binarysearch(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        int firstIndex = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == k) {
                firstIndex = mid;
                right = mid - 1;
            }
            else if (arr[mid] < k) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }
        
        return firstIndex;
    }
};