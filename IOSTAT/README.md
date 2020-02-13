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



