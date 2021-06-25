
#include "pch.h"
#include "ADSIWorker.h"

ADSIWorker::ADSIWorker(void)
{
}


ADSIWorker::~ADSIWorker(void)
{
}

HRESULT ADSIWorker::Authenticate(tstring sUserIP, tstring sUserID, tstring sUserPwd)
{
	IADs *pObject;
	HRESULT hr;
	tstring LDIP = L"LDAP://";
	sUserIP = LDIP + sUserIP;
	hr = ADsOpenObject(CComBSTR(sUserIP.c_str()), CComBSTR(sUserID.c_str()), CComBSTR(sUserPwd.c_str()),
		ADS_SECURE_AUTHENTICATION, IID_IADs, (void**)&pObject);

	if(SUCCEEDED(hr))
	{
		// Use the object.		
		// Release the object.
		pObject->Release();
	}
	return hr;
}
//에러코드 처리기---------------------------------------------------------------------------------------------------------------
CString ADSIWorker::FormatMessage(HRESULT result)
{
	CString strMessage;
	WORD facility = HRESULT_FACILITY(result);
	CComPtr<IErrorInfo> iei;
	if (S_OK == GetErrorInfo(0, &iei) && iei)
	{
		// get the error description from the IErrorInfo 
		BSTR bstr = NULL;
		if (SUCCEEDED(iei->GetDescription(&bstr)))
		{
			// append the description to our label
			strMessage.Append(bstr);

			// done with BSTR, do manual cleanup
			SysFreeString(bstr);
		}
	}
	else if (facility == FACILITY_ITF)
	{
		// interface specific - no standard mapping available
		strMessage.Append(_T("FACILITY_ITF - This error is interface specific.  No further information is available."));
	}
	else
	{
		// attempt to treat as a standard, system error, and ask FormatMessage to explain it
		CString error;
		//FormatMessage(error, result); // <- This is just a wrapper for ::FormatMessage, left to reader as an exercise :)
		if (!error.IsEmpty())
			strMessage.Append(error);
	}
	return strMessage;
}

//--------------------------------------------------------------------------------------------------------------------------


