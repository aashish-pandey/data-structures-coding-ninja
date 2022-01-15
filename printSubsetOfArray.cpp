void helper(int input[], int n, int output[]){
    if(n <= 0){
        int sz = output[0];
        for(int i = 1; i <= sz; i++)
            cout<<output[i]<<" ";
        cout<<endl;
        return;
    }
    
    output[0]++;
    int c = output[0];
    output[c] = input[0];
    helper(input+1, n-1, output);
    
    output[0]--;
    helper(input+1, n-1, output);
    
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    
    int output[size];
    output[0] = 0;
    helper(input, size, output);
    
}
