#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        int prod;
        int cnt[5];
    };

    Node identity(int k) {
        Node id;
        id.prod = 1 % k;
        for (int i = 0; i < k; ++i) id.cnt[i] = 0;
        return id;
    }

    Node makeLeaf(int value, int k) {
        Node leaf;
        leaf.prod = value % k;
        for (int i = 0; i < k; ++i) leaf.cnt[i] = 0;
        leaf.cnt[leaf.prod] = 1;
        return leaf;
    }

    Node mergeNode(const Node& a, const Node& b, int k) {
        Node c;
        c.prod = (a.prod * b.prod) % k;

        for (int i = 0; i < k; ++i) {
            c.cnt[i] = a.cnt[i];
        }

        for (int i = 0; i < k; ++i) {
            if (b.cnt[i] > 0) {
                int r = (a.prod * i) % k;
                c.cnt[r] += b.cnt[i];
            }
        }

        return c;
    }

    void build(int node, int l, int r, vector<int>& nums, int k, vector<Node>& tree) {
        if (l == r) {
            tree[node] = makeLeaf(nums[l], k);
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid, nums, k, tree);
        build(node * 2 + 1, mid + 1, r, nums, k, tree);
        tree[node] = mergeNode(tree[node * 2], tree[node * 2 + 1], k);
    }

    void update(int node, int l, int r, int idx, int value, int k, vector<Node>& tree) {
        if (l == r) {
            tree[node] = makeLeaf(value, k);
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(node * 2, l, mid, idx, value, k, tree);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, value, k, tree);
        }

        tree[node] = mergeNode(tree[node * 2], tree[node * 2 + 1], k);
    }

    Node query(int node, int l, int r, int ql, int qr, int k, vector<Node>& tree) {
        if (qr < l || r < ql) {
            return identity(k);
        }

        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;
        Node left = query(node * 2, l, mid, ql, qr, k, tree);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr, k, tree);
        return mergeNode(left, right, k);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<Node> tree(4 * n + 5);

        build(1, 0, n - 1, nums, k, tree);

        vector<int> ans;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value, k, tree);

            Node res = query(1, 0, n - 1, start, n - 1, k, tree);
            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};