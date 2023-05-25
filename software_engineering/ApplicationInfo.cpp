#include "ApplicationInfo.h"

/*
함수 이름: ApplicationInfo
기능: 생성자
매개변수: RecruitInfo* inputRecruitInfo -> 해당 채용정보, string inputGeneralId -> 일반회원 아이디
반환값: X
*/
ApplicationInfo::ApplicationInfo(RecruitInfo* inputRecruitInfo, string inputGeneralId)
{
	recruitInfo = inputRecruitInfo;
	generalId = inputGeneralId;
}
/*
함수 이름: getGeneralId
기능: 일반 회원 아이디 반환
매개변수: X
반환값: 일반회원 아이디
*/
string ApplicationInfo::getGeneralId()
{
	return generalId;
}

/*
함수 이름: getRecruitInfo
기능: 채용 정보 반환
매개변수: X
반환값: 채용정보
*/
RecruitInfo* ApplicationInfo::getRecruitInfo()
{
	return recruitInfo;
}

/*
함수 이름: getRecruitInfoWork
기능: 채용 정보의 업무를 반환한다.
매개변수: X
반환값: 채용 정보의 업무
*/

string ApplicationInfo::getRecruitInfoWork()
{
	return recruitInfo->getWork();
}


/*
함수 이름: getRecruitInfoCompanyId
기능: 회사 회원의 companyId를 반환한다.
매개변수: X
반환값: 회사회원의 ID
*/

string ApplicationInfo::getRecruitInfoCompanyId()
{
	return recruitInfo->getCompanyId();
}


