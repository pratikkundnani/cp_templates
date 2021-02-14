const int MAXN = 1e6+ 10;

#define int long long
int f[MAXN];
void update(int i,int sum) {
    while(i > 0 && i <  MAXN) {
        f[i]+= sum;
        i += (i & (-i));
    }
}
int sum(int i) {
    int s = 0;
    while(i > 0) {
        s+=f[i];
        i = i - (i&(-i));
    }
    return s;
}
int find(int k) {
    int curr = 0, ans = 0, prevsum = 0;
    for (int i = 19; i >= 0; i--) {
        if ((curr + (1 << i)) < MAXN && f[curr + (1 << i)] + prevsum < k) {
            ans = curr + (1 << i);
            curr = ans;
            prevsum += f[curr];
        }
    }

    return (ans + 1);
}
