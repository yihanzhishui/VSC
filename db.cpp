#include <fstream>
#include <iostream>
#include <string>

// using namespace std;

#define M 100
#define N 50

// ���ݿ���
class DB {
    std::string TABLE_NAME;
    std::string FILE_NAME;
    int INDEX;
};

DB MY_DB[M];        // ά��һ�����ݿ�״̬����
int MY_SQL_NUM = 0; // ��ǰ���ݿ�״̬����

// ���ݱ���
class TABLE {
    std::string TABLE_NAME; // ����
    std::string FILE_NAME;  // �ļ���
    std::string COLUMN[N];  // ��
    int COLUMN_NUMBER;      // ����
    int ROW_NUMBER;         // ����
};

TABLE ALL_TABLE[M];
int TABLE_NUM = 0;

std::string TABLE_DATA[M]
                      [M]; // ά��һ�����ݶ�ά���飬������ʱ�洢���µı������
int ROW = 0, COL = 0; // ��ǰ�������������

int main() {}