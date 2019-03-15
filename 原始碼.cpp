#include<iostream>

#define N 102
using namespace std;


int grid[N][N];
int mem[N][N];

int n,k;

int dp(int x,int y){
    if(mem[x][y]!=-1)
        return mem[x][y];

    int ans=0;

    int row_min = max(1,x-k);
    int row_max = min(n,x+k);
    int col_min = max(1,y-k);
    int col_max = min(n,y+k);

    for(int i = row_min ; i <= row_max ; i++)
        if(grid[x][y] < grid[i][y])
            ans = max(ans,dp(i,y));

    for(int j = col_min ; j <= col_max ; j++)
        if(grid[x][y] < grid[x][j])
            ans = max(ans,dp(x,j));

    return mem[x][y] = ans + grid[x][y];
}


int main(){
    int caseNum;
    cin>>caseNum;

    while(caseNum--){
        cin>>n>>k;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>grid[i][j];

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mem[i][j] = -1;

        int ans = dp(1,1);

        cout<<ans<<endl;

        if(caseNum>0)
            cout<<endl;
    }
    return 0;

}

