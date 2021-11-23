#include <stdio.h>

int main(void){

    // This should not throw typing errors
    int i = 4;
    double d = 2.3;
    char c = 'c';

    // This should
    integer i = 4;
    dobul d = 2.3;
    chara c = 'c';
    
    // This should not throw missing semicolons errors
    for(int k = 0; k<i; k++){
        d++;
        c++;
        printf("%.2f %c\n", d, c);
    }

    // This should
    for(int k = 0; k<i; k++){
        d++
        c++;
        printf("%.2f %c\n", d, c)
    }

    // This should not throw missing brackets error
    int arr[10];
    while(i){
        arr[i] = 0;
    }

    // This should
    int arr[10;
    while i) {
        arr[i] = 0;
    
    return 0;
}