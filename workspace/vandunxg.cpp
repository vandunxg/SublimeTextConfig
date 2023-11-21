#include <bits/stdc++.h>
using namespace std;

//
int MOD = 1e9 + 7;
using ll = long long;

#define show(args...) describe(#args,args);
template<typename T>
void describe(string var_name, T value) {
    clog << var_name << " = " << value << " " << endl;
}

template<typename T, typename... Args>
void describe(string var_names, T value, Args... args) {
    string::size_type pos = var_names.find(',');
    string name = var_names.substr(0, pos);
    var_names = var_names.substr(pos + 1);
    clog << name << " = " << value << " | ";
    describe(var_names, args...);
}
//



void findLeft(int arr[], int n, int left[]){
    stack <int> st;

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && arr[i] < arr[st.top()]){
            left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()){
        left[st.top()] = -1;
        st.pop();
    }

    // for(int i = 0; i < n; i++){
    //     cout << left[i] << " ";
    // }

}


void findRight(int arr[], int n, int right[]){
    stack <int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[i] < arr[st.top()]){
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()){
        right[st.top()] = n;
        st.pop();
    }

    // for(int i = 0; i < n; i++){
    //     cout << right[i] << " ";
    // }

}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(auto &x : arr){
        cin >> x;
    }

    int left[n], right[n];

    findLeft(arr, n, left);
    findRight(arr, n, right);

    ll maxVal = -1e9;

    for(int i = 0; i < n; i++){
        maxVal = max(maxVal, 1ll * arr[i] * (right[i] - left[i] - 1));
    }
    cout << maxVal;

}