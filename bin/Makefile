#	From: @(#)Makefile	8.1 (Berkeley) 5/31/93
# $FreeBSD: src/bin/Makefile,v 1.28.2.2.6.1 2012/03/03 06:15:13 kensmith Exp $

.include <bsd.own.mk>

SUBDIR= cat \
	chflags \
	chio \
	chmod \
	cp \
	${_csh} \
	date \
	dd \
	df \
	domainname \
	echo \
	ed \
	expr \
	getfacl \
	hostname \
	kenv \
	kill \
	ln \
	ls \
	mkdir \
	mv \
	pax \
	pkill \
	ps \
	pwait \
	pwd \
	${_rcp} \
	realpath \
	rm \
	${_rmail} \
	rmdir \
	setfacl \
	sh \
	sleep \
	stty \
	sync \
	test \
	uuidgen

.if ${MK_RCMDS} != "no"
_rcp=	rcp
.endif

.if ${MK_SENDMAIL} != "no"
_rmail=	rmail
.endif

.if ${MK_TCSH} != "no"
_csh=	csh
.endif

.include <bsd.subdir.mk>
