#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> answer;

int getRoot(int start, int end, vector<vector<int>>& nodeinfo) {
    int maxY = -1;
    int maxNode;
    for (int i = start; i <= end; i++) {
        if (nodeinfo[i][1] > maxY) {
            maxY = nodeinfo[i][1];
            maxNode = i;
        }
    }
    return maxNode;
}

void inorder(int start, int end, vector<vector<int>>& nodeinfo) {

    int root = getRoot(start, end, nodeinfo);
    answer[0].push_back(nodeinfo[root][2]);
    if (start < root)
        inorder(start, root - 1, nodeinfo);
    if (root < end)
        inorder(root + 1, end, nodeinfo);
}


void postorder(int start, int end, vector<vector<int>>& nodeinfo) {
    int root = getRoot(start, end, nodeinfo);
    if (start < root)
        postorder(start, root - 1, nodeinfo);
    if (root < end)
        postorder(root + 1, end, nodeinfo);
    answer[1].push_back(nodeinfo[root][2]);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<int> v;
    answer.push_back(v);
    answer.push_back(v);

    for (int i = 0; i < nodeinfo.size(); i++)
        nodeinfo[i].push_back(i + 1);

    sort(nodeinfo.begin(), nodeinfo.end());

    inorder(0, nodeinfo.size() - 1, nodeinfo);
    postorder(0, nodeinfo.size() - 1, nodeinfo);

    for (int i = 0; i < 2; i++) {
        for (int j : answer[i])
            cout << j << " ";
        cout << "\n";
    }

    return answer;
}