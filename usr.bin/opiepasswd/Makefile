# $FreeBSD: src/usr.bin/opiepasswd/Makefile,v 1.10.22.1.8.1 2012/03/03 06:15:13 kensmith Exp $
#
OPIE_DIST?=	${.CURDIR}/../../contrib/opie

PROG=	opiepasswd

CFLAGS+=-I${.CURDIR}/../../lib/libopie
CFLAGS+=-I${OPIE_DIST}
CFLAGS+=-DINSECURE_OVERRIDE

DPADD=	${LIBOPIE} ${LIBMD}
LDADD=	-lopie -lmd

BINOWN=	root
BINMODE=4555
PRECIOUSPROG=

.PATH:	${OPIE_DIST}

.include <bsd.prog.mk>
