# $FreeBSD: src/usr.sbin/kldxref/Makefile,v 1.11.2.1.8.1 2012/03/03 06:15:13 kensmith Exp $

PROG=	kldxref
MAN=	kldxref.8
SRCS=	kldxref.c ef.c ef_obj.c

WARNS?=	2
CFLAGS+=-fno-strict-aliasing

.if exists(ef_${MACHINE_ARCH}.c)
SRCS+=	ef_${MACHINE_ARCH}.c
.else
SRCS+=	ef_nop.c
.endif

.include <bsd.prog.mk>
