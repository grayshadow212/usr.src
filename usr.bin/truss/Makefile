# $FreeBSD: src/usr.bin/truss/Makefile,v 1.25.2.1.8.1 2012/03/03 06:15:13 kensmith Exp $

WARNS?= 6
NO_WERROR=
PROG=	truss
SRCS=	main.c setup.c syscalls.c syscalls.h ioctl.c ${MACHINE_ARCH}-fbsd.c

CFLAGS+= -I${.CURDIR} -I.
CLEANFILES= syscalls.master syscalls.h ioctl.c

.SUFFIXES: .master

syscalls.master:	${.CURDIR}/../../sys/kern/syscalls.master
	cat ${.ALLSRC} > syscalls.master

syscalls.h:	syscalls.master
	/bin/sh ${.CURDIR}/../../sys/kern/makesyscalls.sh syscalls.master \
		${.CURDIR}/i386.conf

ioctl.c: ${.CURDIR}/../kdump/mkioctls
	sh ${.CURDIR}/../kdump/mkioctls ${DESTDIR}/usr/include > ${.TARGET}

.if ${MACHINE_ARCH} == "i386"
SRCS+=	i386-linux.c linux_syscalls.h
CLEANFILES+=i386l-syscalls.master linux_syscalls.h

i386l-syscalls.master:	${.CURDIR}/../../sys/i386/linux/syscalls.master
	cat ${.ALLSRC} > ${.TARGET}

linux_syscalls.h:	i386l-syscalls.master
	/bin/sh ${.CURDIR}/../../sys/kern/makesyscalls.sh ${.ALLSRC} \
		${.CURDIR}/i386linux.conf
.endif

.if ${MACHINE_ARCH} == "amd64"
SRCS+=	amd64-linux32.c linux32_syscalls.h
CLEANFILES+=amd64l32-syscalls.master linux32_syscalls.h

amd64l32-syscalls.master: ${.CURDIR}/../../sys/amd64/linux32/syscalls.master
	cat ${.ALLSRC} > ${.TARGET}

linux32_syscalls.h:	amd64l32-syscalls.master
	/bin/sh ${.CURDIR}/../../sys/kern/makesyscalls.sh ${.ALLSRC} \
		${.CURDIR}/amd64linux32.conf

SRCS+=	amd64-fbsd32.c freebsd32_syscalls.h
CLEANFILES+=fbsd32-syscalls.master freebsd32_syscalls.h

fbsd32-syscalls.master: ${.CURDIR}/../../sys/compat/freebsd32/syscalls.master
	cat ${.ALLSRC} > ${.TARGET}

freebsd32_syscalls.h:	fbsd32-syscalls.master
	/bin/sh ${.CURDIR}/../../sys/kern/makesyscalls.sh ${.ALLSRC} \
		${.CURDIR}/fbsd32.conf
.endif

.include <bsd.prog.mk>
