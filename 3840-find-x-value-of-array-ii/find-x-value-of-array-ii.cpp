class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int n, k;
    vector<Node> tree;

    Node merge(const Node& A, const Node& B) {
        Node C;

        // Product of the whole segment
        C.prod = (A.prod * B.prod) % k;

        // Prefixes ending inside A
        for (int r = 0; r < k; r++) {
            C.cnt[r] = A.cnt[r];
        }

        // Prefixes extending into B
        for (int r = 0; r < k; r++) {
            int nr = (A.prod * r) % k;
            C.cnt[nr] += B.cnt[r];
        }

        return C;
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }
        

        int mid = (l + r) >> 1;

        build(nums, node << 1, l, mid);
        build(nums, node << 1 | 1, mid + 1, r);

        tree[node] = merge(tree[node << 1],
                           tree[node << 1 | 1]);
    }

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            int rem = value % k;

            tree[node] = Node();
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(node << 1, l, mid, idx, value);
        else
            update(node << 1 | 1, mid + 1, r, idx, value);

        tree[node] = merge(tree[node << 1],
                           tree[node << 1 | 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;

        if (qr <= mid)
            return query(node << 1, l, mid, ql, qr);

        if (ql > mid)
            return query(node << 1 | 1, mid + 1, r, ql, qr);

        Node left = query(node << 1, l, mid, ql, qr);
        Node right = query(node << 1 | 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        this->k = k;
        n = nums.size();

        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> result;
        result.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update persists
            nums[index] = value;
            update(1, 0, n - 1, index, value);

            // Query [start, n-1]
            Node ans = query(1, 0, n - 1, start, n - 1);

            result.push_back(ans.cnt[x]);
        }

        return result;
    }
};