#ifndef _DEVCOM_ERROR_
#define _DEVCOM_ERROR_


/*******************ȫ�ִ����� begin**********************/
#define DEV_COM_ERROR_NONE                      0   //û�д���
#define DEV_COM_ERROR_NOINIT                    3   //û�г�ʼ��
#define DEV_COM_ERROR_CONNECT		            7	//���ӷ�����ʧ��
#define DEV_COM_ERROR_SEND			            8	//�����������ʧ��
#define DEV_COM_ERROR_RECV			            9	//�ӷ�������������ʧ��
#define DEV_COM_ERROR_RECV_TIMEOUT		        10	//�ӷ������������ݳ�ʱ
#define DEV_COM_ERROR_DATA                      11  //�����Ͻ��յ��������쳣
#define DEV_COM_ERROR_ORDER                     12  //���ô������
#define DEV_COM_ERROR_PARAMETER                 17  //��������
#define DEV_COM_ERROR_SUPPORT                   23  //��֧�ָù���
#define DEV_COM_ERROR_ALLOC_RESOURCE            41  //��Դ�������
#define DEV_COM_ERROR_NOENOUGH_BUF              43  //������̫С
#define DEV_COM_ERROR_CREATESOCKET              44  //����SOCKET����
#define DEV_COM_ERROR_SETSOCKET                 45  //����SOCKET����
#define DEV_COM_ERROR_MAXNUM                    46  //�ﵽ�������
#define DEV_COM_ERROR_BINDSOCKET    			72	//���׽���ʧ��
#define DEV_COM_ERROR_SOCKETCLOSE   			73	//socket�����жϣ��˴���ͨ�������������жϻ�Ŀ�ĵز��ɴ�

//��֤������
#define DEV_COM_ERROR_AUTHENTICATION_SUCCESS                     500  //��֤�ɹ�
#define DEV_COM_ERROR_AUTHENTICATION_FAIL                        501  //��֤ʧ��
#define DEV_COM_ERROR_AUTHENTICATION_CMD_ERROR                   502  //�Ƿ�����
#define DEV_COM_ERROR_AUTHENTICATION_DATA_INVALID                503  //Э�����ʧ��
#define DEV_COM_ERROR_AUTHENTICATION_DEV_ID_INVALID              504  //DevID�Ƿ�
#define DEV_COM_ERROR_AUTHENTICATION_QUERY_AUTHCODE_FAIL         505  //ƽ̨��ѯ��֤��ʧ��
#define DEV_COM_ERROR_AUTHENTICATION_QUERY_REDIS_FAIL            506  //ƽ̨��ѯredisʧ��
#define DEV_COM_ERROR_AUTHENTICATION_SESSION_KEY_INVALID         507  //SessionKey��Ч
#define DEV_COM_ERROR_AUTHENTICATION_ENCRYPT_FAIL                508  //Э�����ʧ��
#define DEV_COM_ERROR_AUTHENTICATION_QUERY_DATA_ERROR            509  //��ѯDas��Stun��Ϣʧ��
#define DEV_COM_ERROR_AUTHENTICATION_MASTERKEY_INVALID           510  //masterkey�Ƿ�
#define DEV_COM_ERROR_AUTHENTICATION_SESSION_KEY_INVALID_NOT          //�ݲ���
#define DEV_COM_ERROR_STUN_INVALID_AUTHENTICATION                512  //��ѯstun��֤ʧ��
#define DEV_COM_ERROR_DAS_INVALID_AUTHENTICATION                 513  //��ѯdas��֤ʧ��
#define DEV_COM_ERROR_CODE_ERROR                                 514  //�������̴���
#define DEV_COM_ERROR_LBS_UPDATE_REDIS_FAIL                      515  //ƽ̨�����豸��Ϣʧ��

//�����Խ�������
#define DEV_COM_ERROR_PARSING_FAIL               600  //������Ϣʧ��
#define DEV_COM_ERROR_CHECK_TOKEN                601  //��֤tokenʧ��

