#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
using namespace std;
cin.tie(nullptr);
ios::sync_with_stdio(false);

unsigned N;
long A, B;
cin >> N >> A >> B;

vector<long> P(N);
for (auto&& p : P)
cin >> p;

// Sequence of good sequences
vector<vector<long>> seq;

// Sufficiently small value
static constexpr long min_sentinel{-800000000000000};

// Merge two good sequences to obtain an equivalent good sequence
const auto merge{[N, A, B](auto&& lhs, auto&& rhs) -> vector<long> {
    const long L(size(lhs)), R(size(rhs));
    vector<long> result;
    result.emplace_back(min_sentinel); // sentinel
    result.reserve(L + R + 1);

    for (long l{}, r{}; l < L || r < R; )
    // Fill the elements from the beginning
    result.emplace_back(l == L || (r < R && lhs[l] - r * B > rhs[r] - (L - l) * A) ?
    rhs[r++] - (L - l) * A :
    max(result.back() + A, lhs[l++] - r * B));

    result.erase(begin(result)); // Remove the sentinel
    return result;
    }};

// Append a new sequence
// If it has the same length as the last, take it out and merge it
const auto append_seq{[&seq, &merge](const auto& rec, vector<long>&& p) -> void {
if (empty(seq) || size(seq.back()) != size(p))
seq.emplace_back(move(p));
else {
auto lhs{move(seq.back())};
seq.pop_back();
rec(rec, merge(move(lhs), move(p)));
}
}};

for (const auto p : P)
append_seq(append_seq, vector{p});

unsigned Q;
cin >> Q;

for (unsigned i{}; i < Q; ++i) {
unsigned T;
long X;
cin >> T >> X;

if (T == 1)
append_seq(append_seq, vector{X});
else {
for (const auto& s : seq) // For each good sequence
// Do binary search to find mood delta
X += A * size(s) - (A + B) * *ranges::partition_point(views::iota(0UL, size(s)), [X, &s, B](const long i){
return X > s[i] + i * B;
});

cout << X << '\n';
}
}

cout << flush;
return 0;
}