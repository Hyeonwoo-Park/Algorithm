#include<bits/stdc++.h>
using namespace std;

enum {UP,DOWN,FRONT,BACK,LEFT,RIGHT};       //면
enum {TOP,MIDDLE,BOTTOM};                   //줄
enum {FIRST,SECOND,THIRD};                  //칸
//기본 세팅
vector<vector<vector<char>>>CUBE =
{{{'w','w','w'},
  {'w','w','w'},
  {'w','w','w'}}
//위     0
,{{'y','y','y'},
  {'y','y','y'},
  {'y','y','y'}}
//아래    1
,{{'r','r','r'},
  {'r','r','r'},
  {'r','r','r'}}
//앞     2
,{{'o','o','o'},
  {'o','o','o'},
  {'o','o','o'}}
//뒷     3
,{{'g','g','g'},
  {'g','g','g'},
  {'g','g','g'}}
//왼쪽    4
,{{'b','b','b'},
  {'b','b','b'},
  {'b','b','b'}}
//오른쪽   5
};

void Rotate(vector<vector<char>> &side, char dir){
    vector<vector<char>> tmp(3,vector<char>(3));
    if(dir=='+'){
        tmp[TOP][FIRST]=side[BOTTOM][FIRST];
        tmp[TOP][SECOND]=side[MIDDLE][FIRST];
        tmp[TOP][THIRD]=side[TOP][FIRST];

        tmp[MIDDLE][FIRST]=side[BOTTOM][SECOND];
        tmp[MIDDLE][SECOND]=side[MIDDLE][SECOND];
        tmp[MIDDLE][THIRD]=side[TOP][SECOND];

        tmp[BOTTOM][FIRST]=side[BOTTOM][THIRD];
        tmp[BOTTOM][SECOND]=side[MIDDLE][THIRD];
        tmp[BOTTOM][THIRD]=side[TOP][THIRD];

        side=tmp;
    }
    else if(dir=='-'){
        tmp[TOP][FIRST]=side[TOP][THIRD];
        tmp[TOP][SECOND]=side[MIDDLE][THIRD];
        tmp[TOP][THIRD]=side[BOTTOM][THIRD];

        tmp[MIDDLE][FIRST]=side[TOP][SECOND];
        tmp[MIDDLE][SECOND]=side[MIDDLE][SECOND];
        tmp[MIDDLE][THIRD]=side[BOTTOM][SECOND];

        tmp[BOTTOM][FIRST]=side[TOP][FIRST];
        tmp[BOTTOM][SECOND]=side[MIDDLE][FIRST];
        tmp[BOTTOM][THIRD]=side[BOTTOM][FIRST];
        side=tmp;

    }

}

void Left(vector<vector<vector<char>>> &cube,char dir){
    if (dir=='+'){
        vector<char> tmp={cube[UP][TOP][FIRST],cube[UP][MIDDLE][FIRST],cube[UP][BOTTOM][FIRST]};
        cube[UP][TOP][FIRST]=cube[BACK][BOTTOM][THIRD];
        cube[UP][MIDDLE][FIRST]=cube[BACK][MIDDLE][THIRD];
        cube[UP][BOTTOM][FIRST]=cube[BACK][TOP][THIRD];

        cube[BACK][BOTTOM][THIRD]=cube[DOWN][TOP][FIRST];
        cube[BACK][MIDDLE][THIRD]=cube[DOWN][MIDDLE][FIRST];
        cube[BACK][TOP][THIRD]=cube[DOWN][BOTTOM][FIRST];

        cube[DOWN][TOP][FIRST]=cube[FRONT][TOP][FIRST];
        cube[DOWN][MIDDLE][FIRST]=cube[FRONT][MIDDLE][FIRST];
        cube[DOWN][BOTTOM][FIRST]=cube[FRONT][BOTTOM][FIRST];

        cube[FRONT][TOP][FIRST]=tmp[0];
        cube[FRONT][MIDDLE][FIRST]=tmp[1];
        cube[FRONT][BOTTOM][FIRST]=tmp[2];
    }
    else if (dir=='-'){
        vector<char> tmp={cube[UP][TOP][FIRST],cube[UP][MIDDLE][FIRST],cube[UP][BOTTOM][FIRST]};
        cube[UP][TOP][FIRST]=cube[FRONT][TOP][FIRST];
        cube[UP][MIDDLE][FIRST]=cube[FRONT][MIDDLE][FIRST];
        cube[UP][BOTTOM][FIRST]=cube[FRONT][BOTTOM][FIRST];

        cube[FRONT][TOP][FIRST]=cube[DOWN][TOP][FIRST];
        cube[FRONT][MIDDLE][FIRST]=cube[DOWN][MIDDLE][FIRST];
        cube[FRONT][BOTTOM][FIRST]=cube[DOWN][BOTTOM][FIRST];

        cube[DOWN][TOP][FIRST]=cube[BACK][BOTTOM][THIRD];
        cube[DOWN][MIDDLE][FIRST]=cube[BACK][MIDDLE][THIRD];
        cube[DOWN][BOTTOM][FIRST]=cube[BACK][TOP][THIRD];

        cube[BACK][BOTTOM][THIRD]=tmp[0];
        cube[BACK][MIDDLE][THIRD]=tmp[1];
        cube[BACK][TOP][THIRD]=tmp[2];
    }
    Rotate(cube[LEFT],dir);
}

