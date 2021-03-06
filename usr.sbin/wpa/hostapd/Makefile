# $FreeBSD: src/usr.sbin/wpa/hostapd/Makefile,v 1.7.2.1.8.1 2012/03/03 06:15:13 kensmith Exp $

.include "${.CURDIR}/../Makefile.inc"

.PATH.c:${HOSTAPD_DISTDIR} \
	${WPA_DISTDIR}/src/eap_server \
	${WPA_DISTDIR}/src/radius \

PROG=	hostapd
SRCS=	accounting.c aes.c aes_wrap.c ap_list.c beacon.c common.c \
	config.c ctrl_iface.c drivers.c eapol_sm.c eap.c eap_common.c \
	eap_identity.c eap_methods.c eloop.c hostapd.c \
	hw_features.c ieee802_11.c ieee802_11_common.c ieee802_11_auth.c \
	ieee802_1x.c ip_addr.c md5.c mlme.c pmksa_cache.c radius.c \
	radius_client.c rc4.c sha1.c sta_info.c vlan_init.c wme.c \
	wpa.c wpa_auth_ie.c wpa_common.c wpa_debug.c wpabuf.c
SRCS+=	l2_packet.c driver_freebsd.c os_unix.c

MAN=	hostapd.8 hostapd.conf.5

.if ${MK_EXAMPLES} != "no"
FILESDIR= ${SHAREDIR}/examples/hostapd
.PATH:	${HOSTAPD_DISTDIR}
FILES=	hostapd.conf hostapd.eap_user hostapd.wpa_psk
.endif

CFLAGS+= -I${HOSTAPD_DISTDIR}

CFLAGS+= -DCONFIG_DRIVER_BSD
CFLAGS+= -DCONFIG_DRIVER_RADIUS_ACL
.if ${MK_INET6} != "no"
CFLAGS+= -DCONFIG_IPV6
.endif
CFLAGS+= -g
DPADD+=	${LIBPCAP}
LDADD+=	-lpcap

# User customizations for wpa_supplicant/hostapd build environment
CFLAGS+=${HOSTAPD_CFLAGS}
#DPADD+=${HOSTAPD_DPADD}
LDADD+=${HOSTAPD_LDADD}
#LDFLAGS+=${HOSTAPD_LDFLAGS}

.if !empty(CFLAGS:M*-DEAP_SERVER)
#SRCS+=	eap.c eap_methods.c eap_identity.c

.if ${MK_OPENSSL} != "no" && !defined(RELEASE_CRUNCH)

CFLAGS+=-DEAP_TLS -DEAP_PEAP -DEAP_MSCHAPv2 -DEAP_PSK \
	-DEAP_TLS_FUNCS -DEAP_TLS_OPENSSL
SRCS+=	crypto_openssl.c
SRCS+=	eap_tls.c eap_peap.c eap_peap_common.c eap_mschapv2.c \
	eap_psk.c eap_psk_common.c \
	eap_tls_common.c tls_openssl.c ms_funcs.c chap.c

CFLAGS+=-DEAP_TTLS -DEAP_MD5
SRCS+=	eap_ttls.c eap_md5.c

.if !empty(CFLAGS:M*-DEAP_GTC)
SRCS+=	eap_gtc.c
.endif

.if !empty(CFLAGS:M*-DEAP_AKA)
NEED_SIM_COMMON=	true
SRCS+=	eap_aka.c
.endif

.if !empty(CFLAGS:M*-DEAP_SIM)
NEED_SIM_COMMON=	true
SRCS+=	eap_sim.c
.endif

.if defined(NEED_SIM_COMMON)
SRCS+=	eap_sim_common.c eap_sim_db.c
.endif

.if !empty(CFLAGS:M*-DEAP_GPSK)
CFLAGS+=-DEAP_GPSK_SHA256
SRCS+=	eap_gpsk.c eap_gpsk_common.c
NEED_SHA256=	true
.endif

.if !empty(CFLAGS:M*-DEAP_PAX)
SRCS+=	eap_pax.c eap_pax_common.c
.endif

.if !empty(CFLAGS:M*-DEAP_SAKE)
SRCS+=	eap_sake.c eap_sake_common.c
.endif

DPADD+= ${LIBSSL} ${LIBCRYPTO}
LDADD+= -lssl -lcrypto
.else
NEED_TLS_NONE=	true
.endif

.else
NEED_TLS_NONE=	true
.endif

.if defined(NEED_SHA256)
CFLAGS+=-DINTERNAL_SHA256
SRCS+=	sha256.c
.endif

.if defined(NEED_TLS_NONE)
CFLAGS+= -DEAP_TLS_NONE
CFLAGS+= -DINTERNAL_AES
CFLAGS+= -DINTERNAL_SHA1
CFLAGS+= -DINTERNAL_MD5
SRCS+=	tls_none.c
.endif

.include <bsd.prog.mk>
