#ifndef _PROTO_H_
#define _PROTO_H_

#define ETH_IP       0x0800
#define ETH_ARP      0x0806
#define ARP_REQUEST  0x0001
#define ARP_REPLY    0x0002
#define ARP_HARDWARE 0x0001

/*
*14�ֽڵ���̫����ͷ
*/
typedef struct _ETHDR         
{
    unsigned char    eh_dst[ETH_ALEN];            // Ŀ��MAC��ַ
    unsigned char    eh_src[ETH_ALEN];            // ԴMAC��ַ
    unsigned short    eh_type;                    // �²�Э�����ͣ���IP��ETHERTYPE_IP����ARP��ETHERTYPE_ARP����
} ETHDR, *PETHDR;

/*
*28�ֽڵ�ARPͷ
*/
typedef struct _ARPHDR    
{
    unsigned short    arp_hdr;                //    Ӳ����ַ���ͣ���̫����ΪARPHRD_ETHER
    unsigned short    arp_pro;                //  Э���ַ���ͣ�ETHERTYPE_IP
    unsigned char    arp_hln;                //    Ӳ����ַ���ȣ�MAC��ַ�ĳ���Ϊ6
    unsigned char    arp_pln;                //    Э���ַ���ȣ�IP��ַ�ĳ���Ϊ4
    unsigned short    arp_opt;                //    ARP�������룬ARPOP_REQUESTΪ����ARPOP_REPLYΪ��Ӧ
    unsigned char    arp_sha[ETH_ALEN];    //    ԴMAC��ַ
    unsigned long    arp_spa;                //    ԴIP��ַ
    unsigned char    arp_tha[ETH_ALEN];    //    Ŀ��MAC��ַ
    unsigned long    arp_tpa;                //    Ŀ��IP��ַ
} ARPHDR, *PARPHDR;

#endif
