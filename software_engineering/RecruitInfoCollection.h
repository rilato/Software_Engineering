#pragma once
#include "RecruitInfo.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace std;

/*
클래스 이름 : RecruitInfoCollection
기능 : 채용 정보 리스트에 대한 아래 기능을 구현함
	   채용 정보 등록 및 조회를 진행한다.
*/
class RecruitInfoCollection
{
private:
	vector <RecruitInfo*> ownedRecruitInfo;

public:
	void addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId);	// 채용 정보 등록 시, 새로운 채용 정보를 recruitInfoCollection에 추가
	string getRecruitInfo(string currentLoginId); // 로그인 한 사람이 등록한 모든 채용 정보를 담아 반환
	void removeAllRecruitInfo(string currentLoginId); // 회원 탈퇴하려는 사람의 채용 정보를 모두 삭제
	string getRecruitInfoWithoutSign(string currentLoginId); // ">" 기호를 빼고 채용 정보를 반환
	RecruitInfo* findByCompanyId(string companyId);  // 회사 ID가 일치하는 채용 정보를 반환
	string findWorkById(string companyId); //회사 ID가 일치하는 채용 정보의 업무 명 반환

	//control -> 2.1.1 -> recruitinfo collection
	string calcAddedRecruitInfoStats(string currentLoginId); //등록한 채용 정보 통계 계산

	~RecruitInfoCollection();	// 소멸자
};