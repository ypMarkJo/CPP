#pragma once

class ADSIWorker
{
public:
	ADSIWorker(void);
	~ADSIWorker(void);
	CString ADSIWorker::FormatMessage(HRESULT result);
	//����
	HRESULT Authenticate(tstring sUserIP, tstring sUserID, tstring sUserPwd);
		
	//AD ���� ��� ��������
	HRESULT GetADUsers(CStringArray& ArrayDN_Tree, tstring sAuthIP, tstring sAuthID, tstring sAuthPwd);  
	HRESULT FindUsersIn(CStringArray* pArrayDN_Tree, IDirectorySearch *pContainerToSearch);  

	//AD �Ӽ� ���� �ҷ�����
	HRESULT GetAttribute(CStringArray& ObjData,tstring strObjCN, tstring sAuthIP, tstring sAuthID, tstring sAuthPwd);//<---��

	//����� �߰�
	HRESULT CreateUser(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sPath, tstring sUserName, tstring sLoginName, tstring sUserPwd);

	//OU �߰�
	HRESULT CreateOU(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sPath, tstring sOuName);

	//�׷� �߰�
	HRESULT CreateGroup(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sPath, tstring sGroupName, int nGroupType);

	//���� �̵�
	HRESULT MoveObject(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sMovePath, tstring sObjectDN);

	//���� ����
	HRESULT DeleteObject(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sDeletePath, tstring sDeleteType, tstring sDeleteName);
};

