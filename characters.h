constexpr int A = 1;
constexpr int B = 2;
constexpr int C = 4;
constexpr int D = 8;
constexpr int E = 16;
constexpr int F = 32;
constexpr int G = 64;
constexpr int DP = 128;
constexpr int NONE = A + B + C + D + E + F + G + DP;
constexpr int ALL = 0;

constexpr int letterA = NONE - A - B - C - E     - F - G;
constexpr int letterA = ALL                  + D         + DP;


