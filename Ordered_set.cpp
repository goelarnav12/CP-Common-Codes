#include <ext/pb_ds/assoc_container.hpp> // required
#include <ext/pb_ds/tree_policy.hpp> // required
#include<bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds; // required

template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Useful for finding number of elements less than x 
// For multisets use pair<int,int> 

// *(s.find_by_order(x)) value of element at xth index starting from 0
// s.order_of_key(x) number of elements strictly less than x
