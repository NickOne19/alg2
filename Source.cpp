#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>

//Пример входа
//5 4
//1 1 3 3
//1 4 2 1 2

using namespace std;

vector<int> col, res;
vector<vector<int> > g;
vector<stack<int> > s; // вектор стеков цветов

// поиск в глубину с вершины v
// При входе в вершину v кладем в стек значение v, а при
// завершении обработки вершины 
// v удаляем верхушку стека (это как раз будет вершина v). 
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
// Основная часть программы.Читаем дерево.
int main() {
    int i, n, c, val;
    cin >> n >> c;
    g.resize(n + 1); 
    for (i = 2; i <= n; i++)
    {
        cin >> val;
        g[val].push_back(i);
    }
 // Читаем цвета вершин дерева.

    col.resize(n + 1);
    for (i = 1; i <= n; i++) cin >> col[i];

 // Запускаем поиск в глубину из вершины 1.
    s.resize(c + 1);
    res.resize(n + 1);
    dfs(1);

 // Выводим ответ.
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
////Поиск в глубину с вершины v.
//
//
//vector<int> col, res; // вектор стеков
//
//vector<vector<int> > g;
//
//vector<stack<int> > s; // вектор стеков
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
//    //Основная часть программы.Читаем дерево.
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
//    //Читаем цвета вершин дерева.
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
//    //Запускаем поиск в глубину из вершины 1.
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
//    //Выводим ответ.
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