/*
 * N回、素数判定, 素因数分解, 約数列挙 を行う
 *
 * 入力:
 * N, M
 * A_1, A_2, ..., A_N
 *
 * 制約:
 * 1 <= N <= 1e8
 * 1 <= A_i <= M <= N
 *
 * 出力:
 * [素数なら1, 素数でないなら0] [素因数分解した結果]
 * [約数の数] [約数列挙した結果]
 */

#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

int is_prime(int x) {
    if (x == 2) return true;
    if (x < 2 || x % 2 == 0) return false;
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i) continue;
        return false;
    }
    return true;
}

std::vector<int> factrize(int x) {
    std::vector<int> ret;
    if (x < 2) return ret;
    while (x % 2 == 0) {
        ret.emplace_back(2);
        x /= 2;
    }
    for (long long i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            ret.emplace_back(i);
            x /= i;
        }
    }
    if (x != 1) ret.emplace_back(x);
    return ret;
}

std::vector<int> divisors(int x) {
    std::vector<int> ret;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i) continue;
        ret.emplace_back(i);
        if (i * i != x) ret.emplace_back(x / i);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

std::vector<int> randome_values(int seed, int count, int min, int max) {
    std::mt19937_64 mt64(seed);
    std::uniform_int_distribution<int> rand(min, max);
    std::vector<int> ret;
    for (int i = 0; i < count; ++i) {
        ret.emplace_back(rand(mt64));
    }
    return ret;
}

std::ofstream create_filestream(std::filesystem::path filepath) {
    std::filesystem::create_directories(filepath.parent_path());
    std::ofstream file(filepath);
    if (!file) {
        std::cerr << "Failed to open file: " << filepath << std::endl;
        exit(1);
    }
    return file;
}

void write_anser(int a, std::ofstream &file) {
    file << is_prime(a) << ' ';
    auto factors = factrize(a);
    for (auto factor : factors) {
        file << factor << ' ';
    }
    file << '\n';

    auto divs = divisors(a);
    file << divs.size() << ' ';
    for (auto div : divs) {
        file << div << ' ';
    }
    file << '\n';
}

void case_small_all(std::filesystem::path basedir) {
    auto input_file = create_filestream(basedir / "in" / "small_all.txt");
    const auto N_M = 100000;
    input_file << N_M << ' ' << N_M << '\n';
    for (int i = 1; i <= N_M; ++i) {
        input_file << i << ' ';
    }
    input_file << std::flush;
    input_file.close();

    auto output_file = create_filestream(basedir / "out" / "small_all.txt");
    for (int i = 1; i <= N_M; ++i) {
        write_anser(i, output_file);
    }
    output_file << std::flush;
    output_file.close();
}

void case_large_random(std::filesystem::path basedir) {
    for (int number = 0; number < 10; ++number) {
        const auto N = 500;
        const auto MAX_M = 100000000;
        auto values = randome_values(number, N, MAX_M / 1000, MAX_M);

        auto input_file = create_filestream(basedir / "in" / ("large_random" + std::to_string(number) + ".txt"));
        input_file << N << ' ' << MAX_M << '\n';
        for (auto value : values) {
            input_file << value << ' ';
        }
        input_file << std::flush;
        input_file.close();

        auto output_file = create_filestream(basedir / "out" / ("large_random" + std::to_string(number) + ".txt"));
        for (auto value : values) {
            write_anser(value, output_file);
        }
        output_file << std::flush;
        output_file.close();
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "You must spesify 1 argument (cases directory)" << std::endl;
        return 1;
    }

    std::filesystem::path basedir = argv[1];
    if (std::filesystem::exists(basedir)) {
        std::filesystem::remove_all(basedir);
    }
    std::filesystem::create_directories(basedir);

    case_small_all(basedir);
    case_large_random(basedir);
    return 0;
}
