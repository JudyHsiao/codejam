#include <iostream>
#include <string>
#include <map>

using namespace std;

const int maxn = 10000 + 5;
const int maxm = 10;
int cnt;
int m, n;

int db[maxn][maxm];

map<string, int> id;
int ID(const string &s)
{
    if (!id.count(s))
        id[s] = ++cnt;
    return id[s];
}

void find()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            map<pair<int, int>, int> s;
            for (int r = 0; r < n; r++)
            {
                int x = db[r][i];
                int y = db[r][j];
                if (s.count({x, y}) == 0)
                    s[{x, y}] = r;
                else
                {
                    printf("NO\n");
                    printf("%d %d\n", s[{x, y}]+1, r + 1);
                    printf("%d %d\n", i + 1, j + 1);
                    return;
                }
            }
        }
    }
    printf("YES\n");
    return;
}

int main()
{


    while (cin >> n >> m)
    {
        cin.get();
        cnt = 0;
        id.clear();
        for (int i = 0; i < n; i++)
        {
            string s;
            getline(cin, s);
            int last = -1, p = 0;
            for (int j = 0; j < m; j++)
            {
                p = s.find(',', last + 1);
                if (p == string::npos)
                    p = s.length();
                db[i][j] = ID(s.substr(last+1, p - last - 1));
                last = p;
            }
        }
        find();
    }
    return 0;
}