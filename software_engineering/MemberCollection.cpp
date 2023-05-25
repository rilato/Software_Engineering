#include <iostream>
#include "Member.h"
#include "CompanyMember.h"
#include "GeneralMember.h"
#include "MemberCollection.h"

/*
�Լ� �̸�: addMember
���: Member ��ü�� �Ű������� �޾Ƽ� ���Ϳ� ���������� �ִ´�.
�Ű�����: Member* member -> Member ��ü �����Ͱ�
��ȯ��: X
*/
void MemberCollection::addMember(string name, string number, string id, string password, int memType)
{
    Member* member;
    if (memType == 1) {
        member = new CompanyMember(name, number, id, password, memType);
    }
    else {
        member = new GeneralMember(name, number, id, password, memType);
    }
    memberCollection.push_back(member);
}


/*
�Լ� �̸�: removeMember
���: ȸ���� memberCollection ���Ϳ� �����ϴ��� Ȯ���ϰ�, ���� �����Ѵٸ� �ش� ��ü�� �����Ѵ�.
�Ű�����: string memberId -> MemberId char �����Ͱ�
��ȯ��: X
*/
void MemberCollection::removeMember(string memberId)
{
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �� ����
        if ((*it)->getId() == memberId) {
            delete* it;
            memberCollection.erase(it);
            break;
        }
    }
}

/*
�Լ� �̸�: isMember
���: �α��� ��, ������ ��ϵǾ��ִ� ȸ������ Ȯ���Ѵ�.
�Ű�����: string memberId -> MemberId char �����Ͱ�, string memberPassword -> MemberPassword char ������ ��
��ȯ��: bool
*/
bool MemberCollection::isMember(string memberId, string memberPassword)
{
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        if ((*it)->getId() == memberId && (*it)->getPassword() == memberPassword) {
            return true;  // �ش� ����� ã�� ���, true return
        }
    }
    return false;  // ã�� ����� ���� ���, false return
}



/*
�Լ� �̸�: getMemberType
���: �α��� ��, ���� �α��� �� ����� member type�� Ȯ���Ѵ�.
�Ű�����: string memberId -> MemberId char �����Ͱ�, string memberPassword -> MemberPassword char ������ ��
��ȯ��: int
*/
int MemberCollection::getMemberType(string memberId, string memberPassword)
{
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        if ((*it)->getId() == memberId && (*it)->getPassword() == memberPassword) {
            return (*it)->getMemberType();  // �ش� ����� ã�� ���, memberType return
        }
    }
    return 0;  // ã�� ����� ���� ���
}

/*
�Լ� �̸�: findMemberById
���: �ɹ� ���̵� ���� Member ��ü�� ��ȯ�޴´�.
�Ű�����: string memberId -> ã�µ� ����� �ɹ��� ���̵�
��ȯ��: ã�� �ɹ� ��ü
*/
Member* MemberCollection::findMemberById(string memberId)
{

    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        if ((*it)->getId() == memberId) {
            return (*it);  // �ش� ����� ã�� ���, memberType return
        }
    }
    return NULL; // ã�� ����� ���� ��� NULL ������ ��ȯ

}
/*
�Լ� �̸�: findBusinessNumByName
���: �ɹ� ���̵� ���� ����� ��ȣ�� ��ȯ�޴´�.
�Ű�����: string memberName -> ã�µ� ����� �ɹ��� �̸�
��ȯ��: ã�� ����� ��ȣ
*/
string MemberCollection::findBusinessNumByName(string memberName)
{
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // ���� name�� ���� ȸ���� ã����
        if ((*it)->getName() == memberName) {
            return (*it)->getBusinessNum();
        }
    }
    return "";
}
/*
�Լ� �̸�: findIdByName
���: �ɹ� �̸��� ���� ���̵� ��ȯ�޴´�.
�Ű�����: string memberName -> ã�µ� ����� �ɹ��� �̸�
��ȯ��: ã�� ���̵�
*/
string MemberCollection::findIdByName(string memberName)
{
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // ���� name�� ���� ȸ���� ã����
        if ((*it)->getName() == memberName) {
            Member* member = (*it);
            return member->getId();
        }
    }
    return "";
}
/*
�Լ� �̸�: findNameById
���: �ɹ� ���̵� ���� �̸��� ��ȯ�޴´�.
�Ű�����: string memberId -> ã�µ� ����� �ɹ��� ���̵�
��ȯ��: ã�� �̸�
*/
string MemberCollection::findNameById(string memberId)
{
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // ���� name�� ���� ȸ���� ã����
        if ((*it)->getId() == memberId) {
            Member* member = (*it);
            return member->getName();
        }
    }
    return "";
}

/*
�Լ� �̸�: findIdByBusinessNum
���: ����ڹ�ȣ�� ���� ���̵� ��ȯ�޴´�.
�Ű�����: string businessNum -> ã�µ� ����� ����ڹ�ȣ
��ȯ��: ã�� �ƾƵ�
*/

string MemberCollection::findIdByBusinessNum(string businessNum)
{

    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // ���� num�� ���� ȸ���� ã����
        if ((*it)->getBusinessNum() == businessNum) {
            return (*it)->getId();
        }
    }
    return "";
}


/*
�Լ� �̸�: ~MemberCollection
���: �Ҹ���
�Ű�����: X
��ȯ��: X
*/
MemberCollection::~MemberCollection()
{
    for (int i = 0; i < memberCollection.size(); i++)
        memberCollection.pop_back();
}