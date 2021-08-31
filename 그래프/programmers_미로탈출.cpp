#include <bits/stdc++.h>

#define INF INT_MAX
using namespace std;

typedef struct Point {
    int cur, dist, trap;
};

struct compare {
    bool operator()(const Point& p1, const Point& p2) {
        return p1.dist > p2.dist;
    }
};

vector<int> graph[1001]; // 연결된 길 번호

int roomDist[1001][1024];
int isTrap[1001]; // 트랩번호

int djikstra(int start, int end, vector<vector<int>>& roads) {
    priority_queue<Point, vector<Point>, compare> pq;

    roomDist[start][0] = 0;
    pq.push({ start, 0, 0 });

    while (!pq.empty()) {
        bool nextTrap, curTrap = false;
        int trapState = pq.top().trap;
        int cur = pq.top().cur;
        int dist = pq.top().dist;

        pq.pop();

        if (cur == end)
            return dist;

        if (dist > roomDist[cur][trapState]) continue;

        if (isTrap[cur] > -1)
            trapState ^= (1 << isTrap[cur]);

        if (isTrap[cur] > -1 && ((1 << isTrap[cur]) & trapState) > 0)
            curTrap = true;

        for (int r : graph[cur]) {
            int cost = roads[r][2];
            int next = roads[r][1] == cur ? roads[r][0] : roads[r][1];

            nextTrap = false;
            if (isTrap[next] > -1 && ((1 << isTrap[next]) & trapState) > 0)
                nextTrap = true;

            if ((curTrap == nextTrap && cur == roads[r][0]) //정방향
                || (curTrap != nextTrap && cur == roads[r][1])) { //역방향
                if (roomDist[next][trapState] > dist + cost) {
                    roomDist[next][trapState] = dist + cost;
                    pq.push({ next, dist + cost, trapState });
                }
            }
        }
    }

    return -1;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    fill_n(isTrap, 1001, -1);
    fill(&roomDist[0][0], &roomDist[1000][1024], INF);

    for (int i = 0; i < traps.size(); i++)
        isTrap[traps[i]] = i;

    for (int i = 0; i < roads.size(); i++) {
        graph[roads[i][0]].push_back(i);
        graph[roads[i][1]].push_back(i);
    }

    return djikstra(start, end, roads);
}