#pragma once
#include <string>
using namespace std;

/*
Ŭ���� �̸� : RecruitInfo
��� : RecruitInfo�� �����Ѵ�.
	   work, deadline, targetNum�� ���� �����´�.
*/
class RecruitInfo
{
private:
	string work; //����
	string targetNum; //�ο� ��
	string deadline; //������
	string companyId; //ä�� ������ ����� ȸ��ȸ�� ID

public:
	RecruitInfo(string inputWork, string inputDeadline, string inputTargetNum, string inputNowLogin);	// ä�� ���� ������
	string getWork();		// ���� ��ȯ
	string getTargetNum();	// �ο� ��
	string getDeadline();	// ä�� ������
	string getCompanyId();	// ȸ�� ID ��ȯ
};
