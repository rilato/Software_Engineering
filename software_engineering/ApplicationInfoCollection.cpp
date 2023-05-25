#include "ApplicationInfoCollection.h"

/*
함수 이름: ApplicationInfoCollection
기능: 생성자
매개변수: MemberCollection* inputMemberCollection -> 맴버 컬렉션 객체, RecruitInfoCollection* inputRecruitInfoCollection -> 채용정보 컬렉션 객체
반환값: X
*/
ApplicationInfoCollection::ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitInfoCollection)
{
    memberCollection = inputMemberCollection;
    recruitInfoCollection = inputRecruitInfoCollection;
}

/*
함수 이름: getApplicationInfo
기능: 로그인 한 사람의 지원정보를 담아 회사 이름의 오름차순으로 반환한다.
매개변수: string currentLoginId -> 현재 로그인 한 사람의 ID
반환값: string
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
        // 만약 id가 같은 애가 검색되면 그 애들을 returnString에 추가


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
함수 이름: addApplicationInfo
기능: 지원 정보를 등록한다.
매개변수: RecruitInfo* inputRecruitInfo -> 해당하는 채용 정보, string currentLoginId -> 현재 로그인 한 사람의 ID
반환값: X
*/
void ApplicationInfoCollection::addApplicationInfo(RecruitInfo* inputRecruitInfo, string currentLoginId)
{
    ApplicationInfo* applicationInfo = new ApplicationInfo(inputRecruitInfo, currentLoginId);
    ownedApplicationInfo.push_back(applicationInfo);
}

/*
함수 이름: removeApplicationInfo
기능: 지원 정보를 등록한다.
매개변수: string currentLoginId -> 현재 로그인 한 사람의 ID, string inputBusinessNum -> 해당하는 사업자 번호
반환값: 삭제 정보
*/
string ApplicationInfoCollection::removeApplicationInfo(string currentLoginId, string inputBusinessNum)
{

    string returnString = "";
    string id;
    // applicationInfoCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = ownedApplicationInfo.begin(); it != ownedApplicationInfo.end(); it++) {


        string targetCompanyMemberId = memberCollection->findIdByBusinessNum(inputBusinessNum);
        RecruitInfo* targetRecruitInfo = recruitInfoCollection->findByCompanyId(targetCompanyMemberId);

        // 만약 id가 같은 애가 검색되면 그 애를 삭제
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
함수 이름: removeAllApplicationInfoCompany
기능: 회사 회원 탈퇴시 일반회원도 지원 정보 삭제하는 함수
매개변수: string currentLoginId -> 현재 로그인 한 회사 회원의 ID
반환값: X
*/
void ApplicationInfoCollection::removeAllApplicationInfoCompany(string currentLoginId)
{
    // applicationInfoCollection에 있는 애들을 맨 처음부터 순차적으로 살핌

    for (auto it = ownedApplicationInfo.begin(); it != ownedApplicationInfo.end();) {
        // 만약 id가 같은 애가 검색되면 그 애를 삭제
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
함수 이름: removeAllApplicationInfo
기능: 회원 탈퇴 시 일반 회원의 모든 지원 정보 삭제하는 함수
매개변수: string currentLoginId -> 현재 로그인 한 사람의 ID
반환값: X
*/
void ApplicationInfoCollection::removeAllApplicationInfo(string currentLoginId)
{
    // applicationInfoCollection에 있는 애들을 맨 처음부터 순차적으로 살핌

    for (auto it = ownedApplicationInfo.begin(); it != ownedApplicationInfo.end();) {
        // 만약 id가 같은 애가 검색되면 그 애를 삭제
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
함수 이름: calcAppliedRecruitInfoStats
기능: 지원한 채용 정보 통계 계산
매개변수: string currentLoginId -> 현재 로그인 한 일반 회원 ID
반환값: string -> 지원한 통계 정보 저장
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
