#include <linux/fs.h>
#include <linux/fs_stack.h>
#include <linux/fs_struct.h>

#ifndef KRESOLV_H_
# define KRESOLV_H_

void kresolv_init(void);

void *kresolv(const char *name);

/*
 * used by flexdrop to simulate a "echo 3 > /proc/sys/vm/drop_caches"
 */
typedef void (*_f_drop_pagecache_sb)(struct super_block *sb, void *unused);
extern _f_drop_pagecache_sb f_drop_pagecache_sb;

typedef unsigned long (*_f_shrink_slab)(struct shrink_control *shrink, unsigned long nr_pages_scanned,
					unsigned long lru_pages);
extern _f_shrink_slab f_shrink_slab;

typedef void (*_f_iterate_supers)(void (*)(struct super_block *, void *), void *);
extern _f_iterate_supers f_iterate_supers;

#endif /* !KRESOLV_H_ */
