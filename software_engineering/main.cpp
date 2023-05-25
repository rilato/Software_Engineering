#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//Entity ���
#include "MemberCollection.h"
#include "Member.h"
#include "RecruitInfo.h"
#include "RecruitInfoCollection.h"
#include "ApplicationInfoCollection.h"
#include "CompanyMember.h"
#include "GeneralMember.h"

//ȸ������ ����ý��� ���
#include "LoginUI.h"
#include "Login.h"
#include "LogoutUI.h"
#include "Logout.h"
#include "RegisterUI.h"
#include "Register.h"
#include "WithdrawUI.h"
#include "Withdraw.h"

//ä���������� ����ý��� ���
#include "AddRecruitInfoUI.h"
#include "AddRecruitInfo.h"
#include "ViewAddedRecruitListUI.h"
#include "ViewAddedRecruitList.h"

//ä������ ����ý��� ���
#include "SearchRecruitInfoUI.h"
#include "SearchRecruitInfo.h"
#include "ApplyImmediatelyUI.h"
#include "ApplyImmediately.h"
#include "ViewApplicationInfoUI.h"
#include "ViewApplicationInfo.h"
#include "CancelApplicationUI.h"
#include "CancelApplication.h"

//ä��������� ����ý��� ���
#include "ViewRecruitInfoStatsUI.h"
#include "ViewRecruitInfoStats.h"

using namespace std;

//��� ����
#define endl '\n'
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

ifstream fin; // �ؽ�Ʈ ���� ����
ofstream fout; // �ؽ�Ʈ ���Ϸ� �����ϱ�

//�Լ� ����
void run();
void program_exit();


