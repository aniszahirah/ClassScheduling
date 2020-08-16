/* Simple C++ program for implementation 
of SJF scheduling */

#include<iostream> 
using namespace std; 
struct Process
{
   int ccode;     // course code
   int duration;      // class duration or burst time
   int priority;  //priority
   int arrival_time;   //prefered arrival time
};

void findWaitingTime(Process p[], int wt[], int n)
{
    wt[0] = 0;            //waiting time for first process is zero
    //calculate waiting time
    for (int i = 1; i < n; i++)
    {
        wt[i] = p[i-1].duration + wt[i-1];
    }
}

void findTurnaroundTime(Process p[], int wt[], int tat[], int n)
{
	//calculate turnaround time
	for(int i = 0; i < n; i++) 
    { 
    	tat[i] = p[i].duration + wt[i];  
    }	
}

void arrangeArrival(int n, Process p[]) 
{ 
	int i, j, pos, temp;
	float avg_wt, avg_tat, total;
	int wt[n], tat[n], ttat = 0, twt = 0;
	
    //sorting duration, priority and class code in ascending order using selection sort
    for(i = 0; i < n; i++)
    {
        pos = i;
        for(j = i + 1; j < n; j++)
        {
            if(p[j].duration < p[pos].duration)
                pos = j;
        }
 
        temp = p[i].duration;
        p[i].duration = p[pos].duration;
        p[pos].duration = temp;
 
        temp = p[i].priority;
        p[i].priority = p[pos].priority;
        p[pos].priority = temp;
 
        temp = p[i].ccode;
        p[i].ccode = p[pos].ccode;
        p[pos].ccode = temp;
    }
    
    findWaitingTime(p, wt, n);
    
    findTurnaroundTime(p, wt, tat, n);
    
    cout<<"\nFinal Result...\n"; 
    cout<<"Process ID\tClass Duration\tPriority\tWaiting Time\tTurnaround Time\n"; 
    for(i = 0; i < n; i++) 
    { 
    	twt += wt[i];
        ttat += tat[i];
    	cout << p[i].ccode << "\t\t" << p[i].duration << "\t\t" << p[i].priority << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n"; 
    }  
    
    cout << "\n\nAverage Waiting Time = " << (float)twt / (float)n;     //average waiting time
    cout << "\nAverage Turnaround Time = " << (float)ttat / (float)n;     //average turnaround time;
 
}  

int main() 
{ 
	Process proc[] = {{2201,3,2,1}, {3401, 2, 3,2}, {1103, 1,1,3}}; 
	
    int n = sizeof proc / sizeof proc[0];
    
	cout<<"Before Arrange...\n"; 
    cout<<"Process ID\tArrival Time\tPriority\tClass Duration\n"; 
    for(int i = 0; i < n; i++) 
    { 
        cout << proc[i].ccode << "\t\t" << proc[i].arrival_time << "\t\t" << proc[i].priority <<"\t\t" << proc[i].duration << "\n"; 
    } 
    
    arrangeArrival(n, proc);
    
    return 0;  
} 
