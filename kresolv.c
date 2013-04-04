#include <linux/module.h>
#include <linux/fs.h>
#include <linux/fs_stack.h>
#include <linux/fs_struct.h>

#include "kresolv.h"

static unsigned long flexfs_kallsyms = KALLSYMS_LOOKUP_NAME;
module_param_named(kallsyms_lookup_name, flexfs_kallsyms, ulong, 0444);

void *kresolv(const char *name)
{
  return (void *)((unsigned long (*)(const char *))flexfs_kallsyms)(name);
}

_f_drop_pagecache_sb f_drop_pagecache_sb;
_f_shrink_slab f_shrink_slab;
_f_iterate_supers f_iterate_supers;

#define K(prefix, s) prefix ## s = kresolv(#s);\
  printk(KERN_INFO "resolved %s%s to %p\n", #prefix, #s, prefix ## s);

void kresolv_init(void)
{
  printk(KERN_INFO "kallsyms_lookup_name is at address %lx\n", flexfs_kallsyms);
  K(f_, drop_pagecache_sb);
  K(f_, shrink_slab);
  K(f_, iterate_supers);
}
