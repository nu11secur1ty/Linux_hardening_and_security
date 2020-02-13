# Linux iostat Command to Report CPU and I/O Statistics 10 Command
![]()

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

3) Show only the cpu statistic

It is possible to show statistic information and report of our cpu with `-c` option


```bash
$ iostat -c
Linux 4.4.0-78-generic (shinigami) 	05/23/2017 	_x86_64_	(4 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
          12.93    0.08    2.40    3.35    0.00   81.24
```

4) Display only the device report


It is possible to only show the status of the device utilization with `-d` option. It will list information for each connected device


```bash
$ iostat -d
Linux 4.4.0-78-generic (shinigami) 	05/23/2017 	_x86_64_	(4 CPU)

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
sda              17.73       510.80       632.10    5127420    6345037
mmcblk0           0.03         0.63         0.00       6282          0
```

5) Show extended I/O statistic for device only

We can display extended statistic on one side and from the other side we can display extended statistics. It means that we can display extended statistics only for devices with `-xd` option as below

```bash
$ iostat -xd
Linux 4.4.0-78-generic (shinigami) 	05/23/2017 	_x86_64_	(4 CPU)

Device:         rrqm/s   wrqm/s     r/s     w/s    rkB/s    wkB/s avgrq-sz avgqu-sz   await r_await w_await  svctm  %util
sda               0.48    25.33    8.43    7.81   417.06   540.42   117.88     1.18   72.83   35.98  112.62   6.18  10.03
mmcblk0           0.30     0.00    0.02    0.00     0.49     0.00    49.47     0.00    3.73    3.73    4.00   2.99   0.01
```

6) Capture the statistics in kilobytes or megabytes

By default, iostat measure the I/O system with bytes unit. To make it easier to read, we can convert iostat to show us reports in kilobytes or megabytes unit.

Just add `-k` parameter to create reports with kilobytes unit

```bash
$ iostat -k
Linux 4.4.0-78-generic (shinigami) 	05/23/2017 	_x86_64_	(4 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
          12.54    0.08    2.37    3.41    0.00   81.61

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
sda              16.18       345.76       504.55    5622164    8204113
mmcblk0           0.02         0.39         0.00       6282          0
```

and `-m` parameter to create reports with megabytes unit.


```bash
$ iostat -m
Linux 4.4.0-78-generic (shinigami) 	05/23/2017 	_x86_64_	(4 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
          12.54    0.08    2.37    3.41    0.00   81.61

Device:            tps    MB_read/s    MB_wrtn/s    MB_read    MB_wrtn
sda              16.18         0.34         0.49       5490       8012
mmcblk0           0.02         0.00         0.00          6          0
```

7) Display cpu and device statistics with delay

Same with vmstat, as a statistic tool the best way to use it is with delay parameter. With delay, we can see what’s the trend. Here are some samples to run iostat with delay.

Run iostat with kilobytes unit, 2 seconds interval with 3 times reports

```bash
# iostat -k 2 3
Linux 3.10.0-514.16.1.el7.x86_64 (centos-01) 	05/23/2017 	_x86_64_	(1 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           0.70    0.00    0.19    0.02    0.03   99.05

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
vda               1.00         3.33        14.03    1561788    6572152

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           0.50    0.00    0.00    0.00    0.00   99.50

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
vda               0.00         0.00         0.00          0          0

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           3.52    0.00    0.50    0.00    0.00   95.98

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
vda               1.51         0.00        12.06          0         24
```

Show CPU only report with 2 seconds interval and 2 times reports


```bash
# iostat -c 2 2
Linux 3.10.0-514.16.1.el7.x86_64 (centos-01) 	05/23/2017 	_x86_64_	(1 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           0.71    0.00    0.19    0.02    0.03   99.05

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           1.50    0.00    0.00    0.00    0.00   98.50
```

Show sda6 and sda7 device only report with 2 seconds interval and 2 times reports

