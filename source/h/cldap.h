#ifndef __CLDAP_H__
#define __CLDAP_H__

#include <lber.h>
#include <ldap.h>
#include "doorsbase.h"

#define AUTH_SUCCESS 0
#define AUTH_USER_NOT_EXIST 1
#define AUTH_PASSWORD_ERROR 2
#define AUTH_LDAP_SERVER_ERROR 3
#define LDAP_PORT 389
#define LDAP_HOST "192.168.100.194"
#define BASE "o=doors,c=cn"
#define ADMIN_BINDDN "cn=admin,o=doors,c=cn"
#define ADMIN_PASSWD "admin123"

#define HTTP_PROXY 0x01
#define HOME_PROXY 0X02
#define BASE_DOMAIN "o=rd,c=cn"
#define GROUP_BASE "ou=Groups,o=gst,c=CN"
#define HTTP_GROUP_DN "cn=httpgrp,ou=Groups,ou=giantsound,c=cn"
#define HOME_GROUP_DN "cn=domesticgrp,ou=Groups,ou=giatnsound,c=cn"
#define FTP_GROUP_DN "cn=ftpgrp,ou=Groups,ou=giatnsound,c=cn"
#define SOCKS_GROUP_DN "cn=socksgrp,ou=Groups,ou=giatnsound,c=cn"

class CLdap {
public:
    CLdap()
        : m_pLdap(nullptr), m_pMessage(nullptr) {
        strncpy(m_szBase, BASE, sizeof(m_szBase));
        strncpy(m_szLdapHost, LDAP_HOST, sizeof(m_szLdapHost));
        m_nLdapPort = LDAP_PORT;
        strncpy(m_szAdminBindDN, ADMIN_BINDDN, sizeof(m_szAdminBindDN));
        strncpy(m_szAdminPasswd, ADMIN_PASSWD, sizeof(m_szAdminPasswd));
    }
    ~CLdap() = default;

    int Init(const std::string& szHost = LDAP_HOST, int nPort = LDAP_PORT, const std::string& szBindDN = ADMIN_BINDDN, const std::string& szPswd = ADMIN_PASSWD, int nAuthMethod = LDAP_AUTH_SIMPLE);
    int LdapSearchEx(const std::string& szBaseDN, const std::string& szFilter, LDAPMessage** pRet, std::string& szDN);
    int LdapSearch(const std::string& szBaseDN, const std::string& szFilter, LDAPMessage** pRet);
    int LdapSearch(const std::string& szFilter);
    void ShowProperties(LDAP* ld, const std::string& dn);
    void PrintMessage();
    int LdapModify(const std::string& szModifyDN, LDAPMod** pMods);
    int LdapAdd(const std::string& szModifyDN, LDAPMod* pAttrs[]);
    void FreeMods(LDAPMod** pMods);
    int LdapDelete(const std::string& szDN);
    int LdapModifyDN(const std::string& szOldDN, const std::string& szNewDN);
    int DeleteUser(const std::string& szCommonName, const std::string& szOu);
    int ModifyUserAttribute(const std::string& szDN, const std::string& szAttr, const std::string& szValue);
    int ModifyUserAttribute(const std::string& szCommonName, const std::string& szOuName, const std::string& szAttr, const std::string& szValue);
    int AddAttr(const std::string& szBaseDN, const std::string& szAttrType, const std::string& szAttrValue);
    int AddMemberInProxyGroup(const std::string& szMemberDN, long nStatus);
    int DisableUserHttp(const std::string& szCN, const std::string& szOu, int nProxyType = HTTP_PROXY);
    int EnableUserHttp(const std::string& szCN, const std::string& szOu, int nProxyType = HTTP_PROXY);
    int EnableUserHttp(const std::string& szDN, int nProxyType = HTTP_PROXY);
    int DisableUserHttp(const std::string& szDN, int nProxyType = HTTP_PROXY);
    int LdapUnBind();
    bool IsExistUserID(const std::string& szUserID);
    int LdapAddOu(const std::string& szOuName, const std::string& szBaseDN = "ou=zju,o=edu,c=cn");
    int Auth(const std::string& szUID, const std::string& szPasswd);

private:
    LDAP* LdapOpen(const std::string& szHost, int nPort = 389);
    int LdapBind(const std::string& szBindDN, const std::string& szPasswd, int nAuthMethod = LDAP_AUTH_SIMPLE);

    LDAP* m_pLdap;
    LDAPMessage* m_pMessage;
    char m_szBase[256];
    char m_szLdapHost[256];
    int m_nLdapPort;
    char m_szAdminBindDN[256];
    char m_szAdminPasswd[256];
};

#endif // __CLDAP_H__
