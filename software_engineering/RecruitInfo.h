#pragma once
#include <string>
using namespace std;

/*
클래스 이름 : RecruitInfo
기능 : RecruitInfo를 생성한다.
	   work, deadline, targetNum의 값을 가져온다.
*/
class RecruitInfo
{
private:
	string work; //업무
	string targetNum; //인원 수
	string deadline; //마감일
	string companyId; //채용 정보를 등록한 회사회원 ID

public:
	RecruitInfo(string inputWork, string inputDeadline, string inputTargetNum, string inputNowLogin);	// 채용 정보 생성자
	string getWork();		// 업무 반환
	string getTargetNum();	// 인원 수
	string getDeadline();	// 채용 마감일
	string getCompanyId();	// 회사 ID 반환
};
