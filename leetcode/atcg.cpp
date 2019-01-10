#include<string>


const char *AGCT = "AGCT";
const int MOD = 10009;

const int MAX_K = 5;
const int MAX_N = 10;
int N, K;
std::string S;

int next[MAX_K][4];
int dp[MAX_N+1][MAX_K];

void solve() {
    for (int i = 0; i < K; i++){
        for (int j = 0; j < 4; j++) {
            std::string s = S.substr(0, i) + AGCT[j];
            while (S.substr(0, s.length())!=s) {
                s = s.substr(1);
            }
            next[i][j] = s.length();
        }
    }

    dp[0][0] =1;
    for(int i =1; i < K; i++)
        dp[0][i] = 0;
    
    for (int t = 0; t<N; t++){
        for (int i =0; i< K; i++) {
            dp[t+1][i] = 0;
        }


        for(int i = 0; i < K; i++) {
            for (int j = 0; j <4; j++) {
                int ti = next[i][j];
                if (ti == K)
                    continue;
                dp[t+1][ti] = (dp[t+1][ti] + dp[t][i])%MOD;
            }
        }

    }

    int ans = 0;
    for (int i = 0; i < K; i++)
        ans = (ans + dp[N][i]) % MOD;
    printf("%d\n", ans);
    return ;
}
