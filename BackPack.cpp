#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
	Solution() {
	}
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.begin(), coins.end(), greater<int>());
		int res = -1;
		int** dp = new int* [coins.size() + 1];
		int m = coins.size() + 1;
		int n = amount + 1;
		for (int i = 0; i < m; ++i) {
			dp[i] = new int[n];
		}
		for (int i = 1; i < n; ++i) {
			dp[0][i] = amount + 1;
		}
		for (int i = 0; i < m; ++i) {
			dp[i][0] = 0;
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (j - coins[i - 1] >= 0) {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		res = dp[m - 1][amount] == (amount + 1) ? -1 : dp[m - 1][amount];
		for (int i = 0; i < m; ++i) {
			delete[] dp[i];
		}
		return res;
	}

	int coinChange(vector<int>& coins, int amount){
		int* dp = new int[amount + 1, amount + 1];
		for (int i = 1; i < amount;++i) {
			dp[i] = (amount + 1);
		}
		dp[0] = 0;
		int res = -1;
		for (int i = 1; i < amount;++i) {
			for (int j = 0; j < coins.size();++j) {
				if (i-coins[j]>=0) {
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}
		res = (dp[amount] == (amount + 1)) ? -1: dp[amount];
		delete[] dp;
		return res;
	}
};