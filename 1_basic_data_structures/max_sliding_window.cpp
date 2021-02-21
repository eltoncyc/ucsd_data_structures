#include <iostream>
#include <vector>
#include <deque>
using namespace std;

using std::cin;
using std::cout;
using std::vector;
using std::max;

void max_sliding_window_naive(vector<int> const & A, int w) {
    /*for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }*/

    deque<int> deq;
    for (int i = 0; i < A.size(); i++)
    {
        if (!deq.empty() && i - deq.front() == w)
        {
            deq.pop_front();
        }
        while (!deq.empty() && A[i] > A[deq.back()])
        {
            deq.pop_back();
        }
        deq.emplace_back(i);

        if (i - w + 1 >= 0)
        {
            cout << A[deq.front()] << " ";
        }

    }
    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
