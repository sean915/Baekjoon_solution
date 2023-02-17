#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int x,int y,vector<pair<int,int>> vMap);
vector<vector<bool>> flag;
int Rows,Cols;
int cnt = 0;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> result;
  int testCnt;
  int K;
  int row,col;
  cin >> testCnt;

  pair<int,int> p;

  for(int i=0;i<testCnt;i++)
  {
    vector<pair<int,int>> vMap;
    // 가로,세로,연결된 배추 수 
    cin >> Cols >> Rows >> K;
        
    for (int i = 0; i < Rows; i++)
    {
      vector<bool> element(Cols);
      flag.push_back(element);
    }    
    
    for(int i=0;i<Rows;i++)
      for(int j=0;j<Cols;j++) 
        flag[i][j] = 0;
  
    for(int i=0;i<K;i++)
    {
      // 배추의 x = col,y = row좌표
      cin >> col >> row;
      p.first = col; p.second = row;
      vMap.push_back(p);
    }

    for(int i=0;i<K;i++)
    {
      col = vMap[i].first;
      row = vMap[i].second;
      //cout << col << row << '\n';
      if(!flag[row][col]) 
      {
        cnt++;
        DFS(row,col,vMap);
      } 
    }
    result.push_back(cnt);
    
    for (int i = 0; i < Cols; i++)
    {
        flag[i].clear();
    }
    flag.clear();
    cnt = 0;
  }

  for(int i=0;i<result.size();i++)
    cout << result[i] << '\n';

  return 0;
}

void DFS(int row,int col,vector<pair<int,int>> vMap)
{
  if(!flag[row][col])
  {
    flag[row][col] = true;
    if(row+1<Rows) 
    {
      pair<int,int> p = make_pair(col,row+1);
      if(find(vMap.begin(),vMap.end(),p)!= vMap.end())
         DFS(row+1,col,vMap);
    }
    if(col+1<Cols) 
    {
      pair<int,int> p = make_pair(col+1,row);
      if(find(vMap.begin(),vMap.end(),p)!= vMap.end())
         DFS(row,col+1,vMap);
    }
    if(row-1>=0) 
    {
      pair<int,int> p = make_pair(col,row-1);
      if(find(vMap.begin(),vMap.end(),p)!= vMap.end())
        DFS(row-1,col,vMap);
    }
    if(col-1>=0) 
    {
      pair<int,int> p = make_pair(col-1,row);
      if(find(vMap.begin(),vMap.end(),p)!= vMap.end())
        DFS(row,col-1,vMap);
    }
  }
}