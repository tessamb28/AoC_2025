#include <bits/stdc++.h>
using namespace std;

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<long long, long long>> ranges;
    string line;

    // leer RANGOS "L-R" hasta la línea en blanco
    while (getline(cin, line)) {
        if (line.empty()) break;  // hemos llegado a la separación
        long long L, R;
        char dash;
        stringstream ss(line);
        ss >> L >> dash >> R;     // formato "L-R"
        ranges.push_back({L, R});
    }

    // ordenar rangos por L (divide y vencerás / sort)
    sort(ranges.begin(), ranges.end());

    // fusionar rangos solapados en 'merged'
    vector<pair<long long, long long>> merged;
    for (auto [L, R] : ranges) {
        if (merged.empty() || L > merged.back().second) {
            // no solapa: nuevo intervalo
            merged.push_back({L, R});
        } else {
            // solapa con el último: extendemos el final
            merged.back().second = max(merged.back().second, R);
        }
    }

    // preparamos vector con los inicios para usar upper_bound en la parte 1
    vector<long long> starts;
    starts.reserve(merged.size());
    for (auto &p : merged) {
        starts.push_back(p.first);
    }

    // función lambda para comprobar si un ID x es fresco (está en algún intervalo)
    auto is_fresh = [&](long long x) -> bool {
        // upper_bound nos da el primer índice cuyo start > x
        int idx = (int)(upper_bound(starts.begin(), starts.end(), x) - starts.begin()) - 1;
        if (idx < 0) return false;  // x está antes de todos los intervalos
        auto [L, R] = merged[idx];
        return (L <= x && x <= R);
    };

    // leer IDs disponibles (segunda sección) y contar los frescos (parte 1)
    long long countFreshAvailable = 0;
    vector<long long> available;
    long long id;
    while (cin >> id) {
        available.push_back(id);
    }

    for (long long x : available) {
        if (is_fresh(x)) {
            countFreshAvailable++;
        }
    }

    // calcular número TOTAL de IDs frescos cubiertos por los rangos (parte 2)
    long long totalFreshInRanges = 0;
    for (auto [L, R] : merged) {
        totalFreshInRanges += (R - L + 1);
    }

    // imprimir resultados
    cout << countFreshAvailable << "\n";
    cout << totalFreshInRanges << "\n";

    return 0;
}
