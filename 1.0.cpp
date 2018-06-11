#include <iostream>
using namespace std;
#include <queue>
#include <math.h>
#include <vector>
#include <map>
#include <string>
class node{
public:
    int game[5][5] = {
        {-1,-1,-1,-1,-1},
        {-1,1,4,3,-1},
        {-1,7,2,6,-1},
        {-1,8,5,0,-1},
        {-1,-1,-1,-1,-1}
    };
    int z,zz;
    void location();
    vector<int>res;
    string nodehash;
    void hash();
    void swap(int &a,int &b);
};
vector<int>res;
map<string,int>mp;


void node::location(){
    
    for(int i=1; i <4 ;i++){
        for (int j=1;j<4;j++){
            if (game[i][j] ==0){
                z=i;
                zz=j;
            }
        }
    }
}

void node::hash(){
    nodehash = "";
    for(int i=1; i <4 ;i++)
    {
        for (int j=1;j<4;j++)
        {
            nodehash +=to_string(game[i][j]);
            
        }
    }
};
node start;
void node::swap(int &a,int &b)
{   int temp1;
    temp1 =a;
    a = b;
    b =temp1;
}
void output()
{
    cout << "今の盤面は" << endl;
    for(int i=1; i <4 ;i++){
        for (int j=1;j<4;j++){
            if (start.game[i][j]==0)
            {
                cout << " ";
            }
            else  cout << start.game[i][j];
        }
        cout << endl;
    }
};
void input();
void input(){
    cout << "数字を入力してください(1-8)"<<endl;
    for(int i=1; i <4 ;i++){
        for (int j=1;j<4;j++)
            cin >> start.game[i][j];}
    start.location();
    start.hash();
    start.res.clear();
};
int n=0;
int move(int x);
int move(int x){
    cout <<"移動したい数字を入力してください"<<endl;
    
    if (x == -1)
        cout << "カンニング" <<endl;
    if (x == start.game[(start.z)+1][start.zz]){
        swap(start.game[(start.z)+1][start.zz],start.game[start.z][start.zz]);
        n++;
    }
    else if (x == start.game[(start.z)-1][start.zz]){
        swap(start.game[(start.z)-1][start.zz],start.game[start.z][start.zz]);
        n++;
    }
    else if (x == start.game[start.z][(start.zz)+1]){
        swap(start.game[start.z][(start.zz)+1],start.game[start.z][start.zz]);
        n++;
    }
    else if (x == start.game[start.z][(start.zz)-1])
    {   swap(start.game[start.z][(start.zz)-1],start.game[start.z][start.zz]);
        n++;
    }
    else cout <<"入力エラー" <<endl;
    output();
    
    cout << "手数は" << n <<endl;
    return n;
};

bool bfs(){
    queue<node> q;
    node g,h;
    for (int i =0;i<6;i++){
        for(int j =0;j<6;j++){
            g.game[i][j]=start.game[i][j];
        }
    }
    q.push(g);
    while(!q.empty())
    {
        g=q.front();q.pop();
        g.hash();
        if(g.nodehash=="123456780")
        {
            res=g.res;
            return true;
        }
        h=g;
        h.location();
        if(h.game[(h.z+1)][h.zz]!=-1){
            h.res.push_back(h.game[(h.z+1)][h.zz]);
            swap(h.game[(h.z+1)][h.zz],h.game[h.z][h.zz]);
            h.hash();
            if(mp[h.nodehash]==0){
                mp[h.nodehash]=true;
                q.push(h);
            }
        }
        h=g;
        h.location();
        if(h.game[(h.z-1)][h.zz]!=-1){
            h.res.push_back(h.game[(h.z-1)][h.zz]);
            swap(h.game[(h.z-1)][h.zz],h.game[h.z][h.zz]);
            h.hash();
            if(mp[h.nodehash]==0){
                mp[h.nodehash]=true;
                q.push(h);
            }
        }
        h=g;
        h.location();
        if(h.game[(h.z)][h.zz+1]!=-1){
            h.res.push_back(h.game[(h.z)][h.zz+1]);
            swap(h.game[(h.z)][h.zz+1],h.game[h.z][h.zz]);
            h.hash();
            if(mp[h.nodehash]==0){
                mp[h.nodehash]=true;
                q.push(h);
            }
        }
        h=g;
        h.location();
        if(h.game[h.z][h.zz-1]!=-1){
            h.res.push_back(h.game[(h.z)][h.zz-1]);
            swap(h.game[(h.z)][h.zz-1],h.game[h.z][h.zz]);
            h.hash();
            if(mp[h.nodehash]==0){
                mp[h.nodehash]=true;
                q.push(h);
            }
        }
    }
    return false;
};


int main(){
    int xx,x;
    input();
    output();
    cout << "1 自分遊び"  <<endl;
    cout << "2 自動" <<endl;
    cin >> xx;
    switch (xx) {
        case 1:
            while (true) {
                start.location();
                start.hash();
                if (start.nodehash=="123456780"){
                    cout <<"おめでとう"<<endl;
                    return 0;
                }
                cin >> x;
                move(x);
                if (x ==-2){
                    cout << "ゲーム終了" <<endl<<"手数は" << n<<endl;
                    return 0;
                }
                
            }
            
        case 2:
            if(bfs()){
                cout << "手数は" << res.size()<<endl;
                int i;
                for(i=0;i<res.size();i++)
                    cout << res[i] << " ";}
            else cout << "解決不能" <<endl;
        break;}
    return 0;
};
