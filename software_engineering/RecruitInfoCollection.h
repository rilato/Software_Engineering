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
Ŭ���� �̸� : RecruitInfoCollection
��� : ä�� ���� ����Ʈ�� ���� �Ʒ� ����� ������
	   ä�� ���� ��� �� ��ȸ�� �����Ѵ�.
*/
class RecruitInfoCollection
{
private:
	vector <RecruitInfo*> ownedRecruitInfo;

public:
	void addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId);	// ä�� ���� ��� ��, ���ο� ä�� ������ recruitInfoCollection�� �߰�
	string getRecruitInfo(string currentLoginId); // �α��� �� ����� ����� ��� ä�� ������ ��� ��ȯ
	void removeAllRecruitInfo(string currentLoginId); // ȸ�� Ż���Ϸ��� ����� ä�� ������ ��� ����
	string getRecruitInfoWithoutSign(string currentLoginId); // ">" ��ȣ�� ���� ä�� ������ ��ȯ
	RecruitInfo* findByCompanyId(string companyId);  // ȸ�� ID�� ��ġ�ϴ� ä�� ������ ��ȯ
	string findWorkById(string companyId); //ȸ�� ID�� ��ġ�ϴ� ä�� ������ ���� �� ��ȯ

	//control -> 2.1.1 -> recruitinfo collection
	string calcAddedRecruitInfoStats(string currentLoginId); //����� ä�� ���� ��� ���

	~RecruitInfoCollection();	// �Ҹ���
};