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
    
    sscanf(mac_str.c_str(), "%x-%x-%x-%x-%x-%x", &ret[0], &ret[1], &ret[2], &ret[3], &ret[4], &ret[5]);
    
	return ret;
}

void printAllDevs()
{
    pcap_if_t *alldevs;
    pcap_if_t *d;
    int i = 0;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    printf("NIC List:\n");
    
    /* 获取本地机器设备列表 */
    if (pcap_findalldevs(&alldevs, errbuf) == -1)
    {
        fprintf(stderr,"Error in pcap_findalldevs_ex: %s\n", errbuf);
        return;
    }
    
    /* 打印列表 */
    for(d = alldevs; d != NULL; d= d->next)
    {
        printf("%d. %s", ++i, d->name);
        if (d->description)
            printf(" (%s)\n", d->description);
        else
            printf(" (No description available)\n");
    }
    
    if (i == 0)
    {
        printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
        return;
    } else {
        printf("\n");
    }
    
    /* 不再需要设备列表了，释放它 */
    pcap_freealldevs(alldevs);
}

#endif