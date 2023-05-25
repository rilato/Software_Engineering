#pragma once
#include "Member.h"
#include <string>
#include <vector>

using namespace std;

/*
Ŭ���� �̸� : MemberCollection
��� : ��� ����Ʈ�� ���� �Ʒ� ����� ������
	   ����� ȸ�� ����, �α���, �α׾ƿ�, ȸ�� Ż�� �����Ѵ�.
	   ����� Ÿ���� Ȯ���Ѵ�.
*/
class MemberCollection
{
private:
	vector <Member*> memberCollection;

public:

	void addMember(string name, string number, string id, string password, int memType);	// ȸ�� ���� ��, ȸ�� �߰�
	void removeMember(string memberId); // ȸ�� Ż�� ��, ȸ�� ����
	bool isMember(string memberId, string memberPassword); // ��ϵ� ȸ������ Ȯ�� (�α���)
	int getMemberType(string memberId, string memberPassword);	// ȸ�� ȸ������, �Ϲ� ȸ������ ������ �� �ִ� memberType�� ��������
	Member* findMemberById(string memberId); // ȸ�� ID�� ȸ�� ������ ��������.
	string findBusinessNumByName(string memberName); // ȸ�� �̸����� ȸ�� ����� ��ȣ ��������.
	string findIdByName(string memberName); // ȸ�� �̸����� ȸ�� ID ��������.
	string findNameById(string memberId); // ȸ�� ID�� ȸ�� �̸� ��������.
	string findIdByBusinessNum(string businessNum); // ȸ�� ����� ��ȣ�� ȸ�� ID ��������. 
	~MemberCollection(); // �Ҹ���
};