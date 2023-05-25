#include <iostream>
#include <string>
#include "Member.h"

/*
함수 이름: Member
기능: 생성자
매개변수: const string inputName -> 회원 이름, const string inputId -> 회원 ID, const string inputPassword -> 회원 Password,
		  int inputMemberType -> 회원 Type
반환값: X
*/
Member::Member(string inputName, string inputId, string inputPassword, int inputMemberType)
{
	name = inputName;
	id = inputId;
	password = inputPassword;
	memberType = inputMemberType;		// 멤버 타입은 int type 이므로 그대로 넣기
}

/*
함수 이름: getName
기능: 회원 이름 반환
매개변수: X
반환값: 회원 이름
*/
string Member::getName()
{
	return name;
}

/*
함수 이름: getId
기능: 회원 ID 반환
매개변수: X
반환값: 회원 ID
*/
string Member::getId()
{
	return id;
}

/*
함수 이름: getPassword
기능: 회원 Password 반환
매개변수: X
반환값: 회원 Password
*/
string Member::getPassword()
{
	return password;
}

/*
함수 이름: getMemberType
기능: 회원 Member Type 반환
매개변수: X
반환값: 회원 Member Type
*/
int Member::getMemberType()
{
	return memberType;
}

/*
함수 이름: getBusinessNum
기능: CompanyMember 클래스에서 오버라이딩하기 위한 virtual 함수
	  회원 Business Num 반환을 위함
매개변수: X
반환값: 빈 문자열
*/
string Member::getBusinessNum()
{
	return "";
}