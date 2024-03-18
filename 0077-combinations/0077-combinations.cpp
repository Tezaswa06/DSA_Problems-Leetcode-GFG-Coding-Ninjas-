class Solution {
public:

    // Approach 1...........

    // vector<vector<int>>noOfways;

    // void printPaths(int n,int k, vector<int>& output){
    //     if(k == 0){ // positive base case when there is nothing left for selection
    //         noOfways.push_back(output);
    //         return ;
    //     }
    //     if(n == 0 || k > n){ // when no of selection is grater than no of elements and when there is no item to select 
    //         return;
    //     }

    //     output.push_back(n);
    //     printPaths(n - 1,k - 1,output); // yes choice when we select the item
    //     output.pop_back();

    //     printPaths(n - 1,k,output); //  no choice here k will remain same as we have not selected anything

    // }
    // vector<vector<int>> combine(int n, int k) {
    //     vector<int>output; // which will store all the elements in the current path
    //     printPaths(n , k , output);
    //     return noOfways;

    // }
    
    // Approach 2............
    
    vector<vector<int>> ways;
    void printpaths(int n,int k, vector<int>& output,int lastitem){
        if(k == 0){
            ways.push_back(output);
            return ;
        }

        for(int item = lastitem + 1 ; item <= n ; item ++){ // loop for choices which item to choose
            output.push_back(item);
            printpaths(n , k - 1,output , item);
            output.pop_back();

        }
    }
    vector<vector<int>> combine(int n, int k){
        vector<int>output;
        printpaths(n,k,output,0);
        return ways;
    }
    
};