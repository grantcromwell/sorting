#include <stdio.h>
#include <unistd.h> 

    void waiting(const char *msg) {
        printf("%s", msg);
        fflush(stdout);
        usleep(500000);
    }




    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    static void dots(void){
    waiting(".");
    waiting(".");
    waiting(".");
    }


    void PrintArray(int array[], int size){
        for (int i = 0; i < size; i++)
            {

                printf("%d ", array[i]);
            }
        printf("\n");
    }



    void bubbleSort(int arraydef[], int size) {
        printf("Bubble Sort commencing\n");
        fflush(stdout);
        dots();
        printf("\n");
        int steps = 0;
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                steps += 1;
                if (arraydef[j] > arraydef[j + 1]) {
                    swap(&arraydef[j], &arraydef[j + 1]);
            
                }
            }
        }
        PrintArray(arraydef, size);
        fflush(stdout);
        printf("Steps taken %d", steps);
        waiting("\nTime Complexity = O(n^2)\n");
    }

    void merge(int arraydef[], int left, int mid, int right, int *steps) {
        int leftSize = mid - left + 1;
        int rightSize = right - mid;
        int leftarrayDef[leftSize];
        int rightarrayDef[rightSize];

        for (int i = 0; i < leftSize; i++) {
            leftarrayDef[i] = arraydef[left + i];
         
        }

        for (int j = 0; j < rightSize; j++) {
            rightarrayDef[j] = arraydef[mid + 1 + j];
        
        }

        int i = 0, j = 0, k = left;

        while (i < leftSize && j < rightSize) {
            if (leftarrayDef[i] <= rightarrayDef[j]) {
                arraydef[k] = leftarrayDef[i];
                i++;
                (*steps) += 1;
            } else {
                arraydef[k] = rightarrayDef[j];
                j++;
                (*steps) += 1;
            }
           
            k++;
        }

        while (i < leftSize) {
            arraydef[k] = leftarrayDef[i];
            i++;
            k++;
            
            
        }

        while (j < rightSize) {
            arraydef[k] = rightarrayDef[j];
            j++;
            k++;
            
            
        }
    
    }

    void mergeSortRecursive(int arrayDef[], int left, int right, int *steps) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;
        mergeSortRecursive(arrayDef, left, mid, steps);
        mergeSortRecursive(arrayDef, mid + 1, right, steps);
        merge(arrayDef, left, mid, right, steps);
    }

    void mergeSort(int arrayDef[], int size) {
        printf("Merge Sort commencing"); 
        fflush(stdout);
        int steps = 0;
        dots();
        printf("\n");
        mergeSortRecursive(arrayDef, 0, size - 1, &steps);
        PrintArray(arrayDef, size);
        fflush(stdout);
        dots();
        printf("\n");
        printf("Steps taken %d", steps);
        printf("\nTime Complexity = O(n log n)\n");
    }

    void greedySort(int arrayDef[], int size) {
        printf("\nGreedy Sort");
        fflush(stdout);
        dots();
        printf("\n");
        int steps = 0;
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                steps += 1;
                if (arrayDef[j] < arrayDef[minIndex]) {
                    minIndex = j;
                    
                }
            }
            if (minIndex != i) {
                swap(&arrayDef[i], &arrayDef[minIndex]);
                
            }
            
        }
        PrintArray(arrayDef, size);
        fflush(stdout);
        dots();
        printf("\nSteps taken %d", steps);
        printf("\nTime Complexity = O(n log n)\n");

    }

    void orignalArray(int size, int choice) {
            int array [5] = {99, 17 , 11, 97, 1};
            for (int nums = 0; nums < size; nums++) {
                printf("%d ", array[nums]);
            }
            printf("\n");

        switch (choice) {
        case 1:
            bubbleSort(array, size);
        break;
        case 2:
            mergeSort(array, size);
        break;
        case 3:
            greedySort(array, size);
        break;
        

      
    }

        
        

    }

        
    

int main(){


    int choice;
    printf("Hello User!");
    fflush(stdout);
    waiting("\n.");
    dots();
    printf("\n");
    orignalArray(5, 99);
    waiting("\n1: Bubblesort");
    waiting("\n2: Merge Sort");
    waiting("\n3: Greedy Sort\n");
    waiting("Choose your favorite algorithm:\n");
    scanf("%d", &choice);
    orignalArray(5, choice);
    



    return 0;
}

