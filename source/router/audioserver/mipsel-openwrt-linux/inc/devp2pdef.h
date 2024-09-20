/** \file devp2pdef.h
 * \copyright Copyright (c) 2017 by HangZhou Ezviz Network Co., Ltd. All Right Reserved.
 * \brief This file describes all data structure that up-level needs.
 * 
 * \author Jianglin Yang
 * \date   2017/03/06
 *
 * \code history 
 *          [2017/03/06] Jianglin Yang
 *          Initialize the file
 *
 *          [2017/03/06] Jianglin Yang
 *          Add device serial number in DevParam data structure.
 *          Add more error definition get from P2P Server, and common error.

 *
 *          [2017/03/29] Jianglin Yang
 *          Add P2PPlayBusiness structure for callback function fnSynCheckDevStatus().
 *
 *          [2017/06/07] Jianglin Yang
 *          Add data structure for UDT performance(bandwidth now).
 *
 *          [2017/06/12] Jianglin Yang
 *          Add log level parameter in callback function fnDevP2PLog() for better log information control.
 *
 *          [2017/09/20] Jianglin Yang
 *          Add statistic data structure and notify type for p2p preconnection and preview.
 *
 *          [2018/03/14] Jianglin Yang
 *          Add callback function fnSynUpdateP2PKey to support update P2P Link key
 *          Add data structure and callback function fnSynTransBusiness to support transfer business, like ptz-control
 * 
 *          [2018/03/26] Jianglin Yang
 *          Change length of user id to avoid user-id duplication on server side
 *
 *          [2018/03/29] Jianglin Yang
 *          Change length of business transfer content, for only support maximum length 255, becuse of key-value protocol design
 *
 *          [2018/04/03] Jianglin Yang
 *          Change length of business transfer content to 1024
 *
 *          [2018/04/19] Jianglin Yang
 *          Add type definition for playback and talk. And add callback function for playback control
 *          Add playback information for playback start/stop notification
 *          Add talk data definition, and talk data notification type.
 *
 *          [2018/05/03] Jianglin Yang
 *          Add type definition for download record file
 *          Add notification P2PV3_MODULE_RESET for resume devp2p sdk in case of communicate with P2P Server failed
 *          Add client type parameter in play session
 *
 *          [2018/05/16] Jianglin Yang
 *          Add ShareCheckInfo structure to P2PPlaySession
 *
 *          [2018/07/12] Jianglin Yang
 *          Add upnp local port for tag_DevParam
 *
 *          [2018/09/30] Jianglin Yang
 *          Add version number
 *
 *          [2018/10/29] Jianglin Yang
 *          Add parameter in SocketProperty structure to support BINDTODEVICE property setting.
 */ 

#ifndef _DEVP2PDEF_H
#define _DEVP2PDEF_H

#define DEVP2P_VERSION  "2.2.1.20220315"   ///< SDK version number, and svn check-in number

// describes all ERRORs that APIs of DevP2P module return
#define DEVP2P_ER_NoERROR                   0   // �ɹ�
#define DEVP2P_ER_ERROR                     1   // ͨ�ô��󷵻�
#define DEVP2P_ER_NULL_PTR                  2   // ���Ϊ��ָ��
#define DEVP2P_ER_INVALID_PARAS             3   // ���ֵ��Ч
#define DEVP2P_ER_OUT_OF_MEMERY             4   // �ڴ治��
#define DEVP2P_ER_NOT_SUPPORT               5   // ��֧�ֹ���
#define DEVP2P_ER_THREAD_CREATE_FAILED      6   // �̴߳���ʧ��
#define DEVP2P_ER_SOCKET_CREATE_FAILED      7   // UDP Socket����ʧ��
#define DEVP2P_ER_SOCKET_SEND_FAILED        8   // Socket Send ʧ��

#define DEVP2P_ER_INVALID_DATA_LEN          11  // ���ݳ��ȷǷ�
#define DEVP2P_ER_CRC8_NOT_EQUAL            12  // CRC8ֵ��ƥ��
#define DEVP2P_ER_INVALID_PROTOCOL          13  // ��Ч�ı���
#define DEVP2P_ER_INVALID_ATTRIBUTE         14  // ��Ч�ı�������
#define DEVP2P_ER_INVALID_TRANSFOR          15  // ��Ч��Transfor����
#define DEVP2P_ER_INVALID_IPADDR            16  // ��Ч��IP��ַ

