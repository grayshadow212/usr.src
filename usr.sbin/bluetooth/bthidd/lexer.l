%{
/*
 * lexer.l
 */

/*-
 * Copyright (c) 2006 Maksim Yevmenkin <m_evmenkin@yahoo.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id: lexer.l,v 1.3 2006/09/07 21:06:53 max Exp $
 * $FreeBSD: src/usr.sbin/bluetooth/bthidd/lexer.l,v 1.3.10.1.8.1 2012/03/03 06:15:13 kensmith Exp $
 */

#include <bluetooth.h>
#include <stdlib.h>
#include "parser.h"

	int	yylex	(void);
%}

%option yylineno noyywrap nounput

delim				[ \t\n]
ws				{delim}+
empty				{delim}*
comment				\#.*

hexdigit			[0-9a-fA-F]
hexbyte				{hexdigit}{hexdigit}?

device_word			device
bdaddr_word			bdaddr
control_psm_word		control_psm
interrupt_psm_word		interrupt_psm
reconnect_initiate_word		reconnect_initiate
battery_power_word		battery_power
normally_connectable_word	normally_connectable
hid_descriptor_word		hid_descriptor
true_word			true
false_word			false

bdaddrstring			{hexbyte}:{hexbyte}:{hexbyte}:{hexbyte}:{hexbyte}:{hexbyte}
hexbytestring			0x{hexbyte}

%%

\;				return (';');
\:				return (':');
\{				return ('{');
\}				return ('}');

{ws}				;
{empty}				;
{comment}			;

{device_word}			return (T_DEVICE);
{bdaddr_word}			return (T_BDADDR);
{control_psm_word}		return (T_CONTROL_PSM);
{interrupt_psm_word}		return (T_INTERRUPT_PSM);
{reconnect_initiate_word}	return (T_RECONNECT_INITIATE);
{battery_power_word}		return (T_BATTERY_POWER);
{normally_connectable_word}	return (T_NORMALLY_CONNECTABLE);
{hid_descriptor_word}		return (T_HID_DESCRIPTOR);
{true_word}			return (T_TRUE);
{false_word}			return (T_FALSE);

{bdaddrstring}			{
				return (bt_aton(yytext, &yylval.bdaddr)?
						T_BDADDRSTRING : T_ERROR);
				}

{hexbytestring}			{
				char	*ep;

				yylval.num = strtoul(yytext, &ep, 16);

				return (*ep == '\0'? T_HEXBYTE : T_ERROR);
				}

.				return (T_ERROR);

%%

