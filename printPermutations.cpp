#include <iostream>
#include <string>
using namespace std;

void printPermutations(string input, string output=""){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    
    if(input[0] == '\0'){
        cout<<output<<endl;
        return;
    }
    
    for(int i = 0; i < input.length(); i++){
        string str = input;
        char ch = str[i];
        str[i] = str[0];
        str[0] = ch;
        
        printPermutations(str.substr(1), output+str[0]);
    }
}
