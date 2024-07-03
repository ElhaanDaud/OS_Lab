# Project Title

This repository contains various algorithms and scheduling techniques implemented in C. Below is a detailed overview of each file and its purpose.

## File Descriptions

### Scheduling Algorithms

- **FCFS.c**: Implementation of the First-Come, First-Served (FCFS) scheduling algorithm.
  - **Description**: FCFS is the simplest scheduling algorithm. Processes are executed in the order they arrive in the ready queue. The process that arrives first is executed first, and so on. It can lead to the "convoy effect" where short processes wait for long processes to complete.
  
- **RoundRobin.c**: Implementation of the Round Robin scheduling algorithm.
  - **Description**: Round Robin is a pre-emptive scheduling algorithm where each process is assigned a fixed time slice or quantum. After a process executes for its quantum, it is moved to the back of the queue, and the CPU scheduler picks the next process in the queue. This continues until all processes are complete. It is designed to give each process an equal share of the CPU time.
  
- **CSCAN_disk_sched.c**: Implementation of the Circular SCAN (C-SCAN) disk scheduling algorithm.
  - **Description**: C-SCAN is a disk scheduling algorithm that moves the disk arm from one end of the disk to the other, servicing requests along the way. When the arm reaches the end, it immediately returns to the beginning without servicing any requests on the return trip. This provides a more uniform wait time compared to the SCAN algorithm.

- **SCAN_disk_sched.c**: Implementation of the SCAN (Elevator) disk scheduling algorithm.
  - **Description**: The SCAN algorithm, also known as the Elevator algorithm, moves the disk arm towards one end of the disk, servicing all requests along the way, and then reverses direction at the end. This helps to reduce the seek time compared to the FCFS disk scheduling.

### Page Replacement Algorithms

- **fifo_page_replacement.c**: Implementation of the First-In-First-Out (FIFO) page replacement algorithm.
  - **Description**: FIFO is a page replacement algorithm where the oldest page in memory is replaced by the new page. It is simple to implement but can suffer from Belady's anomaly, where increasing the number of page frames results in an increase in the number of page faults.

- **Lru_page_replacement.c**: Implementation of the Least Recently Used (LRU) page replacement algorithm.
  - **Description**: LRU replaces the page that has not been used for the longest period of time. It is based on the principle of temporal locality. LRU typically performs better than FIFO and does not suffer from Belady's anomaly, but it can be more complex to implement.

- **optimal_page_replacement.c**: Implementation of the Optimal page replacement algorithm.
  - **Description**: The Optimal page replacement algorithm replaces the page that will not be used for the longest period of time in the future. It provides the best possible performance but is impractical for real-world use because it requires future knowledge of memory references.

### Process Synchronization

- **Prod_Consumer.c**: Implementation of the Producer-Consumer problem using semaphores.
  - **Description**: The Producer-Consumer problem is a classic synchronization problem. It involves two types of processes, producers and consumers, that share a common, fixed-size buffer. The producer generates data and puts it into the buffer, while the consumer takes the data from the buffer. Semaphores are used to ensure that the producer does not add data to a full buffer and the consumer does not remove data from an empty buffer.

### Banker's Algorithm

- **bankers_algorithm.c**: Implementation of the Banker's Algorithm for deadlock avoidance.
  - **Description**: Banker's Algorithm is a resource allocation and deadlock avoidance algorithm. It tests for the safety of resource allocation by simulating the allocation for predetermined maximum possible amounts of all resources, then makes an "s-state" check to test for possible activities, before deciding whether allocation should be allowed to continue.

### Additional Files

- **instructions.txt**: Contains instructions on how to compile and run the programs.
- **LinuxCmds.md**: Documentation of useful Linux commands for working with these programs.
- **README.md**: This file, providing an overview of the repository.


