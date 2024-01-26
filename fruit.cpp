//思路：每次合并数目最小的两个果子堆，因此我们开优先队列(priority_queue)
//由于优先队列默认的比较规则为less，且数据类型简单，我们直接less-->greater即可
#include <bits/stdc++.h>
using namespace std;

// 由于数据有超出int数据范围的可能，开long long
using ll = long long;

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> arr;
    for (int i = 1; i <= n; ++i)
    {
        ll value; cin >> value;
        arr.push(value);
    }

    //从堆中取出两个最小的数值
    //注意：因为后续要继续使用，需要push()回队列
    //同时需要注意while()的循环条件
    ll ans = 0;
    while (arr.size() >= 2)
    {
        ll a = arr.top(); arr.pop();
        ll b = arr.top(); arr.pop();
        ans += a + b;
        arr.push(ans);
    }
    cout << ans << '\n';
    return 0;
}

//后续我们拓展一下priority_queue修改比较函数的两种方法(大根堆-->小根堆)
//方法一：仿函数-->实际上写了一个类，看起来像函数
//struct Compare{
//    bool operator () (int a, int b)     *重载括号运算符 *其中int数据类型是根据main()中队列类型设定的
//    {
//       return a > b;
//    }
//  };
//int main(void){
//priority_queue<int, vector<int>, Compare> pq;

//方法二：自己写一个比较函数
//*注意需要 decltype
//*同时注意要将写好的compare函数作为参数放进去  eg：pq(compare)
//auto compare = [](int a, int b){
//     return a > b;
//   };
//priority_queue<int, vector<int>, decltype(compare)> pq(compare);

//方法三: -->代码中所用方法
//如果优先队列中的元素类型比较简单，可以直接使用 greater<T>来修改比较方法
//priority_queue<int, vector<int>, greater<int>> pq;
//std::greater函数对象定义在<functional>头文件中。
