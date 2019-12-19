#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include <stdbool.h>
using namespace std;
#define MAX 100
enum boolean{FALSE,TRUE};
int getTotal(int array[],int no){
    int sum=0;
    for(int i=0;i<no;i++)
        sum+=array[i];
    return sum;
}
void arrayCopy(int start,int end,int array1[],int start1,int array2[]){
    for(int i=start,j=start1;i<end;i++,j++){
        array2[j]=array1[i];
    }
}
boolean checkValue(int arr[],int no){
    for(int i=0;i<no;i++)
        if(arr[i]!=0)
            return FALSE;
    return TRUE;
}
int main()
{
    int m,n;
    int stocknumber[MAX];
    int numofdelivered[MAX];
    int cost[MAX][MAX]={0};
    int sum = 0;
    int temp_demand[MAX]={0};
    int temp_source[MAX]={0};
    int sum_of_source,sum_of_delivered;
    int allocation[MAX][MAX]={0};
    int no_of_allocation=0;
    
    cout<<"Number of rows and columns:";
    cin>>m>>n;
    
    cout<<"Enter stock number:";
    for(int i=0;i<m;i++)
    {
        cin>>stocknumber[i];
    }
    cout<<"Enter number of products to be delivered:";
    for(int i=0;i<n;i++)
    {
        cin>>numofdelivered[i];
    }
    
    cout<<"Enter cost:";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>cost[i][j];
        }
    }
    cout<<"\nMatrix\n"<<"\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<cost[i][j]<<"\t";
            cout<<stocknumber[i]<<"\t";
            cout<<endl;
    }
    for(int j=0;j<n;j++)
        cout<<numofdelivered[j]<<"\t";
    
//
//
//    for(int i=0,j=0;(i<m&&j<n);)
//    {
//        if (stocknumber[i]<numofdelivered[j])
//        {
//        sum+=cost[i][j]*stocknumber[i];
//        numofdelivered[j]-=stocknumber[i];
//        i++;
//        }
//        else
//            if(stocknumber[i]>numofdelivered[j])
//            { sum+=cost[i][j]*numofdelivered[j];
//                stocknumber[i]-=numofdelivered[j];
//                j++;
//            }
//            else
//                if(stocknumber[i]==numofdelivered[j])
//            {
//                        sum+=cost[i][j]*numofdelivered[j];
//                        i++;
//                        j++;
//                }
//}
//
//cout<<"\n\nMinimum transportation cost:"<<sum;

int i=0,j=0;
int k=0;
sum_of_source=getTotal(stocknumber,m);
sum_of_delivered=getTotal(numofdelivered,n);
if(sum_of_source!=sum_of_delivered){
    if(sum_of_source>sum_of_delivered){
        for(j=0;j<m;j++)
            cost[j][n]=0;
        numofdelivered[m]=sum_of_source-sum_of_delivered;
        n++;
    }
    else{
        for(j=0;j<n;j++)
            cost[m][j]=0;
        stocknumber[m]=sum_of_delivered-sum_of_source;
        n++;
    }
}
i=j=0;
arrayCopy(0,m,stocknumber,0,temp_source);
arrayCopy(0,n,numofdelivered,0,temp_demand);
while(!checkValue(temp_source,m) || !checkValue(temp_demand,n)){
    if(temp_source[i]>temp_demand[j]){
        allocation[i][j]=temp_demand[j];
        temp_source[i]-=temp_demand[j];
        temp_demand[j]=0;
        j++;
    }
    else if(temp_source[i]<temp_demand[j]){
        allocation[i][j]=temp_source[i];
        temp_demand[j]-=temp_source[i];
        temp_source[i]=0;
        i++;
    }
    else{
        allocation[i][j]=temp_source[i];
        temp_source[i]=temp_demand[j]=0;
        i++;
        j++;
    }
    no_of_allocation++;
}
    cout<<"\n\n after allocation :\n";
     for(i=0;i<m;i++){
         for(int j=0;j<n;j++){
             if(allocation[i][j]!=0)
                 cout<<"\t"<<cost[i][j]<<"*"<<allocation[i][j];
             else
                 cout<<"\t"<<cost[i][j];
         }
         cout<<endl;
     }
     for(i=0;i<m;i++){
         for(int j=0;j<n;j++){
             if(allocation[i][j]!=0){
                 cout<<"("<<cost[i][j] * allocation[i][j]<<")";
                 if(k<no_of_allocation-1){
                     cout<<"+";
                     k++;
                 }
                 sum+=cost[i][j]*allocation[i][j];
             }
         }
     }
}
