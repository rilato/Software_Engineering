#pragma once
#include "Member.h"
//#include "RecruitInfoCollection.h"

using namespace std;

/*
클래스 이름 : GeneralMember
기능 : GeneralMember를 생성한다.
	   socialSecurityNum을 가져오는 함수를 호출한다.
*/
class GeneralMember : public Member
{
private:
	string socialSecurityNum;
public:
	GeneralMember(string inputName, string inputSocialSecurityNum, string inputId, string inputPassword, int inputMemberType);	// 생성자
	string getSocialSecurityNum();	// socialSecurityNum 값을 가져온다.
};