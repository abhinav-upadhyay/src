/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _ACL_COMMON_H
#define _ACL_COMMON_H

#pragma ident   "%Z%%M% %I% %E% SMI"


#include <sys/types.h>
#include <sys/acl.h>
#include <sys/stat.h>

#define _ACL_ACLENT_ENABLED 0x1
#define _ACL_ACE_ENABLED    0x2

#ifdef  __cplusplus
extern "C" {
	#endif

	extern ace_t trivial_acl[6];

	extern int acltrivial(const char *);
	extern void adjust_ace_pair(ace_t *pair, mode_t mode);
	extern void adjust_ace_pair_common(void *, size_t, size_t, mode_t);
	extern int ace_trivial(ace_t *acep, int aclcnt);
	extern int ace_trivial_common(void *, int,
	    uint64_t (*walk)(void *, uint64_t, int aclcnt, uint16_t *, uint16_t *,
		uint32_t *mask));
#if !defined(_KERNEL)
	extern acl_t *acl_alloc(acl_type_t);
	extern void acl_free(acl_t *aclp);
	extern int acl_translate(acl_t *aclp, int target_flavor,
	    int isdir, uid_t owner, gid_t group);
	void ksort(caddr_t v, int n, int s, int (*f)());
	int cmp2acls(void *a, void *b);

#endif /* _KERNEL */

	#ifdef  __cplusplus
}
#endif

#endif /* _ACL_COMMON_H */
