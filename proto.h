#ifndef _PROTO_H_
#define _PROTO_H_

#define ETH_IP       0x0800
#define ETH_ARP      0x0806
#define ARP_REQUEST  0x0001
#define ARP_REPLY    0x0002
#define ARP_HARDWARE 0x0001

/*
*14字节的以太网包头
*/
typedef struct _ETHDR         
{
    unsigned char    eh_dst[ETH_ALEN];            // 目的MAC地址
    unsigned char    eh_src[ETH_ALEN];            // 源MAC地址
    unsigned short    eh_type;                    // 下层协议类型，如IP（ETHERTYPE_IP）、ARP（ETHERTYPE_ARP）等
} ETHDR, *PETHDR;

/*
*28字节的ARP头
*/
typedef struct _ARPHDR    
{
    unsigned short    arp_hdr;                //    硬件地址类型，以太网中为ARPHRD_ETHER
    unsigned short    arp_pro;                //  协议地址类型，ETHERTYPE_IP
    unsigned char    arp_hln;                //    硬件地址长度，MAC地址的长度为6
    unsigned char    arp_pln;                //    协议地址长度，IP地址的长度为4
    unsigned short    arp_opt;                //    ARP操作代码，ARPOP_REQUEST为请求，ARPOP_REPLY为响应
    unsigned char    arp_sha[ETH_ALEN];    //    源MAC地址
    unsigned long    arp_spa;                //    源IP地址
    unsigned char    arp_tha[ETH_ALEN];    //    目的MAC地址
    unsigned long    arp_tpa;                //    目的IP地址
} ARPHDR, *PARPHDR;

#endif
