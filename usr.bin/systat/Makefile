#	@(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: src/usr.bin/systat/Makefile,v 1.20.2.2.6.1 2012/03/03 06:15:13 kensmith Exp $

.include <bsd.own.mk>

PROG=	systat
SRCS=	cmds.c cmdtab.c devs.c fetch.c iostat.c keyboard.c main.c \
	mbufs.c netcmds.c netstat.c pigs.c swap.c icmp.c \
	mode.c ip.c tcp.c \
	vmstat.c convtbl.c ifcmds.c ifstat.c

.if ${MK_INET6_SUPPORT} != "no"
SRCS+=	icmp6.c ip6.c
CFLAGS+= -DINET6
.endif

DPADD=	${LIBCURSES} ${LIBM} ${LIBDEVSTAT} ${LIBKVM}
LDADD=	-lcursesw -lm -ldevstat -lkvm

.include <bsd.prog.mk>
