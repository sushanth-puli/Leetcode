class Solution {
    public int[] sortArray(int[] nums) {
         mergeSort(nums,0,nums.length-1);
         return nums;
    }


    public static void mergeSort(int arr[], int s, int e) {

        if (s >= e) {
            return;
        }
        int mid = s + (e - s) / 2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);
        merge(arr, s, e, mid);

    }

    public static void merge(int arr[], int si, int ei, int mid) {
        int temp[] = new int[ei - si + 1];
        int i = si;
        int j = mid+1;
        int k = 0;

        while (i <= mid && j <= ei) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= ei) {
            temp[k++] = arr[j++];
        }   

        for (k =0, i =si; k < temp.length; k++, i++) {
            arr[i] = temp[k];
        }
    }

}