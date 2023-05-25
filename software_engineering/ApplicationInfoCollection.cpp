#include "ApplicationInfoCollection.h"

/*
�Լ� �̸�: ApplicationInfoCollection
���: ������
�Ű�����: MemberCollection* inputMemberCollection -> �ɹ� �÷��� ��ü, RecruitInfoCollection* inputRecruitInfoCollection -> ä������ �÷��� ��ü
��ȯ��: X
*/
ApplicationInfoCollection::ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitInfoCollection)
{
    memberCollection = inputMemberCollection;
    recruitInfoCollection = inputRecruitInfoCollection;
}

/*
�Լ� �̸�: getApplicationInfo
���: �α��� �� ����� ���������� ��� ȸ�� �̸��� ������������ ��ȯ�Ѵ�.
�Ű�����: string currentLoginId -> ���� �α��� �� ����� ID
��ȯ��: string
*/
string ApplicationInfoCollection::getApplicationInfo(string currentLoginId)
{

    string id;
    string name;
    string work;
    string targetNum;
    string deadline;
    string returnString = "";

    sort(ownedApplicationInfo.begin(), ownedApplicationInfo.end());

    vector <string> forSort;

    for (auto it = ownedApplicationInfo.begin(); it != ownedApplicationInfo.end(); it++) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ֵ��� returnString�� �߰�


        if ((*it)->getGeneralId() == currentLoginId) {
            string tempStr = "";

            id = (*it)->getRecruitInfo()->getCompanyId();
            Member* member = memberCollection->findMemberById(id);

            tempStr = tempStr + "> " + member->getName() + " ";
            tempStr = tempStr + member->getBusinessNum() + " ";
            tempStr = tempStr + (*it)->getRecruitInfo()->getWork() + " ";
            tempStr = tempStr + (*it)->getRecruitInfo()->getTargetNum() + " ";
            tempStr = tempStr + (*it)->getRecruitInfo()->getDeadline();

            forSort.push_back(tempStr);

        }
    }

    sort(forSort.begin(), forSort.end());
    for (int i = 0; i < forSort.size(); ++i) {
        returnString += forSort[i];
        returnString += '\n';
    }

    return returnString;
}

/*
�Լ� �̸�: addApplicationInfo
���: ���� ������ ����Ѵ�.
�Ű�����: RecruitInfo* inputRecruitInfo -> �ش��ϴ� ä�� ����, string currentLoginId -> ���� �α��� �� ����� ID
��ȯ��: X
*/
void ApplicationInfoCollection::addApplicationInfo(RecruitInfo* inputRecruitInfo, string currentLoginId)
{
    ApplicationInfo* applicationInfo = new ApplicationInfo(inputRecruitInfo, currentLoginId);
    ownedApplicationInfo.push_back(applicationInfo);
}

/*
�Լ� �̸�: removeApplicationInfo
���: ���� ������ ����Ѵ�.
�Ű�����: string currentLoginId -> ���� �α��� �� ����� ID, string inputBusinessNum -> �ش��ϴ� ����� ��ȣ
��ȯ��: ���� ����
*/
string ApplicationInfoCollection::removeApplicationInfo(string currentLoginId, string inputBusinessNum)
{

    string returnString = "";
    string id;
    // applicationInfoCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = ownedApplicationInfo.begin(); it != ownedApplicationInfo.end(); it++) {


        string targetCompanyMemberId = memberCollection->findIdByBusinessNum(inputBusinessNum);
        RecruitInfo* targetRecruitInfo = recruitInfoCollection->findByCompanyId(targetCompanyMemberId);

        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ָ� ����
        if ((*it)->getGeneralId() == currentLoginId && (*it)->getRecruitInfo() == targetRecruitInfo) {

            id = (*it)->getRecruitInfo()->getCompanyId();
            Member* member = memberCollection->findMemberById(id);

            returnString = returnString + "> " + member->getName() + " ";
            returnString = returnString + member->getBusinessNum() + " ";
            returnString = returnString + (*it)->getRecruitInfo()->getWork() + "\n";

            delete* it;
            ownedApplicationInfo.erase(it);
            break;
        }
    }

    return returnString;
}


/*
�Լ� �̸�: removeAllApplicationInfoCompany
���: ȸ�� ȸ�� Ż��� �Ϲ�ȸ���� ���� ���� �����ϴ� �Լ�
�Ű�����: string currentLoginId -> ���� �α��� �� ȸ�� ȸ���� ID
��ȯ��: X
*/
void ApplicationInfoCollection::removeAllApplicationInfoCompany(string currentLoginId)
{
    // applicationInfoCollection�� �ִ� �ֵ��� �� ó������ ���������� ����

    for (auto it = ownedApplicationInfo.begin(); it != ownedApplicationInfo.end();) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ָ� ����
        if ((*it)->getRecruitInfoCompanyId() == currentLoginId) {
            delete* it;
            it = ownedApplicationInfo.erase(it);
        }
        else {
            it++;
        }
    }

    return;
}


/*
�Լ� �̸�: removeAllApplicationInfo
���: ȸ�� Ż�� �� �Ϲ� ȸ���� ��� ���� ���� �����ϴ� �Լ�
�Ű�����: string currentLoginId -> ���� �α��� �� ����� ID
��ȯ��: X
*/
void ApplicationInfoCollection::removeAllApplicationInfo(string currentLoginId)
{
    // applicationInfoCollection�� �ִ� �ֵ��� �� ó������ ���������� ����

    for (auto it = ownedApplicationInfo.begin(); it != ownedApplicationInfo.end();) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ָ� ����
        if ((*it)->getGeneralId() == currentLoginId) {
            delete* it;
            it = ownedApplicationInfo.erase(it);
        }
        else {
            it++;
        }
    }

    return;
}


/*
�Լ� �̸�: calcAppliedRecruitInfoStats
���: ������ ä�� ���� ��� ���
�Ű�����: string currentLoginId -> ���� �α��� �� �Ϲ� ȸ�� ID
��ȯ��: string -> ������ ��� ���� ����
*/
string ApplicationInfoCollection::calcAppliedRecruitInfoStats(string currentLoginId)
{
    map<string, int> recruitInfoStats;

    for (auto it = ownedApplicationInfo.begin(); it != ownedApplicationInfo.end(); ++it) {
        if ((*it)->getGeneralId() == currentLoginId) {
            string work = (*it)->getRecruitInfoWork();

            if (recruitInfoStats.find(work) == recruitInfoStats.end()) {
                recruitInfoStats[work] = 1;
            }
            else {
                recruitInfoStats[work] += 1;
            }
        }
    }

    string returnString = "";
    for (auto it = recruitInfoStats.begin(); it != recruitInfoStats.end(); ++it) {
        returnString += ">";
        returnString += it->first;
        returnString += " ";
        returnString += to_string(it->second);
        returnString += "\n";
    }
    return returnString;
}
