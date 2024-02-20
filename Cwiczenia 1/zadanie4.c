#include <stdlib.h>
#include <stdio.h>

void foobar();

int main() {
    foobar(200);
    return 0;
}

void foobar(int ile){
    for (int i = 0; i < ile; i++){
        if (i % 35 == 0){
            printf("FooBar\n");
        }
        else if (i % 7 == 0){
            printf("Bar\n");
        }
        else if (i%5 == 0){
            printf("Foo\n");
        }
        else{
            printf("%d\n",i);
        }
    }
}
