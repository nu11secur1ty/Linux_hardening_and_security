The Linux kernel implements two separate priority ranges.

The first is the nice value, a number from –20 to 19 with a default of zero. Larger nice values correspond to a lower priority (you are being nice to the other processes on the system). Processes with a lower nice value (higher priority) run before processes with a higher nice value (lower priority). The nice value also helps determine how long a processor timeslice the process receives. A process with a nice value of –20 receives the maximum timeslice, whereas a process with a nice value of 19 receives the minimum timeslice. Nice values are the standard priority range used in all Unix systems.

The second range is the real-time priority (rtprio). By default, it ranges from zero to 99. All real-time processes are at a higher priority than normal processes. Linux implements real-time priorities in accordance with POSIX.

In order to select a process to run, the Linux scheduler must consider the priority of each process. Actually, there are two kinds of priority:

Static priority
This kind is assigned by the users to real-time processes and ranges from 1 to 99 (highest). It is never changed by the scheduler. The sys_sched_get_priority_max( ) routine returns the static priority of the process, it returns 0 for non-realtime processes.

Dynamic priority
This kind applies only to conventional processes (non realtime processes)

Processes have an initial priority specified as the nice value. This value is stored in the static_prio member of the process’s task_struct. The value is called the static priority because it does not change from what the user specifies. The scheduler, in turn, bases its decisions on the dynamic priority that is stored in prio. The dynamic priority is calculated as a function of the static priority and the task’s interactivity

The static priority of a real-time process is always higher than the dynamic priority of a conventional one: the scheduler will start running conventional processes only when there is no real-time process in a TASK_RUNNING state.
