#!/usr/bin/perl
use warning;
use strict;
use diagnostics;

print"Network modules\n";
my $call_net = `lshw -c network`;
  print "$call_net\n";
  exit 0;
