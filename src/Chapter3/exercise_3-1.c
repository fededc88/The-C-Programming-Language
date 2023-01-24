/*
 * Exercise 3-1: Our binary search makes two tests inside the loop, when one
 * would sufice (at the price o more tests outside). Write a version with only
 * one test inside the loop and measure the difference in run-time.
 *   
 * Writen by Federico D. Ceccarelli (fededc88@gmail.com), any kind of
 * submissions are welcome. 
 */
  
#include <stdio.h>
#include <time.h>

#define VLEN 26

int binsearch(int x, int v[], int n);
int onetestbinsearch(int x, int v[], int n);

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid-1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1; /* no march */
}

/* onetestbinsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int onetestbinsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low < high)
    {
        mid = (low+high) / 2;
        if (x <= v[mid])
            high = mid;
        else 
            low = mid+1;
    }

    return v[low] == x ? low : (-1);

}


int main(void)
{
    int v[VLEN] = { 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108,
        109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

	char c;
    int x;

    int result;
    float startTime;
    float stopTime;

    /*
     * Shortcut to access EOF:
     *     Windows: CTRL+Z
     *     Unix like systems: CTRL+D.
     */
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            continue;

        startTime = (float)clock()/CLOCKS_PER_SEC;
        result = binsearch(c, v, VLEN);
        stopTime = (float)clock()/CLOCKS_PER_SEC;

        printf("binsearch:%d time: %g   ", result, stopTime-startTime);

        startTime = (float)clock()/CLOCKS_PER_SEC;
        result = onetestbinsearch(c, v, VLEN);
        stopTime = (float)clock()/CLOCKS_PER_SEC;

        printf("onetestbinserch:%d time: %g\n", result, stopTime-startTime);
    }

	return 0;
}

// 
// End of file.
//
