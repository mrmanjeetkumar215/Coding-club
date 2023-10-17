
#include <stdio.h>

int main() {
    double a ,b,ans;
    char operator;
    
    printf("Enter the Operator [+,-,*,/]:  ");
    scanf("%c", &operator);
    
    printf("Enter two  numbers : ");
    scanf("%lf %lf", &a, &b);
    
    switch(operator)
    {
    case '+':
    {
        ans = a + b;
        break;
    }
    
    case '-':
    {
        ans = a-b;
        break;
    }
        
    case '*':
    {
        ans = a*b;
        break;
    }
        
    case '/':
    {
        ans = a/b;
        break;
    }
        
    default:
    {
        printf(" Error! Enter Valid Operator \n");
        break;
    }
}

printf("Result : %.4lf", ans);
    return 0;
}
