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
    
    int n = input.length();
    int k = 0;
    for(int i = 0; i < n; i++){
        string str = input;
        char ch = str[i];
        str[i] = str[0];
        str[0] = ch;
        
        string mid[1000];
        int sz = returnPermutations(str.substr(1), mid);
        
        for(int j = 0; j < sz; j++){
            output[k++] = str[0] + mid[j];
        }
    }
    
    return k;
}