//өʯ΢�ں˴�����
#define DEV_COM_ERROR_EZDEVSDK_INDEX                100000
#define DEV_COM_ERROR_EZDEVSDK_INTERNAL             (DEV_COM_ERROR_EZDEVSDK_INDEX + 1)  //�ڲ�����
#define DEV_COM_ERROR_EZDEVSDK_INVALD_CALL          (DEV_COM_ERROR_EZDEVSDK_INDEX + 2)  //������������
#define DEV_COM_ERROR_EZDEVSDK_PARAMS_INVALID       (DEV_COM_ERROR_EZDEVSDK_INDEX + 3)  //�����Ƿ�
#define DEV_COM_ERROR_EZDEVSDK_BUFFER_TOO_SMALL     (DEV_COM_ERROR_EZDEVSDK_INDEX + 4)  //��������С����
#define DEV_COM_ERROR_EZDEVSDK_DATA_LEN_RANGE       (DEV_COM_ERROR_EZDEVSDK_INDEX + 5)  //���ݴ�С������Χ
#define DEV_COM_ERROR_EZDEVSDK_MEMORY               (DEV_COM_ERROR_EZDEVSDK_INDEX + 6)  //�ڴ��쳣
#define DEV_COM_ERROR_EZDEVSDK_JSON_INVALID         (DEV_COM_ERROR_EZDEVSDK_INDEX + 7)  //�Ƿ���json����
#define DEV_COM_ERROR_EZDEVSDK_JSON_FORMAT          (DEV_COM_ERROR_EZDEVSDK_INDEX + 8)  //json��������
#define DEV_COM_ERROR_EZDEVSDK_EXTEND_NO_FIND       (DEV_COM_ERROR_EZDEVSDK_INDEX + 9)  //����·���Ҳ�����Ӧ��ע������
#define DEV_COM_ERROR_EZDEVSDK_EXTEND_FULL          (DEV_COM_ERROR_EZDEVSDK_INDEX + 10) //��չע������
#define DEV_COM_ERROR_EZDEVSDK_EXTEND_EXISTED       (DEV_COM_ERROR_EZDEVSDK_INDEX + 11) //��չ�Ѿ�ע��
#define DEV_COM_ERROR_EZDEVSDK_QUEUE_FULL           (DEV_COM_ERROR_EZDEVSDK_INDEX + 12) //��Ϣ��������
#define DEV_COM_ERROR_EZDEVSDK_VALUE_LOAD           (DEV_COM_ERROR_EZDEVSDK_INDEX + 13) //��ȡ�豸����ʧ��
#define DEV_COM_ERROR_EZDEVSDK_VALUE_SAVE           (DEV_COM_ERROR_EZDEVSDK_INDEX + 14) //�����������豸ʧ��
#define DEV_COM_ERROR_EZDEVSDK_MSG_STOP_DISTRIBUTE  (DEV_COM_ERROR_EZDEVSDK_INDEX + 15) //�豸����ֹͣ,�ϲ���Ϣֹͣ�·�
#define DEV_COM_ERROR_EZDEVSDK_MSG_DEFLATE_FAIL     (DEV_COM_ERROR_EZDEVSDK_INDEX + 16) //���Ľ�ѹʧ��
#define DEV_COM_ERROR_EZDEVSDK_MSG_INFLATE_FAIL     (DEV_COM_ERROR_EZDEVSDK_INDEX + 17) //����ѹ��ʧ��
#define DEV_COM_ERROR_EZDEVSDK_INS_FULL             (DEV_COM_ERROR_EZDEVSDK_INDEX + 18) //�ͻ��������ﵽ����

#define DEV_COM_ERROR_EZDEVSDK_NET_INDEX            100300
#define DEV_COM_ERROR_EZDEVSDK_NET_CREATE           (DEV_COM_ERROR_EZDEVSDK_NET_INDEX + 1)  ///< ����socketʧ��
#define DEV_COM_ERROR_EZDEVSDK_NET_CONNECT          (DEV_COM_ERROR_EZDEVSDK_NET_INDEX + 2)  ///< ��������ʧ��
#define DEV_COM_ERROR_EZDEVSDK_NET_DISCONNECTED     (DEV_COM_ERROR_EZDEVSDK_NET_INDEX + 3)  ///< �������ӶϿ�
#define DEV_COM_ERROR_EZDEVSDK_NET_TRANSMIT         (DEV_COM_ERROR_EZDEVSDK_NET_INDEX + 4)  ///< ���ݴ���ʧ��
#define DEV_COM_ERROR_EZDEVSDK_NET_DNS              (DEV_COM_ERROR_EZDEVSDK_NET_INDEX + 5)  ///< ��������ʧ��

