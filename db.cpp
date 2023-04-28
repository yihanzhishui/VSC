#include <fstream>
#include <iostream>
#include <string>

// using namespace std;

#define M 100
#define N 50

// 数据库类
class DB {
    std::string TABLE_NAME;
    std::string FILE_NAME;
    int INDEX;
};

DB MY_DB[M];        // 维护一个数据库状态数组
int MY_SQL_NUM = 0; // 当前数据库状态行数

// 数据表类
class TABLE {
    std::string TABLE_NAME; // 表名
    std::string FILE_NAME;  // 文件名
    std::string COLUMN[N];  // 列
    int COLUMN_NUMBER;      // 列数
    int ROW_NUMBER;         // 行数
};

TABLE ALL_TABLE[M];
int TABLE_NUM = 0;

std::string TABLE_DATA[M]
                      [M]; // 维护一个数据二维数组，用于暂时存储更新的表格数据
int ROW = 0, COL = 0; // 当前表格数据行列数

int main() {}