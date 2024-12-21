//Tim Kiem BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(int start, const vector<vector<int> >& list, vector<bool>& visit) {
    queue<int> q;
    q.push(start);
    visit[start] = true;
    cout << "Duyet BFS: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
   for (size_t i = 0; i<list[node].size();i++) {
        	int neighbor = list[node][i];
            if (!visit[neighbor]) {
                q.push(neighbor);
                visit[neighbor] = true;
            }
        }
    }
    cout << endl;
}
int main() {
    int n, m; 
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh: ";
    cin >> m;
    vector<vector<int> > list(n + 1); 
    cout << "Nhap cac canh (dinh 1, dinh 2):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
      int start;
    cout << "Nhap dinh bat dau: ";
    cin >> start;
    vector<bool> visit(n + 1, false);
    BFS(start,list,visit);
       return 0;
}

