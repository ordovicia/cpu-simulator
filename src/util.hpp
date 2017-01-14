#pragma once

#include <cstdint>
#include <cstring>
#include <ncurses.h>

extern bool g_ncurses;

#define FAIL(msg)                      \
    do {                               \
        if (g_ncurses)                 \
            endwin();                  \
        std::cerr << msg << std::endl; \
        std::exit(1);                  \
    } while (0)

/*
 * Extract bit string.
 * Index starts from left(0) to right(31/63).
 * bitset(10110111000..., 0, 8) = 0..010110111
 */
uint32_t bitset(uint32_t inst, int begin, int end);

/*
 * Sign extention.
 * signExt(01010, 5) -> 0..00001010
 * signExt(11010, 5) -> 1..11111010
 */
uint32_t signExt(uint32_t x, int bits);

/*
 * Compare string.
 * streq("hoge", "hoge") == true
 */
inline bool streq(const char* s1, const char* s2) { return strcmp(s1, s2) == 0; }

/*
 * Compare first n chars.
 * streqn("hoge", "hoge2", 4) == true
 * streqn("hoge1", "hoge2", 4) == true
 * streqn("hoge", "hog", 4) == false
 */
bool streqn(const char* s1, const char* s2, int n);

union FloatBit {
    float f;
    uint32_t b;
};

inline uint32_t ftob(float f)
{
    FloatBit fb{f};
    return fb.b;
}

inline float btof(uint32_t b)
{
    FloatBit fb;
    fb.b = b;
    return fb.f;
}
