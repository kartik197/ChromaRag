#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to calculate the cost between two villages
long long calculate_cost(const vector<int>& trees, const vector<int>& distance, int i, int j) {
    long long cost = 0;
    for (int k = i; k < j; ++k) {
        cost += static_cast<long long>(trees[k]) * (distance[j] - distance[k]);
    }
    return cost;
}

int main() {
    int N, K;
    cin >> N >> K;  // N is the number of villages, K is the number of additional sawmills

    vector<int> trees(N);  // number of trees at each village
    vector<int> distance(N);  // distance of each village from Byteland

    for (int i = 0; i < N; ++i) {
        cin >> distance[i] >> trees[i];
    }

    // dp[i][j] represents the minimum cost for the first i villages with j sawmills
    vector<vector<long long>> dp(N, vector<long long>(K + 1, LLONG_MAX));

    // Initialize the cost with no additional sawmills (all trees transported to Byteland)
    for (int i = 0; i < N; ++i) {
        dp[i][0] = calculate_cost(trees, distance, 0, i);
    }

    // Compute the cost for each possible number of sawmills
    for (int j = 1; j <= K; ++j) {
        for (int i = 0; i < N; ++i) {
            for (int m = 0; m < i; ++m) {
                dp[i][j] = min(dp[i][j], dp[m][j - 1] + calculate_cost(trees, distance, m + 1, i));
            }
        }
    }

    // The answer is the minimum cost with K additional sawmills considering all villages
    cout << dp[N - 1][K] << endl;

    return 0;
}