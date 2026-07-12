#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};
#include <vector>
int vote_count(ElectionResult result) { return result.votes; }
void increment_vote_count(ElectionResult& result, int increment) { result.votes += increment; }
ElectionResult& determine_result(std::vector<ElectionResult>& results) {
  ElectionResult* winner = &results[0];
  for (ElectionResult& candidate : results) {
    if (winner->votes <= candidate.votes) winner = &candidate;
  }
  winner->name = "President " + winner->name;
  return *winner;
}
// TODO: Task 1
// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.

// TODO: Task 2
// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.

// TODO: Task 3
// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.

}  // namespace election
