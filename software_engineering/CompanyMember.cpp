#include <iostream>
#include <string>
#include "CompanyMember.h"

/*
함수 이름: CompanyMember
기능: CompanyMember 클래스의 생성자로 기능한다.
매개변수: string inputName -> 이름, string inputBusinessNum -> 사업자번호, string inputId -> ID,
		 string inputPassword -> 비밀번호, int inputMemberType -> 멤버 타입
반환값: X
*/
CompanyMember::CompanyMember(string inputName, string inputBusinessNum, string inputId, string inputPassword, int inputMemberType)
	: Member(inputName, inputId, inputPassword, inputMemberType)
{
	businessNum = inputBusinessNum;	// 문자열 복사해서 넣기
}



/*
함수 이름: getBusinessNum
기능: businessNum 값을 가져온다.
매개변수: X
반환값: 사업자번호
*/
string CompanyMember::getBusinessNum()
{
	return businessNum;
}



/*
함수 이름: ~CompanyMember
기능: 소멸자
매개변수: X
반환값: X
*/
CompanyMember::~CompanyMember()
{

}