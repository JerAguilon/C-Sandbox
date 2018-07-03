#include<string>
#include<iostream>
#include<regex>
#include<assert.h>

using namespace std;

int increment(const string& pattern, int pi) {
    int candidate = pi + 1;
    if (candidate + 1 < pattern.length() && pattern[candidate + 1] == '*') {
        candidate++;
    }
    return candidate;
}

bool matches(const string& text, const string& pattern, int ti, int pi) {
    char curr_p = text[pi];
    if (curr_p == '*') {
        return matches(text, pattern, ti, pi - 1); 
    }
    return pattern[pi] == '.' || text[ti] == pattern[pi];
}

bool helper(const string& text, const string& pattern, int ti, int pi) {
    /**
     * Special case: if curr char is *, then handle this separately
     */
    char p_curr = pattern[pi];
    if (p_curr == '*') {
        if (matches(text, pattern, ti, pi)) {
            return helper(text, pattern, ti + 1, increment(pattern, pi)) || helper(text, pattern, ti + 1, pi);
        } else {
            return helper(text, pattern, ti + 1, increment(pattern, pi));
        }
    }

    /**
     * Base case 1: if we've hit the end of the pattern, then check for one final
     * match
     *
     * Base case 2: if there isn't a match, then return false
     */
    if (pi == pattern.length() - 1) {
        return matches(text, pattern, ti, pi);
    }

    if (!matches(text, pattern, ti, pi)) {
        return false;
    }

    /**
     * Recurse case 1: Advance ti and pi
     */
    return helper(text, pattern, ti + 1, increment(pattern, pi));
}

bool regex_match(const string& text, const string& pattern) {
    return helper(text, pattern, 0, 0);
}

void test(const string& text, const string& pattern) {
    bool match1 = regex_match(text, pattern);
    cout << "[" << text << "] - [" << pattern << "]";
    cout << (match1 ? " matches." : " does not match.");

    smatch m;
    regex e(pattern);
    bool expected = regex_match(text, m, e);

    cout << "(" << match1 << ", " << expected << ")" << endl;

    assert(match1 == expected);


    cout << endl;
}
int main(int argc, char* argv[]) {
    test("abb", "abb");
    test("a", "ab*");
    test("aaabbbbbcccd", "a*bbb*.*d");
    test("a", "ab*");
    test("aaabbbbbcccd", "a*bbb*.*d");
    test("aaabbbbbcccde", "a*bbb*.*d");
    test("aaabbbbbcccde", "a*bbb*c*d");
    test("aaabbbbbcccde", "a*bbb*c*de");
    test("aabcd", "aa*d");
    test("", "aa*d");
    test("", "a*");
    test("abb", "ab*c");
    test("fabbbc", ".ab*c");
}