// error definition for P2P Server communication
#define DEVP2P_ER_SERVER_NOTINIT            100 // P2P Serverδ��ʼ����Ϊ��
#define DEVP2P_ER_SERVER_UNKNOWN_ERROR      101 // P2P Server δ֪����
#define DEVP2P_ER_SERVER_PARAMS_ERROR       102 // P2P Server ��������
#define DEVP2P_ER_SERVER_PARSE_FAILED       103 // P2P Server ���Ľ�������
#define DEVP2P_ER_SERVER_NO_USER            113 // �豸δ���û�
#define DEVP2P_ER_SERVER_TICKET_EXPIRED     114 // ����ƾ֤����
#define DEVP2P_ER_SERVER_TICKET_INVALID     115 // ����ƾ֤��Ч
#define DEVP2P_ER_SERVER_NO_RESOURCE        116 // �޿���P2P����
#define DEVP2P_ER_SERVER_DISCONNECT         117 // ��P2P Server������ʱ����·�Ͽ�
#define DEVP2P_ER_SERVER_DECRYPT_FAILED     118 // ����ʧ��
#define DEVP2P_ER_SERVER_CREATE_KEY_FAILED  119 // ������Կʧ��
#define DEVP2P_ER_SERVER_UPDATE_KEY         120 // ����������Կ

// error definition for client communication
#define DEVP2P_ER_LINK_NO_RESOURCE          201 // û��Ԥ������Դ
#define DEVP2P_ER_SESSION_EXIST             202 // �ػ�uuid�Ѿ����ڣ���ʾP2P��·�Ѿ�����
#define DEVP2P_ER_LINK_INVALID              203 // P2P��·������
#define DEVP2P_ER_PLAY_NO_RESOURCE          204 // û�в�����Դ����·������
#define DEVP2P_ER_PLAY_SESSION_EXIST        205 // �ỰplaySession�Ѿ����ڣ���ʾ�Ѿ���ȡ������
#define DEVP2P_ER_PLAY_SESSION_INVALID      206 // �ỰplaySession������
#define DEVP2P_ER_UDT_CONNECT_FAILED        207 // UDT connectʧ��
#define DEVP2P_ER_KEY_VER_NOT_EQUAL         208 // P2P��·����Կ�汾��һ��
#define DEVP2P_ER_CMD_NOT_ENCRYPT           209 // ������Ϣ��δ����
#define DEVP2P_ER_CMD_DECRYPT_FAILED        210 // ������Ϣ�����ʧ��
#define DEVP2P_ER_PLAY_UDT_SEND_FAIL        211 // UDT��������ʧ��

// error definition for stream stop result
#define DEVP2P_ER_PLAY_STATUS_ERROR         301 // play UDTδ��������
#define DEVP2P_ER_LINK_STATUS_ERROR         302 // ȡ������·״̬����
#define DEVP2P_ER_CONNECT_FAILED            303 // UDT::connnect()ʧ��
#define DEVP2P_ER_UDT_STATUS_ERROR          304 // UDT��·broken\notexist\closed
#define DEVP2P_ER_NOT_RECEIVE_DATA          305 // DevApp�ϲ������쳣ֹͣ, 10s��δ�յ��κ�������
#define DEVP2P_ER_DATA_SEND_FINISH          306 // ���ݷ������

