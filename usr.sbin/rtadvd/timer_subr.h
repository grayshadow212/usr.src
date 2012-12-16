/*	$FreeBSD: src/usr.sbin/rtadvd/timer_subr.h,v 1.1.4.2.2.1 2012/03/03 06:15:13 kensmith Exp $	*/
/*	$KAME: timer.h,v 1.5 2002/05/31 13:30:38 jinmei Exp $	*/

/*
 * Copyright (C) 1998 WIDE Project.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#define	SSBUFLEN	1024
#define MILLION 1000000

/* a < b */
#define	TIMEVAL_LT(a, b)				\
		(((a)->tv_sec < (b)->tv_sec) ||		\
		    (((a)->tv_sec == (b)->tv_sec) &&	\
		    ((a)->tv_usec < (b)->tv_usec)))

/* a <= b */
#define	TIMEVAL_LEQ(a, b)				\
		(((a)->tv_sec < (b)->tv_sec) ||		\
		    (((a)->tv_sec == (b)->tv_sec) &&	\
		    ((a)->tv_usec <= (b)->tv_usec)))

#define	TIMEVAL_EQUAL(a,b)				\
		(((a)->tv_sec == (b)->tv_sec) &&	\
		    ((a)->tv_usec == (b)->tv_usec))

struct timeval	*rtadvd_timer_rest(struct rtadvd_timer *);
void		TIMEVAL_ADD(struct timeval *, struct timeval *,
		    struct timeval *);
void		TIMEVAL_SUB(struct timeval *, struct timeval *,
		    struct timeval *);
char		*sec2str(uint32_t, char *buf);
