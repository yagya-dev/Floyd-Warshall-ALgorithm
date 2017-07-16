#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 9999
#define NIL -1
int adj[MAX][MAX],dis[MAX][MAX],pre[MAX][MAX],n;
void create_graph();
void floyd();
void find_path(int ,int);
int main()
{int i,j;
    create_graph();
    floyd();
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        find_path(i,j);
}
void find_path(int s,int d)
{
    int i,path[MAX],counts;
    if(dis[s][d]==INF){cout<<"NO PATH"<<endl;return;}
    counts=-1;
    do
    {
        path[++counts]=d;
        d=pre[s][d];
    }while(d!=s);
    cout<<s<<"->";
    for(i=counts;i>=0;i--)cout<<path[i]<<"->";
    cout<<endl;
}
void create_graph()
{
    int source,dest,max_edges,i,j,wt;

    cout<<"ENTER THE TOTAL NO VERTICES"<<" ";
    cin>>n;
    max_edges=n*(n-1);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        adj[i][j]=0;
    for(i=0;i<max_edges;i++)
       {

        cout<<"ENTER SOURCE AND DESTINATION VERTEX (-1 AND -1 TO QUIT)"<<endl;
    cin>>source>>dest;
    if(source==-1&&dest==-1)
        break;
        else if(source>n||dest>n)
            {cout<<"INVALID EDGE"<<endl;i--;continue;}
    else
    {

        cout<<"ENTER THE COST OF THAT EDGE"<<endl;
            cin>>wt;


        adj[source][dest]=wt;}
    }
}
void floyd()
{

  int i,j,k,flag=0;
  for(i=0;i<n;i++)
  {
      for(j=0;j<n;j++)
      {
          if(adj[i][j]==0)
          {
              dis[i][j]=INF;
              pre[i][j]=NIL;
          }
          else
          {
              dis[i][j]=adj[i][j];
              pre[i][j]=i;
          }
      }
  }
  for(k=0;k<n;k++)
  {
      for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(dis[i][j]>dis[i][k]+dis[k][j])
      {
          dis[i][j]=dis[i][k]+dis[k][j];
          pre[i][j]=pre[k][j];
      }
  }
  cout<<"SHORTEST PATH MATRIX IS"<<endl;
  for(i=0;i<n;i++)
  {
      for(j=0;j<n;j++)
        cout<<dis[i][j]<<" ";
      cout<<endl;
  }
  for(i=0;i<n;i++)
  {
      if(dis[i][i]<0)
      {flag++;continue;}
  }
  if(flag==n){cout<<"NEGATIVE CYCLE"<<endl;exit(1);}
}