int Right(vector<vector<vector<char>>> &cube,char dir){

    if (dir=='+'){
        vector<char> tmp={cube[UP][TOP][THIRD],cube[UP][MIDDLE][THIRD],cube[UP][BOTTOM][THIRD]};

        cube[UP][TOP][THIRD]=cube[FRONT][TOP][THIRD];
        cube[UP][MIDDLE][THIRD]=cube[FRONT][MIDDLE][THIRD];
        cube[UP][BOTTOM][THIRD]=cube[FRONT][BOTTOM][THIRD];


        cube[FRONT][TOP][THIRD]=cube[DOWN][TOP][THIRD];
        cube[FRONT][MIDDLE][THIRD]=cube[DOWN][MIDDLE][THIRD];
        cube[FRONT][BOTTOM][THIRD]=cube[DOWN][BOTTOM][THIRD];

        cube[DOWN][TOP][THIRD]=cube[BACK][BOTTOM][FIRST];
        cube[DOWN][MIDDLE][THIRD]=cube[BACK][MIDDLE][FIRST];
        cube[DOWN][BOTTOM][THIRD]=cube[BACK][TOP][FIRST];

        cube[BACK][BOTTOM][FIRST]=tmp[0];
        cube[BACK][MIDDLE][FIRST]=tmp[1];
        cube[BACK][TOP][FIRST]=tmp[2];
    }
    else if (dir=='-'){
        vector<char> tmp={cube[UP][TOP][THIRD],cube[UP][MIDDLE][THIRD],cube[UP][BOTTOM][THIRD]};

        cube[UP][TOP][THIRD]=cube[BACK][BOTTOM][FIRST];
        cube[UP][MIDDLE][THIRD]=cube[BACK][MIDDLE][FIRST];
        cube[UP][BOTTOM][THIRD]=cube[BACK][TOP][FIRST];

        cube[BACK][BOTTOM][FIRST]=cube[DOWN][TOP][THIRD];
        cube[BACK][MIDDLE][FIRST]=cube[DOWN][MIDDLE][THIRD];
        cube[BACK][TOP][FIRST]=cube[DOWN][BOTTOM][THIRD];

        cube[DOWN][TOP][THIRD]=cube[FRONT][TOP][THIRD];
        cube[DOWN][MIDDLE][THIRD]=cube[FRONT][MIDDLE][THIRD];
        cube[DOWN][BOTTOM][THIRD]=cube[FRONT][BOTTOM][THIRD];

        cube[FRONT][TOP][THIRD]=tmp[0];
        cube[FRONT][MIDDLE][THIRD]=tmp[1];
        cube[FRONT][BOTTOM][THIRD]=tmp[2];
    }
    Rotate(cube[RIGHT],dir);
}

