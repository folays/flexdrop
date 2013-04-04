#!/usr/bin/perl -w

use strict;
use warnings FATAL => qw(uninitialized);

use Getopt::Long qw(:config no_auto_abbrev require_order);

my %long_opts = (verbose => 1, min_mb => 10);
GetOptions("verbose=i" => \$long_opts{verbose},
	   "min_mb=i" => \$long_opts{min_mb},
    ) or die "bad options";

sub run()
{
    printf "-> %s\n", join(" ", @_);
    return system(@_);
}

do { !&run(qw(rmmod flexdrop.ko)) or die } if -e "/sys/module/flexdrop";

chomp (my $kallsyms = `grep 'T kallsyms_lookup_name\$' /proc/kallsyms | cut -d\\  -f1`);
!&run(qw(insmod flexdrop.ko), "kallsyms_lookup_name=0x$kallsyms",
      "verbose=$long_opts{verbose}",
      "min_mb=$long_opts{min_mb}",
    ) or die;
