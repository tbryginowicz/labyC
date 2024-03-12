/*
### Silnia

**Cel:** Zdefiniuj nową funkcję o nazwie `factorial()`, k
tóra obliczy czynnik przez rekurencyjne mnożenie (5! = 5 x 4 x 3 x 2 x 1). 
Zauważ, że zgodnie z konwencją, czynnik 0 jest równy 1 (0! = 1).
*/

#include<stdlib.h>
#include<stdio.h>
unsigned long long factorial(unsigned long long k){
    if (k == 0 || k == 1){
        return 1;
    }
    else{
        return k*factorial(k-1);
    }

}

int main(){
    printf("%lld\n",factorial(0));
    printf("%lld\n",factorial(1));
    printf("%lld\n",factorial(5));
    printf("%lld\n",factorial(20)); //Najwieksza na jaka pozwala ull

    return 0;
}