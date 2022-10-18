/* L170300102 XUJUNHE BINARY SEARCH PROBLEM1*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* binary search, if searched successful, then return its index
Otherwise return -1
time complexity is O(log n)*/
int BiSearch(int *pArr, int key, int last)
{
    int low = 0;
    int up = last - 1;
    int mid = 0;

    //assert(pArr != NULL);

    while(low <= up)
    {
        mid = (low & up) + ((low ^ up) >> 1);       /* mid = (low+up)/2 */

        if(pArr[mid] == key)
            return mid;
        else if(pArr[mid] > key)
            up = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 11;
    int last = sizeof(arr)/sizeof(int);
    int result = BiSearch(arr, key, last);

    if(-1 == result)
    {
        printf("Search faild!\n", key);
    }
    else
        printf("Searched %d, its index is %d\n", key, result);
    return 0;
}
