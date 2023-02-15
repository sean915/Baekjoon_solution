#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vGraph;
bool *flag;

void dfs(int Indx);

int main(){

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n,m,node,node2;
  int cnt = 0;
  // node번호를 배열 인덱스로 치환 ( -1)
  int indx,indx2;
  vector<int> v;

  // input
  cin >> n >> m; 
  flag = new bool[n];
  
  for(int i=0;i<n;i++) 
  {
    vGraph.push_back(v);
    flag[i] = false;
  }
  
  for(int i=0; i<m; i++)
  { // node값 입력, 배열 indx로 연결관계 치환
    cin >> node >> node2;
    indx = node -1; indx2 = node2 -1;
    // 무방향 그래프
    vGraph[indx].push_back(indx2);
    vGraph[indx2].push_back(indx);
  }

  // 연결 요소 카운트
  for(int i=0;i<n;i++) 
  {
    if(flag[i] == false)
    {
      cnt++;
      dfs(i);
    }
  }
  cout << cnt;
}


void dfs(int Indx)
{
  if(flag[Indx] == false)
  {
    flag[Indx] = true;
    int nextIndx;
    if(vGraph[Indx].size() > 0)
    {
      for(int i=0;i<vGraph[Indx].size();i++)
      {
        nextIndx = vGraph[Indx][i];
        dfs(nextIndx);
      }
    }
  }
}