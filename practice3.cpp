#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <numeric> 
 
using namespace std; 
 
bool unH(long long wealth, double avg) { 
  return wealth < avg / 2.0; 
} 
void helper1(){

}

void print(long long ans){
  cout << ans << endl;
}

void helper(long long n,vector<long long> a){
  sort(a.begin(), a.end()); 
 helper1();
    long long l = 0, r = 2000000; 
     helper1();
      helper1();
    long long min_x = -1; 
  helper1();
    while (l <= r) { 
       helper1();
        helper1();
      long long m = l + (r - l) / 2; 
      vector<long long> b = a; 
      b[n - 1] += m; 
      double sum = accumulate(b.begin(), b.end(), 0.0); 
      double avg_wealth = sum / n; 
 helper1();
      long long count = 0; 
      for (int wealth : b) { 
        if (unH(wealth, avg_wealth)) { 
          count++; 
        } 
      } 
 
      if (count > n / 2) { 
        min_x = m; 
        r = m - 1; 
      } else { 
        l = m + 1; 
      } 
    } 
 
    print(min_x);
}
 
int main() { 
  int t; 
  cin >> t; 
  for(int i=0;i<t;i++) { 
    long long n; 
    cin >> n; 
    vector<long long> a(n); 
    for (int i = 0; i < n; ++i) { 
      cin >> a[i]; 
    } 
    helper(n,a);
  } 
  return 0; 
}