#define DEV_COM_ERROR_EZDEVSDK_LBS_INDEX                100600
#define DEV_COM_ERROR_EZDEVSDK_NET_AUTHCODE_MISMATCH    (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 1)  ///< ��֤�벻һ��
#define DEV_COM_ERROR_EZDEVSDK_NET_INVALID_CALL         (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 2)  ///< �ͷ������Ľ�������������
#define DEV_COM_ERROR_EZDEVSDK_NET_INVALID_DATA         (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 3)  ///< �������յ���������
#define DEV_COM_ERROR_EZDEVSDK_NET_DEVID_MISMATCH       (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 4)  ///< devid��һ��
#define DEV_COM_ERROR_EZDEVSDK_NET_MASTERKEY_MISMATCH   (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 5)  ///< masterkey��һ��
#define DEV_COM_ERROR_EZDEVSDK_NET_SESSIONKEY_MISMATCH  (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 6)  ///< sessionkey��һ��
#define DEV_COM_ERROR_EZDEVSDK_NET_INVALID_DEV          (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 7)  ///< ��Ч�豸
#define DEV_COM_ERROR_EZDEVSDK_NET_SERVER_CRYPTO        (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 8)  ///< �������ӽ���ʧ��
#define DEV_COM_ERROR_EZDEVSDK_NET_GET_DATA             (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 9)  ///< ��ȡdas����stun��Ϣʧ��
#define DEV_COM_ERROR_EZDEVSDK_NET_SERVER_EXCEPTION     (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 10) ///< �������ڲ��쳣
#define DEV_COM_ERROR_EZDEVSDK_NET_CHECK_SESSIONKEY_FAIL (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX +  11) ///< sessionkey��֤ʧ��
#define DEV_COM_ERROR_EZDEVSDK_NET_SIGN_CHECK_FAIL       (DEV_COM_ERROR_EZDEVSDK_LBS_INDEX + 12)  ///< auth_iУ��signʧ�ܡ�����device idУ��signʧ��(������֤�����)

#define DEV_COM_ERROR_EZDEVSDK_SECRETKEY_INDEX              100900
#define DEV_COM_ERROR_EZDEVSDK_SECRETKEY_DECRYPT_FAIL       (DEV_COM_ERROR_EZDEVSDK_SECRETKEY_INDEX + 0)    ///< ����secretkey����ƽ̨����ʧ��
#define DEV_COM_ERROR_EZDEVSDK_SECRETKEY_OVERFLOW_WINDOWS   (DEV_COM_ERROR_EZDEVSDK_SECRETKEY_INDEX + 1)    ///< ����secretkey�����ڴ�����
#define DEV_COM_ERROR_EZDEVSDK_SECRETKEY_NO_USER            (DEV_COM_ERROR_EZDEVSDK_SECRETKEY_INDEX + 2)    ///< �豸δ���û�
#define DEV_COM_ERROR_EZDEVSDK_SECRETKEY_SN_NOT_EXIST       (DEV_COM_ERROR_EZDEVSDK_SECRETKEY_INDEX + 3)    ///< �豸������
#define DEV_COM_ERROR_EZDEVSDK_SECRETKEY_AGAIN              (DEV_COM_ERROR_EZDEVSDK_SECRETKEY_INDEX + 4)    ///< �豸�ظ�����

#define DEV_COM_ERROR_EZDEVSDK_DAS_INDEX                    101000
#define DEV_COM_ERROR_EZDEVSDK_DAS_NOSUPPORT_PROTOCOL_VER   (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 1)  ///< ��֧�ֵ�Э��汾
#define DEV_COM_ERROR_EZDEVSDK_DAS_CLIENT_ID_INVALID        (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 2)  ///< ���ϸ�Ŀͻ��˱�ʶ��
#define DEV_COM_ERROR_EZDEVSDK_DAS_SERVER_UNUSABLE          (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 3)  ///< ����˲�����(�������ڲ��쳣)
#define DEV_COM_ERROR_EZDEVSDK_DAS_INVALID_USERNAME         (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 4)  ///< ��Ч���û��������루�ֽ׶��ݲ�ʹ�ã�
#define DEV_COM_ERROR_EZDEVSDK_DAS_UNAUTHORIZED             (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 5)  ///< δ��Ȩ���ֽ׶��ݲ�ʹ�ã�
#define DEV_COM_ERROR_EZDEVSDK_DAS_SESSION_INVAILD          (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 6)  ///< ����ỰʧЧ
#define DEV_COM_ERROR_EZDEVSDK_DAS_FORCE_OFFLINE            (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 7)  ///< �豸��ǿ������
#define DEV_COM_ERROR_EZDEVSDK_DAS_FORCE_DEV_RISK           (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 8)  ///< �豸����أ���������
#define DEV_COM_ERROR_EZDEVSDK_DAS_FORCE_DOMAIN_RISK        (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 9)  ///< ���򱻷��
#define DEV_COM_ERROR_EZDEVSDK_DAS_FORCE_CMD_RISK           (DEV_COM_ERROR_EZDEVSDK_DAS_INDEX + 10) ///< ָ����

/*******************ȫ�ִ����� end**********************/
#endif