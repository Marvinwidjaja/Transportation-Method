#include<iostream>
using namespace std;
#define MAX 100

int main()
{
    int m,n;
    int stocknumber[MAX];
    int numofdelivered[MAX];
    int cost[MAX][MAX];
    int sum = 0;
    
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
    


    for(int i=0,j=0;(i<m&&j<n);)
    {
        if (stocknumber[i]<numofdelivered[j])
        {
        sum+=cost[i][j]*stocknumber[i];
        numofdelivered[j]-=stocknumber[i];
        i++;
        }
        else
            if(stocknumber[i]>numofdelivered[j])
            { sum+=cost[i][j]*numofdelivered[j];
                stocknumber[i]-=numofdelivered[j];
                j++;
            }
            else
                if(stocknumber[i]==numofdelivered[j])
            {
                        sum+=cost[i][j]*numofdelivered[j];
                        i++;
                        j++;
                }
}

cout<<"\n\nMinimum transportation cost:"<<sum;
}

