# $FreeBSD: src/usr.sbin/lpr/chkprintcap/Makefile,v 1.12.36.1.8.1 2012/03/03 06:15:13 kensmith Exp $

.PATH: ${.CURDIR}/../common_source

PROG=	chkprintcap
MAN=	chkprintcap.8
SRCS=	chkprintcap.c skimprintcap.c

CFLAGS+= -I${.CURDIR}/../common_source

DPADD=	${LIBLPR}
LDADD=	${LIBLPR}

.include <bsd.prog.mk>
