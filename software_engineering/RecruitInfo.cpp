#include <iostream>
#include <string>
#include "RecruitInfo.h"

/*
�Լ� �̸�: RecruitInfo
���: ������
�Ű�����: string inputWork -> ����, string inputDeadline -> ��û ������, string inputTargetNum -> �ο� ��
��ȯ��: X
*/
RecruitInfo::RecruitInfo(string inputWork, string inputTargetNum, string inputDeadline, string inputCompanyId)
{
	work = inputWork;
	targetNum = inputTargetNum;
	deadline = inputDeadline;
	companyId = inputCompanyId;
}



/*
�Լ� �̸�: getWork
���: ���� ��ȯ
�Ű�����: X
��ȯ��: string Ÿ���� work ��ȯ
*/
string RecruitInfo::getWork()
{
	return work;
}


/*
�Լ� �̸�: getId
���: ��û ������ ��ȯ
�Ű�����: X
��ȯ��: string Ÿ���� deadline ��ȯ
*/
string RecruitInfo::getDeadline()
{
	return deadline;
}


/*
�Լ� �̸�: getTargetNum
���: �ο� �� ��ȯ
�Ű�����: X
��ȯ��: string Ÿ���� targetNum ��ȯ
*/
string RecruitInfo::getTargetNum()
{
	return targetNum;
}


/*
�Լ� �̸�: getCompanyId
���: Company ID ��ȯ
�Ű�����: X
��ȯ��: string Ÿ���� companyId ��ȯ
*/
string RecruitInfo::getCompanyId()
{
	return companyId;
}

