// Problem Link: https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1#

int evaluatePostfix(char* exp)
{
    int n = strlen(exp);
    struct Stack* st = createStack(n);
    int vs[2];

    for(int i=0;i<n;i++){
        if(exp[i]!='*' && exp[i]!= '/' && exp[i] != '+' && exp[i]!= '-'){
            push(st,exp[i]-'0');
        }else{
            vs[1] = pop(st);
            vs[0] = pop(st);
            if(exp[i]=='*'){
                push(st,vs[0]*vs[1]);
            }else if(exp[i]=='/') push(st,vs[0]/vs[1]);
            else if(exp[i]=='+') push(st,vs[0]+vs[1]);
            else if(exp[i]=='-') push(st,vs[0]-vs[1]);
            else return -1;
        }
    }

    return pop(st);
}
