#include <bits/stdc++.h> // incluye casi todo lo necesario
using namespace std; // evita escribir std::

struct Hasher { // para hashing de cadenas
    const long long B = 131; // base del hash
    const long long MOD = 1e9+7; // módulo del hash
    vector<long long> H, P;  // hashes y potencias

    Hasher(const string &s) { // constructor
        int n = s.size(); // longitud de la cadena
        H.resize(n+1); // hashes
        P.resize(n+1); // potencias
        H[0] = 0; // hash vacío
        P[0] = 1; // B^0 = 1
        for (int i = 0; i < n; i++) { // calcular hashes y potencias
            H[i+1] = (H[i] * B + s[i]) % MOD; // hash prefijo
            P[i+1] = (P[i] * B) % MOD; // B^(i+1)
        }
    }
    long long get(int l, int r) { // obtener hash de s[l..r-1]
        long long res = (H[r] - H[l] * P[r-l] % MOD + MOD) % MOD; // fórmula
        return res; // devolver hash
    }
};

// parte 1: debe ser exactamente 2 repeticiones
bool isTwoRepeat(const string &s) { // verificar si s es de la forma XX
    int n = s.size(); // longitud de la cadena
    if (n % 2 != 0) return false; // debe ser par
    int len = n/2; // longitud de cada mitad
    Hasher h(s); // crear hasher
    return h.get(0, len) == h.get(len, n); // comparar hashes
}

// parte 2: debe ser >= 2 repeticiones
bool isMultiRepeat(const string &s) {
    int n = s.size(); // longitud de la cadena
    Hasher h(s); // crear hasher
    for (int len = 1; len <= n/2; len++) { // probar longitudes
        if (n % len != 0) continue; // debe dividir n
        bool ok = true; // suponer que es válido
        long long block = h.get(0, len); // hash del bloque inicial
        for (int i = 1; i < n/len; i++) { // verificar bloques
            if (h.get(i*len, (i+1)*len) != block) { // comparar hashes
                ok = false; // no coincide
                break; // salir del bucle
            }
        }
        if (ok) return true; // si es válido, devolver true
    }
    return false; // no se encontró ninguna repetición válida
}

int main() { // punto de entrada del programa
    ios::sync_with_stdio(false); // optimiza cin/cout
    cin.tie(nullptr); // desliga cin de cout
    
    string line; // línea de entrada
    getline(cin, line); // leer línea completa

    stringstream ss(line); // crear stream de cadenas
    string part; // parte individual de la línea
    long long sum1 = 0, sum2 = 0; // sumas para partes 1 y 2

    while (getline(ss, part, ',')) { // separar por comas
        if (part.empty()) continue; // ignorar partes vacías

        long long L, R; // límites del rango
        sscanf(part.c_str(), "%lld-%lld", &L, &R); // leer límites

        for (long long x = L; x <= R; x++) { // iterar en el rango
            string s = to_string(x); // convertir a cadena

            if (isTwoRepeat(s)) sum1 += x; // parte 1
            if (isMultiRepeat(s)) sum2 += x; // parte 2
        }
    }

    cout << "Parte 1: " << sum1 << "\n";
    cout << "Parte 2: " << sum2 << "\n";

    return 0;
}
