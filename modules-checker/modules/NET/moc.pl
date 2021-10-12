#!/usr/bin/perl
# Author @nu11secur1ty
use Term::ANSIColor;
use warnings;
use strict;
use diagnostics;

# all network interfaces output menu:
print color('bold blue');
print "Network modules\n";
print color('reset');

# all network interfaces
my $all_net = `lshw -c network`;
  print "$all_net\n";

# wifi interfaces output menu:
print color('bold green');
print "WIFI modules checking...\n";
print color('reset');

print color('bold red');
print "if the status is empty you will see, (wireless module status:)\n";
print "This mean that we don't have a wireless module and driver installed in to your system!\n";
	sleep 3;
print color('reset');

# wifi network interfaces
my $wifi_net = `lshw -c network 2>&1 | grep wireless`;
	print "wireless module status: $wifi_net\n";
    exit 0;
