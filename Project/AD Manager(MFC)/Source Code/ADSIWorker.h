#pragma once

class ADSIWorker
{
public:
	ADSIWorker(void);
	~ADSIWorker(void);
	CString ADSIWorker::FormatMessage(HRESULT result);
	//인증
	HRESULT Authenticate(tstring sUserIP, tstring sUserID, tstring sUserPwd);
		
	//AD 계정 목록 가져오기
	HRESULT GetADUsers(CStringArray& ArrayDN_Tree, tstring sAuthIP, tstring sAuthID, tstring sAuthPwd);  
	HRESULT FindUsersIn(CStringArray* pArrayDN_Tree, IDirectorySearch *pContainerToSearch);  

	//AD 속성 정보 불러오기
	HRESULT GetAttribute(CStringArray& ObjData,tstring strObjCN, tstring sAuthIP, tstring sAuthID, tstring sAuthPwd);//<---나

	//사용자 추가
	HRESULT CreateUser(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sPath, tstring sUserName, tstring sLoginName, tstring sUserPwd);

	//OU 추가
	HRESULT CreateOU(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sPath, tstring sOuName);

	//그룹 추가
	HRESULT CreateGroup(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sPath, tstring sGroupName, int nGroupType);

	//계정 이동
	HRESULT MoveObject(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sMovePath, tstring sObjectDN);

	//계정 삭제
	HRESULT DeleteObject(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sDeletePath, tstring sDeleteType, tstring sDeleteName);
};

