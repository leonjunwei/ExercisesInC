#include <string.h>
#include <stdio.h>


int sum(int a[], int arrayLength){
    int i, sum = 0;
    for (i=0; i<arrayLength; i++) {
        sum = sum + a[i];
    }
    return sum;
}


int getNumber(int intArrayLength, int numLength){ /*intArrayLength is how many ints to store, numLength is how long each int can be*/
    int intArray[intArrayLength];
    char num[numLength+1];
    int index = 0;
    while(scanf("%s", num) != EOF) { /*I have no idea what this means, but Emily said it'd work*/
        if(index<intArrayLength) {
            intArray[index] = atoi(num);
            index++; 
        } else {
            printf("Too many numbers!\n");
            return 0;
        }
    }

    printf("%d\n", sum(intArray, intArrayLength));
    return 0;
}


int main(){
    getNumber(10,10);
}