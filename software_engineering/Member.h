#pragma once
#include <string>
using namespace std;

/*
Ŭ���� �̸� : Member
��� : ȸ�� ������ �����Ѵ�.
	   Name, Id, Password, MemberType�� ���� �����Ѵ�.
*/
class Member
{
private:
	string name; //�̸�
	string id; //�α��� ���̵�
	string password; //�α��� ��й�ȣ
	int memberType; //ȸ�� Ÿ��(ȸ�� ȸ�� 1, �Ϲ� ȸ�� 2)

public:
	Member(string inputName, string inputId, string inputPassword, int inputMemberType); // ������
	string getName(); // ȸ�� �̸��� ��ȯ	
	string getId(); // ȸ�� ID�� ��ȯ
	string getPassword(); // ȸ�� Password�� ��ȯ

	int getMemberType(); // ȸ�� Ÿ�� ��ȯ

	virtual string getBusinessNum(); // ȸ�� ����ڹ�ȣ�� ��ȯ, CompanyMember Ŭ�������� �������̵�
};
