# CPU-Scheduling

## Introduction

CPU scheduling is a fundamental concept in operating systems that determines the order in which processes are given access to the CPU. Efficient scheduling algorithms are crucial for maximizing CPU utilization, minimizing waiting time, and ensuring fairness among processes. Different algorithms are used depending on the requirements, such as First-Come-First-Serve (FCFS), Shortest Job First (SJF), Priority Scheduling, and Round Robin (RR).

## Round Robin Scheduling

Round Robin (RR) is a pre-emptive CPU scheduling algorithm that assigns a fixed time quantum to each process in the ready queue. Each process is executed for a maximum of one time quantum. If a process does not finish during its allocated time, it is placed at the end of the queue, and the CPU scheduler picks the next process. This continues until all processes are completed. RR is widely used in time-sharing systems due to its simplicity and fairness.

**Key Features:**

- Each process gets an equal share of the CPU.
- The time quantum is a crucial parameter; too small leads to excessive context switching, too large degrades to FCFS.
- Suitable for systems requiring quick response times.

## How the Code Works (`RoundRobin.cpp`)

This repository currently contains an implementation of the Round Robin scheduling algorithm in C++. The program:

1. Prompts the user to enter the number of processes and the time quantum.
2. Accepts the arrival time and CPU burst time for each process.
3. Simulates the Round Robin scheduling, displaying the Gantt chart for process execution.
4. Calculates and displays the Finish Time (FT), Turnaround Time (TT), Waiting Time (WT), Response Time (RT), and Start Time (ST) for each process in a neatly aligned table.
5. Outputs the average waiting time and average turnaround time.

**Sample Input:**

```
6 3
0 10
3 4
5 1
7 5
10 4
11 5
```

**Sample Output:**

```
Gantt Chart
0---(1)---3---(2)---6---(1)---9---(3)---10---(1)---13---(4)---16---(1)---19---(5)---22---(1)---25---(6)---28---(4)---29---(5)---30---(6)---32---(4)---33---(6)---35

      FT      TT      WT      RT      ST
     25      25      15       0       0
      9       6       2       0       3
     10       5       4       4       9
     33      26      21      12      16
     30      20      16      12      19
     35      24      19      17      28

Average Waiting Time: 12.8333
Average Turnaround Time: 17.6667
```

## Future Work

This repository will be updated with implementations of other CPU scheduling algorithms, such as FCFS, SJF, and Priority Scheduling. Each algorithm will be documented and explained in this README.
