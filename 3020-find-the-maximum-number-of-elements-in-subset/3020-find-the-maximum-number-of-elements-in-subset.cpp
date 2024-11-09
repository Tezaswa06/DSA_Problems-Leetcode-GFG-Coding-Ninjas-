// in this question we have to return the size of subset array which satisfies [2,4,2]
// now there are some cases what will be the ans for this arr [2,2,4,4,4,4,16,16] the ans will be [2,4,16,4,2]
// which will cover all the base cases
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int,int>freq;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }

        int ans = 0;// if no elements follow the order of array then min we have to return is 1

        if(freq[1] % 2 == 1){// this is the case for the no of 1's in the arr that is [1,1,1,1,1]
            ans = freq[1];
        }
        else{
            ans = freq[1]-1;
        }

        for(int i=2; i*i<=1e9; i++){
            long long num = i;
            int count = 0;
            while(num <= 1e9){
                if(freq.find(num) == freq.end()){// means the no is not present
                    break;
                }
                if(freq[num] >= 2){
                    count += 2;// if the freq is equals to 2 then we will increase the count by 2
                    num = num * num;// and then we will check for the new no will will be the square of the previyous one
                }
                else{
                    count++;// if the digit has freq = 1 then it is the middle elem
                    break;
                }
            }
            if(freq.find(num) == freq.end()){
                count--;//if no is not present then we will make the previyous element as middle and decrease the count by 1
            }
            ans = max(ans,count);
        }
        return ans;
    }
};