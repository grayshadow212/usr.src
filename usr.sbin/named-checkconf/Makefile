# $FreeBSD: src/usr.sbin/named-checkconf/Makefile,v 1.6.10.1.8.1 2012/03/03 06:15:13 kensmith Exp $

BIND_DIR=	${.CURDIR}/../../contrib/bind9
LIB_BIND_REL=	../../lib/bind
LIB_BIND_DIR=	${.CURDIR}/${LIB_BIND_REL}
SRCDIR=		${BIND_DIR}/bin/check

.include	"${LIB_BIND_DIR}/config.mk"

PROG=		named-checkconf

.PATH: ${SRCDIR}
SRCS+=		named-checkconf.c check-tool.c

CFLAGS+=	-I${LIB_BIND_DIR}

DPADD+=		${BIND_DPADD} ${CRYPTO_DPADD} ${PTHREAD_DPADD}
LDADD+=		${BIND_LDADD} ${CRYPTO_LDADD} ${PTHREAD_LDADD}

MAN=		named-checkconf.8

MANFILTER=	sed -e "s@/etc/named\.conf@/etc/namedb/named.conf@g"

.include <bsd.prog.mk>
