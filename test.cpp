#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100];
bool visited[100];

bool dfs(int start, int target, vector<int>& path) {
    if (start == target) {  // 如果当前节点是目标节点，则返回true。
        path.push_back(target);
        return true;
    }

    visited[start] = true;
    path.push_back(start);

    for (int next : graph[start]) {  // 遍历所有相邻的节点
        if (!visited[next]) {  // 如果该节点未被访问，则递归访问它。
            if (dfs(next, target, path)) {
                return true;
            }
        }
    }

    path.pop_back();
    visited[start] = false;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {  // 输入无向图的边
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start, target;
    cin >> start >> target;

    vector<int> path;
    if (dfs(start, target, path)) {
        cout << "Found a path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    else {
        cout << "No path found." << endl;
    }

    return 0;
}