int Up(vector<vector<vector<char>>> &cube,char dir){
    vector<char> tmp;
    if (dir=='-'){
        tmp=cube[FRONT][TOP];
        cube[FRONT][TOP]=cube[LEFT][TOP];
        cube[LEFT][TOP]=cube[BACK][TOP];
        cube[BACK][TOP]=cube[RIGHT][TOP];
        cube[RIGHT][TOP]=tmp;
    }
    else if (dir=='+'){
        tmp=cube[FRONT][TOP];
        cube[FRONT][TOP]=cube[RIGHT][TOP];
        cube[RIGHT][TOP]=cube[BACK][TOP];
        cube[BACK][TOP]=cube[LEFT][TOP];
        cube[LEFT][TOP]=tmp;
    }
    Rotate(cube[UP],dir);
}

int Down(vector<vector<vector<char>>> &cube,char dir){
    vector<char> tmp;
    if (dir=='+'){
        tmp=cube[FRONT][BOTTOM];
        cube[FRONT][BOTTOM]=cube[LEFT][BOTTOM];
        cube[LEFT][BOTTOM]=cube[BACK][BOTTOM];
        cube[BACK][BOTTOM]=cube[RIGHT][BOTTOM];
        cube[RIGHT][BOTTOM]=tmp;
    }
    else if (dir=='-'){
        tmp=cube[FRONT][BOTTOM];
        cube[FRONT][BOTTOM]=cube[RIGHT][BOTTOM];
        cube[RIGHT][BOTTOM]=cube[BACK][BOTTOM];
        cube[BACK][BOTTOM]=cube[LEFT][BOTTOM];
        cube[LEFT][BOTTOM]=tmp;
    }
    Rotate(cube[DOWN],dir);
}

void Front(vector<vector<vector<char>>> &cube,char dir){
    if (dir=='+'){
        vector<char> tmp={cube[UP][BOTTOM][FIRST],cube[UP][BOTTOM][SECOND],cube[UP][BOTTOM][THIRD]};
        cube[UP][BOTTOM][FIRST]=    cube[LEFT][BOTTOM][THIRD];
        cube[UP][BOTTOM][SECOND]=   cube[LEFT][MIDDLE][THIRD];
        cube[UP][BOTTOM][THIRD]=    cube[LEFT][TOP][THIRD];

        cube[LEFT][TOP][THIRD]=     cube[DOWN][TOP][FIRST];
        cube[LEFT][MIDDLE][THIRD]=  cube[DOWN][TOP][SECOND];
        cube[LEFT][BOTTOM][THIRD]=  cube[DOWN][TOP][THIRD];

        cube[DOWN][TOP][FIRST]=     cube[RIGHT][BOTTOM][FIRST];
        cube[DOWN][TOP][SECOND]=    cube[RIGHT][MIDDLE][FIRST];
        cube[DOWN][TOP][THIRD]=     cube[RIGHT][TOP][FIRST];

        cube[RIGHT][TOP][FIRST]= tmp[0];
        cube[RIGHT][MIDDLE][FIRST]= tmp[1];
        cube[RIGHT][BOTTOM][FIRST]=    tmp[2];
    }
    else if (dir=='-'){
        vector<char> tmp={cube[UP][BOTTOM][FIRST],cube[UP][BOTTOM][SECOND],cube[UP][BOTTOM][THIRD]};
        cube[UP][BOTTOM][FIRST]=    cube[RIGHT][TOP][FIRST];
        cube[UP][BOTTOM][SECOND]=   cube[RIGHT][MIDDLE][FIRST];
        cube[UP][BOTTOM][THIRD]=    cube[RIGHT][BOTTOM][FIRST];

        cube[RIGHT][TOP][FIRST]=     cube[DOWN][TOP][THIRD];
        cube[RIGHT][MIDDLE][FIRST]=  cube[DOWN][TOP][SECOND];
        cube[RIGHT][BOTTOM][FIRST]=  cube[DOWN][TOP][FIRST];

        cube[DOWN][TOP][THIRD]=     cube[LEFT][BOTTOM][THIRD];
        cube[DOWN][TOP][SECOND]=    cube[LEFT][MIDDLE][THIRD];
        cube[DOWN][TOP][FIRST]=     cube[LEFT][TOP][THIRD];

        cube[LEFT][BOTTOM][THIRD]= tmp[0];
        cube[LEFT][MIDDLE][THIRD]= tmp[1];
        cube[LEFT][TOP][THIRD]=    tmp[2];
    }
    Rotate(cube[FRONT],dir);
}

