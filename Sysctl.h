/* Do not edit this file. It was automatically generated. */

#ifndef HEADER_Sysctl
#define HEADER_Sysctl
/*
 * Inspired by :
 *      sysctl(8)   - /usr/src/sbin/sysctl
 *      kvm(3)      - /usr/src/lib/libkvm
 *      procstat(1) - /usr/src/usr.bin/procstat
 *      top(1)      - /usr/src/usr.bin/top
 *
 * Copyright (c) 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/user.h>
#include <sys/vmmeter.h>
#include <vm/vm_param.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define B2P(x) ((x) >> PAGE_SHIFT) /* bytes to pages */
#define T2J(x) (((x) * 100UL) / (stathz ? stathz : hz)) /* ticks to jiffies */
#define P2K(x) ((x) << (PAGE_SHIFT - 10))		/* pages to kbytes */


typedef struct SysctlType_ SysctlType;


typedef void * (*Sysctl_Get)(const char *name, size_t *size);

typedef int (*Sysctl_GetInt)(const char *name);
typedef long (*Sysctl_GetLong)(const char *name);
typedef unsigned int (*Sysctl_GetUnsignedInt)(const char *name);
typedef unsigned long (*Sysctl_GetUnsignedLong)(const char *name);
typedef struct xswdev * (*Sysctl_GetSwap)(const int swapdevid);
typedef size_t (*Sysctl_getAllProc)(struct kinfo_proc **data);

typedef char * (*Sysctl_getCmdline)(int pid);
typedef int (*TvToHz)(struct timeval *tv, int hz, int tick);


struct SysctlType_ {
    Sysctl_Get get;

    Sysctl_GetInt geti;
    Sysctl_GetLong getl;
    Sysctl_GetUnsignedInt getui;
    Sysctl_GetUnsignedLong getul;

    Sysctl_GetSwap getswap;
    Sysctl_getAllProc getallproc;

    Sysctl_getCmdline getcmdline;
    TvToHz tvtohz;
};













/* stolen from /usr/src/sys/kern/kern_clock.c */

extern SysctlType Sysctl;


/* stuff stolen from sysctl(8) */

/*
 * These functions uses a presently undocumented interface to the kernel
 * to walk the tree and get the type so it can print the value.
 * This interface is under work and consideration, and should probably
 * be killed with a big axe by the first person who can find the time.
 * (be aware though, that the proper interface isn't as obvious as it
 * may seem, there are various conflicting requirements.
 */



#endif
