//
//  main.cpp
//  宿題２　2.2
//
//  Created by Hao Feng on 2018/06/08.
//  Copyright © 2018年 Hao Feng. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
const int N=400000;
bool vis[N];
class node
{   public:
    string str;                  //盤面を保存します
    vector<int>res;
    void getindex(string str);   //indexを計算します
    int index,num;                   //indexで　０の位置を保存します
};
vector<int>res[N];
void node::getindex(string str){
    for(int i=0;i<9;i++){
        if(str[i]=='0'){
            index =i;
        }
    }
}      //{1!,2!,3!,4!,5!,6!,7!,8!,9!} Cantor expansion
int  kanto[] = {1,1,2,6,24,120,720,5040,40320,362880};
int KanTo(string str)    // Cantor expansionを計算します
{
    int i, j, t, sum;
    int s[10];
    for(i=0;i<9;i++)
    {
        s[i]=str[i]-'0';
        // s[i]=atoi(str[i].c_str());
    }
    sum = 0;
    for (i=0; i<9; i++)
    {
        t = 0;
        for (j=i+1; j<9; j++)
            if (s[j] < s[i])
                t++;
        sum += t*kanto[9-i-1];
    }
    return sum+1;
}
node start;
int goal;
bool bfs(){
    char c;
    queue<node> q;                  //宿題１と同じ、今回はstrを使って探索します
    node g,h;
    g.str ="123456780";
    g.getindex(g.str);
    g.num =0;
    q.push(g);
    while (!q.empty()) {
        g=q.front();q.pop();
        int t =KanTo(g.str);
        res[t]=g.res;
        g.num++;
        h=g;
        h.getindex(h.str);
        if((h.index+1)%3!=0)
        {   h.res.push_back(h.str[h.index+1]-'0');
            c=h.str[h.index];h.str[h.index]=h.str[h.index+1];h.str[h.index+1]=c;
            h.index++;
            int t =KanTo(h.str);
            if(!vis[t])
            {
                vis[t]=true;
                q.push(h);
            }
        }
        h=g;
        h.getindex(h.str);
        if(h.index%3!=0)
        {   h.res.push_back(h.str[h.index-1]-'0');
            c=h.str[h.index];h.str[h.index]=h.str[h.index-1];h.str[h.index-1]=c;
            h.index--;
            int t =KanTo(h.str);
            if(!vis[t])
            {
                vis[t]=true;
                q.push(h);
            }
        }
        h=g;
        h.getindex(h.str);
        if(h.index<6)
        {
            h.res.push_back(h.str[h.index+3]-'0');
            c=h.str[h.index];h.str[h.index]=h.str[h.index+3];h.str[h.index+3]=c;
            h.index+=3;
            int t =KanTo(h.str);
            if(!vis[t])
            {
                vis[t]=true;
                q.push(h);
            }
        }
        h=g;
        g.getindex(g.str);
        if(h.index>2)
        {   h.res.push_back(h.str[h.index-3]-'0');
            c=h.str[h.index];h.str[h.index]=h.str[h.index-3];h.str[h.index-3]=c;
            h.index-=3;
            int t =KanTo(h.str);
            if(!vis[t])
            {
                vis[t]=true;
                q.push(h);
            }
        }
    }
    return false;
    
};


int main(int argc, const char * argv[]) {
    int t;
    long int i;
    cout << "数字を入力してください(string)"<<endl;
    string s;
    cin >> s;
    start.str =s;
    goal =KanTo(start.str);
    start.res.clear();
    bfs();
    t=goal;
    if(res[t].size()!=0||t==46234)
    {
        for (i =res[t].size()-1;i>=0;i--){
            cout << res[t][i]<<" ";
               //手数を出力します
        }
        cout << "手数は" << res[t].size()<<endl;
    }
    else cout << "解決不能" <<endl;
//    if(bfs()){
//        cout << "手数は" << res.size()<<endl;   //手数を出力します
//        int i;
//        for(i=(res.size()-1);i>0;i--)//移動の順序を出力
//            //            res[i]= res[i]- '0';
//            cout << res[i] << " ";}
//    else cout << "解決不能" <<endl;
    return 0;
}
