class Solution {
public:
    string reverseWords(string s) {
        string str;
        int right = s.size()-1;
        int left = right;
        
        while(right>=0){
            
            // here we are checking from the end
            while(right>=0 && s[right]==' '){
                right--;
            }
            left = right;
            
            // here we are starting from right till we get the full string
            
            while(left>=0 && s[left]!=' '){
                left--;
            }

            // now we will be using space after inserting the string in out new string array
            if(str.size()>0 && left!=right){
                str.push_back(' ');
            }
            
            // now as we know the starting and ending index of out string we will simply append the string it in the new string array
            
            for(int i=left+1;i<=right;i++){
                str.push_back(s[i]);
            }
            right = left;
        }
        return str;
    }
};