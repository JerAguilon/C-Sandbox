#include<string>
#include<iostream>
#include<regex>
#include<assert.h>
#include<algorithm>

using namespace std;

int increment_pattern(const string& pattern, int pi) {
    int candidate = pi + 1;
    if (pattern[candidate + 1] == '*') {
        candidate++;
    }
    return candidate;
}

bool matches(const string& text, const string& pattern, int ti, int pi) {
    char curr_p = pattern[pi];
    if (curr_p == '*') {
        // matches empty string and previous char
        return (ti == static_cast<int>(text.length())) || matches(text, pattern, ti, pi - 1);
    }
    return pattern[pi] == '.' || text[ti] == pattern[pi];
}

bool helper(const string& text, const string& pattern, int ti, int pi) {
    char p_curr = pattern[pi];
    char t_curr = text[ti];

    if (pi == pattern.length() && ti == text.length()) {
        return true;
    }
    if (!matches(text, pattern, ti, pi) || ti > text.length()) {
        return false;
    }


    /**
     * Special case: if curr char is *, then handle this separately. Note that
     * we already know that the * selector matches from above.
     * 
     * We can do three things here:
     * 1. Advance ti and continue checking for the * selector
     * 2. Advance pi and attempt to match the next character
     * 3. Advance pi and ti and attempt to matc the next character
     * 
     */
    if (p_curr == '*') {
            return helper(text, pattern, ti, increment_pattern(pattern, pi)) 
                || helper(text, pattern, ti + 1, increment_pattern(pattern, pi))
                || helper(text, pattern, ti + 1, pi);
    }

    /**
     * Recurse case 1: Advance ti and pi
     */
    return helper(text, pattern, ti + 1, increment_pattern(pattern, pi));
}

bool regex_match(const string& text, const string& pattern) {
    return helper(text, pattern, 0, increment_pattern(pattern, -1));
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
    test("aaabbbbb", "a*");
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
