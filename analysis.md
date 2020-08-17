Group Members:
1) Anis Zahirah Binti Ahmad Madani (1818060)
2) Nurul Fadhillah Binti Ismail (1811722)
3) Nur Syifa’ Aina Binti Zahaimi (1817794)
4) Nur Asimah Binti Che Mamat (1813212)

Section: 4

# Introduction

In this project, we were assigned to find the optimum class scheduling using 3 algorithms. To find the optimum class, we chose 3 non-preemptive algorithms which are FCFS algorithm, SJF algorithm and Priority Scheduling. Non-preemptive means we cannot stop a class from running to allow another process to run.
First Come First Serve (FCFS) is an operating system scheduling algorithm that automatically executes queued requests and processes in order of their arrival. It is the easiest and simplest CPU scheduling algorithm. In this type of algorithm, processes which requests the CPU first get the CPU allocation first. This is managed with a FIFO queue. The full form of FCFS is First Come First Serve.As the process enters the ready queue, its PCB (Process Control Block) is linked with the tail of the queue and, when the CPU becomes free, it should be assigned to the process at the beginning of the queue.

Shortest Job First (SJF) is an algorithm in which the process having the smallest execution time is chosen for the next execution. This scheduling method can be preemptive or non-preemptive. It significantly reduces the average waiting time for other processes awaiting execution. It is associated with each job as a unit of time to complete.This algorithm method is helpful for batch-type processing, where waiting for jobs to complete is not critical.It can improve process throughput by making sure that shorter jobs are executed first, hence possibly have a short turnaround time.It improves job output by offering shorter jobs, which should be executed first, which mostly have a shorter turnaround time.

Priority Scheduling is a method of scheduling processes that is based on priority. In this algorithm, the scheduler selects the tasks to work as per the priority.The processes with higher priority should be carried out first, whereas jobs with equal priorities are carried out on a round-robin or FCFS basis. Priority depends upon memory requirements, time requirements,etc.A CPU algorithm that schedules processes based on priority.It used in Operating systems for performing batch processes.If two jobs having the same priority are ready it works on a first come,first served basis.In priority scheduling, a number is assigned to each process that indicates its priority level.Lower the number, higher is the priority.In this type of scheduling algorithm, if a newer process arrives, that is having a higher priority than the currently running process, then the currently running process is preempted.


# Consideration

To find the best class scheduling solution, three non-preemptive scheduling algorithms are compared. The algorithms involved in the analysis is First Come First Serve (FCFS), Shortest Job First (SJF) and Priority Scheduling. Similar data is used in arrival time, burst time(duration) and priority to calculate the average waiting time and average turnaround time and to determine the order of process execution.

# Analysis

The input for analysis are as below:

|Course Code|Duration|Priority|Arrival Time|
|---|---|---|---|
|2201|3|2|1|
|3401|2|3|2|
|1103|1|1|3|

## FCFS

Give an analysis of your algo and compare it with the other two

Output :
|Course Code|Arrival Time|Duration|Waiting Time|Turnaround Time|
|---|---|---|---|---|
|2201|1|3|0|3|
|3401|2|2|3|5|
|1103|3|1|5|6|

Order of scheduling =

Average waiting time = 2.66667

Average turnaround time = 4.66667

## SJF

Shortest Job First Scheduling is a method of scheduling processes that prioritize burst time. The processes with shortest burst time will be carried out first, whereas jobs with equal burst time are carried out on FCFS basis which is according to their respective arrival time. In this case, the average waiting time and average turnaround time for SJF scheduling is lower than FCFS but compared to priority, the average waiting time is equal meanwhile the average turnaround time is lower. The average turnaround time is lower than priority scheduling because SJF scheduling considers the duration of a process rather than priority. As it did not consider the arrival time unless for the first class, it has a lower average waiting time and turnaround time than FCFS scheduling. The order of executed processes which is based on their arrival time and class duration start with 2201 and followed by 1103, then 3401. 

Output : 
|Course Code|Arrival Time|Duration|Waiting Time|Turnaround Time|
|---|---|---|---|---|
|2201|1|3|0|3|
|1103|3|1|1|2|
|3401|2|2|4|5|

Order of scheduling = 2201 → 1103 → 3401

Average Waiting Time = 1.66667

Average Turnaround Time = 3.33333

## Priority Scheduling

Priority Scheduling is a method of scheduling processes that depends on priority. The processes with higher priority will be carried out first, whereas jobs with equal priorities are carried out on FCFS basis. The average waiting time and average turnaround time for priority scheduling is lower than FCFS but higher than SJF. Average waiting time and turnaround time is lower than FCFS because priority scheduling considers the priority of a process rather than executing all of the queued processes without considering the duration or priority. The reason why this algorithm has a higher average waiting time and average turnaround time than SJF is because it does not prioritize the process with lower duration. At time 1 only process 2201 arrived makes 2201 the first process to be executed without considering the priority. 2201 ends at time 4 where at this time both 3401 and 1103 have arrived. 3401 is chosen to be executed first because it has higher priority than 1103. 3401 ends at 6 and process 1103 continues to execute from time 6 to 7. By considering the arrival time and priority, the result obtained for the execution order is 2201 continued by 3401 and 1103. This shows that priority scheduling is an average non-preemptive scheduling compared to SJF while FCFS is the worst because it has the highest average waiting time and average turnaround time. 

Output : 
|Course Code|Arrival Time|Duration|Priority|Waiting Time|Turnaround Time|
|---|---|---|---|---|---|
|2201|1|3|2|0|3|
|3401|2|2|3|2|4|
|1103|3|1|1|3|4|

Order of scheduling =	2201 → 3401 → 1103

Average waiting time = 1.66667

Average turnaround time = 3.66667

