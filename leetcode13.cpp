//
//  main.cpp
//  leetcode2
//
//  Created by Hao Feng on 2018/06/04.
//  Copyright © 2018年 Hao Feng. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
static int int1[] {1000,900,500,400,100,90,50,40,10,9,5,4,1};
static string roma[]{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
int main(){
    string romaint= "";
    cout <<"INT数字を入力してください"<<"(III=3,IV=4,XI=11)"<<endl;
    cout << "I=1" <<endl;
    cout << "V=5"<<endl;
    cout <<"X=10"<<endl;
    cout <<"L=50"<<endl;
    cout << "C=100" <<endl;
    cout << "D=500" <<endl;
    cout << "M=1000" <<endl;
    int xx=0;
    cin >> xx;
    if(xx==0){
        cout <<"エーラ"<<endl;}
    else{while (xx >0){
        for (int i=0;i<13;i++)
        {if (xx>=int1[i]){
            xx -=int1[i];
            romaint +=roma[i];
        }
        }
        }cout  << romaint<<endl;
    } return 0;
};
