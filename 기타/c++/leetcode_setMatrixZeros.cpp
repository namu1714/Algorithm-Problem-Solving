class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int rowPoint = -1, colPoint = -1;

        //기준 row,col 정한 후 0인 element 위치 저장
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (rowPoint < 0) {
                        rowPoint = i;
                        colPoint = j;
                    }
                    matrix[i][colPoint] = 0;
                    matrix[rowPoint][j] = 0;
                }
            }
        }

        //0이 없다면 리턴
        if (rowPoint < 0) return;

        //matrix row, col 0으로 바꾸기
        for (int i = 0; i < m; i++) {
            if (matrix[i][colPoint] == 0 && i != rowPoint) {
                for (int j = 0; j < n; j++)
                    matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            if (matrix[rowPoint][i] == 0 && i != colPoint) {
                for (int j = 0; j < m; j++)
                    matrix[j][i] = 0;
            }
        }

        for (int i = 0; i < m; i++) matrix[i][colPoint] = 0;
        for (int i = 0; i < n; i++) matrix[rowPoint][i] = 0;

        return;
    }
};