// error definition for relay module
#define DEVP2P_ER_INNER_PARAM_ERROR         401 // �ڲ���������
#define DEVP2P_ER_SET_RELAYSOCK_OPT_FAIL    402 // ����relay socket�����Գ���
#define DEVP2P_ER_CREATE_ENCRYPT_CONN_FAIL  403 // ����������������ʧ��
#define DEVP2P_ER_DECRYPT_CONN_RSP_FAIL     404 // ���ܷ�������Ӧʧ��
#define DEVP2P_ER_TCP_SEND_FAILED           405 // TCP�������ݽӿ�ʧ��
#define DEVP2P_ER_TCP_RECV_FAILED           406 // TCP��������ʧ��
#define DEVP2P_ER_BUFFER_FULL               407 // Relayģ���ڲ��Ļ�����
#define DEVP2P_ER_NO_AVAIL_LINK             408 // ��ǰ�޿��ô�����·
#define DEVP2P_ER_WRONG_PLAYSESSION         409 // Play session�쳣
#define DEVP2P_ER_CONNECT_TUNNEL_FAIL       410 // �����豸Tunnel����ʧ��
#define DEVP2P_ER_INVALID_INPUT_PARAM       411 // �������ֵ��Ч
#define DEVP2P_ER_TUNNEL_TCP_EXCEED         412 // Tunnel client socket������������
#define DEVP2P_ER_UPDATE_KEY_FAILED         413 // ������Կʧ��
#define DEVP2P_ER_INVALID_KEY               414 // ��Ч��Կ
#define DEVP2P_ER_CONNECT_RELAY_FAIED       415 // ����Relay������ʧ��
#define DEVP2P_ER_PARSE_RSP_FAIL            416 // ������������Ӧ����ʧ��
#define DEVP2P_ER_SEND_UNACK_BUFFER_FAILED  417 // ���ͻ�������δȷ�ϵ�����ʧ��
#define DEVP2P_ER_RECV_OUT_OF_ORDER         418 // �յ�����������
#define DEVP2P_ER_TUNNEL_SOCKET_EXIST       419 // playsession��Ӧ��tunnel socket�Ѿ�����
#define DEVP2P_ER_UNKNOWN_TUNNEL_PORT       420 // δ�ҵ���Ӧ�˿ڵ�Tunnel Socket
#define DEVP2P_ER_TUNNEL_SOCKET_NOT_EXIST   421 // ��·δ������Ӧ��Tunnel Socket
#define DEVP2P_ER_RELAY_THREAD_CREATE_FAILED 422 // Relayģ���̴߳���ʧ��
#define DEVP2P_ER_TUNNEL_THREADPOOL_ERROR    423 // Tunnel�����̳߳��쳣

// macro definition for string length
#define DEVP2P_SERIAL_LEN   128  ///< string length of device serial number
#define DEVP2P_USERID_LEN   32  ///< string length of user-id
#define DEVP2P_IP_LEN       32  ///< string length of ip address
#define DEVP2P_KEY_LEN      32  ///< string length of encrypte/decrypt key
#define DEVP2P_UUID_LEN     32  ///< string length of uuid
#define DEVP2P_TIME_LEN     32  ///< string length of time, format: yyyy-mm-dd hh:mm:ss,xxx
#define DEVP2P_DOMAIN_LEN   64  ///< string length of server domain name
#define DEVP2P_BIZ_LEN      64  ///< string length of stream biz
#define DEVP2P_NWCARD_LEN   64  ///< string length of network card name
#define DEVP2P_BASE64_LEN   256  ///< string length of key, contain cltpbkey, encrypted sessionkey
#define DEVP2P_TOKEN_LEN    128 ///< string length of stream token
#define DEVP2P_BUSITRAN_LEN 1024 ///< string length of business transfer content
#define DEVP2P_ERRDESC_LEN  128 ///< string length of error description
#define DEVP2P_NEW_SERIAL_LEN  128 ///< string length of new device serial number
#define DEVP2P_LID_LEN         128 ///< string length of business id


/**
 * \brief Callback function for log print, implement by up-level
 *
 * \param level [in] Log level for current log information, detail defined in DEVP2P_LOG_LEVEL.
 * \param szLog [in] Detail log information
 * \param userData [in] User data for reserved
 *
 * \return void
 */
typedef void (*fnDevP2PLog)(const int level, const char* szLog, void* userData);

/**
 * \brief Callback function asynchronous notify to up-level
 *
 * \param type [in] Notify type, detail defined in DevP2PNotify
 * \param value [in] Detail value for related notify type, error code for P2PSERVER_NEEDUPDATE,
 *                   P2PPlaySession for P2PV3_START_PREVIEW/P2PV3_STOP_PREVIEW/P2PV3_START_TALK/P2PV3_STOP_TALK/P2PV3_START_PLAYBACK/P2PV3_STOP_PLAYBACK/P2PV3_START_DOWNLOAD
 *                   P2PTalkData for P2PV3_TALK_DATA,
 *                   StatLink for P2PV3_STATISTIC_LINK, and StatPlay for P2PV3_STATISTIC_PLAY
 * \param userData [in] User data for reserved
 *
 * \return void
 */
typedef void (*fnAsynNotify)(int type, void* value, void* userData);

