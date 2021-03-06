#include <iostream>
#include <algorithm>
using namespace std;
int size ;
int gold[1000][1000] ;
int maxGold[1000][1000] ;
int route[1000][1000];

int getMaxGold(){

    for (int j = 1;j <= size;j++){
        maxGold[size][j] = gold[size][j] ;
    }
    for (int i = size - 1;i >= 1;i--){
        for (int j = 1;j <= i;j++){
//            maxGold[i][j] = max(gold[i][j] + maxGold[i + 1][j], gold[i][j] + maxGold[i + 1][j + 1]);
            if (maxGold[i + 1][j] > maxGold[i + 1][j + 1]) {
                maxGold[i][j] = gold[i][j] + maxGold[i + 1][j];
                route[i][j] = 0 ;
            }
            else{
                maxGold[i][j] = gold[i][j] + maxGold[i + 1][j + 1] ;
                route[i][j] = 1 ;
            }
        }
    }
    return maxGold[1][1] ;
}


void printRoute(){
    int current = 1 ;
    for (int i = 1;i < size;i++){
        cout << gold[i][current] <<"->" ;
        current += route[i][current] ;
    }
    cout << gold[size][current] << endl ;
}

int main() {
    int maxnum ;
    cout <<"请输入金字塔层数（最少为1层）：" ;
    cin >> size;
    cout << "请输入每个砖块中的钻石数目：" ;
    for (int i = 1;i <= size;i++){
        for (int j = 1;j <= i;j++){
            cin >> gold[i][j] ;
        }
    }
    maxnum = getMaxGold() ;
    cout << "最大钻石数量为：" ;
    cout << maxnum << endl;
    cout << "路径为：" ;
    printRoute() ;
    return 0;

}
