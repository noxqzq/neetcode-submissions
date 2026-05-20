class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        int left = 1, right = x;
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Use division to avoid overflow: mid*mid <= x becomes mid <= x/mid
            if (mid <= x / mid) {
                result = mid;  // mid could be the answer
                left = mid + 1;  // search for larger values
            } else {
                right = mid - 1;  // mid is too large
            }
        }
        
        return result;
    }
};