/**
 * \brief Callback function for up-level checking device status synchronously
 *
 * \param type [in] Request business type by client, detail defined in RequestBusiness
 * \param value [in] Detail value for request business, P2PPlayBusiness for PREVIEW, PLAYBACK, TALK
 * \param resultCode [in/out] Result code for current request business
 * \param encodeType [in/out] Audio encode type need notify client, used for TALK
 * \param userData [in] User data for reserved
 *
 * \return void
 *
 * \attention This callback function is used for checking device status. 
 *            For preview/playback/talk/download, up-level needs to check the channel whether exist, and request stream index 
 *            whether supported. And it also needs to check the client ticket whether valid.
 */
typedef void (*fnSynCheckDevStatus)(int type, void* value, int* resultCode, int* encodeType, void* userData);

/**
 * \brief Callback function for resource apply synchronously
 *
 * \param type [in] Resource type, detail defined in ResourceType
 * \param value [in] Detail value for request resource, NULL for RESOURCE_LINK, and P2PPlayBusiness for RESOURCE_PREVIEW, 
 *                   RESOURCE_PLAYBACK, RESOURCE_TALK, RESOURCE_DOWNLOAD, RESOURCE_DATATRANS
 * \param hasResource [in/out] Has resource to use or not
 * \param userData [in] User data for reserved
 *
 * \return void
 */
typedef void (*fnSynApplyResource)(int type, void* value, bool* hasResource, void* userData);

/**
 * \brief Callback function for resource return synchronously
 *
 * \param type [in] Resource type, detail defined in ResourceType
 * \param value [in] Detail value for request resource, NULL for RESOURCE_LINK, and P2PPlaySession for RESOURCE_PREVIEW,
 *                   RESOURCE_PLAYBACK, RESOURCE_TALK
 * \param userData [in] User data for reserved
 *
 * \return void
 */
typedef void (*fnSynReturnResource)(int type, void* value, void* userData);

/**
 * \brief Callback function for get updated p2p link encrypt/decrypt key synchronously
 *
 * \param keyVer [in] Key version for client used p2p link key
 * \param p2pKey [out] P2P link key need to update
 * \param keyLen [in] Length of string arrary p2pKey
 * \param userData [in] User data for reserved
 *
 * \return 0 for success, otherwise for error
 */

typedef int (*fnSynUpdateP2PKey)(const int keyVer, unsigned char* p2pKey, const int keyLen, void* userData);

/**
 * \brief Callback function for notify up-level transfer business
 *
 * \param value [in] Detail value for transfer business
 * \param rspContent [out] Detail content for response to client, need fill in by up-level
 * \param maxLen [in/out] Maximum length of string rspContent, need reset the length value by up-level
 * \param userData [in] User data for reserved
 *
 * \return 0 for success, otherwise for error
 */
typedef int (*fnSynTransBusiness)(void* value, char* rspContent, int* maxLen, void* userData);

/**
 * \brief Callback function for notify playback control information synchronously
 *
 * \param type [in] Resource type, detail defined in ControlType
 * \param value [in] Detail value for control type, default P2PPlayControlInfo
 * \param userData [in] User data for reserved
 *
 * \return 0 for success, otherwise for error
 */
typedef int (*fnSynPlaybackControl)(int type, void* value, void* userData);

/**
 * \brief Log level definition
 */
typedef enum
{
    LEVEL_NON = 0,      ///< not used level
    LEVEL_ERROR,        ///< log level for error information
    LEVEL_WARNING,      ///< log level for warning information
    LEVEL_DEBUG,        ///< log level for debug information
    LEVEL_INFO          ///< log level for info(trace) information
}DEVP2P_LOG_LEVEL;

/**
 * \brief Notify types defined for notify callback function
 */
