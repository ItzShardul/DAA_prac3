#include <stdio.h>
typedef struct {
int start, finish, profit;
char name[4];
} Activity;
void sortByFinishTime(Activity arr[], int n) {
int i, j;
Activity temp;
for(i=0; i<n-1; i++) {
for(j=i+1; j<n; j++) {
if(arr[i].finish > arr[j].finish) {
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
}
}
int main() {
Activity activities[] = {
{1,4,10,"A1"},{3,5,15,"A2"},{0,6,14,"A3"},{5,7,12,"A4"},
{3,9,20,"A5"},{5,9,30,"A6"},{6,10,32,"A7"},{8,11,28,"A8"},
{8,12,30,"A9"},{2,14,40,"A10"},{12,16,45,"A11"}
};
int n = sizeof(activities)/sizeof(activities[0]);
sortByFinishTime(activities, n);
int i, lastFinish = -1, totalProfit = 0;
printf("Selected Activities:\n");
for(i=0; i<n; i++) {
if(activities[i].start >= lastFinish) {
printf("%s: Start=%d, Finish=%d, Profit=%d\n", activities[i].name, activities[i].start,
activities[i].finish, activities[i].profit);
totalProfit += activities[i].profit;
lastFinish = activities[i].finish;
}
}
printf("\nTotal Profit = %d\n", totalProfit);
return 0;
}