// 트리
HRESULT ADSIWorker::GetADUsers(CStringArray& ArrayDN_Tree, tstring sAuthIP, tstring sAuthID, tstring sAuthPwd)
{
	// COM 초기화
	CoInitialize(NULL);  
    HRESULT hr = S_OK;  

	// rootDSE, user domain container DN 가져오기 
	IADs *pObject = NULL;  
    IDirectorySearch *pContainerToSearch = NULL;  
    LPOLESTR szPath = new OLECHAR[MAX_PATH];  
    VARIANT var;  
	VariantInit(&var);
	tstring LDIP = L"LDAP://";
	sAuthIP = LDIP + sAuthIP;
	//hr = Authenticate(sAuthIP, sAuthID, sAuthPwd, pObject);
	hr = ADsOpenObject(CComBSTR(sAuthIP.c_str()), CComBSTR(sAuthID.c_str()), CComBSTR(sAuthPwd.c_str()),
		ADS_SECURE_AUTHENTICATION, IID_IADs, (void**)&pObject);
	
	if (FAILED(hr))  
    {       
		AfxMessageBox(L"Cannot execute query.\n Cannot bind to LDAP://rootDSE.\n");

        if (pObject)  
            pObject->Release();  
        return hr;  
    }  
	if (SUCCEEDED(hr))  
    {  
		//도메인 이름
		//hr = pObject->Get(CComBSTR(L"distinguishedName"),&var);  
		hr = pObject->Get(CComBSTR(L"objectClass"),&var);  

		if (SUCCEEDED(hr))  
        {  
			//  Build path to the domain container.
       //    wcscpy(szPath,L"LDAP://");  
        //    wcscat(szPath,var.bstrVal);
			hr = ADsOpenObject(CComBSTR(sAuthIP.c_str()), CComBSTR(sAuthID.c_str()), CComBSTR(sAuthPwd.c_str()),ADS_SECURE_AUTHENTICATION, 
				IID_IDirectorySearch,(void**)&pContainerToSearch);
                

			if (SUCCEEDED(hr))  
            {  
				// Search 
                hr = FindUsersIn(&ArrayDN_Tree, pContainerToSearch);

				if (SUCCEEDED(hr))
                {
                    if (S_FALSE==hr)
                        AfxMessageBox(L"User object cannot be found.\n");
                }
                else if (E_ADS_INVALID_FILTER==hr)
                    AfxMessageBox(L"Cannot execute query. Invalid filter was specified.\n");
                else
                    AfxMessageBox(L"Query failed to run. HRESULT: %x\n",hr);

            }  
			else  
            {  
                AfxMessageBox(L"Cannot execute query. Cannot bind to the container.\n");
				return hr;
               
            }  
			if (pContainerToSearch)  
                pContainerToSearch->Release();  
		}
		VariantClear(&var);  
    }  
    if (pObject)  
        pObject->Release();  
      
    CoUninitialize();  
    return hr; 
}
//계정 속성 불러오기
HRESULT ADSIWorker::GetAttribute(CStringArray& ObjData, tstring strObjCN, tstring sAuthIP, tstring sAuthID, tstring sAuthPwd)
{
	HRESULT hr = S_OK; // COM result variable
	ADS_SEARCH_COLUMN col;  // COL for iterations
	LPWSTR szUsername = NULL; // user name
	LPWSTR szPassword = NULL; // password

	// Interface Pointers.
	IDirectorySearch     *pDSSearch = NULL;

	// Initialize COM.
	CoInitialize(0);

	// Add code to securely retrieve the user name and password or
	// leave both as NULL to use the default security context.

	// Open a connection with server.
	tstring LDIP = L"LDAP://";
	sAuthIP = LDIP + sAuthIP;
	hr = ADsOpenObject(sAuthIP.c_str(),
		sAuthID.c_str(),
		sAuthPwd.c_str(),
		ADS_SECURE_AUTHENTICATION,
		IID_IDirectorySearch,
		(void **)&pDSSearch);
	LPWSTR pszAttr[] = { L"Name", L"objectCategory", L"memberOf", L"description"};
	ADS_SEARCH_HANDLE hSearch;
	DWORD dwAttrNameSize = sizeof(pszAttr) / sizeof(LPWSTR);
	// Search for all objects with the 'cn' property that start with c.
	tstring filter = L"(distinguishedname=";
	filter = filter + strObjCN+L")";
	hr = pDSSearch->ExecuteSearch((LPWSTR)filter.c_str(), pszAttr, dwAttrNameSize, &hSearch);
	LPWSTR pszColumn;
	pDSSearch->GetNextRow(hSearch);
	for (int i = 0; i < 4; i++)
	{
		// Get the property.
		hr = pDSSearch->GetColumn(hSearch,pszAttr[i], &col);
		
		// If this object supports this attribute, display it.
		if (SUCCEEDED(hr))
		{
			ObjData.Add(col.pADsValues->CaseIgnoreString);
			pDSSearch->FreeColumn(&col);
		}
		else
			ObjData.Add(L"해당사항 없음");
	}
	
	pDSSearch->CloseSearchHandle(hSearch);
	pDSSearch->Release();
	return hr;
}

