# $Id: Makefile,v 1.2 2004/02/13 21:44:41 max Exp $
# $FreeBSD: src/usr.sbin/bluetooth/bthidcontrol/Makefile,v 1.1.30.1.8.1 2012/03/03 06:15:13 kensmith Exp $

.PATH:	${.CURDIR}/../bthidd

PROG=		bthidcontrol
MAN=		bthidcontrol.8
SRCS=		bthidcontrol.c hid.c lexer.l  parser.y sdp.c
WARNS?=		1
CFLAGS+=	-DBTHIDCONTROL=1 -I${.CURDIR}/../bthidd

DPADD=		${LIBBLUETOOTH} ${LIBSDP} ${LIBUSBHID}
LDADD=		-lbluetooth -lsdp -lusbhid

.include <bsd.prog.mk>
