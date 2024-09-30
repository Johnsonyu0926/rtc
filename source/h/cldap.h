#ifndef __CLDAP_H__
#define __CLDAP_H__

#include <lber.h>
#include <ldap.h>
#include "doorsbase.h"
#include <string>

#define AUTH_SUCCESS 0
#define AUTH_USER_NOT_EXIST 1
#define AUTH_PASSWORD_ERROR 2
#define AUTH_LDAP_SERVER_ERROR 3

constexpr int LDAP_PORT = 389;
constexpr const char* LDAP_HOST = "192.168.100.194";
constexpr const char* BASE = "o=doors,c=cn";
constexpr const char* ADMIN_BINDDN = "cn=admin,o=doors,c=cn";
constexpr const char* ADMIN_PASSWD = "admin123";
constexpr const char* BASE_DOMAIN = "o=rd,c=cn";
constexpr const char* GROUP_BASE = "ou=Groups,o=gst,c=CN";
constexpr const char* HTTP_GROUP_DN = "cn=httpgrp,ou=Groups,ou=giantsound,c=cn";
constexpr const char* HOME_GROUP_DN = "cn=domesticgrp,ou=Groups,ou=giatnsound,c=cn";
constexpr const char* FTP_GROUP_DN = "cn=ftpgrp,ou=Groups,ou=giatnsound,c=cn";
constexpr const char* SOCKS_GROUP_DN = "cn=socksgrp,ou=Groups,ou=giatnsound,c=cn";

class CLdap {
public:
    CLdap();
    ~CLdap() = default;

    int Init(const std::string& host = LDAP_HOST, int port = LDAP_PORT, const std::string& bindDN = ADMIN_BINDDN, const std::string& password = ADMIN_PASSWD, int authMethod = LDAP_AUTH_SIMPLE);
    int LdapSearchEx(const std::string& baseDN, const std::string& filter, LDAPMessage** ret, std::string& dn);
    int LdapSearch(const std::string& baseDN, const std::string& filter, LDAPMessage** ret);
    int LdapSearch(const std::string& filter);
    void ShowProperties(LDAP* ld, const std::string& dn);
    void PrintMessage();
    int LdapModify(const std::string& modifyDN, LDAPMod** mods);
    int LdapAdd(const std::string& modifyDN, LDAPMod* attrs[]);
    void FreeMods(LDAPMod** mods);
    int LdapDelete(const std::string& dn);
    int LdapModifyDN(const std::string& oldDN, const std::string& newDN);
    int DeleteUser(const std::string& commonName, const std::string& ou);
    int ModifyUserAttribute(const std::string& dn, const std::string& attr, const std::string& value);
    int ModifyUserAttribute(const std::string& commonName, const std::string& ouName, const std::string& attr, const std::string& value);
    int AddAttr(const std::string& baseDN, const std::string& attrType, const std::string& attrValue);
    int AddMemberInProxyGroup(const std::string& memberDN, long status);
    int DisableUserHttp(const std::string& cn, const std::string& ou, int proxyType = HTTP_PROXY);
    int EnableUserHttp(const std::string& cn, const std::string& ou, int proxyType = HTTP_PROXY);
    int EnableUserHttp(const std::string& dn, int proxyType = HTTP_PROXY);
    int DisableUserHttp(const std::string& dn, int proxyType = HTTP_PROXY);
    int LdapUnBind();
    bool IsExistUserID(const std::string& userID);
    int LdapAddOu(const std::string& ouName, const std::string& baseDN = "ou=zju,o=edu,c=cn");
    int Auth(const std::string& uid, const std::string& passwd);

private:
    LDAP* LdapOpen(const std::string& host, int port = 389);
    int LdapBind(const std::string& bindDN, const std::string& passwd, int authMethod = LDAP_AUTH_SIMPLE);

    LDAP* m_pLdap;
    LDAPMessage* m_pMessage;
    char m_szBase[256];
    char m_szLdapHost[256];
    int m_nLdapPort;
    char m_szAdminBindDN[256];
    char m_szAdminPasswd[256];
};

#endif // __CLDAP_H__
