#pragma once
#include <iostream>
#include <string>
#include <map>
#include "RecruitInfo.h"
using namespace std;

/*
클래스 이름 : ApplicationInfo
기능 : 지원 정보를 저장한다.
	   일반 회원과 채용 정보, 업무를 가져올 수 있다.
*/
class ApplicationInfo {

private:
	RecruitInfo* recruitInfo;
	string generalId;

public:
	ApplicationInfo(RecruitInfo* inputRecruitInfo, string inputGeneralId); // 생성자

	string getGeneralId(); // 일반 회원 ID를 가져오기
	RecruitInfo* getRecruitInfo(); //  채용 정보를 가져오기
	string getRecruitInfoWork(); // 채용 정보의 업무를 가져오기	
	string getRecruitInfoCompanyId(); // 채용 정보의 업무를 가져오기
};


