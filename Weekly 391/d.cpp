class Solution {
public:
    using ll = long long;
    using T = pair<ll, ll>;
    static constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
    std::array<ll, 3> get(vector<vector<int>>& points, int skip = -1) {
        // initialisation
        T sum[2] = {{INF, -1}, {-INF, -1}};
        T diff[2] = {{INF, -1},  {-INF, -1}};
        for (int i = 0; i < points.size(); ++i) {
            if (i == skip) continue;
            auto p = points[i];
            if (p[0] + p[1] < sum[0].first) {
                sum[0].first = p[0] + p[1];
                sum[0].second = i;
            }

            if (p[0] + p[1] > sum[1].first) {
                sum[1].first = p[0] + p[1];
                sum[1].second = i;
            }

            if (p[0] - p[1] < diff[0].first) {
                diff[0].first = p[0] - p[1];
                diff[0].second = i;
            }

            if (p[0] - p[1] > diff[1].first) {
                diff[1].first = p[0] - p[1];
                diff[1].second = i;
            }
        }
        // cout << abs(sum[0].first - sum[1].first) << ' ' << abs(diff[0].first - diff[1].first) << '\n';
        // cout << sum[0].second << ' ' << sum[1].second << '\n';
        // cout << diff[0].second << ' ' << diff[1].second << '\n';
        if (abs(sum[0].first - sum[1].first) > abs(diff[0].first - diff[1].first)) {
            return {abs(sum[1].first - sum[0].first), sum[0].second, sum[1].second};
        }

        return {abs(diff[1].first - diff[0].first), diff[0].second, diff[1].second};

    }

    int minimumDistance(vector<vector<int>>& points) {
        auto [a, b, d] = get(points);

        auto [a2, b2, d2] = get(points, b);

        auto [a3, b3, d3] = get(points, d);


        return min(a2, a3);


    }
};
