#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<sys/time.h>
int* heap,heapSize;
void Initialize()
{
        heapSize = 0;
        heap = malloc(sizeof(int));
        heap[0] = INT_MIN;
}
void Insert(int element)
{
        heapSize++;
        heap = realloc(heap, (heapSize+1)*sizeof(int));
        heap[heapSize] = element;
        //Adjustment
        int current = heapSize;
        while(heap[current/2] > element)
        {
                heap[current] = heap[current/2];
                current = current/2;
        }
        heap[current] = element;
}
//int DeleteMin()
void DeleteMin()
{
    int minElement, lastElement, child, curIndex;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    for(curIndex=1;curIndex*2<=heapSize;curIndex=child)
    {
          child = curIndex*2;
          if(child!=heapSize&&heap[child+1]<heap[child])
          {
               child++;
          }
          if(lastElement>heap[child])
          {
               heap[curIndex]=heap[child];
          }
          else
          {
               break;
          }
    }
    heap[curIndex] = lastElement;

//    return minElement;

}
int main(int argc, char* argv[])
{
        FILE *fp;
        fp = fopen(argv[1], "r");
        int iter, element;
        Initialize();
        for(iter = 0;iter < atoi(argv[2]);iter++)
        {
                fscanf(fp, "%d", &element);
                Insert(element);
        }

        struct timeval start, end;
        gettimeofday(&start, NULL);

        for(iter = 0;iter < atoi(argv[2]);iter++)
        {
              //  printf("%d\t",DeleteMin());
                DeleteMin();
        }

        gettimeofday(&end, NULL);

        long seconds = end.tv_sec - start.tv_sec;
        long useconds = end.tv_usec - start.tv_usec;
        long mtime =((seconds)*1000000 + (useconds));

         printf("%d", mtime);
        return 0;
}
