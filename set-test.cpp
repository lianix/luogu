#include <iostream>
#include <set>

using namespace std;

int main(int argc, char* argv[])
{
    set<int> st;

    // �������в���Ԫ��
    st.insert(4);
    st.insert(5);
    st.insert(6);
    // ����λ�ò���һ��Ԫ��
    set<int>::iterator it = st.begin();
    st.insert(it, 7);

    // ������ʾ
    for (it = st.begin(); it != st.end(); it++)
        cout << *it << " "; // �����2 4
    cout << endl;

    return 0;
}
