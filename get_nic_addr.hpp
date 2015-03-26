/**
 * Copyright (C) 2014 Shindo
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __GET_NIC_ADDR_HPP__
#define __GET_NIC_ADDR_HPP__
 
#include <stdio.h>
#include <pcap.h>
#include <windows.h>
#include <iphlpapi.h>
#undef WIN32

#if defined(WIN32)
#include <windows.h>
#include <Iphlpapi.h>
#elif defined(__APPLE__)
#include <sys/types.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#elif defined(LINUX) || defined(linux)
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#endif

std::vector<uint8_t> get_mac_address(std::string mac_str)
{
	std::vector<uint8_t> ret(6, 0);
    
    sscanf(mac_str.c_str(), "%x:%x:%x:%x:%x:%x", &ret[0], &ret[1], &ret[2], &ret[3], &ret[4], &ret[5]);
    
	return ret;
}

void SelectNIC(int id, std::string &nic, std::string &mac, std::string &ip)
{
    printf("\nNIC List:\n");
    
	PIP_ADAPTER_INFO pIpAdapterInfo  = (PIP_ADAPTER_INFO)malloc(sizeof(IP_ADAPTER_INFO));
	unsigned long stSize = sizeof(IP_ADAPTER_INFO);
	int nRel = GetAdaptersInfo(pIpAdapterInfo,&stSize);
    int num = 0;

	if (ERROR_BUFFER_OVERFLOW == nRel) {
		free(pIpAdapterInfo);
		//重新申请内存
		pIpAdapterInfo = (PIP_ADAPTER_INFO)malloc(stSize);
		nRel=GetAdaptersInfo(pIpAdapterInfo,&stSize); 
	}

	if (ERROR_SUCCESS == nRel) {
		num ++;

		while (pIpAdapterInfo) {
			if (id == num)
			{
				int i = pIpAdapterInfo->AddressLength - 6;
				char tmpMac[18];
				sprintf(tmpMac, "%02X:%02X:%02X:%02X:%02X:%02X", pIpAdapterInfo->Address[i], pIpAdapterInfo->Address[i+1], pIpAdapterInfo->Address[i+2],
					pIpAdapterInfo->Address[i+3], pIpAdapterInfo->Address[i+4], pIpAdapterInfo->Address[i+5]);
				mac = tmpMac;
				
				if (strcmp(pIpAdapterInfo->IpAddressList.IpAddress.String, "") != 0)
				{
					ip = pIpAdapterInfo->IpAddressList.IpAddress.String;
				}

				nic = "\\Device\\NPF_";
				nic += pIpAdapterInfo->AdapterName;

				printf("*");
			}
			else
			{
				printf(" ");
			}

			printf("%d. %s\n", num, pIpAdapterInfo->Description);
			pIpAdapterInfo = pIpAdapterInfo->Next;
			num ++;
		}
	}

	//释放内存空间
	if (pIpAdapterInfo)
	{
		free (pIpAdapterInfo);
	}
    
    if (num == 0)
    {
        printf("No interfaces found!\n");
    }
    
    printf("\n");
}

#endif