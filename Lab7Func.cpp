#define limitUI 4294967295
#include<iostream>
#include "Lab7FuncLib.h"
#include <fstream>
#include "string.h"
#include <iostream>
using namespace std; // ������������� ������������ ���� std

int cntNum(ULL num) {
    int numdigits = 0;
    while (num != 0) {
        num /= 10;
        numdigits++; // ������� ���������� ���� � ����� num
    }
    return numdigits;
}
void createFile() {
    std::string fileName;
    cout << "\n������� �������� �����(txt) ������� ������ �������\n";
    cin >> fileName;
    ofstream MyFile(fileName + ".txt");
}

int PrintfBin(int A)
{
    for (int i = 31; i >= 0; i--)
        printf("%c", (A & (1 << i)) ? '1' : '0');
    return 0;
}

int PrintfBin(int* A)
{
    for (int i = 31; i >= 0; i--)
        printf("%c", (*A & (1 << i)) ? '1' : '0');
    return 0;
}

int PrintfBin3(int& A)
{
    for (int i = 31; i >= 0; i--)
        printf("%c", (A & (1 << i)) ? '1' : '0');
    A = 501;
    return 0;
}

int CheckStr(char* pAr)
{
    //check length
    size_t len = 0;
    do {
        len++;
        pAr++;
    } while (*pAr);
    if (len > 10)
        return -1;
    return 0;
}

int CheckStr(char* pAr, size_t sz)
{
    //
    return 0;
}

void TestDinArray()
{
    size_t sz;
    printf("Enter array size\n");
    scanf_s("%d", &sz);
    //char *sArr = (char *)malloc(sz);
    char* sArr = (char*)calloc(sz, sizeof(char));
    if (sArr)
    {
        if (sz > 10)
        {
            *(sArr + 10) = 10;
            printf("*(sArr + 10) = %d\n", *(sArr + 10));
            sArr[10] = 5;
            printf("sArr[10] = %d\n", sArr[10]);

        }
        free(sArr);
        sArr = nullptr; //== NULL  === 0
    }
    //*sArr = 3;
}

void MakeTab(char* Tab, int cx, int cy)
{
    memset(Tab, ' ', cx * cy);
    for (int i = 0; i < cy; i++)
        Tab[i * cx + cx - 1] = '\n';
    Tab[99 * cx + cx - 1] = '\0';
}

void Print_XY_Tab(int x, int y, const char* strA, char* Tab, int cx, int cy)
{
    size_t pos = y * cx + x;
    if (pos + strlen(strA) < cx * cy - 1)//in range
    {
        while (*strA)
        {
            Tab[pos] = *strA;
            strA++;
            pos++;
        }
    }
}
// ������� ��� ������ ����������� ������
void PrintPhoneNo(PhN_s* pPh)
{
    printf("%c", pPh->Plus ? '+' : ' ');
    printf("%llu\n", pPh->Number);


}
// ������� ��� ������ ����������� ������
void PrintPorNo(PhBookRec_t& PhBookRec) {
    printf("\t\t\t\t%d\n", PhBookRec.por); // �������� ���������� �����
}
// ������� ��� ������ ������ � ���������� �����
void PrintPhoneBookRec(PhBookRec_t& PhBookRec)
{
    if (PhBookRec.por == 1) {
        printf("\n\nname\t\t\t\t number\t\t\t\t\tn\n"); // �������� ��������� ������� ���������� �����
    }
    PrintPorNo(PhBookRec); // �������� ������� ��� ������ ����������� ������
    printf("%s", PhBookRec.Nik);
    string spaces((MY_STR_LEN - strlen(PhBookRec.Nik)), ' '); // ������� ������ ��������, ����� ��������� ����������� �����
    cout << spaces;
    PrintPhoneNo(&PhBookRec.Phone);
}
// ������� ��� ����� ����������� ������
int InPhoneNo(PhN_s* pPh)
{
    printf("������� ����� ��������\n");
    char buf[MY_STR_LEN];
    scanf_s("%s", buf, MY_STR_LEN);
    if (CheckStr(buf, 13))
        return -1;
    char* posN = buf;
    if ('+' == buf[0])
        pPh->Plus = 1;

    else
        pPh->Plus = 0;
    pPh->Number = atoll(posN);
    return 0;

}
// ������� ��� ����� ������ � ���������� �����
int InPhoneRec(PhBookRec_t& PhBookRec)
{
    int nRet = InPhoneNo(&PhBookRec.Phone);
    if (nRet)
        return nRet;
    printf("������� ��� ��������\n");
    scanf_s("%s", PhBookRec.Nik, MY_STR_LEN);
    return 0;
}

