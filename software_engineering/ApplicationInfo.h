#pragma once
#include <iostream>
#include <string>
#include <map>
#include "RecruitInfo.h"
using namespace std;

/*
Ŭ���� �̸� : ApplicationInfo
��� : ���� ������ �����Ѵ�.
	   �Ϲ� ȸ���� ä�� ����, ������ ������ �� �ִ�.
*/
class ApplicationInfo {

private:
	RecruitInfo* recruitInfo;
	string generalId;

public:
	ApplicationInfo(RecruitInfo* inputRecruitInfo, string inputGeneralId); // ������

	string getGeneralId(); // �Ϲ� ȸ�� ID�� ��������
	RecruitInfo* getRecruitInfo(); //  ä�� ������ ��������
	string getRecruitInfoWork(); // ä�� ������ ������ ��������	
	string getRecruitInfoCompanyId(); // ä�� ������ ������ ��������
};


