#pragma once
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "ApplicationInfo.h"
#include "MemberCollection.h"
#include "RecruitInfoCollection.h"

using namespace std;

/*
클래스 이름 : ApplicationInfoCollection
기능 : 지원 리스트에 대한 아래 기능을 구현함
	   채용 지원시 지원 추가, 지원 삭제, 회원 탈퇴시 해당 회원 지원 삭제
	   채용 지원에 대한 정보를 반환
*/
class ApplicationInfoCollection {
private:
	vector<ApplicationInfo*> ownedApplicationInfo;

	MemberCollection* memberCollection;
	RecruitInfoCollection* recruitInfoCollection;
public:

	ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitCollection);	// 생성자

	void addApplicationInfo(RecruitInfo* inputRecruitInfo, string currentLoginId);	// 채용 지원 시, 지원 추가
	string removeApplicationInfo(string currentLoginId, string inputBusinessNum); // 지원 취소
	void removeAllApplicationInfoCompany(string currentLoginId);	// 회사 회원 탈퇴시 일반회원도 지원 정보 삭제
	void removeAllApplicationInfo(string currentLoginId); //일반 회원 탈퇴시 지원 정보 삭제
	string getApplicationInfo(string currentLoginId);  //로그인 한 사람의 지원정보를 담아 회사 이름의 오름차순으로 반환

	//control -> 3.1.1 -> applicationinfo collection
	string calcAppliedRecruitInfoStats(string currentLoginId); //지원한 채용 정보 통계 계산
};