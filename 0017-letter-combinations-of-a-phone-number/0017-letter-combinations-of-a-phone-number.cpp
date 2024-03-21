class Solution {
public:
vector<string> digit_strings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string>ways;

    void printPaths(string digits,int index,string output){
        if(index == digits.size()){
            ways.push_back(output);
            return ;
        }

        int digit = digits[index] - '0';

        for(char letter : digit_strings[digit]){
            printPaths(digits , index + 1, output + letter);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return ways;
        }
        printPaths(digits,0,"");
        return ways;
    }
};