void Back(vector<vector<vector<char>>> &cube,char dir){
    if (dir=='-'){
        vector<char> tmp={cube[UP][TOP][FIRST],cube[UP][TOP][SECOND],cube[UP][TOP][THIRD]};
        cube[UP][TOP][FIRST]=    cube[LEFT][BOTTOM][FIRST];
        cube[UP][TOP][SECOND]=   cube[LEFT][MIDDLE][FIRST];
        cube[UP][TOP][THIRD]=    cube[LEFT][TOP][FIRST];

        cube[LEFT][BOTTOM][FIRST]=  cube[DOWN][BOTTOM][THIRD];
        cube[LEFT][MIDDLE][FIRST]=  cube[DOWN][BOTTOM][SECOND];
        cube[LEFT][TOP][FIRST]=     cube[DOWN][BOTTOM][FIRST];

        cube[DOWN][BOTTOM][THIRD]=     cube[RIGHT][TOP][THIRD];
        cube[DOWN][BOTTOM][SECOND]=    cube[RIGHT][MIDDLE][THIRD];
        cube[DOWN][BOTTOM][FIRST]=     cube[RIGHT][BOTTOM][THIRD];

        cube[RIGHT][TOP][THIRD]=    tmp[0];
        cube[RIGHT][MIDDLE][THIRD]= tmp[1];
        cube[RIGHT][BOTTOM][THIRD]= tmp[2];
    }
    else if (dir=='+'){
        vector<char> tmp={cube[UP][TOP][FIRST],cube[UP][TOP][SECOND],cube[UP][TOP][THIRD]};
        cube[UP][TOP][FIRST]=    cube[RIGHT][TOP][THIRD];
        cube[UP][TOP][SECOND]=   cube[RIGHT][MIDDLE][THIRD];
        cube[UP][TOP][THIRD]=    cube[RIGHT][BOTTOM][THIRD];

        cube[RIGHT][TOP][THIRD]=        cube[DOWN][BOTTOM][THIRD];
        cube[RIGHT][MIDDLE][THIRD]=     cube[DOWN][BOTTOM][SECOND];
        cube[RIGHT][BOTTOM][THIRD]=     cube[DOWN][BOTTOM][FIRST];

        cube[DOWN][BOTTOM][THIRD]=     cube[LEFT][BOTTOM][FIRST];
        cube[DOWN][BOTTOM][SECOND]=    cube[LEFT][MIDDLE][FIRST];
        cube[DOWN][BOTTOM][FIRST]=     cube[LEFT][TOP][FIRST];

        cube[LEFT][TOP][FIRST]=    tmp[2];
        cube[LEFT][MIDDLE][FIRST]= tmp[1];
        cube[LEFT][BOTTOM][FIRST]= tmp[0];
    }
    Rotate(cube[BACK],dir);
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        vector<vector<vector<char>>> cube=CUBE;
        int n;
        cin>>n;
        for(int j=0;j<n;++j){
            char side;
            char dir;
            cin>>side>>dir;
            if(side=='L')
                Left(cube,dir);
            else if(side=='R')
                Right(cube,dir);
            else if(side=='U')
                Up(cube,dir);
            else if(side=='D')
                Down(cube,dir);
            else if(side=='F')
                Front(cube,dir);
            else if(side=='B')
                Back(cube,dir);
        }
        cout<<cube[UP][TOP][FIRST]<<cube[UP][TOP][SECOND]<<cube[UP][TOP][THIRD]<<endl;
        cout<<cube[UP][MIDDLE][FIRST]<<cube[UP][MIDDLE][SECOND]<<cube[UP][MIDDLE][THIRD]<<endl;
        cout<<cube[UP][BOTTOM][FIRST]<<cube[UP][BOTTOM][SECOND]<<cube[UP][BOTTOM][THIRD]<<endl;
    }
}