// 계정 찾기
HRESULT ADSIWorker::FindUsersIn(CStringArray* pArrayDN_Tree, IDirectorySearch *pContainerToSearch)
{
	if (pContainerToSearch == NULL || pArrayDN_Tree == NULL)
	{
		return E_POINTER;
	}
	LPOLESTR pszSearchFilter = new OLECHAR[MAX_PATH];
	DWORD dwLength = MAX_PATH * 2;

	//필터 그룹
	CStringArray sArrayFilter;

	sArrayFilter.Add(L"(objectCategory=domain)");
	sArrayFilter.Add(L"(objectCategory=builtinDomain)");
	sArrayFilter.Add(L"(objectCategory=container)");
	sArrayFilter.Add(L"(objectCategory=organizationalUnit)");
	//sArrayFilter.Add(L"(objectCategory=lostAndFound)");
	//sArrayFilter.Add(L"(objectCategory=msDS-QuotaContainer)");
	//sArrayFilter.Add(L"(objectCategory=msTPM-InformationObjectsContainer)");

	sArrayFilter.Add(L"(objectCategory=computer)");
	sArrayFilter.Add(L"(objectCategory=group)");
	sArrayFilter.Add(L"(objectCategory=user)");
	sArrayFilter.Add(L"(objectCategory=secret)");

	sArrayFilter.Add(L"(&(objectClass=*)(!(objectCategory=secret))(!(objectCategory=domain))(!(objectCategory=builtinDomain))(!(objectCategory=container))(!(objectCategory=organizationalUnit))(!(objectCategory=computer))(!(objectCategory=group))(!(objectCategory=user)))");


	//  Specify subtree search.
	ADS_SEARCHPREF_INFO SearchPrefs;
	SearchPrefs.dwSearchPref = ADS_SEARCHPREF_SEARCH_SCOPE;
	SearchPrefs.vValue.dwType = ADSTYPE_INTEGER;
	SearchPrefs.vValue.Integer = ADS_SCOPE_SUBTREE;
	DWORD dwNumPrefs = 1;

	//  COL for iterations.
	LPOLESTR pszColumn = NULL;
	ADS_SEARCH_COLUMN col;
	HRESULT hr = S_OK;


	//  Interface Pointers  
	IADs    *pObj = NULL;
	IADs    *pIADs = NULL;

	//  Search handle
	ADS_SEARCH_HANDLE hSearch = NULL;

	//  Set search preference
	hr = pContainerToSearch->SetSearchPreference(&SearchPrefs, dwNumPrefs);
	if (FAILED(hr))
	{
		return hr;
	}

	/*LPOLESTR pszBool = NULL;
	DWORD dwBool = 0;
	PSID pObjectSID = NULL;
	LPOLESTR szSID = NULL;
	LPOLESTR szDSGUID = new WCHAR [39];
	LPGUID pObjectGUID = NULL;

	VARIANT varDate;
	LARGE_INTEGER liValue;
	LPOLESTR *pszPropertyList = NULL;*/
	LPOLESTR pszNonVerboseList[] = { L"distinguishedName" };

	LPOLESTR szName = new OLECHAR[MAX_PATH];
	LPOLESTR szDN = new OLECHAR[MAX_PATH];

	//VariantInit(&varDate);

	int iCount = 0;
	DWORD x = 0L;
	//  Return specified properties.
	for (int i = 0; i < sArrayFilter.GetCount(); i++)
	{
		//필터
		wcscpy(pszSearchFilter, sArrayFilter.GetAt(i));
		//wcscpy(pszSearchFilter,L"(|(objectCategory=domain)(objectCategory=builtinDomain)(objectCategory=container)(objectCategory=organizationalUnit))");

		hr = pContainerToSearch->ExecuteSearch(pszSearchFilter, pszNonVerboseList, sizeof(pszNonVerboseList) / sizeof(LPOLESTR), &hSearch);
		if (SUCCEEDED(hr))
		{
			//  Call IDirectorySearch::GetNextRow() to retrieve the next data row.
			hr = pContainerToSearch->GetFirstRow(hSearch);
			if (SUCCEEDED(hr))
			{
				while (hr != S_ADS_NOMORE_ROWS)
				{
					//  Keep track of count.
					iCount++;
					while (pContainerToSearch->GetNextColumnName(hSearch, &pszColumn) != S_ADS_NOMORE_COLUMNS)
					{
						hr = pContainerToSearch->GetColumn(hSearch, pszColumn, &col);
						if (SUCCEEDED(hr))
						{
							if (0 == wcscmp(L"distinguishedName", pszColumn))
							{
								wcscpy(szDN, col.pADsValues->CaseIgnoreString);

								// 종류 정하기
								if (sArrayFilter.GetAt(i) == "(objectCategory=domain)")
								{
									wcscat(szDN, L"/domain");
								}
								else if (sArrayFilter.GetAt(i) == "(objectCategory=builtinDomain)")
								{
									wcscat(szDN, L"/builtinDomain");
								}
								else if (sArrayFilter.GetAt(i) == "(objectCategory=container)")
								{
									wcscat(szDN, L"/container");
								}
								else if (sArrayFilter.GetAt(i) == "(objectCategory=organizationalUnit)")
								{
									wcscat(szDN, L"/organizationalUnit");
								}
								/*		else if(sArrayFilter.GetAt(i) == "(objectCategory=lostAndFound)")
										{
											wcscat(szDN,L"/lostAndFound");
										}
										else if(sArrayFilter.GetAt(i) == "(objectCategory=msDS-QuotaContainer)")
										{
											wcscat(szDN,L"/msDS-QuotaContainer");
										}
										else if(sArrayFilter.GetAt(i) == "(objectCategory=msTPM-InformationObjectsContainer)")
										{
											wcscat(szDN,L"/msTPM-InformationObjectsContainer");
										}*/
								else if (sArrayFilter.GetAt(i) == "(objectCategory=computer)")
								{
									wcscat(szDN, L"/computer");
								}
								else if (sArrayFilter.GetAt(i) == "(objectCategory=group)")
								{
									wcscat(szDN, L"/group");
								}
								else if (sArrayFilter.GetAt(i) == "(objectCategory=user)")
								{
									wcscat(szDN, L"/user");
								}
								else if (sArrayFilter.GetAt(i) == "(objectCategory=secret)")
								{
									wcscat(szDN, L"/secret");
								}
								else
								{
									wcscat(szDN, L"/etc");
								}

								pArrayDN_Tree->Add(szDN);  //ex) DC=selyun90,DC=com/domain
							}

						}
						FreeADsMem(pszColumn);
					}
					hr = pContainerToSearch->GetNextRow(hSearch);
				}
			}
			pContainerToSearch->CloseSearchHandle(hSearch);
		}
	}

	if (SUCCEEDED(hr) && 0 == iCount)
	{
		hr = S_FALSE;
	}

	return hr;
}


