/*
   Samba Unix/Linux SMB client library
   net ads cldap functions
   Copyright (C) 2001 Andrew Tridgell (tridge@samba.org)
   Copyright (C) 2003 Jim McDonough (jmcd@us.ibm.com)
   Copyright (C) 2008 Guenther Deschner (gd@samba.org)
   Copyright (C) 2009 Stefan Metzmacher (metze@samba.org)

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _LIBADS_CLDAP_H_
#define _LIBADS_CLDAP_H_

#include "../libcli/netlogon/netlogon.h"

/* The following definitions come from libads/cldap.c  */

bool check_cldap_reply_required_flags(uint32_t ret_flags,
				      uint32_t req_flags);

struct tevent_req *cldap_multi_netlogon_send(
	TALLOC_CTX *mem_ctx, struct tevent_context *ev,
	const struct tsocket_address * const *servers,
	int num_servers,
	const char *domain, const char *hostname, unsigned ntversion,
	int min_servers);
NTSTATUS cldap_multi_netlogon_recv(
	struct tevent_req *req, TALLOC_CTX *mem_ctx,
	struct netlogon_samlogon_response ***responses);
NTSTATUS cldap_multi_netlogon(
	TALLOC_CTX *mem_ctx,
	const struct tsocket_address * const *servers,
	int num_servers,
	const char *domain, const char *hostname, unsigned ntversion,
	int min_servers, struct timeval timeout,
	struct netlogon_samlogon_response ***responses);

bool ads_cldap_netlogon(TALLOC_CTX *mem_ctx,
			struct sockaddr_storage *ss,
			const char *realm,
			uint32_t nt_version,
			struct netlogon_samlogon_response **reply);
bool ads_cldap_netlogon_5(TALLOC_CTX *mem_ctx,
			  struct sockaddr_storage *ss,
			  const char *realm,
			  struct NETLOGON_SAM_LOGON_RESPONSE_EX *reply5);

#endif /* _LIBADS_CLDAP_H_ */
