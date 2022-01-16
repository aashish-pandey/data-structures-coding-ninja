#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    
    if(input[0] == '\0'){
        output[0] = "";
        return 1;
    }
    
    string mid[1000];
    int sz = returnPermutations(input.substr(1), mid);
    int k = 0;
    
    for(int i = 0; i < sz; i++){
        string str = mid[i];
        string tmp, tmp1;
        
         output[k++] = input[0] + str;
        if(str != "")
         output[k++] = str + input[0];
        int n = str.length();
        for(int j = 1; j < n;j++){
            tmp = str.substr(0, j);
            tmp1 = str.substr(j, n);
            output[k++] = tmp + input[0] + tmp1;
        }
    }
    
    return k;
}
