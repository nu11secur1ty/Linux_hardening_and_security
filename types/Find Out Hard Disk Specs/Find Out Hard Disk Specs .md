
# hdparm Command:
Open the terminal and type the following command to find information about /dev/sda:

```
# hdparm -I /dev/sda
```
Sample outputs:
```
/dev/sda:
SG_IO: bad/missing sense data, sb[]:  70 00 05 00 00 00 00 0a 00 00 00 00 20 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00

ATA device, with non-removable media
Standards:
	Likely used: 1
Configuration:
	Logical		max	current
	cylinders	0	0
	heads		0	0
	sectors/track	0	0
	--
	Logical/Physical Sector size:           512 bytes
	device size with M = 1024*1024:           0 MBytes
	device size with M = 1000*1000:           0 MBytes 
	cache/buffer size  = unknown
Capabilities:
	IORDY not likely
	Cannot perform double-word IO
	R/W multiple sector transfer: not supported
	DMA: not supported
	PIO: pio0 
  ```
  # lshw Command:
  
  You need to install lshw command using apt-get or yum command. To display all disks and storage controllers in the system, enter:
  
  ```
  # lshw -class disk -class storage
  ```
  Sample outputs:
  
  
  ```
   *-ide                     
       description: IDE interface
       product: 82371AB/EB/MB PIIX4 IDE
       vendor: Intel Corporation
       physical id: 7.1
       bus info: pci@0000:00:07.1
       version: 01
       width: 32 bits
       clock: 33MHz
       capabilities: ide bus_master
       configuration: driver=ata_piix latency=64
       resources: irq:0 ioport:1f0(size=8) ioport:3f6 ioport:170(size=8) ioport:376 ioport:1060(size=16)
  *-scsi
       description: SCSI storage controller
       product: 53c1030 PCI-X Fusion-MPT Dual Ultra320 SCSI
       vendor: LSI Logic / Symbios Logic
       physical id: 10
       bus info: pci@0000:00:10.0
       logical name: scsi2
       version: 01
       width: 64 bits
       clock: 33MHz
       capabilities: scsi bus_master cap_list rom
       configuration: driver=mptspi latency=64 maxlatency=255 mingnt=6
       resources: irq:17 ioport:1400(size=256) memory:feba0000-febbffff memory:febc0000-febdffff memory:c0008000-c000bfff
     *-disk
          description: SCSI Disk
          product: VMware Virtual S
          vendor: VMware,
          physical id: 0.0.0
          bus info: scsi@2:0.0.0
          logical name: /dev/sda
          version: 1.0
          size: 100GiB (107GB)
          capabilities: 7200rpm partitioned partitioned:dos
          configuration: ansiversion=2 logicalsectorsize=512 sectorsize=512 signature=0f219ec2
  *-scsi
       physical id: 1
       logical name: scsi1
       capabilities: emulated
     *-cdrom
          description: DVD-RAM writer
          product: VMware IDE CDR10
          vendor: NECVMWar
          physical id: 0.0.0
          bus info: scsi@1:0.0.0
          logical name: /dev/cdrom
          logical name: /dev/cdrw
          logical name: /dev/dvd
          logical name: /dev/sr0
          version: 1.00
          capabilities: removable audio cd-r cd-rw dvd dvd-r dvd-ram
          configuration: ansiversion=5 status=open
```
# Find Out Disks Name Only:

The following command will quickly list installed disks including CD/DVD/BD drivers:

```
# lshw -short -C disk
```
Sample outputs:

```
H/W path             Device      Class       Description
========================================================
/0/100/10/0.0.0      /dev/sda    disk        107GB VMware Virtual S
/0/1/0.0.0           /dev/cdrom  disk        VMware IDE CDR10
```

# smartctl Command:

The smartctl command act as a control and monitor Utility for SMART disks under Linux and Unix like operating systems. Type the following command to get information about /dev/sda (...SATA disk...your_):

```
# smartctl -d ata -a -i /dev/sda
# smartctl --all /dev/sda
```
Sample outputs:

```
=== START OF INFORMATION SECTION ===
Vendor:               VMware,
Product:              VMware Virtual S
Revision:             1.0
User Capacity:        107,374,182,400 bytes [107 GB]
Logical block size:   512 bytes
Device type:          disk
Local Time is:        Mon Jul 31 09:25:39 2017 EDT
SMART support is:     Unavailable - device lacks SMART capability.

=== START OF READ SMART DATA SECTION ===
Current Drive Temperature:     0 C
Drive Trip Temperature:        0 C

Error Counter logging not supported

Device does not support Self Test logging
```
# Have fun with nu11secur1ty =)

