
void helper(int input[], int n, int k, int output[]){
    if(n == 0){
        if(k == 0){
            for(int i = 1; i <= output[0]; i++){
                cout<<output[i];
                if(i != output[0])cout<<" ";
            }
            cout<<endl;
            return;
        }
        return;
    }
    
    
    helper(input+1, n-1, k, output);
    output[0]++;
    int c = output[0];
    
    output[c] = input[0];
    
    helper(input+1, n-1, k-input[0], output);
    
    output[0]--;
    
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[1000];
    output[0] = 0;
    
    helper(input, size, k, output);
}
