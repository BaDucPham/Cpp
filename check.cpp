#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ull unsigned long long
#define flr(t, i, a, b) for (t i = (a); i < (b); ++i)
#define frl(t, i, a, b) for (t i = (a); i >= (b); --i)
#define fa(x, a) for (auto x : a)
# define PT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//squence is x_0 =1,  x_(i+1) = (a*x_i + x_i//b) % c
//Floyd's Cycle-Finding Algorithm Steps:
//1. Initialize slow and fast pointers to the head of the linked list.
//2. Move the slow pointer by one and the fast pointer by two. If they meet at some point, then there is a loop.
//3. If they don’t meet and the fast pointer reaches the end, then there is no loop.

// Function to find first repeating mu et lambda
ll findRepeating(ll a, ll b, ll c){
    ll slow = 1, fast = 1;
    do{
        slow = (a*slow + slow/b) % c;
        fast = (a*fast + fast/b) % c;
        fast = (a*fast + fast/b) % c;
    }while(slow != fast);
    ll mu = 0;
    slow = 1;
    while(slow != fast){
        slow = (a*slow + slow/b) % c;
        fast = (a*fast + fast/b) % c;
        mu++;
    }
    ll lambda = 1;
    fast = (a*slow + slow/b) % c;
    while(slow != fast){
        fast = (a*fast + fast/b) % c;
        lambda++;
    }
    return mu + lambda;
}




// Driver code
int main(){
    PT;
    ll a, b, c; cin>>a>>b>>c;
    cout << findRepeating(a, b, c) << endl;
}