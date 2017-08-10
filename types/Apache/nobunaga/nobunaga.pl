#!/usr/bin/perl
#copyright @nu11secur1ty
use strict;
use warnings;

print "Type Your path of root doc on your Apache...\n";
    my $dir = <STDIN>;
    my $inst = `cp .htaccess $dir`;
print "Type the real path of your httpd.conf...\n";    
    my $httpd = <STDIN>;
    my $inst_httpd = `cp httpd.conf $httpd`;
print "All is done\n";


