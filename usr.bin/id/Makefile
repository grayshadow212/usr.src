#	@(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: src/usr.bin/id/Makefile,v 1.12.10.1.8.1 2012/03/03 06:15:13 kensmith Exp $

.include <bsd.own.mk>

PROG=	id
WARNS?=	6
LINKS=	${BINDIR}/id ${BINDIR}/groups
LINKS+=	${BINDIR}/id ${BINDIR}/whoami
MAN=	id.1 groups.1 whoami.1

.if ${MK_AUDIT} != "no"
CFLAGS+=	-DUSE_BSM_AUDIT
DPADD+=	${LIBBSM}
LDADD+=	-lbsm
.endif

.include <bsd.prog.mk>
