#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
void swap(int* x, int* y)
{
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
}
long BubbleSort(int A[], int N)
{
        int swapped,i;
        struct timeval start, end;
        gettimeofday(&start, NULL);
        do
        {       swapped = 0;
                for(i=1;i<N;i++)
                {
                        if(A[i-1]>A[i])
                        {       swap(&A[i-1], &A[i]);
                                swapped = 1;
                        }
                }
                N--;
        }while(swapped);
        gettimeofday(&end, NULL);

        long seconds = end.tv_sec - start.tv_sec;
        long useconds = end.tv_usec - start.tv_usec;
        long mtime =((seconds)*1000000 + (useconds));

        return mtime;
}
int main(int argc, char* argv[])                //Pass the input file and the no. of numbers in the input file
{
        FILE *fp;
        int i=0,j;
        int arr[atoi(argv[2])];
        fp = fopen(argv[1],"r");
        if(fp==NULL)
        {
                printf("Error Opening File! Exiting...");
                exit(1);
        }
        while(fscanf(fp, "%d", &arr[i])!=EOF)
        {
                i++;
        }

        long time = BubbleSort(arr,i);

/*      for(j=0;j<i;j++)
        {
                printf("%d\t", arr[j]);
        }
        printf("\n");
*/
        fclose(fp);
        printf("%d", time);
        return 0;
}
