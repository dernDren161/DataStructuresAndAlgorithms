// Functional Program

// Problem Link: https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1/?track=amazon-strings&batchId=192

int call(char a){

    switch(a){
        case 'I':
        return 1;

        case 'V':
        return 5;

        case 'X':
        return 10;

        case 'L':
        return 50;

        case 'C':
        return 100;

        case 'D':
        return 500;

        case 'M':
        return 1000;
    }
}

int romanToDecimal(string &str) {

    int num = str.size();
    int res = 0;
    for(int i=0;i<num;i++){

        // This is a very good trick;
        if(i+1 < num){ /// till excluding the last element
            if(call(str[i]) >= call(str[i+1])){
                res = res + call(str[i]);
            }else{
                res = res + call(str[i+1]) - call(str[i]);
                i++;  // extra addition
            }
        }else{  // This condition is for the single digit numbers
            res = res + call(str[i]);
        }
    }
    return res;
}