// 사용자 생성
HRESULT ADSIWorker::CreateUser(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sPath, tstring sUserName, tstring sLoginName, tstring sUserPwd)
{
	HRESULT hr;
	IADsContainer *pCont;
	IDispatch *pDisp;	
	IADsUser *pUser;
	VARIANT var;
	tstring LDIP = L"LDAP://";
	sAuthIP = LDIP + sAuthIP;
	  
	hr = ADsOpenObject((sAuthIP + _T("/") + sPath).c_str(), CComBSTR(sAuthID.c_str()), CComBSTR(sAuthPwd.c_str()),
		ADS_SECURE_AUTHENTICATION,IID_IADsContainer,( void **) &pCont);

	if (SUCCEEDED(hr))
	{
		// Create the new object in the User folder
		hr = pCont->Create(CComBSTR("user"), CComBSTR((_T("CN=")+ sUserName).c_str()), &pDisp);
		if (SUCCEEDED(hr))
		{
			// Get the IADs interface.
			hr = pDisp->QueryInterface(IID_IADsUser, (void**)&pUser);
			if (SUCCEEDED(hr))
			{
				CComBSTR sbstrProp;
				//사용자 로그온 이름
				CComVariant svar;
				svar = sLoginName.c_str();
				sbstrProp = "userPrincipalName";
				hr = pUser->Put(sbstrProp, svar);
				hr = pUser->SetInfo();

				//Windows 2000 이전 버전 사용자 로그온 이름 
				svar = sLoginName.c_str();
				sbstrProp = "sAMAccountName";
				hr = pUser->Put(sbstrProp, svar);
				hr = pUser->SetInfo();

				//비밀번호 
				hr = pUser->SetPassword(CComBSTR(sUserPwd.c_str()));

				//다음 로그인시 비밀번호 변경 안함 옵션
				sbstrProp = "pwdLastSet";
				svar = -1;
				hr = pUser->Put(sbstrProp, svar);

				//Enable the user account
				svar.Clear();
				sbstrProp = "userAccountControl";
				hr = pUser->Get(sbstrProp, &svar);
				if(SUCCEEDED(hr))
				{
					svar = svar.lVal & ~(ADS_UF_ACCOUNTDISABLE | ADS_UF_PASSWD_NOTREQD | ADS_UF_DONT_EXPIRE_PASSWD);

					hr = pUser->Put(sbstrProp, svar);
					hr = pUser->SetInfo();

					pUser->Release();
				}
				pDisp->Release();
			}
			pCont->Release();
		}
	}
	return hr;
}

// OU 생성
HRESULT ADSIWorker::CreateOU(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sPath, tstring sOuName)
{
	HRESULT hr = NULL;
	IADsContainer* pContainer = NULL;
	IDispatch* pDisp = NULL;
    IADs* pOrganizationalUnit = NULL;
	tstring LDIP = L"LDAP://";
	sAuthIP = LDIP + sAuthIP;
    // Initialize COM.
    CoInitialize(NULL);  
    
    // Bind to the container.
	hr = ADsOpenObject((sAuthIP + _T("/") + sPath).c_str(), CComBSTR(sAuthID.c_str()), CComBSTR(sAuthPwd.c_str()),
		ADS_SECURE_AUTHENTICATION,IID_IADsContainer,(void**) &pContainer);

    if ( SUCCEEDED(hr) )
    {        
        // Create the new organizational unit.
        hr = pContainer->Create(CComBSTR("organizationalUnit"), CComBSTR((_T("OU=")+ sOuName).c_str()), &pDisp);
        
        if ( SUCCEEDED(hr) )
		{
			hr = pDisp->QueryInterface(IID_IADs,(void**) &pOrganizationalUnit);
           
           if ( SUCCEEDED(hr) )
           {
                // Commit newly created organizational unit to the
                // directory.
                hr = pOrganizationalUnit->SetInfo();
            
				if ( !SUCCEEDED(hr) )
                {
					//wprintf(L"Error 0x%x occurred. Container not created.\n", hr);
					return hr;
                }        
                
            }
            
            // Release the IDispatch object.
            pDisp->Release();
            
        }
        // Release the organizational unit object.
        pOrganizationalUnit->Release();
    }
    // Release the container object.
    pContainer->Release();
    
    CoUninitialize();
	
	return hr;

}


