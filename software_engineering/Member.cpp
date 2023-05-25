#include <iostream>
#include <string>
#include "Member.h"

/*
�Լ� �̸�: Member
���: ������
�Ű�����: const string inputName -> ȸ�� �̸�, const string inputId -> ȸ�� ID, const string inputPassword -> ȸ�� Password,
		  int inputMemberType -> ȸ�� Type
��ȯ��: X
*/
Member::Member(string inputName, string inputId, string inputPassword, int inputMemberType)
{
	name = inputName;
	id = inputId;
	password = inputPassword;
	memberType = inputMemberType;		// ��� Ÿ���� int type �̹Ƿ� �״�� �ֱ�
}

/*
�Լ� �̸�: getName
���: ȸ�� �̸� ��ȯ
�Ű�����: X
��ȯ��: ȸ�� �̸�
*/
string Member::getName()
{
	return name;
}

/*
�Լ� �̸�: getId
���: ȸ�� ID ��ȯ
�Ű�����: X
��ȯ��: ȸ�� ID
*/
string Member::getId()
{
	return id;
}

/*
�Լ� �̸�: getPassword
���: ȸ�� Password ��ȯ
�Ű�����: X
��ȯ��: ȸ�� Password
*/
string Member::getPassword()
{
	return password;
}

/*
�Լ� �̸�: getMemberType
���: ȸ�� Member Type ��ȯ
�Ű�����: X
��ȯ��: ȸ�� Member Type
*/
int Member::getMemberType()
{
	return memberType;
}

/*
�Լ� �̸�: getBusinessNum
���: CompanyMember Ŭ�������� �������̵��ϱ� ���� virtual �Լ�
	  ȸ�� Business Num ��ȯ�� ����
�Ű�����: X
��ȯ��: �� ���ڿ�
*/
string Member::getBusinessNum()
{
	return "";
}