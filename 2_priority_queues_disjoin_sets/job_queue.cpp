#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <functional>
#include <utility>

using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;
using std::pair;
using std::make_pair;

#define ll long long

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());

    auto comp = [](const pair<int, ll> left, const pair<int, ll>right) {
        if (left.second == right.second) {
            return (left.first > right.first);
        }
        else {
            return (left.second > right.second);
        }
    };

    priority_queue<pair<int, ll>, vector <pair<int, ll>>, decltype(comp)>worker_finish_time(comp);

    for (int i = 0; i < jobs_.size(); ++i) {
        int dur = jobs_[i];
        int next_worker = 0;

        pair<int, ll> min_worker_pair;
        if (worker_finish_time.size() < num_workers_) {
            min_worker_pair = make_pair(i, 0);
        }
        else {
            min_worker_pair = worker_finish_time.top();
            worker_finish_time.pop();
        }
        next_worker = min_worker_pair.first;
        assigned_workers_[i] = next_worker;
        start_times_[i] = min_worker_pair.second;
        worker_finish_time.push(make_pair(next_worker, (min_worker_pair.second + dur)));
    }



  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
