class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int st = 0;
        int end = numbers.size()-1;

        while(st<end){

            if(numbers[st]+numbers[end] < target){
                st++;
            }else if(numbers[st]+numbers[end] > target){
                end--;
            }else{
                return {st+1,end+1};
            }

        }

        return {};
    }
};