/*
    �Լ� �̸� : main
    ���: ���� ��Ʈ�� ���� run �Լ� ����. ���� ���� �� 0�� ����
    �Ű�����: X
    ��ȯ��: int
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fin.open(INPUT_FILE);       // ���� ifstream ����
    fout.open(OUTPUT_FILE);     // ���� ofstream ����

    run();

    fin.close(); // ���� ifstream �ݱ�
    fout.close(); // ���� ofstream �ݱ�

    return 0;
}

/*
    �Լ� �̸� : run
    ���: ������ �� �پ� �о�� ��, �о� �� ���뿡 �°� �Լ��� ������.
    �Ű�����: X
    ��ȯ��: X
*/
void run()
{
    // ������ ������ �ʴ� ���
    if (!fin || !fout) {
        cout << "������ �� �� �����ϴ�." << endl;
        return;
    }

    string inputEvent;  // ���� ���Ͽ��� �о�� �� ��
    bool keepGoing = 1;  // keepGoing�� 1�̸� ����ؼ� ������ �а�, 0�� �Ǵ� ���� while�� Ż��

    // MemberCollection �ν��Ͻ� ����
    MemberCollection memberCollection = MemberCollection();
    // RecruitInfoCollection �ν��Ͻ� ����
    RecruitInfoCollection recruitInfoCollection = RecruitInfoCollection();
    // ApplicationInfoCollection �ν��Ͻ� ����
    ApplicationInfoCollection applicationInfoCollection = ApplicationInfoCollection(&memberCollection, &recruitInfoCollection);

    string currentLoginId = "";       // ���� �α��� ���� ȸ�� ID�� currentLoginId�� ����
    int currentMemberType = 0;         // 1�̸� ȸ�� ȸ��, 2�� �Ϲ� ȸ��
    // currentMemberType�� 1�� ������ ȸ�� ȸ�� ���� �ý����� �۵��ϰ�, �Ϲ� ȸ�� ���� �ý��ۿ� ���� �� �ƹ� �ൿ�� ���� ������,
    // currentMemberType�� 2�� ������ �Ϲ� ȸ�� ���� �ý����� �۵��ϰ�, ȸ�� ȸ�� ���� �ý��ۿ� ���� �� �ƹ� �ൿ�� ���� �ʴ´�.

    while (keepGoing) {
        getline(fin, inputEvent); // input.txt ���� �� �پ� �о� inputEvent�� ����

        int firstEvent = inputEvent[0] - '0';       // �޴� �Ľ��� ���� ù��° ����
        int secondEvent = inputEvent[2] - '0';      // �޴� �Ľ��� ���� �ι�° ����

        string tempId = currentLoginId;     // �α׾ƿ� �ϸ� ���Ͽ� currentLoginId ������ �ۼ��ؾ� �ϴµ�, �Ʒ� �Լ� ���� �� currentLoginId�� ������Ƿ�, ��� ��� ��
        // ȸ�� Ż���� ������ ��������

        switch (firstEvent) {
        case 1:
        {
            switch (secondEvent) {
                // 1.1 ȸ�� ����
            case 1:
            {
                Register regist = Register(&memberCollection);  // ��Ʈ�� ����
                regist.getRegisterUI()->init(&fout);    // UI ȣ��
                regist.getRegisterUI()->startInterface();   // �������̽� ����

                currentMemberType = regist.getRegisterUI()->selectMemberType(inputEvent); // 1. 1. 1���� �� ���� 1�� currentMemberType�� ����� 
                regist.getRegisterUI()->requestRegister(inputEvent, currentMemberType);   // Boundary�� �ִ� requestRegister �Լ� ȣ��
            }
            break;
            // 1.2 ȸ�� Ż��
            case 2:
            {
                Withdraw withdraw = Withdraw(&memberCollection, &recruitInfoCollection, &applicationInfoCollection);    // ��Ʈ�� ����
                withdraw.getWithdrawUI()->init(&fout);  // UI ȣ��
                withdraw.getWithdrawUI()->startInterface();    // �������̽� ����

                if (currentLoginId == "") // �α��� ���� ���� ���¶�� currentLoginId�� ""�̰�, ȸ�� Ż���� �� �����Ƿ�, �ƹ� �͵� ���� �ʰ� �ǳʶ�
                    break;
                else {              // �α��� �Ǿ��� ������ ȸ�� Ż��
                    withdraw.getWithdrawUI()->requestWithdraw(currentLoginId, tempId, currentMemberType);     // Boundary�� �ִ� requestWithdraw �Լ� ȣ��
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
                // 2.1 �α���
            case 1:
            {
                Login login = Login(&memberCollection);     // ��Ʈ�� ����
                login.getLoginUI()->init(&fout);    // UI ȣ��
                login.getLoginUI()->startInterface();    // �������̽� ����

                if (currentLoginId != "")                 // ������ �α��� ���̸� �α��� �� �� �����Ƿ�, �ƹ� �͵� ���� �ʰ� �ǳʶ�
                    break;

                else {
                    login.getLoginUI()->verifyLogin(inputEvent, currentLoginId, currentMemberType);   // Boundary�� �ִ� requestLogin �Լ� ȣ��
                    break;
                }
            }
            break;
            // 2.2 �α׾ƿ�
            case 2:
            {
                Logout logout = Logout();       // ��Ʈ�� ����
                logout.getLogoutUI()->init(&fout);      // UI ȣ��
                logout.getLogoutUI()->startInterface();    // �������̽� ����

                if (currentLoginId == "")               // �α��� ���� ���� ���¶�� �α׾ƿ��� �� �����Ƿ�, �ƹ� �͵� ���� �ʰ� �ǳʶ�
                    break;
                else {              // �α��� �� ���¿����� �α׾ƿ� ���� ����!
                    logout.getLogoutUI()->requestLogout(currentLoginId, tempId, currentMemberType);       // �α��� �� ���¶�� �α׾ƿ� ���� ����. Boundary�� �ִ� requestLogout �Լ� ȣ��
                    break;
                }
            }
            break;
            }
            break;
        case 3:
        {
            switch (secondEvent) {
                //3.1 ä�� ���� ���
            case 1:
            {
                AddRecruitInfo addRecruitInfo = AddRecruitInfo(&recruitInfoCollection);     // ��Ʈ�� ����
                addRecruitInfo.getAddRecruitInfoUI()->init(&fout);      // UI ȣ��
                addRecruitInfo.getAddRecruitInfoUI()->startInterface();    // �������̽� ����

                if (currentMemberType == 2)        // �Ϲ� ȸ���� �� �۾� ���� �Ұ���
                    break;
                else {
                    addRecruitInfo.getAddRecruitInfoUI()->requestAddRecruitInfo(inputEvent, currentLoginId);     // recruitInfoCollection ���Ϳ� recruitInfo�� �߰��ϱ� ���� �Լ� ȣ��
                }
                break;
            }
            //3.2 ä�� ���� ��ȸ
            case 2:
            {
                ViewAddedRecruitList viewAddedRecruitList = ViewAddedRecruitList(&recruitInfoCollection);   // ��Ʈ�� ����
                viewAddedRecruitList.getViewAddedRecruitListUI()->init(&fout);      // UI ȣ��
                viewAddedRecruitList.getViewAddedRecruitListUI()->startInterface();     // �������̽� ����

                if (currentMemberType == 2)
                    break;
                else {
                    viewAddedRecruitList.getViewAddedRecruitListUI()->showRecruitInfo(currentLoginId);      // ����� ä�� ���� ��� ��ȸ
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
                //4.1 ä�� ���� �˻�
            case 1:
            {
                SearchRecruitInfo searchRecruitInfo = SearchRecruitInfo(&recruitInfoCollection, &memberCollection);  // ��Ʈ�� ����
                searchRecruitInfo.getSearchRecruitInfoUI()->init(&fout);        // UI ȣ��
                searchRecruitInfo.getSearchRecruitInfoUI()->startInterface(); // �������̽� ����

                if (currentMemberType == 1) // ȸ�� ȸ���� �� �۾� ���� �Ұ���
                    break;
                else {
                    searchRecruitInfo.getSearchRecruitInfoUI()->showSearchRecruitInfo(inputEvent);
                    break;
                }
            }
            //4.2 ä�� ����
            case 2:
            {
                ApplyImmediately applyImmediately = ApplyImmediately(&applicationInfoCollection,
                    &recruitInfoCollection, &memberCollection); // ��Ʈ�� ����
                applyImmediately.getApplyImmediatelyUI()->init(&fout);      // UI ȣ��
                applyImmediately.getApplyImmediatelyUI()->startInterface();     //�������̽� ����

                if (currentMemberType == 1) // ȸ�� ȸ���� �� �۾� ���� �Ұ���
                    break;
                else
                {
                    applyImmediately.getApplyImmediatelyUI()->showApplyImmediately(inputEvent, currentLoginId);

                }
                break;
            }
            //4.3 ���� ���� ��ȸ
            case 3:
            {
                ViewApplicationInfo viewApplicationInfo = ViewApplicationInfo(&applicationInfoCollection);  // ��Ʈ�� ����
                viewApplicationInfo.getViewApplicationInfoUI()->init(&fout);        // UI ȣ��
                viewApplicationInfo.getViewApplicationInfoUI()->startInterface(); //�������̽� ����

                if (currentMemberType == 1)  // ȸ�� ȸ���� �� �۾� ���� �Ұ���
                    break;
                else {
                    viewApplicationInfo.getViewApplicationInfoUI()->showApplicationInfo(currentLoginId);
                    break;
                }
            }
            //4.4 ���� ���
            case 4:
            {
                CancelApplication cancelApplication = CancelApplication(&applicationInfoCollection);    // ��Ʈ�� ����
                cancelApplication.getCancelApplicationUI()->init(&fout);        // UI ȣ��
                cancelApplication.getCancelApplicationUI()->startInterface();   //�������̽� ����

                if (currentMemberType == 1) // ȸ�� ȸ���� �� �۾� ���� �Ұ���
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
                //5.1 ���� ���� ���
            case 1: {
                //ä�� ���� ��� Control Ŭ���� �ν��Ͻ� ����
                ViewRecruitInfoStats viewRecruitInfoStats = ViewRecruitInfoStats(&recruitInfoCollection, &applicationInfoCollection);
                //ä�� ���� ��� Boundary Ŭ������ ofstream ���� �� ����
                viewRecruitInfoStats.getViewRecruitInfoStatsUI()->init(&fout);

                viewRecruitInfoStats.getViewRecruitInfoStatsUI()->startInterface();     //�������̽� ����
                if (currentMemberType == 1) {//���� �α����� ȸ���� ȸ�� ȸ���� ���
                    //ȸ�� ȸ���� ����� ä�� ���� ��� ���� ���
                    viewRecruitInfoStats.getViewRecruitInfoStatsUI()->requestAddedRecruitInfoStats(currentLoginId);
                }
                else if (currentMemberType == 2) {//���� �α����� ȸ���� �Ϲ� ȸ���� ���
                    //�Ϲ� ȸ���� ������ ä�� ���� ��� ���� ���
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
                //6.1 ���α׷� ����
            case 1:
            {
                program_exit();     // ���α׷� �����ϱ� ���� �Լ� ȣ��
                keepGoing = 0;      // keepGoing�� 0���� ���������ν� while�� Ż��
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
    fout << "6.1. ����";  // ���Ͽ� ���� ���� �Է�
}
