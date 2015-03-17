#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int z, x, y;
    Point(int z, int x, int y) : z(z), x(x), y(y) {}
};

int main() {
    int m, n, l, t;
    vector<vector<vector<int> > > matrix;

    scanf("%d %d %d %d", &m, &n, &l, &t);
    for (int k = 0; k != l; ++k) {
        vector<vector<int> > v1;
        for (int i = 0; i != m; ++i) {
            vector<int> v2;
            for (int j = 0; j != n; ++j) {
                int num;
                scanf("%d", &num);
                v2.push_back(num);
            }
            v1.push_back(v2);
        }
        matrix.push_back(v1);
    }

    int totalV = 0;
    int v;
    queue<Point> pointList;

    for (int k = 0; k != l; ++k) {
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (matrix[k][i][j] == 1) {
                    v = 0;
                    pointList.push(Point(k, i, j));

                    while (!pointList.empty()) {
                        Point p = pointList.front();
                        int z = p.z;
                        int x = p.x;
                        int y = p.y;
                        pointList.pop();

                        if (matrix[z][x][y] == 1) {
                            matrix[z][x][y] = 2;
                            ++v;

                            if (z > 0) {
                                pointList.push(Point(z - 1, x, y));
                            }
                            if (z < l - 1) {
                                pointList.push(Point(z + 1, x, y));
                            }
                            if (x > 0) {
                                pointList.push(Point(z, x - 1, y));
                            }
                            if (x < m - 1) {
                                pointList.push(Point(z, x + 1, y));
                            }
                            if (y > 0) {
                                pointList.push(Point(z, x, y - 1));
                            }
                            if (y < n - 1) {
                                pointList.push(Point(z, x, y + 1));
                            }
                        }
                    }

                    totalV += v >= t ? v : 0;
                }
            }
        }
    }

    printf("%d\n", totalV);

    return 0;
}