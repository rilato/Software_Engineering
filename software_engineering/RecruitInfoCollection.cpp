#include <iostream>
#include <string>
#include <map>
#include "RecruitInfo.h"
#include "RecruitInfoCollection.h"


/*
함수 이름: addRecruitInfo
기능: recruitInfo 객체를 매개변수로 받아서 벡터에 순차적으로 넣는다.
매개변수: string work -> 업무, string targetNum -> 인원 수, string deadline -> 신청 마감일, string currentLoginId -> 현재 로그인한 ID
반환값: X
*/
void RecruitInfoCollection::addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId)
{
    RecruitInfo* recruitInfo = new RecruitInfo(work, targetNum, deadline, currentLoginId);
    ownedRecruitInfo.push_back(recruitInfo);
}


/*
함수 이름: getRecruitInfo
기능: 로그인 한 사람이 등록한 모든 채용 정보를 담아 반환한다.
매개변수: string currentLoginId -> 현재 로그인 한 사람의 ID
반환값: string 타입의 returnString 반환
*/
string RecruitInfoCollection::getRecruitInfo(string currentLoginId)
{
    string returnString = "";
    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end(); it++) {
        // 만약 id가 같은 애가 검색되면 그 애들을 returnString에 추가
        if ((*it)->getCompanyId() == currentLoginId) {
            returnString = returnString + "> " + (*it)->getWork() + " ";
            returnString = returnString + (*it)->getTargetNum() + " ";
            returnString = returnString + (*it)->getDeadline() + "\n";
        }
    }
    return returnString;
}


/*
함수 이름: removeAllRecruitInfo
기능: 회원 탈퇴 시 회사 회원의 모든 채용 정보 삭제하는 함수
매개변수: string currentLoginId -> 현재 로그인 한 사람의 ID
반환값: X
*/
void RecruitInfoCollection::removeAllRecruitInfo(string currentLoginId) {
    // recruitInfoCollection에 있는 애들을 맨 처음부터 순차적으로 살핌

    for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end();) {
        // 만약 id가 같은 애가 검색되면 그 애를 삭제
        if ((*it)->getCompanyId() == currentLoginId) {
            delete* it;
            it = ownedRecruitInfo.erase(it);
        }
        else {
            it++;
        }
    }

    return;
}

/*
함수 이름: getRecruitInfoWithoutSign
기능: 로그인 한 사람이 등록한 모든 채용 정보를 담아 ">" 기호를 제외하고 반환한다.
매개변수: string currentLoginId -> 현재 로그인 한 사람의 ID
반환값: string 타입의 returnString 반환
*/
string RecruitInfoCollection::getRecruitInfoWithoutSign(string currentLoginId)
{
    string returnString = "";

    // 현재 시간을 받아옵니다.
    auto now = chrono::system_clock::now();
    time_t now_time_t = chrono::system_clock::to_time_t(now);
    tm now_tm = {};
    localtime_s(&now_tm, &now_time_t);

    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end(); it++) {
        // 만약 id가 같은 애가 검색되면 그 애들을 returnString에 추가
        if ((*it)->getCompanyId() == currentLoginId) {
            // 입력된 문자열을 시간으로 변환합니다.
            istringstream dateDeadline(((*it)->getDeadline()));
            tm input_tm = {};
            dateDeadline >> get_time(&input_tm, "%Y/%m/%d"); // 형식은 "YYYY/MM/DD"
            // 입력된 날짜가 현재보다 이후인지 확인합니다.
            if (input_tm.tm_year > now_tm.tm_year) {
                returnString = returnString + (*it)->getWork() + " ";
                returnString = returnString + (*it)->getTargetNum() + " ";
                returnString = returnString + (*it)->getDeadline() + "\n";
                return returnString;
            }
            else if (input_tm.tm_year == now_tm.tm_year) {
                if (input_tm.tm_mon > now_tm.tm_mon) {
                    returnString = returnString + (*it)->getWork() + " ";
                    returnString = returnString + (*it)->getTargetNum() + " ";
                    returnString = returnString + (*it)->getDeadline() + "\n";
                    return returnString;
                }
                else if (input_tm.tm_mon == now_tm.tm_mon) {
                    if (input_tm.tm_mday >= now_tm.tm_mday) {
                        returnString = returnString + (*it)->getWork() + " ";
                        returnString = returnString + (*it)->getTargetNum() + " ";
                        returnString = returnString + (*it)->getDeadline() + "\n";
                        return returnString;
                    }
                }
            }
        }
    }

    return returnString;

}

/*
함수 이름: calcAddedRecruitInfoStats
기능: 등록한 채용 정보 통계 계산
매개변수: string currentLoginId -> 현재 로그인 한 회사 회원 ID
반환값: string -> 등록한 통계 정보 저장
*/
string RecruitInfoCollection::calcAddedRecruitInfoStats(string currentLoginId)
{
    map<string, int> recruitInfoStats;

    for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end(); ++it) {
        if ((*it)->getCompanyId() == currentLoginId) {
            string work = (*it)->getWork();

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

/*
함수 이름: findWorkById
기능: 업무를 아이디로 찾는다.
매개변수: string companyId -> 회사회원 아이디
반환값: 찾은 업무
*/
string RecruitInfoCollection::findWorkById(string companyId)
{
    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end(); it++) {
        // 만약 id가 같은 애가 검색되면 그 애들을 returnString에 추가
        if ((*it)->getCompanyId() == companyId) {
            return (*it)->getWork();
        }
    }

    return "";
}

/*
함수 이름: findByCompanyID
기능: 회사 회원 ID로 해당 채용 정보를 가져온다.
매개변수: string companyID -> 회사 회원 아이디
반환값: 해당 회사 회원 ID이 등록한 채용 정보가 있으면 그 채용 정보를 반환하고, 없다면 NULL 값을 반환
*/
RecruitInfo* RecruitInfoCollection::findByCompanyId(string companyId)
{
    for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end(); it++) {

        if ((*it)->getCompanyId() == companyId) {
            return *it;
        }
    }

    return NULL; //발견하지 못했을때
}

/*
함수 이름: ~RecruitInfoCollection
기능: 소멸자
매개변수: X
반환값: X
*/
RecruitInfoCollection::~RecruitInfoCollection()
{
    for (int i = 0; i < ownedRecruitInfo.size(); i++)
        ownedRecruitInfo.pop_back();
}
