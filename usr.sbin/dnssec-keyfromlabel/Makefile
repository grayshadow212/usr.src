# $FreeBSD: src/usr.sbin/dnssec-keyfromlabel/Makefile,v 1.1.2.1.8.1 2012/03/03 06:15:13 kensmith Exp $

BIND_DIR=	${.CURDIR}/../../contrib/bind9
LIB_BIND_REL=	../../lib/bind
LIB_BIND_DIR=	${.CURDIR}/${LIB_BIND_REL}
SRCDIR=		${BIND_DIR}/bin/dnssec

.include	"${LIB_BIND_DIR}/config.mk"

PROG=		dnssec-keyfromlabel

.PATH: ${SRCDIR}
SRCS+=		dnssec-keyfromlabel.c dnssectool.c

CFLAGS+=	-I${SRCDIR}/unix/include -I${SRCDIR}/include

DPADD+=		${BIND_DPADD} ${CRYPTO_DPADD} ${PTHREAD_DPADD}
LDADD+=		${BIND_LDADD} ${CRYPTO_LDADD} ${PTHREAD_LDADD}

MAN=		dnssec-keyfromlabel.8

.include <bsd.prog.mk>