typedef enum tag_DevP2PNotify
{
    P2PSERVER_NEEDUPDATE = 1,   ///< communicate with P2P Server failed or ticket expired 
    P2PV3_START_PREVIEW = 2,    ///< peer client request for start preview
    P2PV3_STOP_PREVIEW = 3,     ///< peer client request for stop preview
    P2PV3_START_PLAYBACK = 4,   ///< peer client request for start playback
    P2PV3_STOP_PLAYBACK = 5,    ///< peer client request for stop playback
    P2PV3_START_TALK = 6,       ///< peer client request for start talk
    P2PV3_STOP_TALK = 7,        ///< peer client request for stop talk
    P2PV3_TALK_DATA = 8,        ///< talk data send by client
    P2PV3_START_DOWNLOAD = 9,   ///< peer client request for start download record file
    P2PV3_STOP_DOWNLOAD = 10,   ///< peer client request for stop download record file
    P2PV3_MODULE_RESET = 11,    ///< need reset p2pv3 module
    P2PV3_STATISTIC_LINK = 12,  ///< statistic data for P2P link action
    P2PV3_STATISTIC_PLAY = 13,  ///< statistic data for P2P play action
    P2PV3_START_DATATRANS = 14, ///< peer client request for start data transfer for third party
    P2PV3_STOP_DATATRANS = 15,  ///< peer client request for stop data transfer for third party
    P2PV3_DATA_TRANS = 19,      ///< data transfer statistics in ezP2PCloud mode
}DevP2PNotify;

/**
 * \brief Request business types defined for device status checking callback function
 */
typedef enum tag_RequestBusiness
{
    PREVIEW = 1,    ///< preview request business
    PLAYBACK = 2,   ///< playback request business
    TALK = 3,       ///< talk request business
    DOWNLOAD = 4,   ///< record file download
    DATATRANS = 9   ///< data transfer for third party
}RequestBusiness;

/**
 * \brief Resource types, containing pre-connection and stream link resource
 */
typedef enum tag_ResourceType
{
    RESOURCE_LINK = 1,      ///< type for link resource 
    RESOURCE_PREVIEW = 2,   ///< type for preview resource 
    RESOURCE_PLAYBACK = 3,  ///< type for playback resource
    RESOURCE_TALK = 4,      ///< type for talk resource
    RESOURCE_DOWNLOAD = 5,  ///< type for download resource
    RESOURCE_DATATRANS = 9  ///< type for data transfer for third party
}ResourceType;

/**
 * \brief Playback control types
 */
typedef enum tag_ControlType
{
    PLAYBACK_PAUSE = 1,     ///< type for playback pause
    PLAYBACK_RESUME = 2,    ///< type for playback resume
    PLAYBACK_STREAMCTRL = 3,///< type for stream control
    PLAYBACK_SEEK = 4,      ///< type for playback seek
    PLAYBACK_CONTINUE = 5,  ///< type for playback continue
}ControlType;

/**
 * \brief config types
 */
typedef enum tag_ConfigType
{
    CONFIG_NATTYPE = 1,         ///< config for nattype
    CONFIG_BIGCHANNEL = 2,      ///< config for two byte channel
    CONFIG_ONEBIND = 3,         ///< config for one bind
}ConfigType;

/**
 * \brief Callback function structure
 */
typedef struct tag_CallbackFun
{
    fnAsynNotify cbfAsynNotify;                 ///< Asynchronous notify callback function to notify up-level
    fnSynCheckDevStatus cbfSynCheckDevStatus;   ///< Synchronous callback function, check device status
    fnSynApplyResource cbfSynApplyResource;     ///< Synchronous callback function, apply for resource
    fnSynReturnResource cbfSynReturnResource;   ///< Synchronous callback function, return resource
    fnSynUpdateP2PKey cbfSynUpdateP2PKey;       ///< synchronous callback function, update p2p link key
    fnSynTransBusiness cbfSynTransBusiness;     ///< synchronous callback function for transfer business, like Ptz control
    fnSynPlaybackControl cbfSynPlaybackCtrl;    ///< synchronous callback function for playback control notification
    fnDevP2PLog cbfP2PLog;                      ///< Synchronous callback function for log print
    void* userData;                             ///< User data for reserve
}CallbackFuns;

/**
 * \brief Parameter need up-level to set
 */
typedef struct tag_DevParam
{
    char devSerialNum[DEVP2P_SERIAL_LEN + 1];  ///< device's serial number
    char upnpIp[DEVP2P_IP_LEN + 1];     ///< device upnp ip address mapped by Router
    unsigned short upnpPort;            ///< device upnp port mapped by Router
    unsigned short upnpLocalPort;       ///< device upnp local port, it should not change for different device
    char localIp[DEVP2P_IP_LEN + 1];    ///< device local ip address 
    unsigned short listenPort;      ///< port used for data communication with P2P Server and Client, local port. 
                                    //   DO NOT change this port after service started.
    unsigned char  natType;         ///< device nat type in current network
}DevParam;

