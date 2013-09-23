#include<stdio.h>
#include<sys/time.h>
void merge(int* A, int low, int high, int mid)
{

        int i,j,k;
        i = low;
        j = mid+1;
        k=0;
        int X[high-low+1];

        while(i<=mid&&j<=high)
        {
                if(A[i]<A[j])
                {
                        X[k] = A[i];
                        i++;
                        k++;
                }
                else
                {
                        X[k] = A[j];
                        j++;
                        k++;
                }
        }
        while(i<=mid)
        {
                X[k] = A[i];
                i++;
                k++;
        }
        while(j<=high)
        {
                X[k] = A[j];
                j++;
                k++;
        }
        for(i=low,j=0;j<(high-low+1);i++,j++)
        {
                A[i] = X[j];
        }
}
long mergesort(int* A, int low, int high)
{
        int mid;

        struct timeval start, end;
        gettimeofday(&start, NULL);

        if(low<high)
        {
                mid=(int)(low+high)/2;
                mergesort(A,low,mid);
                mergesort(A,mid+1,high);
                merge(A,low,high,mid);
        }

        gettimeofday(&end, NULL);

        long seconds = end.tv_sec - start.tv_sec;
        long useconds = end.tv_usec - start.tv_usec;
        long mtime =((seconds)*1000000 + (useconds));

        return mtime;

}
int main(int argc, char* argv[])
{
        FILE* fp;
        fp = fopen(argv[1], "r");
        int arr[atoi(argv[2])];
        int i=0;
        while(fscanf(fp, "%d", &arr[i])!=EOF)
        {
                i++;
        }
        long time = mergesort(arr,0,i-1);
/*      for(i=0;i<atoi(argv[2]);i++)
        {
                printf("%d\t", arr[i]);
        }
*/
        printf("%d", time);
        fclose(fp);
        return 0;
}
