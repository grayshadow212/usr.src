# $Id: Makefile,v 1.1 2003/09/08 02:27:27 max Exp $
# $FreeBSD: src/usr.sbin/bluetooth/sdpcontrol/Makefile,v 1.1.32.1.8.1 2012/03/03 06:15:13 kensmith Exp $

PROG=		sdpcontrol
MAN=		sdpcontrol.8
SRCS=		sdpcontrol.c search.c
WARNS?=		2

DPADD=		${LIBBLUETOOTH} ${LIBSDP}
LDADD=		-lbluetooth -lsdp

.include <bsd.prog.mk>
