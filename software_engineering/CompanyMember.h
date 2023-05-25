#pragma once
#include "Member.h"

using namespace std;

/*
Ŭ���� �̸� : CompanyMember
��� : CompanyMember�� �����Ѵ�.
	   businessNum�� �������� �Լ��� ȣ���Ѵ�.
*/
class CompanyMember : public Member
{
private:
	string businessNum;

public:
	CompanyMember(string inputName, string businessNum, string inputId, string inputPassword, int inputMemberType); //������
	virtual string getBusinessNum();		// businessNum ���� �����´�.
	~CompanyMember(); // �Ҹ���
};