#include <bits/stdc++.h>
using namespace std;

//-----------------------------[DEFINE]-----------------------------//
const int MOD = 1e9 + 7;
using ll = long long;

//-----------------------------[DEBUG]-----------------------------//

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
//-----------------------------[END-DEBUG]-----------------------------//


//-----------------------------[DECLARATION]-----------------------------//

int n, m, result;
int arr[105][105], tmp[105][105];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

//-----------------------------[FUNCTION]-----------------------------//

void solve(int x1, int y1){
    int cnt = 0;
    arr[x1][y1] = 0;

    for(int i = 0; i < 4; i++){
        int x2 = dx[i] + x1, y2 = dy[i] + y1;
        if(x2 >= 1 && y2 >= 1 && x2 <= n && y2 <= m && tmp[x2][y2] == 1)
            cnt++;
    }
    result += 4 - cnt;

    for(int i = 0; i < 4; i++){
        int x2 = dx[i] + x1, y2 = dy[i] + y1;
        if(x2 >= 1 && y2 >= 1 && x2 <= n && y2 <= m && arr[x2][y2] == 1)
            solve(x2, y2);
    }
}

//-----------------------------[END]-----------------------------//


int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            tmp[i][j] = arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j]){
                result = 0;
                solve(i, j);
                cout << result << " ";
            }
        }
    }
}