using ll = long long;

class Solution {
public:
    ll find(ll a, vector<ll>& p) {
        if (p[a] != a) {
            p[a] = find(p[a], p);
        }

        return p[a];
    }

    void uf(ll a, ll b, ll c, vector<ll>& p, vector<ll>& A) {
        ll p1 = find(a, p);
        ll p2 = find(b, p);

        p[p2] = p1;
        A[p1] &= c;
        A[p1] &= A[p2];
        A[p2] = A[p1];

    }


    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<ll>p(n, 0);
        vector<ll>A(n, (1LL << 62) - 1LL);
        for (int i = 0; i < n; ++i) p[i] = i;
        for (auto& e: edges) {
            int a = e[0], b = e[1], c = e[2];
            uf(a, b, c, p, A);
        }

        vector<int>res;
        for (auto& q: query) {
            int a = q[0], b = q[1];
            auto c = find(a, p);
            auto d = find(b, p);
            if (c != d) {
                res.push_back(-1);
            } else {
                res.push_back(A[c]);
            }
        }
        return res;
    }
};
