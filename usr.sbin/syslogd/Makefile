#	@(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: src/usr.sbin/syslogd/Makefile,v 1.14.2.1.8.1 2012/03/03 06:15:13 kensmith Exp $

.include <bsd.own.mk>

.PATH: ${.CURDIR}/../../usr.bin/wall

PROG=	syslogd
MAN=	syslog.conf.5 syslogd.8
SRCS=	syslogd.c ttymsg.c

DPADD=	${LIBUTIL}
LDADD=	-lutil

WARNS?=	3

.if ${MK_INET6_SUPPORT} != "no"
CFLAGS+= -DINET6
.endif

CFLAGS+= -I${.CURDIR}/../../usr.bin/wall

.include <bsd.prog.mk>
