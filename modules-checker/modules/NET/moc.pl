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
print color('bold blue');
print "WIFI modules\n";
print color('reset');

# wifi network interfaces
my $wifi_net = `lshw -c network 2>&1 | grep wireless | grep driver`;
  print "$wifi_net\n";
    
    exit 0;
