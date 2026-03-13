//#include <iostream>
//#include <queue>
//#include <stack>
//using namespace std;
//
//class RescueBot {
//private:
//    int grid[50][50];
//    int rows, cols;
//
//public:
//    RescueBot(int g[][50], int r, int c) {
//        rows = r;
//        cols = c;
//        for (int i = 0; i < r; i++)
//            for (int j = 0; j < c; j++)
//                grid[i][j] = g[i][j];
//    }
//
//    int find_shortest_path(pair<int, int> start, pair<int, int> end, pair<int, int> pathOut[]) {
//        bool visited[50][50];
//        pair<int, int> parent[50][50];
//
//        for (int i = 0; i < 50; i++)
//            for (int j = 0; j < 50; j++)
//                visited[i][j] = false;
//
//        int sr = start.first, sc = start.second;
//        int er = end.first, ec = end.second;
//
//        if (grid[sr][sc] == 1 || grid[er][ec] == 1)
//            return 0;
//
//        queue<pair<int, int>> q;
//        visited[sr][sc] = true;
//        parent[sr][sc] = { -1, -1 };
//        q.push(start);
//
//        while (!q.empty()) {
//            auto p = q.front();
//            q.pop();
//
//            int r = p.first, c = p.second;
//            if (r == er && c == ec)
//                return reconstruct(parent, start, end, pathOut);
//
//            int nr, nc;
//
//            nr = r - 1; nc = c;
//            if (nr >= 0 && grid[nr][nc] == 0 && !visited[nr][nc]) {
//                visited[nr][nc] = true;
//                parent[nr][nc] = p;
//                q.push({ nr, nc });
//            }
//
//            nr = r + 1; nc = c;
//            if (nr < rows && grid[nr][nc] == 0 && !visited[nr][nc]) {
//                visited[nr][nc] = true;
//                parent[nr][nc] = p;
//                q.push({ nr, nc });
//            }
//
//            nr = r; nc = c - 1;
//            if (nc >= 0 && grid[nr][nc] == 0 && !visited[nr][nc]) {
//                visited[nr][nc] = true;
//                parent[nr][nc] = p;
//                q.push({ nr, nc });
//            }
//
//            nr = r; nc = c + 1;
//            if (nc < cols && grid[nr][nc] == 0 && !visited[nr][nc]) {
//                visited[nr][nc] = true;
//                parent[nr][nc] = p;
//                q.push({ nr, nc });
//            }
//        }
//
//        return 0;
//    }
//
//    int find_any_path(pair<int, int> start, pair<int, int> end, pair<int, int> pathOut[]) {
//        bool visited[50][50];
//        pair<int, int> parent[50][50];
//
//        for (int i = 0; i < 50; i++)
//            for (int j = 0; j < 50; j++)
//                visited[i][j] = false;
//
//        int sr = start.first, sc = start.second;
//        int er = end.first, ec = end.second;
//
//        if (grid[sr][sc] == 1 || grid[er][ec] == 1)
//            return 0;
//
//        stack<pair<int, int>> st;
//        visited[sr][sc] = true;
//        parent[sr][sc] = { -1, -1 };
//        st.push(start);
//
//        while (!st.empty()) {
//            auto p = st.top();
//            st.pop();
//
//            int r = p.first, c = p.second;
//            if (r == er && c == ec)
//                return reconstruct(parent, start, end, pathOut);
//
//            int nr, nc;
//
//            nr = r - 1; nc = c;
//            if (nr >= 0 && grid[nr][nc] == 0 && !visited[nr][nc]) {
//                visited[nr][nc] = true;
//                parent[nr][nc] = p;
//                st.push({ nr, nc });
//            }
//
//            nr = r + 1; nc = c;
//            if (nr < rows && grid[nr][nc] == 0 && !visited[nr][nc]) {
//                visited[nr][nc] = true;
//                parent[nr][nc] = p;
//                st.push({ nr, nc });
//            }
//
//            nr = r; nc = c - 1;
//            if (nc >= 0 && grid[nr][nc] == 0 && !visited[nr][nc]) {
//                visited[nr][nc] = true;
//                parent[nr][nc] = p;
//                st.push({ nr, nc });
//            }
//
//            nr = r; nc = c + 1;
//            if (nc < cols && grid[nr][nc] == 0 && !visited[nr][nc]) {
//                visited[nr][nc] = true;
//                parent[nr][nc] = p;
//                st.push({ nr, nc });
//            }
//        }
//
//        return 0;
//    }
//
//private:
//    int reconstruct(pair<int, int> parent[50][50], pair<int, int> start, pair<int, int> end, pair<int, int> out[]) {
//        pair<int, int> temp[2500];
//        int idx = 0;
//
//        pair<int, int> cur = end;
//        while (!(cur.first == -1 && cur.second == -1)) {
//            temp[idx++] = cur;
//            cur = parent[cur.first][cur.second];
//        }
//
//        int k = 0;
//        for (int i = idx - 1; i >= 0; i--)
//            out[k++] = temp[i];
//
//        return k;
//    }
//};
//
//int main() {
//    int grid[50][50] = { 0 };
//    int r = 17, c = 17;
//
//    int g2[17][17] = {
//        {0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
//        {1,1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,0},
//        {0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0},
//        {0,1,1,0,1,1,1,0,1,1,1,1,0,1,0,1,0},
//        {0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0},
//        {0,1,0,1,1,0,1,1,1,0,1,1,0,1,0,1,0},
//        {0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0},
//        {1,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,0},
//        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0},
//        {0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0},
//        {0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0},
//        {1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0},
//        {0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0},
//        {0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0},
//        {0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0},
//        {1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0},
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//    };
//
//    for (int i = 0; i < r; i++)
//        for (int j = 0; j < c; j++)
//            grid[i][j] = g2[i][j];
//
//    RescueBot bot(grid, r, c);
//
//    pair<int, int> start = { 0, 0 };
//    pair<int, int> end = { 14, 10 };
//
//    pair<int, int> shortest[2500];
//    pair<int, int> anypath[2500];
//
//    int len1 = bot.find_shortest_path(start, end, shortest);
//    int len2 = bot.find_any_path(start, end, anypath);
//
//    cout << "Shortest Path (BFS): ";
//    if (len1 == 0) cout << "No path";
//    else for (int i = 0; i < len1; i++)
//        cout << "(" << shortest[i].first << "," << shortest[i].second << ") ";
//
//    cout << "\nAny Path (DFS): ";
//    if (len2 == 0) cout << "No path";
//    else for (int i = 0; i < len2; i++)
//        cout << "(" << anypath[i].first << "," << anypath[i].second << ") ";
//}
