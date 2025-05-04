class Solution {
public:

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    map<pair<int, int>, int> dominoCount;
    int equivalentPairs = 0;

    for (const auto& domino : dominoes) {
        int a = min(domino[0], domino[1]);
        int b = max(domino[0], domino[1]);
        pair<int, int> normalizedDomino = {a, b};

        if (dominoCount.find(normalizedDomino) != dominoCount.end()) {
            equivalentPairs += dominoCount[normalizedDomino];
            dominoCount[normalizedDomino]++;
        } else {
            dominoCount[normalizedDomino] = 1;
        }
    }

    return equivalentPairs;
}
};