#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//Entity 헤더
#include "MemberCollection.h"
#include "Member.h"
#include "RecruitInfo.h"
#include "RecruitInfoCollection.h"
#include "ApplicationInfoCollection.h"
#include "CompanyMember.h"
#include "GeneralMember.h"

//회원관리 서브시스템 헤더
#include "LoginUI.h"
#include "Login.h"
#include "LogoutUI.h"
#include "Logout.h"
#include "RegisterUI.h"
#include "Register.h"
#include "WithdrawUI.h"
#include "Withdraw.h"

//채용정보관리 서브시스템 헤더
#include "AddRecruitInfoUI.h"
#include "AddRecruitInfo.h"
#include "ViewAddedRecruitListUI.h"
#include "ViewAddedRecruitList.h"

//채용지원 서브시스템 헤더
#include "SearchRecruitInfoUI.h"
#include "SearchRecruitInfo.h"
#include "ApplyImmediatelyUI.h"
#include "ApplyImmediately.h"
#include "ViewApplicationInfoUI.h"
#include "ViewApplicationInfo.h"
#include "CancelApplicationUI.h"
#include "CancelApplication.h"

//채용정보통계 서브시스템 헤더
#include "ViewRecruitInfoStatsUI.h"
#include "ViewRecruitInfoStats.h"

using namespace std;

//상수 선언
#define endl '\n'
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

ifstream fin; // 텍스트 파일 열기
ofstream fout; // 텍스트 파일로 추출하기

//함수 선언
void run();
void program_exit();


