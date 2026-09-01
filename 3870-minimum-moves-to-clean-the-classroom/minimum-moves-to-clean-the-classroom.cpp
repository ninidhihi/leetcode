class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int litterCount = 0;

        vector<vector<int>> litterId(m, vector<int>(n, -1));

        // Find S and number every L
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                }

                if (classroom[r][c] == 'L') {
                    litterId[r][c] = litterCount++;
                }
            }
        }

        // No litter -> already finished
        if (litterCount == 0)
            return 0;

        int maskCount = 1 << litterCount;
        int fullMask = maskCount - 1;

        /*
            best[cell][mask] = maximum energy with which
            we have reached this cell having this mask.
        */

        int totalCells = m * n;

        vector<int> best(totalCells * maskCount, -1);

        auto getIndex = [&](int r, int c, int mask) {
            return ((r * n + c) * maskCount + mask);
        };

        struct State {
            int r;
            int c;
            int mask;
            int en;
        };

        queue<State> q;

        best[getIndex(sr, sc, 0)] = energy;

        q.push({sr, sc, 0, energy});

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                State cur = q.front();
                q.pop();

                int r = cur.r;
                int c = cur.c;
                int mask = cur.mask;
                int en = cur.en;

                int currentIndex = getIndex(r, c, mask);

                /*
                    This state is outdated.

                    A better state with the same
                    position + mask has already been found.
                */
                if (best[currentIndex] != en)
                    continue;

                // All litter collected
                if (mask == fullMask)
                    return moves;

                // No energy -> cannot move
                if (en == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Spend 1 energy for the move
                    int newEnergy = en - 1;

                    int newMask = mask;

                    // If we reach litter
                    if (classroom[nr][nc] == 'L') {

                        int id = litterId[nr][nc];

                        newMask |= (1 << id);
                    }

                    // If we reach reset cell
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    int idx = getIndex(nr, nc, newMask);

                    /*
                        If we have already reached this
                        position + mask with MORE energy,
                        this state is useless.
                    */
                    if (best[idx] >= newEnergy)
                        continue;

                    best[idx] = newEnergy;

                    q.push({
                        nr,
                        nc,
                        newMask,
                        newEnergy
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};