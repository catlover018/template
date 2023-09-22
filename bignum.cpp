// cre: Nguyen Hoang Hung - Train VOI 2024

#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define bit(X, i) ((X >> i) & 1)
#define cntbit(X, i) __builtin_popcountll(X)
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define all(X) begin(X), end(X)
#define SZ(X) ((int)(X).size())
#define RR(X) X.resize(unique(all(X)) - begin(X))
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

using namespace std;

template <typename T>
bool maximize(T &x, T y)
{
  if(x < y)
    x = y;
  else
    return 0;
  return 1;
}
template <typename T>
bool minimize(T &x, T y)
{
  if(x > y)
    x = y;
  else
    return 0;
  return 1;
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> BigInt;

ll Rand(ll l, ll r) { return l + rand() % (r - l + 1); }

const int maxN = 1e6;
const ll inf = 1e18+7;
const int MOD = 1e9 + 7;
const double PI = acos(-1);
const int base = 10000;

/*
-------------------------------------------------------------------------------------
    END OF TEMPLATE
-------------------------------------------------------------------------------------
    Nguyen Hoang Hung - catlover
    Training for VOI24 gold medal
-------------------------------------------------------------------------------------
*/

BigInt bigint(string s) {
    BigInt a;

    if(SZ(s) == 0) {
        a.pb(0);
        return a;
    }

    while(SZ(s) % 4 != 0) {
        s = '0' + s;
    }

    for(int i = 0; i < SZ(s); i += 4) {
        int value = 0;
        FOR(j, 0, 3)
            value = value * 10 + (s[i + j] - '0');
        a.insert(a.begin(), value);
    }

    return a;
}

void Print(const BigInt a) {
    int limit = SZ(a);
    printf("%d", a[limit - 1]);
    FORD(i, limit - 2, 0) printf("%04d", a[i]);
    printf("\n");
}

BigInt operator + (BigInt a, BigInt b) {
    BigInt c;
    int carry = 0;
    FOR(i, 0, max(SZ(a), SZ(b)) - 1)
    {
        if(i < SZ(a)) carry += a[i];
        if(i < SZ(b)) carry += b[i];
        c.pb(carry % base);
        carry /= base;
    }
    if(carry) c.pb(carry);
    return c;
}

void fix(BigInt &a) {
    while(SZ(a) && *a.rbegin() == 0) a.pop_back();
}

BigInt operator - (BigInt a, BigInt b) {
    BigInt c;
    int carry = 0;
    FOR(i, 0, SZ(a) - 1) {
        int s = a[i] - carry;
        if(i < SZ(b)) s -= b[i];
        if(s < 0) s += base, carry = 1;
        else carry = 0;
        c.pb(s);
    }
    while(*c.rbegin() == 0 && SZ(c) > 1) c.pop_back();
    return c;
}

BigInt operator * (BigInt a, int mul) {
    BigInt c;
    int carry = 0;
    FOR(i, 0, SZ(a) - 1) {
        carry += a[i] * mul;
        c.pb(carry % base);
        carry /= base;
    }
    if(carry) c.pb(carry);
    return c;
}

BigInt operator * (BigInt a, BigInt b) {
    BigInt c(SZ(a) + SZ(b) + 5, 0);
    FOR(i, 0, SZ(a) - 1) {
        int carry = 0;
        FOR(j, 0, SZ(b) - 1) {
            int k = i + j;
            c[k] += a[i] * b[j] + carry;
            carry = c[k] / base;
            c[k] %= base;
        }
        if(carry) c[i+SZ(b)] += carry;
    }
    while(*c.rbegin() == 0 && SZ(c) > 1) c.pop_back();
    return c;
}

bool operator < (BigInt a, BigInt b) {
    fix(a); fix(b);
    if(SZ(a) != SZ(b)) return SZ(a) < SZ(b);
    FORD(i, SZ(a) - 1, 0)
        if(a[i] != b[i]) return a[i] < b[i];
    return false;
}

void solve() {
    string sa, sb;  cin >> sa >> sb;
    BigInt a = bigint(sa);
    BigInt b = bigint(sb);
    Print(a + b);
    if(a < b) {
        printf("-");
        Print(b - a);
    } else {
        Print(a - b);
    }
    Print(a * b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    file("template");

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}