```bash
$ iostat -d sda7 sda6 2 2
Linux 4.4.0-78-generic (shinigami) 	05/23/2017 	_x86_64_	(4 CPU)

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
sda6              3.40       108.29       130.75    1928577    2328496
sda7             12.19       211.96       305.79    3774804    5445696

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
sda6              0.00         0.00         0.00          0          0
sda7              1.00         0.00        24.00          0         48
```

8) Display persistent device name statistics

It is possible to print the report by device name. Instead of the standard `/dev/sda` name, it will print the persistent device name with `-j` parameter and adding `ID` keyword ( specify the type of the persistent name).

```bash
$ iostat -j ID mmcbkl0 sda6 -x -m 2 2 
Linux 4.4.0-78-generic (shinigami) 	05/23/2017 	_x86_64_	(4 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
          14.33    0.10    2.48    3.26    0.00   79.83

Device:  rrqm/s   wrqm/s     r/s     w/s    rMB/s    wMB/s avgrq-sz avgqu-sz   await r_await w_await  svctm  %util
ata-ST500LT012-1DG142_S3P4312X-part6
         0.19     0.88    2.51    0.82     0.10     0.12   138.36     0.21   61.81   57.12   76.12  10.81   3.60

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
          19.40    0.00    1.25    0.63    0.00   78.72

Device:  rrqm/s   wrqm/s     r/s     w/s    rMB/s    wMB/s avgrq-sz avgqu-sz   await r_await w_await  svctm  %util
ata-ST500LT012-1DG142_S3P4312X-part6
         0.00     0.00    0.00    0.00     0.00     0.00     0.00     0.00    0.00    0.00    0.00   0.00   0.00
```


9) Display  statistics  for  block devices


It is possible to directly show information for each block device automatically. No need to indicate each device name. It will display statistics for block devices and all their partitions that are used by the system. If a device name is entered on the command line, then statistics for it and all its partitions are displayed. Just use `-p` option


```bash
$ iostat -p
Linux 4.4.0-78-generic (shinigami) 	05/23/2017 	_x86_64_	(4 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
          14.93    0.10    2.51    3.19    0.00   79.28

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
sda              15.82       297.18       474.87    5928512    9473117
sda1              0.00         0.11         0.00       2108          0
sda2              0.01         0.28         0.00       5679          1
sda3              0.00         0.10         0.00       2084          0
sda4              0.00         0.10         0.00       2092          0
sda5              0.09         0.77        45.62      15428     910068
sda6              3.26       102.76       117.09    2049957    2335908
sda7             12.09       192.75       306.99    3845120    6124136
sda8              0.12         0.20         5.16       3896     103004
mmcblk0           0.01         0.31         0.00       6282          0
mmcblk0p1         0.01         0.26         0.00       5242          0
```

```bash
$ iostat -p sdf 1 2
Linux 3.10.0-514.16.1.el7.x86_64 (centos7-srv) 	05/23/2017 	_x86_64_	(1 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           7.18    0.41    3.94    4.10    0.00   84.37

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
sdf               0.47         3.54         0.00       4656          0
sdf1              0.09         0.70         0.00        920          0
sdf2              0.09         0.69         0.00        904          0
sdf3              0.09         0.69         0.00        904          0
sdf4              0.09         0.69         0.00        904          0

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           6.00    1.00    2.00    0.00    0.00   91.00

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
sdf               0.00         0.00         0.00          0          0
sdf1              0.00         0.00         0.00          0          0
sdf2              0.00         0.00         0.00          0          0
sdf3              0.00         0.00         0.00          0          0
sdf4              0.00         0.00         0.00          0          0
```

10) Display lvm2 statistic information

It is possible to view LVM statistic with `-N` option. The command displays the registered device mapper names for any device mapper devices

- Conclusion

We can tell iostat to omit output for any devices for which there was no activity during the sample period with -z option.

One of the advantages of this tool is you can run them without root privilege. You can dig it deeper by exploring iostat manual page by typing man iostat in your console to bring iostat manual page.