// ����� ������ CPhN ��� ������ ����������� ������
void CPhN::PrintPhoneNo(std::ofstream& MyFile)
{
    PhN_s pPh(Number, Plus);
    if (Plus) {
        MyFile << Plus << Number;
    }
    else {
        MyFile << Number;
    }
    ::PrintPhoneNo(&pPh);
}
// ����� ������ CPhN ��� ����� ����������� ������
int CPhN::InPhoneNo()
{
    PhN_s A;
    int Ret = ::InPhoneNo(&A);
    Number = A.Number;
    Plus = A.Plus;
    return Ret;
    //return ::InPhoneNo((PhN_s *)this);
}
// ����� ������ ��������
void CPhR::write(size_t Len, int por, std::ofstream& MyFile)
{
    if (por == 1) {
        printf("\n\nn\tname\t\t\t\tnumber\n"); // �������� ��������� ������� ���������� �����
        MyFile << "n\tname\t\tnumber\n";
    }
    std::cout << por << "\t";
    MyFile << por << "\t";
    std::cout << Nick << std::string(Len - Nick.size() + 10, ' '); //std::endl
    MyFile << Nick << std::string(Len - Nick.size() + 10, ' ');
    PrintPhoneNo(MyFile);
    MyFile << "\n";
}
//����� ��� ������
void CPhR::read()
{
    InPhoneNo();
    std::cout << "������� ��� ��������\n"; // << std::endl;
    std::cin >> Nick;
}
int tr = 0;

// ������� ��� ���������� ������� true
size_t FindMinTrue(std::vector<CPhR> Book) {
    for (size_t i = 0; i < Book.size(); i++) {
        tr++;
        if (Book[i].OnOrOff) {
            return i;

        }
    }
    return limitUI;
}
//������� ��� ���������� ������� ������������ ��������
size_t FindMin(std::vector<CPhR>& Book) {
    size_t i = FindMinTrue(Book);
    if (i == (limitUI)) {
        return limitUI;
    }

    for (int j = 0; j < Book.size(); j++) {
        if ((Book[j].Up() < Book[i].Up()) && (Book[j].OnOrOff)) {

            tr++;
            i = j;
        }

    }
    Book[i].OnOrOff = false;
    return i;
}
// ������� ������� ����������
std::vector<CPhR> SimpleSort(std::vector<CPhR>& Book) {
    size_t i = 0;
    std::vector<CPhR> newBook = {};
    while (i != Book.size()) {

        size_t minInd = FindMin(Book);
        if (minInd == limitUI) {
            break;
        }
        newBook.push_back(Book[minInd]);
        i += 1;
    }
    cout << "\n ���������� ����� ��� ������� ���������� = " << tr << "\n";
    return newBook;
}
//������� ���������� ���������
void rightLeftSort(std::vector<CPhR>& Book) {
    size_t N = Book.size();
    CPhR glass;
    unsigned int tr = 0;
    for (int i = 0; i < (N - 1); i++) {
        for (int j = 0; j > N; j++) {
            if (Book[j].Up() > Book[j - 1].Up()) {

                glass = Book[j];
                Book[j] = Book[j - 1];
                Book[j - 1] = glass;
                tr++;
            }

        }
    }
    cout << "\n ���������� ����� ��� ���������� ��������� = " << tr << "\n";
}
std::string Up(std::string name) { // ����� ��� ���������� � ������� �������
    std::string NewNick = ""; // ������ ����� ������ ��� ������ � ���
    for (int i = 0; i < name.length(); i++) { // ���������� �� ����� ����� � �������� ����������� � ����� ������ ������� � ������� ��������
        NewNick += toupper(name[i]);
    }
    return NewNick;
}
int binS(std::vector<CPhR>& Book, std::string name) {
    int n = Book.size();
    int i = 0;
    int j = n - 1;
    if ((Book[i].Up() != Up(name)) == false) {
        return i;
    }
    else if ((Book[j].Up() != Up(name)) == false) {
        return j;
    }
    int t = ceil(i + j / 2);
    while ((Book[t].Up() != Up(name)) && (i <= j)) {
        if (Book[t].Up() < Up(name)) {
            i = t + 1;
        }
        else {
            j = t - 1;
        }
        t = round((i + j) / 2);
    }
    if ((Book[t].Up() != Up(name)) == false) {
        return t;
    }
    else {
        return -1;
    }



}
