# $FreeBSD: src/usr.bin/nslookup/Makefile,v 1.7.10.1.8.1 2012/03/03 06:15:13 kensmith Exp $

BIND_DIR=	${.CURDIR}/../../contrib/bind9
LIB_BIND_REL=	../../lib/bind
LIB_BIND_DIR=	${.CURDIR}/${LIB_BIND_REL}
SRCDIR=		${BIND_DIR}/bin/dig

.include	"${LIB_BIND_DIR}/config.mk"

PROG=		nslookup

.PATH: ${SRCDIR}
SRCS+=		dighost.c nslookup.c

CFLAGS+=	-I${SRCDIR}/include
CFLAGS+=	-I${BIND_DIR}/lib/isc/${ISC_ATOMIC_ARCH}/include

DPADD+=		${BIND_DPADD} ${CRYPTO_DPADD} ${PTHREAD_DPADD}
LDADD+=		${BIND_LDADD} ${CRYPTO_LDADD} ${PTHREAD_LDADD}

MANFILTER=	sed -e "s@^host \[server\]@\\\fBhost\\\fR \\\fI[server]\\\fR@"

.include <bsd.prog.mk>