/**
 * \brief Parameter for udp socket properties, need up-level to set
 */
typedef struct tag_SocketProperty
{
    int udpRecvBufSize;    ///< udp receive buffer size, bytes
    int udpSendBufSize;    ///< udp send buffer size, bytes

    int udtRecvBufSize;    ///< receive buffer size of UDT, bytes
    int udtSendBufSize;    ///< send buffer size of UDT, bytes

    char networkCard[DEVP2P_NWCARD_LEN];    ///< network card name, used for SO_BINDTODEVICE setting
                                            ///< please set the length of this parameter to 0 if not used
}SocketProperty;

/**
 * \brief Parameter for udp socket properties, need up-level to set
 */
typedef struct tag_SRTPerf
{
    int     pktFlightSize;      ///< number of packets on flight
    double  mbpsBandwidth;      ///< estimated bandwidth by SRT, in Mb/s
    double  mbpsSendRate;       ///< sending rate in Mb/s
    double  msRTT;              // RTT, in milliseconds

    tag_SRTPerf()
    {
        pktFlightSize = 0;
        mbpsBandwidth = 0.0;
        mbpsSendRate = 0.0;
        msRTT = 0.0;
    }
}SRTPerf;

/**
 * \brief Encrypt key information need to get from platfrom. use aes_128_cbc algrithom for encrypt/decrypt
 */
typedef struct tag_KeyInfo
{
    unsigned char key[DEVP2P_KEY_LEN];  ///< key used to encrypt/decrypt message body while communicate with P2P Server, 
                                        //   which need to get from platform same as P2P Server
    unsigned char saltIndex;            ///< salt index, value [0, 7]
    unsigned char saltVer;              ///< salt version, only two value: 0 or 1

    tag_KeyInfo()
    {
        saltIndex = 0;
        saltVer = 0;
    }
}KeyInfo;

/**
 * \brief P2P Server Ip and Port information
 */
typedef struct tag_P2PServer
{
    char ipAddr[DEVP2P_IP_LEN + 1];     ///< ip address for p2p server
    unsigned short port;                ///< port for p2p server
}P2PServer;

/**
 * \brief Share check information
 */
typedef struct tag_ShareCheckInfo
{
    char streamToken[DEVP2P_TOKEN_LEN + 1]; ///< token information of current stream request
    char streamBiz[DEVP2P_BIZ_LEN + 1];     ///< biz information of current stream request
    int checkInterval;                      ///< check interval time for shared stream
}ShareCheckInfo;

/**
 * \brief P2P Play Session information
 */
typedef struct tag_P2PPlaySession
{
    int playSessionId;          ///< session id for play, this is an index number for play resource
    int streamSession;          ///< client created session used for preview, need to set in RTP session segment
    unsigned short channel;     ///< channel index for request stream preview
    unsigned char streamIndex;  ///< stream index for request stream preview( 1-main 2-sub), video level for playback(3-HD 2-Basic 1-Fluency)
    unsigned char clnType;      ///< client type, 1-IOS, 3-Android, 9-Studio
    ShareCheckInfo shareCheck;  ///< share check information
}P2PPlaySession;

/**
 * \brief P2P Playback video information
 */
typedef struct tag_P2PVideoInfo
{
    char startTime[DEVP2P_TIME_LEN + 1];            ///< start time of playback file
    char endTime[DEVP2P_TIME_LEN + 1];              ///< end time of playback file
}P2PVideoInfo;

/**
 * \brief P2P control information
 */
typedef struct tag_P2PControlInfo
{
    P2PPlaySession stPlaySession;
    unsigned char playbackRate;                     ///< stream control rate for playback
    char curTime[DEVP2P_TIME_LEN + 1];              ///< the osd current time of playback
    P2PVideoInfo*  pVideoInfo;                      ///< video records
    unsigned int   iVideoNum;                       ///< the number of pVideoInfo
}P2PPlayControlInfo;
    
/**
 * \brief P2P Play business information
 */
