#include <iostream>
#include "bits/stdc++.h"
using namespace std;
typedef long long int LL;
int max_continus_fields_with_value_limit(const vector<vector<int>> &grid, vector<vector<int>> &visited, int iteration, int max_val, tuple<int, int> pos)
{
    static const auto directions = array<tuple<int, int>, 4>{
        tuple<int, int>{1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    const auto num_rows = grid.size();
    const auto num_columns = grid.at(0).size();
    auto [row, col] = pos;
    visited[row][col] = iteration;

    auto covered = 1;
    for (auto &direction : directions) {
        auto [dr, dc] = direction;
        auto child = make_pair(row + dr, col + dc);
        auto [child_row, child_col] = child;

        auto range_ok = (0 <= child_row && child_row < num_rows) && (0 <= child_col && child_col < num_columns);
        if (!range_ok ||
                (visited[child_row][child_col] == iteration) ||
                (grid[child_row][child_col] > max_val)) {
            continue;
        }
        covered += max_continus_fields_with_value_limit(
            grid, visited, iteration, max_val, child);
    }
    return covered;
}

bool k_continus_fields_with_max_value(
    const vector<vector<int>> &grid, vector<vector<int>> &visited,
    int iteration, int max_val, int k)
{
    const auto num_rows = visited.size();
    const auto num_columns = visited.at(0).size();

    for (auto row = 0; row < num_rows; row++) {
        for (auto col = 0; col < num_columns; col++) {
            if ((visited[row][col] == iteration) || (grid[row][col] > max_val))
                continue;
            auto pos = make_pair(row, col);
            auto max_continus = max_continus_fields_with_value_limit(
                grid, visited, iteration, max_val, pos);
            if (max_continus >= k) {
                return true;
            }
        }
    }
    return false;
}

void najmlodszedrzewo(vector<vector<int>> &grid, int k) {
    LL nwier=grid.size();
    LL nkol=grid.size();

    vector<vector<int>> odwiedzone(nwier, vector<int>(nkol, 0));
    vector<int> wynik;


    for (auto &row : grid) {
        copy(row.begin(), row.end(), inserter(wynik, wynik.end()));
    }
    sort(wynik.begin(), wynik.end());
    wynik.erase(unique(wynik.begin(), wynik.end()), wynik.end());

    LL i=0;
    LL start=size_t(0);
    LL koniec=wynik.size();
    LL len=wynik.size();
    while (len > 0) {
        i++;
        LL srodek = start + len / 2;
        LL can_cover_k_fields = k_continus_fields_with_max_value(grid, odwiedzone, i, wynik[srodek], k);
        if (can_cover_k_fields)
        {
            koniec = srodek;
        }
        else
        {
            start=srodek+1;
        }
        len=koniec-start;
    }
    cout<<wynik[start];
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    int a,k;
    cin>>a>>k;
    vector< vector<int> >  tab1(a, vector<int>(a));
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<a;j++)
        {
        cin>>tab1[i][j];
        }
    }
    najmlodszedrzewo(tab1,k);

    return 0;
}
