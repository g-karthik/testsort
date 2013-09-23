#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
int partition(int* arr, int left, int right, int pivotIndex)
{
        int pivotValue = arr[pivotIndex];
        int temp;
        temp = arr[pivotIndex];
        arr[pivotIndex] = arr[right];
        arr[right] = temp;
        int storeIndex = left;
        int i;
        for(i=left;i<right;i++)
        {
                if(arr[i]<pivotValue)
                {
                        temp = arr[i];
                        arr[i] = arr[storeIndex];
                        arr[storeIndex] = temp;
                        storeIndex++;
                }
        }
        temp = arr[storeIndex];
        arr[storeIndex] = arr[right];
        arr[right] = temp;
        return storeIndex;
}
void quick_sort(int* arr, int left, int right)
{
        if(left<right)
        {
                int pivotIndex = left + (int)(right-left)/2;
                int newIndex = partition(arr,left,right,pivotIndex);

                quick_sort(arr, left, newIndex - 1);
                quick_sort(arr,newIndex + 1, right);
        }
}
int main(int argc, char* argv[])
{
        FILE *fp;
        fp = fopen(argv[1], "r");
        int arr[atoi(argv[2])];
        int i=0;
        while(fscanf(fp, "%d", &arr[i])!=EOF)
        {
                i++;
        }

        struct timeval start, end;
        gettimeofday(&start, NULL);

        quick_sort(arr,0,i-1);

        gettimeofday(&end, NULL);
        long seconds = end.tv_sec - start.tv_sec;
        long useconds = end.tv_usec - start.tv_usec;
        long mtime =((seconds)*1000000 + (useconds));


/*      for(i=0;i<atoi(argv[2]);i++)
        {
                printf("%d\t", arr[i]);
        }
*/
        printf("%d", mtime);
        return 0;
}
