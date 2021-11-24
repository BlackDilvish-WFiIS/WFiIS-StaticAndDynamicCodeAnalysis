#include <stdio.h>

float processing() {
    int i;
    float f = 0.5f;

    for (i=0; i<5; i++) {
        f += (float)i / 2; 
    }

    f *= 3;

    return f;
}

int main() {
    float result; 
    result = processing();
    result += 1;
    return 0;
}