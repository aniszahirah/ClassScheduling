#include <bits/stdc++.h>
using namespace std;
//structure for every process
struct Process 
{
   	int ccode; 				// Process ID
   	int duration; 			// Burst Time
   	int priority; 			// Priority
   	int arrival_time; 		// Arrival Time
};

void swap(int *a, int *b) 
{ 
	int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) 
{
   	for (int i = 0; i < n; i++)
   	tat[i] = proc[i].duration + wt[i];
}

void findWaitingTime(Process proc[], int n, int wt[]) 			//waiting time of all process
{
    int rt[n];
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
   
    for (int i = 0; i < n; i++)
    	rt[i] = proc[i].duration;
    	
    while (complete != n) {
        for (int j = 0; j < n; j++) {
        	if ((proc[j].arrival_time <= t) && (rt[j] < minm) && rt[j] > 0) 
			{
            	minm = rt[j];
            	shortest = j;
            	check = true;
         	}
      	}
      	
      	if (check == false) 
		{
         	t++;
         	continue;
      	}

      	rt[shortest]--;      	// decrementing the remaining time
      	minm = rt[shortest];
      	
      	if (minm == 0)
         	minm = INT_MAX;

      	if (rt[shortest] == 0)         // If a process gets completely executed
		{
        	complete++;
        	check = false;
        	finish_time = t + 1;

        	wt[shortest] = finish_time - proc[shortest].duration - proc[shortest].arrival_time;        	// Calculate waiting time
        	if (wt[shortest] < 0)
        		wt[shortest] = 0;
      	}
      	t++;          	// Increment time
   }
   
   for(int i = 0; i < n; i++)
    {
        int pos = i;
        for(int j = i+1; j < n; j++)
        {
            if(wt[j]<wt[pos])
                pos=j;
        }
 
        swap(proc[pos].ccode, proc[i].ccode);
        swap(proc[pos].duration, proc[i].duration); 
        swap(proc[pos].priority, proc[i].priority);
        swap(proc[pos].arrival_time, proc[i].arrival_time); 
        swap(wt[pos], wt[i]); 
    }
}

// Function to calculate average time
void findavgTime(Process proc[], int n) 
{
   	int wt[n], tat[n], total_wt = 0,
   	total_tat = 0;
   	
   	findWaitingTime(proc, n, wt);					// Function to find waiting time of all processes
   	findTurnAroundTime(proc, n, wt, tat);			// Function to find turn around time for all processes
   	
   	cout<<"\nFinal Result...\n"; 
   	cout<<"Process ID\tClass Duration\tArrival Time\tWaiting Time\tTurnaround Time\n"; 
   	for (int i = 0; i < n; i++) 
	{
      	total_wt = total_wt + wt[i];
      	total_tat = total_tat + tat[i];
      	cout << proc[i].ccode << "\t\t" << proc[i].duration << "\t\t" << proc[i].arrival_time << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n"; 
   	}
   	
   	cout << "\nAverage waiting time = " << (float)total_wt / (float)n; cout << "\nAverage turnaround time = " << (float)total_tat / (float)n;
}

// main function
int main() 
{
   	Process proc[] = {{2201, 3, 2, 1}, {3401, 2, 3, 2}, {1103, 1, 1, 3}};
   	int n = sizeof(proc) / sizeof(proc[0]);
   	cout<<"Before Arrange...\n"; 
    cout<<"Process ID\tArrival Time\tPriority\tClass Duration\n"; 
    for(int i = 0; i < n; i++) 
    { 
        cout << proc[i].ccode << "\t\t" << proc[i].arrival_time << "\t\t" << proc[i].priority <<"\t\t" << proc[i].duration << "\n"; 
    }
   	
   	findavgTime(proc, n);
   	return 0;
}
