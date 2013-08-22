#include <iostream>
#include <stack>
using namespace std;
int vis[11], target[11];
int num;
#define TEST
bool test(int *target, int depth)
{
    stack<int> s;

    int a = 1,b = 1;
    while(b <= depth)
    {
        if(a == target[b]) {a++; b++;}

        else if(!s.empty() && s.top() == target[b]) {s.pop();b++;}

        else if(a <= depth) {s.push(a++);}

        else {return false;}
    }
    return true;
}
void dfs(int cur, int depth)
{
    if(cur == depth)
    {
#ifdef TEST
        for(int i = 1; i <= depth; i++)
            cout<<target[i];

        if(test(target, depth))
            cout<<" "<<"yes";
        else
            cout<<" "<<"no";
        cout<<endl;
#endif
        if(test(target, depth)) num++;

    }
    else
    {
        for(int i = 1; i <= depth; i++)
        {
            if(vis[i]) continue;
            vis[i] = 1;
            target[cur+1] = i;
            dfs(cur+1, depth);
            vis[i] = 0;
        }
    }
}

int main()
{
    /*
    for(int i = 1; i <= 10; i++)
    {
        num = 0;
        dfs(0,i);
        cout<<"n="<<i<<": "<<num<<endl;
    }
    */
    dfs(0,4);
    return 0;
}
