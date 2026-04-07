class Robot {
public:
    int w, h;
    int x, y;
    int dir; // 0=E, 1=N, 2=W, 3=S
    int cycle;

    vector<string> dirs = {"East", "North", "West", "South"};
    vector<vector<int>> moves = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
        cycle = 2 * (w + h - 2);
    }

    void step(int num) {
        num %= cycle;
        if (num == 0) num = cycle;  // 🔥 key fix

        while (num > 0) {
            int nx = x + moves[dir][0];
            int ny = y + moves[dir][1];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4;
            } else {
                x = nx;
                y = ny;
                num--;
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return dirs[dir];
    }
};