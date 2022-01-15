/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    
    if(n == 0){
        if(k == 0){
            output[0][0] = 0;
            return 1;
        }
        return 0;
    }
    
    int sou1[1000][50], sou2[1000][50];
    int s1 = subsetSumToK(input+1, n-1, sou1, k);
    int s2 = subsetSumToK(input+1, n-1, sou2, k-input[0]);
    
    int row = 0;
    
    for(int i = 0; i < s1; i++){
        for(int j = 0; j <= sou1[i][0]; j++){
            output[row][j] = sou1[i][j];
        }
        row++;
    }
    
    for(int i = 0; i < s2; i++){
        int col = sou2[i][0] + 1;
        output[row][0] = col;
        output[row][1] = input[0];
        
        for(int j = 2; j <= col; j++)
            output[row][j] = sou2[i][j-1];
        row++;
    }
    
    return s1+s2;

}