//그룹 생성
HRESULT ADSIWorker::CreateGroup(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sPath, tstring sGroupName, int nGroupType)
{
	HRESULT hr;
	IADsContainer *pCont;
	IDispatch *pDisp;
	IADs *pGroup = NULL;
	tstring LDIP = L"LDAP://";
	sAuthIP = LDIP + sAuthIP;

	hr = ADsOpenObject((sAuthIP + _T("/") + sPath).c_str(), CComBSTR(sAuthID.c_str()), CComBSTR(sAuthPwd.c_str()),
		ADS_SECURE_AUTHENTICATION,IID_IADsContainer,( void **) &pCont);

	if (SUCCEEDED(hr))
	{
		// 새로운 그룹 추가
		hr = pCont->Create(CComBSTR("group"), CComBSTR((_T("CN=")+ sGroupName).c_str()), &pDisp);
		if (SUCCEEDED(hr))
		{
			// Get the IADs interface.
			hr = pDisp->QueryInterface(IID_IADs, (void**)&pGroup);
			if (SUCCEEDED(hr))
			{
				CComBSTR sbstrProp;
				CComVariant svar;
				
				// 그룹이름
				svar = sGroupName.c_str();
				sbstrProp = "sAMAccountName";
				hr = pGroup->Put(sbstrProp, svar);
				//hr = pGroup->SetInfo();

				// 그룹타입
				svar = nGroupType;
				sbstrProp = "groupType";
				hr = pGroup->Put(sbstrProp, svar);
			
				hr = pGroup->SetInfo();




				svar.Clear();
				pGroup->Release();
			}
			pDisp->Release();
		}
		pCont->Release();
	}
	return hr;
}
			
// 개체 이동
HRESULT ADSIWorker::MoveObject(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sMovePath, tstring sObjectDN)
{
	HRESULT hr;
	IADsContainer *pCont=NULL;
	IDispatch *pDisp=NULL;
	tstring LDIP = L"LDAP://";
	sAuthIP = LDIP + sAuthIP;
	CoInitialize(NULL);

	// 이동할 위치로 바인딩
	hr = ADsOpenObject((sAuthIP + _T("/") + sMovePath).c_str(), CComBSTR(sAuthID.c_str()), CComBSTR(sAuthPwd.c_str()),
		ADS_SECURE_AUTHENTICATION,IID_IADsContainer,( void **) &pCont);
	
	if (SUCCEEDED(hr))
	{
		// 개체 이동 CComBSTR((_T("CN=")+ sGroupName).c_str())
		hr = pCont->MoveHere(CComBSTR((_T("LDAP://") + sObjectDN).c_str()), NULL, &pDisp );
		pCont->Release();
 
		if (SUCCEEDED(hr) )
		{ 
			// You can perform another operation here, such as updating attributes.
			pDisp->Release();
		}
	}
	return hr;
}

// 개체 삭제
HRESULT ADSIWorker::DeleteObject(tstring sAuthIP, tstring sAuthID, tstring sAuthPwd, tstring sDeletePath, tstring sDeleteType, tstring sDeleteName)
{
	HRESULT hr = S_OK;
	IADsContainer *pCont=NULL;
 
	CoInitialize(NULL);
	tstring LDIP = L"LDAP://";
	sAuthIP = LDIP + sAuthIP;
	// 바인딩
	hr = ADsOpenObject(CComBSTR((sAuthIP + L"/" + sDeletePath).c_str()), CComBSTR(sAuthID.c_str()), CComBSTR(sAuthPwd.c_str()),
		ADS_SECURE_AUTHENTICATION,IID_IADsContainer,( void **) &pCont);

	if (!SUCCEEDED(hr))
	{
		 AfxMessageBox(L"바인딩 실패");
	}
	else 
	{
		hr = pCont->Delete(CComBSTR(sDeleteType.c_str()),CComBSTR(sDeleteName.c_str()));
		
		pCont->Release();
	}

	return hr;
}
