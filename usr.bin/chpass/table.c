/*-
 * Copyright (c) 1990, 1993, 1994
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
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
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

#if 0
#ifndef lint
static const char sccsid[] = "@(#)table.c	8.3 (Berkeley) 4/2/94";
#endif /* not lint */
#endif
#include <sys/cdefs.h>
__FBSDID("$FreeBSD: src/usr.bin/chpass/table.c,v 1.10.34.1.8.1 2012/03/03 06:15:13 kensmith Exp $");

#include <sys/types.h>
#include <stddef.h>
#include "chpass.h"

char e1[] = ": ";
char e2[] = ":,";

ENTRY list[] = {
	{ "login",		p_login,  1,   5, e1,   NULL },
	{ "password",		p_passwd, 1,   8, e1,   NULL },
	{ "uid",		p_uid,    1,   3, e1,   NULL },
	{ "gid",		p_gid,    1,   3, e1,   NULL },
	{ "class",		p_class,  1,   5, e1,   NULL },
	{ "change",		p_change, 1,   6, NULL, NULL },
	{ "expire",		p_expire, 1,   6, NULL, NULL },
#ifdef RESTRICT_FULLNAME_CHANGE		/* do not allow fullname changes */
	{ "full name",		p_gecos,  1,   9, e2,   NULL },
#else
	{ "full name",		p_gecos,  0,   9, e2,   NULL },
#endif
	{ "office phone",	p_gecos,  0,  12, e2,   NULL },
	{ "home phone",		p_gecos,  0,  10, e2,   NULL },
	{ "office location",	p_gecos,  0,  15, e2,   NULL },
	{ "other information",	p_gecos,  0,  11, e1,   NULL },
	{ "home directory",	p_hdir,   1,  14, e1,   NULL },
	{ "shell",		p_shell,  0,   5, e1,   NULL },
	{ NULL, NULL, 0, 0, NULL, NULL },
};
