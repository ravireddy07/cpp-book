#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int kMaxN = 1e3 + 5;

int el[kMaxN][kMaxN];

bool visited[kMaxN][kMaxN];
int group_id[kMaxN][kMaxN];

int next_group = 1;
int group_size[kMaxN * kMaxN];

const int dx[4] = {0, 0, -1, +1};
const int dy[4] = {-1, +1, 0, 0};

void Expand(int x, int y) {
    vector<pair<int, int>> fill_q = {{x, y}};
    visited[x][y] = true;

    int g = next_group++;
    while (fill_q.size()) {
        int x = fill_q.back().first;
        int y = fill_q.back().second;
        fill_q.pop_back();

        group_size[g] += 1;
        group_id[x][y] = g;

        for (int d = 0; d < 4; d += 1) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (not visited[nx][ny] and el[nx][ny]) {
                visited[nx][ny] = true;
                fill_q.push_back({nx, ny});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            cin >> el[i][j];
        }
    }

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            if (visited[i][j] == false and el[i][j]) {
                Expand(i, j);
            }
        }
    }

    int mx = 0;
    vector<int> ap(5, 0);
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            if (el[i][j]) {
                continue;
            }

            vector<int> groups = {};
            for (int d = 0; d < 4; d += 1) {
                groups.push_back(group_id[i + dx[d]][j + dy[d]]);
            }

            sort(groups.begin(), groups.end());
            groups.resize(unique(groups.begin(), groups.end()) - groups.begin());


            int s = 0;
            for (auto itr : groups) {
                s += group_size[itr];
            }
            mx = max(mx, s + 1);
        }
    }
    cout << mx << '\n';
    return 0;
}
