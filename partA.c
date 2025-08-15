#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Box{
int weight,profit;
float ratio;
};
void fractionalKanpsack(int n,struct Box arr[n],int W,float x [n]){
//initialize
int currentweight=0;
for(int i=0;i<n;i++){
x[i]=0;
}
for(int i=0;i<n;i++){
if(arr[i].weight == 0) continue;
if(currentweight + arr[i].weight <=W) {
x[i]=1;
currentweight=currentweight+arr[i].weight;
}else{
x[i]=(float)(W-currentweight) / arr[i].weight;
break;
}
}
}
int compMaxprofit(const void* a, const void* b) {
struct Box *b1 = (struct Box *)a;
struct Box *b2 = (struct Box *)b;
return (b2->profit - b1->profit);
}
int compMinweight(const void* a, const void* b) {
struct Box *b1 = (struct Box *)a;
struct Box *b2 = (struct Box *)b;
return (b1->weight - b2->weight);
}
int compRatio(const void* a, const void* b) {
struct Box *b1 = (struct Box *)a;
struct Box *b2 = (struct Box *)b;
if (b2->ratio > b1->ratio) return 1;
else if (b2->ratio < b1->ratio) return -1;
else return 0;
}
int main(){
int W=850;
int weight[50]={7, 0, 30, 22, 80, 94, 11, 81, 70, 64, 59, 18, 0, 36, 3, 8, 15, 42, 9, 0, 42, 47, 52,
32, 26, 48, 55,
6, 29, 84, 2, 4, 18, 56, 7, 29, 93, 44, 71, 3, 86, 66, 31, 65, 0, 79, 20, 65, 52, 13};
int profit[50]={ 360, 83, 59, 130, 431, 67, 230, 52, 93, 125, 670, 892, 600, 38, 48, 147, 78,
256, 63, 17, 120,
164, 432, 35, 92, 110, 22, 42, 50, 323, 514, 28, 87, 73, 78, 15, 26, 78, 210, 36, 85, 189,
274,
43, 33, 10, 19, 389, 276, 312};
int n=50;
struct Box arr[n], temp[n];
float x[n];
double totalProfit;
clock_t start, end;
double timeTaken;
for (int i=0;i<n;i++) {
arr[i].weight=weight[i];
arr[i].profit=profit[i];
arr[i].ratio=(weight[i] == 0)?0:(float)profit[i]/weight[i];
}
//for Min weight
for (int i=0;i<n;i++){
temp[i] = arr[i];
}
qsort(temp, n, sizeof(struct Box), compMinweight);
start=clock();
fractionalKnapsack(n, temp, W, x);
totalProfit = 0;
for (int i=0;i<n;i++) {
totalProfit+=x[i]*temp[i].profit;
}
end=clock();
timeTaken=(double)(end-start)/CLOCKS_PER_SEC;
printf("Min Weight: Profit = %.2f, Time = %f sec\n", totalProfit, timeTaken);
//for Max Profit
for (int i = 0; i < n; i++){
temp[i] = arr[i];
}
qsort(temp, n, sizeof(struct Box), compMaxprofit);
start=clock();
fractionalKnapsack(n, temp, W, x);
totalProfit = 0;
for (int i=0;i<n;i++) {
totalProfit+=x[i]*temp[i].profit;
}
end = clock();
timeTaken = (double)(end-start)/CLOCKS_PER_SEC;
printf("Max Profit: Profit = %.2f, Time = %f sec\n", totalProfit, timeTaken);
//Max Ratio
for (int i=0;i<n;i++) {
temp[i] = arr[i];
}
qsort(temp, n, sizeof(struct Box), compRatio);
start = clock();
fractionalKnapsack(n, temp, W, x);
totalProfit = 0;
for (int i=0;i<n;i++){
totalProfit += x[i] * temp[i].profit;
}
end = clock();
timeTaken = (double)(end-start)/CLOCKS_PER_SEC;
printf("Max Ratio: Profit = %.2f, Time = %f sec\n", totalProfit, timeTaken);
return 0;
}