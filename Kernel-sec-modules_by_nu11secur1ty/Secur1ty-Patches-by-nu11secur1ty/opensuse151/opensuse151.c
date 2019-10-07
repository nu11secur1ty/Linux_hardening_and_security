#include <stdio.h>
#include <stdlib.h>
//Author @nu11secur1ty//

int main(void)
{
	/*clean*/
 system("cat /dev/null/ > /etc/sysctl.d/99-custom.conf");
	
 
 system("echo -e 'kernel.sysrq = 0' >> /etc/sysctl.d/99-custom.conf");
	
	 /* ## Network Tweaks */
 	/* Default Socket Receive Buffer */
 system("echo -e 'net.core.rmem_default = 31457280' >> /etc/sysctl.d/99-custom.conf");
 
 	/* Maximum Socket Receive Buffer */
 system("echo -e 'net.core.rmem_max = 12582912' >> /etc/sysctl.d/99-custom.conf");

 	/* Default Socket Send Buffer */
 system("echo -e 'net.core.wmem_default = 31457280' >> /etc/sysctl.d/99-custom.conf");

 	/* Maximum Socket Send Buffer */
 system("echo -e 'net.core.wmem_max = 12582912' >> /etc/sysctl.d/99-custom.conf");

 	/* Maximum Number of Packets */
 system("echo -e 'net.core.netdev_max_backlog = 30000' >> /etc/sysctl.d/99-custom.conf");

 	/* Number of times SYNACKs for passive TCP connection.*/
 system("echo -e 'net.ipv4.tcp_synack_retries = 2' >> /etc/sysctl.d/99-custom.conf");
 
 	/* Protect Against TCP Time-Wait */
 system("echo -e 'net.ipv4.tcp_rfc1337 = 1' >> /etc/sysctl.d/99-custom.conf");
 
 	/* TCP Timestamps */
 system("echo -e 'net.ipv4.tcp_timestamps = 0' >> /etc/sysctl.d/99-custom.conf");

 	/* Ignore Bogus ICMP Errors */
 system("echo -e 'net.ipv4.icmp_ignore_bogus_error_responses = 1' >> /etc/sysctl.d/99-custom.conf");

 	/* Avoid a smurf attack */
 system("echo -e 'net.ipv4.icmp_echo_ignore_broadcasts = 0' >> /etc/sysctl.d/99-custom.conf");

	/* Turn on protection for bad icmp error messages */
 system("echo -e 'net.ipv4.icmp_ignore_bogus_error_responses = 1' >> /etc/sysctl.d/99-custom.conf");

 	/* Turn on syncookies for SYN flood attack protection */
 system("echo -e 'net.ipv4.tcp_syncookies = 1' >> /etc/sysctl.d/99-custom.conf");

	/* Turn on and log spoofed, source routed, and redirect packets */
 system("echo -e 'net.ipv4.conf.all.log_martians = 1' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv4.conf.default.log_martians = 1' >> /etc/sysctl.d/99-custom.conf");
 
 
 	/* No source routed packets here */
 system("echo -e 'net.ipv4.conf.all.accept_source_route = 0' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv4.conf.default.accept_source_route = 0' >> /etc/sysctl.d/99-custom.conf");

	/* Turn on reverse path filtering */
 system("echo -e 'net.ipv4.conf.all.rp_filter = 1' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv4.conf.default.rp_filter = 1' >> /etc/sysctl.d/99-custom.conf");


	/*  Make sure no one can alter the routing tables */
 system("echo -e 'net.ipv4.conf.all.accept_redirects = 0' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv4.conf.default.accept_redirects = 0' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv4.conf.all.secure_redirects = 0' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv4.conf.default.secure_redirects = 0' >> /etc/sysctl.d/99-custom.conf");
 
 	/*  Don't act as a router */
 system("echo -e 'net.ipv4.ip_forward = 0' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv4.conf.all.send_redirects = 0' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv4.conf.default.send_redirects = 0' >> /etc/sysctl.d/99-custom.conf");

 	/*  Turn on execshild
	 kernel.exec-shield = 1*/
 system("echo -e 'kernel.randomize_va_space = 1' >> /etc/sysctl.d/99-custom.conf");
 
 
 	/* Tune IPv6 */
 system("echo -e 'net.ipv6.conf.default.router_solicitations = 0' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv6.conf.default.accept_ra_rtr_pref = 0' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv6.conf.default.accept_ra_pinfo = 0' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv6.conf.default.accept_ra_defrtr = 0' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv6.conf.default.autoconf = 0' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv6.conf.default.dad_transmits = 0' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv6.conf.default.max_addresses = 1' >> /etc/sysctl.d/99-custom.conf");
 
 	/*  Optimization for port usefor LBs
	  Increase system file descriptor limit */
 system("echo -e 'fs.file-max = 65535' >> /etc/sysctl.d/99-custom.conf");
 
 	/* # Allow for more PIDs
	# (to reduce rollover problems);
	# may break some programs 32768 */
 system("echo -e 'kernel.pid_max = 65536' >> /etc/sysctl.d/99-custom.conf");
 
 	/* Increase system IP port limits */
 system("echo -e 'net.ipv4.ip_local_port_range = 2000 65000' >> /etc/sysctl.d/99-custom.conf");


	/* # Increase TCP max buffer size setable using setsockopt()
	# net.ipv4.tcp_rmem = 4096 87380 8388608
	# net.ipv4.tcp_wmem = 4096 87380 8388608

	# Increase Linux auto tuning TCP buffer limits
	# min, default, and max number of bytes to use
	# set max to at least 4MB, or higher if you use very high BDP paths
	# Tcp Windows etc
	# net.core.rmem_max = 8388608
	# net.core.wmem_max = 8388608*/

 	/* net.core.netdev_max_backlog = 5000 */
 system("echo -e 'net.ipv4.tcp_window_scaling = 1' >> /etc/sysctl.d/99-custom.conf");

	/* Disable IPv6 */
 system("echo -e 'net.ipv6.conf.all.disable_ipv6 = 1' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv6.conf.enp4s0.disable_ipv6 = 1' >> /etc/sysctl.d/99-custom.conf");

 	/* Preventing link TOCTOU vulnerabilities*/
 system("echo -e 'fs.protected_hardlinks = 1' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'fs.protected_symlinks = 1' >> /etc/sysctl.d/99-custom.conf");

 	/* Hide kernel symbol addresses */
 system("echo -e 'kernel.kptr_restrict = 1' >> /etc/sysctl.d/99-custom.conf");

 	/*# Improving Performance reuse/recycle time-wait sockets*/
 system("echo -e 'net.ipv4.tcp_tw_reuse = 1' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'net.ipv4.tcp_tw_recycle = 1' >> /etc/sysctl.d/99-custom.conf");
 
	/* Small periodic system freezes */
 system("echo -e 'vm.dirty_background_bytes = 4194304' >> /etc/sysctl.d/99-custom.conf");
 system("echo -e 'vm.dirty_bytes = 4194304' >> /etc/sysctl.d/99-custom.conf");

}
