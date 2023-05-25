#pragma once
#include <string>
using namespace std;

/*
클래스 이름 : Member
기능 : 회원 정보를 저장한다.
	   Name, Id, Password, MemberType의 값을 저장한다.
*/
class Member
{
private:
	string name; //이름
	string id; //로그인 아이디
	string password; //로그인 비밀번호
	int memberType; //회원 타입(회사 회원 1, 일반 회원 2)

public:
	Member(string inputName, string inputId, string inputPassword, int inputMemberType); // 생성자
	string getName(); // 회원 이름을 반환	
	string getId(); // 회원 ID를 반환
	string getPassword(); // 회원 Password를 반환

	int getMemberType(); // 회원 타입 반환

	virtual string getBusinessNum(); // 회사 사업자번호를 반환, CompanyMember 클래스에서 오버라이딩
};
