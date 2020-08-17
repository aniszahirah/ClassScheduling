/* Simple C++ program for implementation 
of FCFS scheduling */

#include<iostream>

using namespace std;
 
// function to find the waiting time for all ccode
void findWaitingTime(int ccode[], int n, int bt[], int wt[])
{
    // waiting time for first process will be 0
    wt[0] = 0;
 
    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        wt[i] =  bt[i-1] + wt[i-1];
    }
}
 
// function to calculate turn around time
void findTurnAroundTime( int ccode[], int n, int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
 
// function to calculate average time
void findAverageTime( int ccode[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // function to find waiting time of all processes
    findWaitingTime(ccode, n, bt, wt);
 
    // function to find turn around time for all processes
    findTurnAroundTime(ccode, n, bt, wt, tat);
 
    // display processes along with all details
    cout << "Course code  "<< " Arrival Time  "<< " Duration  "<< " Waiting time  " << " Turn around time\n";
 
    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << ccode[i] << "\t\t" << i+1 << "\t\t" << bt[i] <<"\t    "<< wt[i] <<"\t\t  " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}
 
// main function
int main()
{
    // process ids
    int ccode[] = {2201, 3401, 1103};
    int n = sizeof ccode / sizeof ccode[0];
 
    // burst time of all processes
    int  duration[] = {3, 2, 1};
 
    findAverageTime(ccode, n,  duration);
    
    return 0;
}
