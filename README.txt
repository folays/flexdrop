root@winterfell:~/flexdrop# lsmod | grep flex
root@winterfell:~/flexdrop# free -m
[...]
root@winterfell:~/flexdrop# ./insert.pl -verbose=0 -min-mb=5000
-> insmod flexdrop.ko kallsyms_lookup_name=0xffffffff810b6c40 verbose=0 min_mb=5000
root@winterfell:~/flexdrop# free -m
[...]

Now you will still be able to SSH on your server, ZFS won't anymore eat all your memory. Enjoy!

Beware:

Some functions needed to do the equivalent of a "echo 3 > /proc/sys/vm/drop_cache" but at a quite pace
 are not exported by the Linux Kernel module API.
To use those needed functions, flexdrop will resolve some function symbols normally private using the
 kernel function "kallsyms_lookup_name" which is also not exported.
To use "kallsyms_lookup_name", the insert.pl script will resolve it's address from /proc/kallsyms and
 will pass it to the flexdrop kernel module parameters...

The remove (rmmod flexdrop) is safe, ie. it will unload cleanly.
