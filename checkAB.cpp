bool checkAB(char input[]) {
	// Write your code here
    if(*input == '\0')return true;
    
    if(*input == 'a'){
        if(*(input+1) == 'a' || *(input+1) == '\0')return checkAB(input+1);
        
        else if(*(input+1) == 'b' && *(input+2) == 'b')
        {
            if(*(input+3) == '\0')return true;
            else
            return checkAB(input+3);
        }
        
    }else
        return false;
    
    

}



