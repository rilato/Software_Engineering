#include "ApplicationInfo.h"

/*
�Լ� �̸�: ApplicationInfo
���: ������
�Ű�����: RecruitInfo* inputRecruitInfo -> �ش� ä������, string inputGeneralId -> �Ϲ�ȸ�� ���̵�
��ȯ��: X
*/
ApplicationInfo::ApplicationInfo(RecruitInfo* inputRecruitInfo, string inputGeneralId)
{
	recruitInfo = inputRecruitInfo;
	generalId = inputGeneralId;
}
/*
�Լ� �̸�: getGeneralId
���: �Ϲ� ȸ�� ���̵� ��ȯ
�Ű�����: X
��ȯ��: �Ϲ�ȸ�� ���̵�
*/
string ApplicationInfo::getGeneralId()
{
	return generalId;
}

/*
�Լ� �̸�: getRecruitInfo
���: ä�� ���� ��ȯ
�Ű�����: X
��ȯ��: ä������
*/
RecruitInfo* ApplicationInfo::getRecruitInfo()
{
	return recruitInfo;
}

/*
�Լ� �̸�: getRecruitInfoWork
���: ä�� ������ ������ ��ȯ�Ѵ�.
�Ű�����: X
��ȯ��: ä�� ������ ����
*/

string ApplicationInfo::getRecruitInfoWork()
{
	return recruitInfo->getWork();
}


/*
�Լ� �̸�: getRecruitInfoCompanyId
���: ȸ�� ȸ���� companyId�� ��ȯ�Ѵ�.
�Ű�����: X
��ȯ��: ȸ��ȸ���� ID
*/

string ApplicationInfo::getRecruitInfoCompanyId()
{
	return recruitInfo->getCompanyId();
}


