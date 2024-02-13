#pragma once // ��������� �������������, ������� �����������, ��� ���� ����� ������� ������ ���� ���
#include <string.h>  // ��������� ���������� ��� ������ �� ��������
#define MY_STR_LEN 33 // ����������� ��������� ��� ����� �����
#define MY_TAB_CX 54 // ����������� ��������� ��� ��������������� ������� �������
#define MY_TAB_CY 100 // ����������� ��������� ��� ������������� ������� �������
#include <iostream> // ��������� ���������� ��� �����/������
#include <vector>
///////////////////types///////////////////////
typedef unsigned long long ULL; // ����������� ���������� ��� ���� unsigned long long

struct PhN_s // ����������� ��������� ��� ������������� ����������� ������
{
    ULL Number : 44; // 44 ���� ��� �������� ������ ��������  � �.� ��� ����� ������� ����� �������� <=13 �������� 2^44 = 17592186044415 � ����� ����� 14 �������� ��� ������� � �������
    ULL Plus : 1; // 1 ��� ��� �������� �������� "����"
    PhN_s() {} // ����������� �� ���������
    PhN_s(ULL num, bool plus) { Number = num; Plus = plus; } // ����������� � �����������
    //PhN_s(ULL num, bool plus) : Number(num), Plus(plus) {}
};


typedef struct PhBookRec_s // ����������� ��������� ��� ������������� ������ � ���������� �����
{
    PhN_s Phone; // ���� ��� �������� ����������� ������
    unsigned int por = 0; // ���������� ����� ������
    char Nik[MY_STR_LEN]; // ���� ��� �������� �����
    PhBookRec_s() {}  // ����������� �� ���������
    PhBookRec_s(ULL num, bool plus, const char* pName) :Phone(num, plus) { strcpy_s(Nik, pName); } // ����������� � �����������
}PhBookRec_t;

///////////////////classes////////////////////////

class CPhN  // ����������� ������ ��� ������ � ����������� ��������
{
protected:
    ULL Number : 44; //44 bits in 64 rtotal space for Number
    ULL Plus : 1; //1 bit for plus
public:
    CPhN() {} // ����������� �� ���������
    CPhN(ULL num, bool plus) { Number = num; Plus = plus; } // ����������� � �����������
    ~CPhN() {} // ����������
    //PhN_s(ULL num, bool plus) : Number(num), Plus(plus) {}
    void PrintPhoneNo(std::ofstream& MyFile);  // ����� ��� ������ ����������� ������
    int InPhoneNo();  	// ����� ��� ����� ����������� ������

};

class CPhR : public CPhN  // ����������� ������ ��� ������ � �������� � ���������� �����
{
protected:
    std::string Nick;  // ���� ��� �������� �����
public:
    bool OnOrOff = true;  // ���������� ����� ������
    CPhR() :CPhN() {} 	// ����������� �� ���������
    ~CPhR() {}  // ����������
    CPhR& operator +(const char* surname) { Nick += std::string(" ") + surname; return *this; } // ���������� ��������� "+" ��� ���������� �������
    void write(size_t Len, int por, std::ofstream& MyFile); // ����� ��� ������ ����������
    std::string Up() { // ����� ��� ���������� � ������� �������
        std::string NewNick = ""; // ������ ����� ������ ��� ������ � ���
        for (int i = 0; i < Nick.length(); i++) { // ���������� �� ����� ����� � �������� ����������� � ����� ������ ������� � ������� ��������
            NewNick += toupper(Nick[i]);
        }
        return NewNick;
    }
    void read(); // ����� ��� ���������� ����������
    bool IsVald() { return 0 != Number; } // ����� ��� �������� ������� �������� ����������� ������
    size_t GetNikLen() { return Nick.size(); } // ����� ��� ��������� ����� �����
    bool operator <(const CPhR& other) { return Nick < other.Nick; } // �������� ������
    bool operator >(const CPhR& other) { return Nick > other.Nick; } // �������� ������
    bool operator ==(const CPhR& other) { return Nick == other.Nick; } // �������� �����
    bool operator !=(const std::string other) { return Nick != other; } // �������� �������
    bool operator >(const std::string other) { return Nick > other; } // �������� �������
    bool operator <(const std::string other) { return Nick < other; } // �������� �������
};



///////////////////func/////////////////////////
int PrintfBin(int A); //1

int PrintfBin(int* A); //2

int PrintfBin3(int& A); //3

int CheckStr(char* pAr);

int CheckStr(char* pAr, size_t sz);

void TestDinArray();

void MakeTab(char* Tab, int cx, int cy);

void Print_XY_Tab(int x, int y, const char* strA, char* Tab, int cx, int cy);

void PrintPhoneNo(PhN_s* pPh, std::ofstream MyFile); // ������� ��� ������ ����������� ������

void PrintPhoneBookRec(PhBookRec_t& PhBookRec); // ������� ��� ������ ������ � ���������� �����

int InPhoneNo(PhN_s* pPh); // ������� ��� ����� ����������� ������

int InPhoneRec(PhBookRec_t& PhBookRec); // ������� ��� ����� ������ � ���������� �����


size_t FindMin(std::vector<CPhR>& Book); // ������� ��� ������ ������������ �������

std::vector<CPhR> SimpleSort(std::vector<CPhR>& Book); // ������� ��� ������� ����������

void rightLeftSort(std::vector<CPhR>& Book); // ������� ��� ���������� ���������

int binS(std::vector<CPhR>& Book, std::string name);
