#include <iostream>
#include <set>

using namespace std;

int main(int argc, char* argv[])
{
    set<int> st;

    // 在容器中插入元素
    st.insert(4);
    st.insert(5);
    st.insert(6);
    // 任意位置插入一个元素
    set<int>::iterator it = st.begin();
    st.insert(it, 7);

    // 遍历显示
    for (it = st.begin(); it != st.end(); it++)
        cout << *it << " "; // 输出：2 4
    cout << endl;

    return 0;
}
