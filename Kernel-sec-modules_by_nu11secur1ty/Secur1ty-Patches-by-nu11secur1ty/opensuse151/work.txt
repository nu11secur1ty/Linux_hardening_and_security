#
# /etc/sysctl.d/99-sysctl.conf
#

kernel.sysrq = 0

## Network Tweaks

# Default Socket Receive Buffer
net.core.rmem_default = 31457280

# Maximum Socket Receive Buffer
net.core.rmem_max = 12582912

# Default Socket Send Buffer
net.core.wmem_default = 31457280

# Maximum Socket Send Buffer
net.core.wmem_max = 12582912

# Maximum Number of Packets
net.core.netdev_max_backlog = 30000

# Number of times SYNACKs for passive TCP connection.
net.ipv4.tcp_synack_retries = 2

# Protect Against TCP Time-Wait
net.ipv4.tcp_rfc1337 = 1

# TCP Timestamps
net.ipv4.tcp_timestamps = 0

# Ignore Bogus ICMP Errors
net.ipv4.icmp_ignore_bogus_error_responses = 1

# Avoid a smurf attack
net.ipv4.icmp_echo_ignore_broadcasts = 0

# Turn on protection for bad icmp error messages
net.ipv4.icmp_ignore_bogus_error_responses = 1

# Turn on syncookies for SYN flood attack protection
net.ipv4.tcp_syncookies = 1

# Turn on and log spoofed, source routed, and redirect packets
net.ipv4.conf.all.log_martians = 1
net.ipv4.conf.default.log_martians = 1

# No source routed packets here
net.ipv4.conf.all.accept_source_route = 0
net.ipv4.conf.default.accept_source_route = 0

# Turn on reverse path filtering
net.ipv4.conf.all.rp_filter = 1
net.ipv4.conf.default.rp_filter = 1

# Make sure no one can alter the routing tables
net.ipv4.conf.all.accept_redirects = 0
net.ipv4.conf.default.accept_redirects = 0
net.ipv4.conf.all.secure_redirects = 0
net.ipv4.conf.default.secure_redirects = 0

# Don't act as a router
net.ipv4.ip_forward = 0
net.ipv4.conf.all.send_redirects = 0
net.ipv4.conf.default.send_redirects = 0

# Turn on execshild
#kernel.exec-shield = 1
kernel.randomize_va_space = 1

# Tune IPv6
net.ipv6.conf.default.router_solicitations = 0
net.ipv6.conf.default.accept_ra_rtr_pref = 0
net.ipv6.conf.default.accept_ra_pinfo = 0
net.ipv6.conf.default.accept_ra_defrtr = 0
net.ipv6.conf.default.autoconf = 0
net.ipv6.conf.default.dad_transmits = 0
net.ipv6.conf.default.max_addresses = 1

# Optimization for port usefor LBs
# Increase system file descriptor limit
fs.file-max = 65535

# Allow for more PIDs
# (to reduce rollover problems);
# may break some programs 32768
kernel.pid_max = 65536

# Increase system IP port limits
net.ipv4.ip_local_port_range = 2000 65000

# Increase TCP max buffer size setable using setsockopt()
#net.ipv4.tcp_rmem = 4096 87380 8388608
#net.ipv4.tcp_wmem = 4096 87380 8388608

# Increase Linux auto tuning TCP buffer limits
# min, default, and max number of bytes to use
# set max to at least 4MB, or higher if you use very high BDP paths
# Tcp Windows etc
#net.core.rmem_max = 8388608
#net.core.wmem_max = 8388608

#net.core.netdev_max_backlog = 5000
net.ipv4.tcp_window_scaling = 1

# Disable IPv6
net.ipv6.conf.all.disable_ipv6 = 1
net.ipv6.conf.enp4s0.disable_ipv6 = 1

# Preventing link TOCTOU vulnerabilities
fs.protected_hardlinks = 1
fs.protected_symlinks = 1

# Hide kernel symbol addresses
kernel.kptr_restrict = 1

# Improving Performance
# reuse/recycle time-wait sockets
net.ipv4.tcp_tw_reuse = 1
net.ipv4.tcp_tw_recycle = 1

# Small periodic system freezes
vm.dirty_background_bytes = 4194304
vm.dirty_bytes = 4194304

#EOF: 99-sysctl.conf