typedef struct tag_P2PPlayBusiness
{
    char userId[DEVP2P_USERID_LEN + 1];             ///< client user-id, used for share verification
    unsigned char  videoLevel;                      ///< video quality, 1-fluent, 2-balance, 3-HD
    P2PVideoInfo*  pVideoInfo;                      ///< video records
    unsigned int   iVideoNum;                       ///< the number of pVideoInfo
    char playbackSerial[DEVP2P_SERIAL_LEN + 1]; ///< device serial for playback
    char clnSessionKey[DEVP2P_BASE64_LEN + 1];  ///< client session key(base64)
    char relatedDevice[DEVP2P_NEW_SERIAL_LEN + 1];  ///< the related device serial
    char clnPublicKey[DEVP2P_BASE64_LEN + 1];  ///< client public key(base64)
    char lId[DEVP2P_LID_LEN + 1];            ///< client business unique id
    char timeStamp[DEVP2P_BASE64_LEN + 1];      ///< client operation unique id
    P2PPlaySession playSession;             ///< play session information
}P2PPlayBusiness;

/**
 * \brief P2P talk data get from client
 */
typedef struct tag_P2PTalkData
{
    int playSessionId;      ///< session id for play, this is an index number for play resource
    unsigned short channel; ///< channel index for request talk business
    char* buffer;           ///< talk buffer send by client
    int bufSize;            ///< buffer length
}P2PTalkData;


/**
 * \brief P2P talk data get from client
 */
typedef struct tag_P2PTransData
{
    int playSessionId;      ///< session id for play, this is an index number for play resource
    char* buffer;           ///< talk buffer send by client
    int bufSize;            ///< buffer length
}P2PTransData;

/**
 * \brief Statistic for P2P Preconnection information
 */
typedef struct tag_StatLink
{
    char uuid[DEVP2P_UUID_LEN + 1];         ///< pre-connection identifier
    char devSerial[DEVP2P_SERIAL_LEN + 1];  ///< device's serial number
    unsigned char clnType;      ///< client type, 1-IOS, 3-Android, 9-Studio
    unsigned char cnt;          ///< client nat type 
    unsigned char dnt;          ///< device nat type
    unsigned char linkType;     ///< link type, 0-inner, 1-upnp, 2-nat
    unsigned char compatibility;///< compatibility version
    char clnNatIp[DEVP2P_IP_LEN + 1];   ///< client nat ip address
    unsigned short clnNatPort;          ///< client nat port
    char clnInnerIp[DEVP2P_IP_LEN + 1]; ///< client inner ip address
    unsigned short clnInnerPort;        ///< client inner port
    char clnPunchIp[DEVP2P_IP_LEN + 1]; ///< client ip address while punching success
    unsigned short clnPunchPort;        ///< client nat port while punching success
    int reqCost;    ///< cost time from receiving setupreq to first punching reqest package from client
    int rspCost;    ///< cost time from receiving setupreq to first punching response package from client
    int punchCost;  ///< cost time form receiving setupreq to punch successed/failed
    int res;        ///< result code for punching
}StatLink;

/**
 * \brief Statistic for P2P Preview information
 */
typedef struct tag_StatPlay
{
    char uuid[DEVP2P_UUID_LEN + 1]; ///< pre-connection identifier
    char sbt[DEVP2P_TIME_LEN + 1];  ///< stream begin time
    char sst[DEVP2P_TIME_LEN + 1];  ///< stream stop time
    unsigned short channel;         ///< channel index for request stream preview
    unsigned char streamIndex;      ///< stream index for request stream preview
    unsigned char clnType;          ///< client type, 1-IOS, 3-Android, 9-Studio
    unsigned char busiType;         ///< business type, 1-preview, 2-playback, 3-talk
    unsigned char cmdTypePlay;      ///< command type for playreq, 1-server, 2-UDT; 3(0X01 | 0X10=3)-both
    unsigned char cmdTypeStop;      ///< command type for teardownreq, 0-not received, 1-server, 2-UDT; 3(0X01 | 0X10=3)-both
    unsigned char dropPermille;     ///< stream data drop permillage
    int resPlay;                    ///< result code for processing playreq command
    int resStop;                    ///< reason for why stream stop
}StatPlay;

/**
 * \brief Business transfer command information, for example PTZ control
 */
typedef struct tag_BusiTransInfo
{
    char userId[DEVP2P_USERID_LEN + 1];     ///< client user-id, used for share verification
    char transContent[DEVP2P_BUSITRAN_LEN]; ///< detail business transfer content, format defined by client-device
    int contentLength;                      ///< length of content
}BusiTransInfo;

#endif

