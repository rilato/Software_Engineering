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
Ŭ���� �̸� : ApplicationInfoCollection
��� : ���� ����Ʈ�� ���� �Ʒ� ����� ������
	   ä�� ������ ���� �߰�, ���� ����, ȸ�� Ż��� �ش� ȸ�� ���� ����
	   ä�� ������ ���� ������ ��ȯ
*/
class ApplicationInfoCollection {
private:
	vector<ApplicationInfo*> ownedApplicationInfo;

	MemberCollection* memberCollection;
	RecruitInfoCollection* recruitInfoCollection;
public:

	ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitCollection);	// ������

	void addApplicationInfo(RecruitInfo* inputRecruitInfo, string currentLoginId);	// ä�� ���� ��, ���� �߰�
	string removeApplicationInfo(string currentLoginId, string inputBusinessNum); // ���� ���
	void removeAllApplicationInfoCompany(string currentLoginId);	// ȸ�� ȸ�� Ż��� �Ϲ�ȸ���� ���� ���� ����
	void removeAllApplicationInfo(string currentLoginId); //�Ϲ� ȸ�� Ż��� ���� ���� ����
	string getApplicationInfo(string currentLoginId);  //�α��� �� ����� ���������� ��� ȸ�� �̸��� ������������ ��ȯ

	//control -> 3.1.1 -> applicationinfo collection
	string calcAppliedRecruitInfoStats(string currentLoginId); //������ ä�� ���� ��� ���
};