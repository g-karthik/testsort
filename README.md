testsort
========

'testsort' is a custom made Linux command which takes as input:

1) An initial value 'init' using the '-i' option (example: ./testsort -i init)

2) A resolution value 'res' using the '-r' option (example: ./testsort -i init -r res)

3) A final value 'fin' using the '-f' option (example: ./testsort -i init -r res -f fin)

4) An integer 'avg' using the '-a' option (example: ./testsort -i init -r res -f fin -a avg)

5) A filename using the '-o' option (example: ./testsort -i init -r res -f fin -a avg -o outputfile.txt)

6) Sorting routines using the '-s' option (example: ./testsort -i init -r res -f fin -a avg -o outputfile.txt -s heap merge quick bubble)

The sorting routines mentioned in the command may be one, two, three or all four of the mentioned routines in the previous example.

Suppose the user enters the following on the command-line:

./testsort -i 50000 -r 10000 -f 100000 -a 10 -o output.txt -s heap merge quick

The command does the following in response:

1) Generates a file containing 50000 random numbers

2) Sorts the number 10 times using heap, merge and quick sort routines (available as C executables and internally called by 'testsort')

3) Computes the average sorting times required by the different sorting routines

4) Generates a file containing 50000 + 10000 = 60000 random numbers and repeats the previous steps; continues like this till the above procedure is done for a file containing 100000 random numbers

5) Writes the output of all the above runs (i.e., the average sorting times) in the file named 'output.txt'; the write operation is done in a format recognizable by 'gnuplot', a GNU plotting utility

6) Renders using 'gnuplot' the average sorting times required by the sort routines for the different sample sizes (with X-Axis marked from 50000 to 100000 separated by 10000 and Y-Axis marked with time values)

The image is rendered in the file 'output.png'.


A usage manual command for 'testsort':

./testsort -h

The output of './testsort -h' is:

usage: testsort -i init [50000] -r res [10000] -f fin [100000] -a avg [10] -o filename [out.txt] -s heap merge quick bubble [bubble quick] where default values are specified by []


The 'testsort' command was created for the Systems Programming Lab course at IIT Patna and is useful for plotting the increase in running times of different sorting algorithms with an increase in input size.


NOTE: Before trying to run the command, run the following commands:

gcc quicksort.c -o quick

gcc mergesort.c -o merge

gcc heapsort.c -o heap

gcc bubblesort.c -o bubble
