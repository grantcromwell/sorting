#include <stdio.h>
#include <unistd.h> 

    void waiting(const char *msg) {
        printf("%s", msg);
        fflush(stdout);
        usleep(500000);
    };

    void arraydef(int size) {
            int array [5] = {10, 20 , 40, 50, 70};
            for (int nums = 0; nums < size; nums++) {
                printf("%d ", array[nums]);
            }


    }


int main(){


    int choice;
    printf("Hello User!");
    fflush(stdout);
    waiting("\n.");
    waiting(".");
    waiting(".");
    printf("\n");
    arraydef(5);
    waiting("\nChoose your favorite algorithm");
    waiting("\n1: Bubblesort");
    waiting("\n2: Merge Sort");
    waiting("\n3: Greedy Sort");
    printf("\nChoose your favorite algorithm\n");
    fflush(stdout);
    scanf("%d", &choice);




    return 0;
}

