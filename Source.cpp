#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>

//������ �����
//5 4
//1 1 3 3
//1 4 2 1 2

using namespace std;

vector<int> col, res;
vector<vector<int> > g;
vector<stack<int> > s; // ������ ������ ������

// ����� � ������� � ������� v
// ��� ����� � ������� v ������ � ���� �������� v, � ���
// ���������� ��������� ������� 
// v ������� �������� ����� (��� ��� ��� ����� ������� v). 
void dfs(int v)
{
    int color = col[v];
    if (s[color].empty()) res[v] = -1;
    else res[v] = s[color].top();
    s[color].push(v);
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        dfs(to);
    }
    s[color].pop();
}
// �������� ����� ���������.������ ������.
int main() {
    int i, n, c, val;
    cin >> n >> c;
    g.resize(n + 1); 
    for (i = 2; i <= n; i++)
    {
        cin >> val;
        g[val].push_back(i);
    }
 // ������ ����� ������ ������.

    col.resize(n + 1);
    for (i = 1; i <= n; i++) cin >> col[i];

 // ��������� ����� � ������� �� ������� 1.
    s.resize(c + 1);
    res.resize(n + 1);
    dfs(1);

 // ������� �����.
    for (i = 1; i <= n; i++) cout << res[i] << " ";

}






















































//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <stdio.h>
//
//
//
//using namespace std;
//
////����� � ������� � ������� v.
//
//
//vector<int> col, res; // ������ ������
//
//vector<vector<int> > g;
//
//vector<stack<int> > s; // ������ ������
//
//void dfs(int v)
//
//{
//
//    int color = col[v];
//
//    if (s[color].empty())
//
//        res[v] = -1;
//
//    else
//
//        res[v] = s[color].top();
//
//
//
//    s[color].push(v);
//
//
//
//    for (int i = 0; i < g[v].size(); i++)
//
//    {
//
//        int to = g[v][i];
//
//        dfs(to);
//
//    }
//
//    s[color].pop();
//
//}
//
//
//
//
//int main() {
//    //�������� ����� ���������.������ ������.
//
//    int n, c;
//    cin >> n >> c;
//    int val;
//   /* cin >> val;*/
//    scanf("%d %d", &n, &c);
//
//    g.resize(n + 1);
//
//    for (int i = 2; i <= n; i++)
//
//    {
//
//        scanf("%d", &val);
//
//        g[val].push_back(i);
//
//    }
//
//
//
//    //������ ����� ������ ������.
//
//
//
//    col.resize(n + 1);
//
//    for (int i = 1; i <= n; i++)
//
//        scanf("%d", &col[i]);
//
//
//
//    //��������� ����� � ������� �� ������� 1.
//
//
//
//    s.resize(c + 1);
//
//    res.resize(n + 1);
//
//    dfs(1);
//
//
//
//    //������� �����.
//
//
//
//    for (int i = 1; i <= n; i++)
//
//        printf("%d ", res[i]);
//
//    printf("\n");
//
//}