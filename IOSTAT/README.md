# Linux iostat Command to Report CPU and I/O Statistics

Iostat command is a command used to monitor system's input/output (I/O) device load by observing the time the devices are active in relation to their average transfer rates.  The iostat create reports that can be used to change system configuration to better balance the input/output between physical disks.

Iostat is included in sysstat package. If you don’t have it, you need to install first.

- On RedHat / CentOS / Fedora  

Installing  
```bash
yum install sysstat
```
- On OpenSUse 
```bash
For openSUSE Tumbleweed run the following as root:
zypper addrepo https://download.opensuse.org/repositories/server:monitoring/openSUSE_Tumbleweed/server:monitoring.repo
zypper refresh
zypper install sysstat

For openSUSE Leap 42.3 run the following as root:
zypper addrepo https://download.opensuse.org/repositories/server:monitoring/openSUSE_Leap_42.3/server:monitoring.repo
zypper refresh
zypper install sysstat

For openSUSE Leap 15.2 run the following as root:
zypper addrepo https://download.opensuse.org/repositories/server:monitoring/openSUSE_Leap_15.2/server:monitoring.repo
zypper refresh
zypper install sysstat

For openSUSE Leap 15.1 run the following as root:
zypper addrepo https://download.opensuse.org/repositories/server:monitoring/openSUSE_Leap_15.1/server:monitoring.repo
zypper refresh
zypper install sysstat

For openSUSE Leap 15.0 run the following as root:
zypper addrepo https://download.opensuse.org/repositories/server:monitoring/openSUSE_Leap_15.0/server:monitoring.repo
zypper refresh
zypper install sysstat
```


- On  Debian
```bash
apt install-y sysstat
```

When the command is run without arguments, it generates a detailed report containing information since the system was booted. You can provide two optional parameters to change this:


```
iostat [option] [interval] [count]
```


- **interval** parameter specifies the duration of time in seconds between each report
- **Count** parameter allows you to specify the number of reports that are generated before iostat exits.
When the command is run for the first time with these arguments, the first report contains information since the system was boot, while each subsequent report covers the time period since the last report was generated.


```bash
# iostat 2 3
Linux 3.10.0-514.16.1.el7.x86_64 (centos-01) 	05/23/2017 	_x86_64_  (1 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           0.65    0.00    0.18    0.02    0.00   99.15

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
vda               0.88         4.29         7.07     217829     358600

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           1.01    0.00    0.50    0.00    0.00   98.49

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
vda               0.50         0.00         2.01          0          4

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           3.00    0.00    0.50    0.00    0.00   96.50

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
vda               1.00         0.00        30.00          0         60
```



1) Get report and statistic
To run it, just use the command in your console. Here’s a sample.

```bash
# iostat
Linux 3.10.0-514.16.1.el7.x86_64 (centos-01) 	05/22/2017 	_x86_64   (1 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           0.69    0.00    0.19    0.02    0.04   99.08

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
vda               1.00         3.40        14.08    1552428    6423128
```

- The first section contains CPU report


- **%user** : percentage of CPU utilization that occurred while executing at the user (application) level
- **%nice** : percentage of CPU utilization that occurred while executing at the user level with nice priority
- **%system** : percentage of CPU utilization that occurred while executing at the system (kernel) level
- **%iowait** : percentage of the time that the CPU or CPUs were idle during which the system had an outstanding disk I/O       request
- **%steal** : percentage of time spent in involuntary wait by the virtual CPU or CPUs while the hypervisor was servicing       another virtual processor
- **%idle** : percentage of time that the CPU or CPUs were idle and the system did not have an outstanding disk I/O request

# The second section contains device utilization report

- **Device** : device/partition name as listed in /dev directory
- **tps** : number of transfers per second that were issued to the device. Higher tps means the processor is busier
- **Blk_read/s** : show the amount of data read from the device expressed in a number of blocks (kilobytes, megabytes) per second
- **Blk_wrtn/s** : amount of data written to the device expressed in a number of blocks (kilobytes, megabytes) per second
- **Blk_read** : show the total number of blocks read
- **Blk_wrtn** : show the total number of blocks written

- iostat uses the files below to create reports.

`/proc/stat` contains system statistics.
`/proc/uptime` contains system uptime.
`/proc/diskstats` contains disks statistics.
`/sys` contains statistics for block devices.
`/proc/self/mountstats` contains statistics for network filesystems.
`/dev/disk`contains persistent device names

2) Show more details statistics information


Iostat command gives I/O devices report utilization. It is possible to extend the statistic result for a diagnose in depth with `-x` option


```bash
# iostat -x
Linux 3.10.0-514.16.1.el7.x86_64 (centos-01) 	05/23/2017 	_x86_64_	(1 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           0.69    0.00    0.19    0.02    0.04   99.06

Device: rrqm/s   wrqm/s     r/s     w/s    rkB/s    wkB/s avgrq-sz avgqu-sz   await r_await w_await  svctm  %util
vda     0.01     1.10    0.16    0.84     3.37    14.04    34.88     0.00    2.35    1.41    2.53   0.40   0.04
```


- **avg-cpu**: it is the cpu block information
- **Devide**: it is device block information. To be sure you are on the good device
- **%util**: how much time did the storage device have outstanding work (was busy).
- **svctm**: indicate how fast does your I/O subsystem respond requests overall when busy. Actually, less you load your         system, higher svctm is.
- **await**: indicates how fast do requests go through. It is just an average.
- **avgqu-sz**: how many requests are there in a request queue. Low = either your system is not loaded, or has serialized       I/O and cannot utilize underlying storage properly. High = your software stack is scalable enough to load properly           underlying I/O.
- **avgrq-sz**: Just an average request size. can indicate what kind of workload happens.
- **wsec/s** & **rsec/s**: Sectors read and written per second. Divide by 2048, and you’ll get megabytes per second.
- **r/s** & **w/s**: Read and write requests per second. These numbers are the ones that are the I/O capacity figures,           though of course, depending on how much pressure underlying I/O subsystem gets (queue size!), they can vary.
- **rrqm/s** & **wrqm/s**: How many requests were merged by block layer.
