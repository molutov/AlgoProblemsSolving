// link: https://leetcode.com/problems/sort-an-array/

class Solution {
public:
    void mergeSort (vector <int> & a, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort (a, l, m);
            mergeSort (a, m + 1, r);
            
            int n1 = m - l + 1, n2 = r - m;
            vector <int> left (n1), right (n2);
            for (int i = 0; i < n1; i++) left[i] = a[l + i];
            for (int i = 0; i < n2; i++) right[i] = a[m + 1 + i];
            int i = 0, j = 0, k = l;
            while (i < n1 && j < n2) {
                if (left[i] <= right[j]) a[k++] = left[i++];
                else a[k++] = right[j++];
            }
            while (i < n1) a[k++] = left[i++];
            while (j < n2) a[k++] = right[j++];
            
        } else return;
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort (nums, 0, (int) nums.size () - 1);
        return nums;
    }
};