/*
    함수 이름 : main
    기능: 파일 스트림 열고 run 함수 실행. 정상 종료 시 0을 리턴
    매개변수: X
    반환값: int
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fin.open(INPUT_FILE);       // 파일 ifstream 열기
    fout.open(OUTPUT_FILE);     // 파일 ofstream 열기

    run();

    fin.close(); // 파일 ifstream 닫기
    fout.close(); // 파일 ofstream 닫기

    return 0;
}

/*
    함수 이름 : run
    기능: 파일을 한 줄씩 읽어온 후, 읽어 온 내용에 맞게 함수를 실행함.
    매개변수: X
    반환값: X
*/
void run()
{
    // 파일이 열리지 않는 경우
    if (!fin || !fout) {
        cout << "파일을 열 수 없습니다." << endl;
        return;
    }

    string inputEvent;  // 현재 파일에서 읽어온 한 줄
    bool keepGoing = 1;  // keepGoing이 1이면 계속해서 파일을 읽고, 0이 되는 순간 while문 탈출

    // MemberCollection 인스턴스 생성
    MemberCollection memberCollection = MemberCollection();
    // RecruitInfoCollection 인스턴스 생성
    RecruitInfoCollection recruitInfoCollection = RecruitInfoCollection();
    // ApplicationInfoCollection 인스턴스 생성
    ApplicationInfoCollection applicationInfoCollection = ApplicationInfoCollection(&memberCollection, &recruitInfoCollection);

    string currentLoginId = "";       // 현재 로그인 중인 회원 ID를 currentLoginId에 저장
    int currentMemberType = 0;         // 1이면 회사 회원, 2면 일반 회원
    // currentMemberType이 1일 때에는 회사 회원 관련 시스템이 작동하고, 일반 회원 관련 시스템에 접근 시 아무 행동도 하지 않으며,
    // currentMemberType이 2일 때에는 일반 회원 관련 시스템이 작동하고, 회사 회원 관련 시스템에 접근 시 아무 행동도 하지 않는다.

    while (keepGoing) {
        getline(fin, inputEvent); // input.txt 파일 한 줄씩 읽어 inputEvent에 저장

        int firstEvent = inputEvent[0] - '0';       // 메뉴 파싱을 위한 첫번째 숫자
        int secondEvent = inputEvent[2] - '0';      // 메뉴 파싱을 위한 두번째 숫자

        string tempId = currentLoginId;     // 로그아웃 하면 파일에 currentLoginId 내용을 작성해야 하는데, 아래 함수 실행 시 currentLoginId이 사라지므로, 잠시 담아 둠
        // 회원 탈퇴할 때에도 마찬가지

        switch (firstEvent) {
        case 1:
        {
            switch (secondEvent) {
                // 1.1 회원 가입
            case 1:
            {
                Register regist = Register(&memberCollection);  // 컨트롤 생성
                regist.getRegisterUI()->init(&fout);    // UI 호출
                regist.getRegisterUI()->startInterface();   // 인터페이스 시작

                currentMemberType = regist.getRegisterUI()->selectMemberType(inputEvent); // 1. 1. 1에서 맨 뒤의 1이 currentMemberType에 저장됨 
                regist.getRegisterUI()->requestRegister(inputEvent, currentMemberType);   // Boundary에 있는 requestRegister 함수 호출
            }
            break;
            // 1.2 회원 탈퇴
            case 2:
            {
                Withdraw withdraw = Withdraw(&memberCollection, &recruitInfoCollection, &applicationInfoCollection);    // 컨트롤 생성
                withdraw.getWithdrawUI()->init(&fout);  // UI 호출
                withdraw.getWithdrawUI()->startInterface();    // 인터페이스 시작

                if (currentLoginId == "") // 로그인 하지 않은 상태라면 currentLoginId은 ""이고, 회원 탈퇴할 수 없으므로, 아무 것도 하지 않고 건너뜀
                    break;
                else {              // 로그인 되었을 때에만 회원 탈퇴
                    withdraw.getWithdrawUI()->requestWithdraw(currentLoginId, tempId, currentMemberType);     // Boundary에 있는 requestWithdraw 함수 호출
                    break;
                }
            }
            break;
            }
        }
        break;
        case 2:
        {
            switch (secondEvent) {
                // 2.1 로그인
            case 1:
            {
                Login login = Login(&memberCollection);     // 컨트롤 생성
                login.getLoginUI()->init(&fout);    // UI 호출
                login.getLoginUI()->startInterface();    // 인터페이스 시작

                if (currentLoginId != "")                 // 누군가 로그인 중이면 로그인 할 수 없으므로, 아무 것도 하지 않고 건너뜀
                    break;

                else {
                    login.getLoginUI()->verifyLogin(inputEvent, currentLoginId, currentMemberType);   // Boundary에 있는 requestLogin 함수 호출
                    break;
                }
            }
            break;
            // 2.2 로그아웃
            case 2:
            {
                Logout logout = Logout();       // 컨트롤 생성
                logout.getLogoutUI()->init(&fout);      // UI 호출
                logout.getLogoutUI()->startInterface();    // 인터페이스 시작

                if (currentLoginId == "")               // 로그인 하지 않은 상태라면 로그아웃할 수 없으므로, 아무 것도 하지 않고 건너뜀
                    break;
                else {              // 로그인 한 상태에서만 로그아웃 진행 가능!
                    logout.getLogoutUI()->requestLogout(currentLoginId, tempId, currentMemberType);       // 로그인 한 상태라면 로그아웃 진행 가능. Boundary에 있는 requestLogout 함수 호출
                    break;
                }
            }
            break;
            }
            break;
        case 3:
        {
            switch (secondEvent) {
                //3.1 채용 정보 등록
            case 1:
            {
                AddRecruitInfo addRecruitInfo = AddRecruitInfo(&recruitInfoCollection);     // 컨트롤 생성
                addRecruitInfo.getAddRecruitInfoUI()->init(&fout);      // UI 호출
                addRecruitInfo.getAddRecruitInfoUI()->startInterface();    // 인터페이스 시작

                if (currentMemberType == 2)        // 일반 회원은 이 작업 수행 불가능
                    break;
                else {
                    addRecruitInfo.getAddRecruitInfoUI()->requestAddRecruitInfo(inputEvent, currentLoginId);     // recruitInfoCollection 벡터에 recruitInfo를 추가하기 위한 함수 호출
                }
                break;
            }
            //3.2 채용 정보 조회
            case 2:
            {
                ViewAddedRecruitList viewAddedRecruitList = ViewAddedRecruitList(&recruitInfoCollection);   // 컨트롤 생성
                viewAddedRecruitList.getViewAddedRecruitListUI()->init(&fout);      // UI 호출
                viewAddedRecruitList.getViewAddedRecruitListUI()->startInterface();     // 인터페이스 시작

                if (currentMemberType == 2)
                    break;
                else {
                    viewAddedRecruitList.getViewAddedRecruitListUI()->showRecruitInfo(currentLoginId);      // 등록한 채용 정보 모두 조회
                    break;
                }
            }
            break;
            }
            break;
        }
        case 4:
        {
            switch (secondEvent) {
                //4.1 채용 정보 검색
            case 1:
            {
                SearchRecruitInfo searchRecruitInfo = SearchRecruitInfo(&recruitInfoCollection, &memberCollection);  // 컨트롤 생성
                searchRecruitInfo.getSearchRecruitInfoUI()->init(&fout);        // UI 호출
                searchRecruitInfo.getSearchRecruitInfoUI()->startInterface(); // 인터페이스 시작

                if (currentMemberType == 1) // 회사 회원은 이 작업 수행 불가능
                    break;
                else {
                    searchRecruitInfo.getSearchRecruitInfoUI()->showSearchRecruitInfo(inputEvent);
                    break;
                }
            }
            //4.2 채용 지원
            case 2:
            {
                ApplyImmediately applyImmediately = ApplyImmediately(&applicationInfoCollection,
                    &recruitInfoCollection, &memberCollection); // 컨트롤 생성
                applyImmediately.getApplyImmediatelyUI()->init(&fout);      // UI 호출
                applyImmediately.getApplyImmediatelyUI()->startInterface();     //인터페이스 시작

                if (currentMemberType == 1) // 회사 회원은 이 작업 수행 불가능
                    break;
                else
                {
                    applyImmediately.getApplyImmediatelyUI()->showApplyImmediately(inputEvent, currentLoginId);

                }
                break;
            }
            //4.3 지원 정보 조회
            case 3:
            {
                ViewApplicationInfo viewApplicationInfo = ViewApplicationInfo(&applicationInfoCollection);  // 컨트롤 생성
                viewApplicationInfo.getViewApplicationInfoUI()->init(&fout);        // UI 호출
                viewApplicationInfo.getViewApplicationInfoUI()->startInterface(); //인터페이스 시작

                if (currentMemberType == 1)  // 회사 회원은 이 작업 수행 불가능
                    break;
                else {
                    viewApplicationInfo.getViewApplicationInfoUI()->showApplicationInfo(currentLoginId);
                    break;
                }
            }
            //4.4 지원 취소
            case 4:
            {
                CancelApplication cancelApplication = CancelApplication(&applicationInfoCollection);    // 컨트롤 생성
                cancelApplication.getCancelApplicationUI()->init(&fout);        // UI 호출
                cancelApplication.getCancelApplicationUI()->startInterface();   //인터페이스 시작

                if (currentMemberType == 1) // 회사 회원은 이 작업 수행 불가능
                    break;
                else {
                    cancelApplication.getCancelApplicationUI()->showCancelApplication(currentLoginId, inputEvent);
                    break;
                }
            }
            }
            break;
        }
        case 5:
        {
            switch (secondEvent) {
                //5.1 지원 정보 통계
            case 1: {
                //채용 정보 통계 Control 클래스 인스턴스 생성
                ViewRecruitInfoStats viewRecruitInfoStats = ViewRecruitInfoStats(&recruitInfoCollection, &applicationInfoCollection);
                //채용 정보 통계 Boundary 클래스의 ofstream 참조 값 지정
                viewRecruitInfoStats.getViewRecruitInfoStatsUI()->init(&fout);

                viewRecruitInfoStats.getViewRecruitInfoStatsUI()->startInterface();     //인터페이스 시작
                if (currentMemberType == 1) {//현재 로그인한 회원이 회사 회원인 경우
                    //회사 회원이 등록한 채용 정보 통계 정보 출력
                    viewRecruitInfoStats.getViewRecruitInfoStatsUI()->requestAddedRecruitInfoStats(currentLoginId);
                }
                else if (currentMemberType == 2) {//현재 로그인한 회원이 일반 회원인 경우
                    //일반 회원이 지원한 채용 정보 통계 정보 출력
                    viewRecruitInfoStats.getViewRecruitInfoStatsUI()->requestAppliedRecruitInfoStats(currentLoginId);
                }
                break;
            }
            }
            break;
        }
        case 6:
        {
            switch (secondEvent) {
                //6.1 프로그램 종료
            case 1:
            {
                program_exit();     // 프로그램 종료하기 위한 함수 호출
                keepGoing = 0;      // keepGoing을 0으로 설정함으로써 while문 탈출
                break;
            }
            break;
            }
            break;
        }
        break;
        }
        }
    }
}

void program_exit()
{
    fout << "6.1. 종료";  // 파일에 종료 내용 입력
}
