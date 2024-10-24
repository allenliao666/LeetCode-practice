#include <limits.h>
int minGroups(int** intervals, int intervalsSize, int* intervalsColSize) {
    *intervalsColSize = 2;
    int minStart = INT_MAX, maxEnd = INT_MIN, group = 0, maxGroup = 0;

    //traverse input array, find the minStart and maxEnd
    for(int i = 0; i < intervalsSize; i++){
        if(minStart > intervals[i][0]) minStart = intervals[i][0];
        if(maxEnd < intervals[i][1]) maxEnd = intervals[i][1];
    }

    //allocate heap to store array
    int *res = (int *) calloc(maxEnd + 2,sizeof(int));

    //set 1 at each start and set -1 at next element of end
    for(int i = 0; i < intervalsSize; i++){
        res[intervals[i][0]]++;
        res[intervals[i][1] + 1]--;
    }

    //calculate the total value, which means the minimum group needed. Ex: [[1,5][2,3]] -> [1,1,0,-1,0,-1] so group needed is 2
    for(int i = minStart; i < maxEnd + 1; i++){
        group += res[i];
        if(maxGroup < group) maxGroup = group;
    }

    free(res);
    return maxGroup;
}
