#!/usr/bin/perl
# Author @nu11secur1ty
use warnings;
use strict;
use diagnostics;

print"Network modules\n";
my $all_net = `lshw -c network`;
my $wifi_net = `lshw -c network 2>&1 | grep wireless | grep driver`;
  print "$all_net\n";
  print "$wifi_net\n";
  exit 0;
