#include <iostream>
#include "Member.h"
#include "CompanyMember.h"
#include "GeneralMember.h"
#include "MemberCollection.h"

/*
함수 이름: addMember
기능: Member 객체를 매개변수로 받아서 벡터에 순차적으로 넣는다.
매개변수: Member* member -> Member 객체 포인터값
반환값: X
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
함수 이름: removeMember
기능: 회원이 memberCollection 벡터에 존재하는지 확인하고, 만약 존재한다면 해당 객체를 삭제한다.
매개변수: string memberId -> MemberId char 포인터값
반환값: X
*/
void MemberCollection::removeMember(string memberId)
{
    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // 만약 id가 같은 애가 검색되면 그 애 삭제
        if ((*it)->getId() == memberId) {
            delete* it;
            memberCollection.erase(it);
            break;
        }
    }
}

/*
함수 이름: isMember
기능: 로그인 시, 기존에 등록되어있는 회원인지 확인한다.
매개변수: string memberId -> MemberId char 포인터값, string memberPassword -> MemberPassword char 포인터 값
반환값: bool
*/
bool MemberCollection::isMember(string memberId, string memberPassword)
{
    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        if ((*it)->getId() == memberId && (*it)->getPassword() == memberPassword) {
            return true;  // 해당 멤버를 찾은 경우, true return
        }
    }
    return false;  // 찾는 멤버가 없는 경우, false return
}



/*
함수 이름: getMemberType
기능: 로그인 시, 현재 로그인 한 사람의 member type을 확인한다.
매개변수: string memberId -> MemberId char 포인터값, string memberPassword -> MemberPassword char 포인터 값
반환값: int
*/
int MemberCollection::getMemberType(string memberId, string memberPassword)
{
    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        if ((*it)->getId() == memberId && (*it)->getPassword() == memberPassword) {
            return (*it)->getMemberType();  // 해당 멤버를 찾은 경우, memberType return
        }
    }
    return 0;  // 찾는 멤버가 없는 경우
}

/*
함수 이름: findMemberById
기능: 맴버 아이디를 통해 Member 객체를 반환받는다.
매개변수: string memberId -> 찾는데 사용할 맴버의 아이디
반환값: 찾는 맴버 객체
*/
Member* MemberCollection::findMemberById(string memberId)
{

    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        if ((*it)->getId() == memberId) {
            return (*it);  // 해당 멤버를 찾은 경우, memberType return
        }
    }
    return NULL; // 찾는 멤버가 없는 경우 NULL 포인터 반환

}
/*
함수 이름: findBusinessNumByName
기능: 맴버 아이디를 통해 사업자 번호를 반환받는다.
매개변수: string memberName -> 찾는데 사용할 맴버의 이름
반환값: 찾은 사업자 번호
*/
string MemberCollection::findBusinessNumByName(string memberName)
{
    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // 만약 name이 같은 회원을 찾으면
        if ((*it)->getName() == memberName) {
            return (*it)->getBusinessNum();
        }
    }
    return "";
}
/*
함수 이름: findIdByName
기능: 맴버 이름을 통해 아이디를 반환받는다.
매개변수: string memberName -> 찾는데 사용할 맴버의 이름
반환값: 찾은 아이디
*/
string MemberCollection::findIdByName(string memberName)
{
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // 만약 name이 같은 회원을 찾으면
        if ((*it)->getName() == memberName) {
            Member* member = (*it);
            return member->getId();
        }
    }
    return "";
}
/*
함수 이름: findNameById
기능: 맴버 아이디를 통해 이름을 반환받는다.
매개변수: string memberId -> 찾는데 사용할 맴버의 아이디
반환값: 찾은 이름
*/
string MemberCollection::findNameById(string memberId)
{
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // 만약 name이 같은 회원을 찾으면
        if ((*it)->getId() == memberId) {
            Member* member = (*it);
            return member->getName();
        }
    }
    return "";
}

/*
함수 이름: findIdByBusinessNum
기능: 사업자번호를 통해 아이디를 반환받는다.
매개변수: string businessNum -> 찾는데 사용할 사업자번호
반환값: 찾은 아아디
*/

string MemberCollection::findIdByBusinessNum(string businessNum)
{

    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // 만약 num이 같은 회원을 찾으면
        if ((*it)->getBusinessNum() == businessNum) {
            return (*it)->getId();
        }
    }
    return "";
}


/*
함수 이름: ~MemberCollection
기능: 소멸자
매개변수: X
반환값: X
*/
MemberCollection::~MemberCollection()
{
    for (int i = 0; i < memberCollection.size(); i++)
        memberCollection.pop_back();
}