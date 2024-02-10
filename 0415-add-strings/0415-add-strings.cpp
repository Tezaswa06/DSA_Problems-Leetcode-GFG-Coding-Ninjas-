#include<bits/stdc++.h>
class Solution {
public:
    string addStrings(string num1, string num2) {
        string str;
        int p1 = num1.size()-1;
        int p2 = num2.size()-1;

        int carry = 0;

        while(p1 >= 0 || p2 >= 0 ){
            int digit1 = (p1>=0) ? num1[p1] - '0' : 0;
            int digit2 = (p2>=0) ? num2[p2] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            
            carry = sum / 10;
            
            str.push_back(sum%10 + '0');
            p1--;
            p2--;
        }
        if(carry > 0){
            str.push_back(carry+'0');
        }
        reverse(str.begin(),str.end());
        return str;
    }
};