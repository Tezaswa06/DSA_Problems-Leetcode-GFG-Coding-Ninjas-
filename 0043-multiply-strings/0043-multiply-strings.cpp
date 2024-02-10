class Solution {
public:
    string addingbigstring(string num1,string num2){
        string addstr;
        int p1 = num1.size()-1;
        int p2 = num2.size()-1;
        int carry = 0;

        while(p1 >= 0 || p2 >= 0){
            int digit1 = (p1>=0) ? num1[p1] - '0' : 0;
            int digit2 = (p2>=0) ? num2[p2] - '0' : 0;
            int sum = digit1 + digit2 + carry;

            carry = sum / 10;
            addstr.push_back(sum % 10 + '0');
            p1--;
            p2--;
        }
        if(carry > 0){
            addstr.push_back(carry + '0');
        }
        reverse(addstr.begin(),addstr.end());
        return addstr;
    }
    string multiplyingstring(string num1,int d2){
        string multstr;
        int p1 = num1.size()-1;
        int carry = 0;
        while(p1 >= 0){
            int digit1 = (p1>=0) ? num1[p1] - '0' : 0;
            int product = digit1 * d2 + carry;
            
            carry = product / 10;
            multstr.push_back(product%10 + '0');
            p1--;
        }
        if(carry>0){
            multstr.push_back(carry + '0');
        }
        reverse(multstr.begin(),multstr.end());
        return multstr;
    }
    string multiply(string num1, string num2) {
        string str;
        int count = 0;

        for(int i=num2.size()-1;i>=0;i--){
            int d2 = num2[i] - '0';
            string temp = multiplyingstring(num1,d2);
            for(int c=0;c<count;c++){
                temp = temp + '0';
            }
            str = addingbigstring(str,temp);
            count++;

        }
        if(str[0]== '0'){
            return "0";
        }
        return str;

    }
};