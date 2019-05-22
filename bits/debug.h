#include <iostream>
using namespace std;

template < class T > struct rge { T b, e; };
template < class T > rge<T> range(T i, T j) { return rge<T> {i, j}; }
template < class T > char dud(...);
template < class T > auto dud(T* x) -> decltype(cout << *x, 0);

struct debug {
    template < class T >
    typename enable_if< sizeof(dud<T>(0)) != 1, debug& >::type operator<< (T i) {
        cout << i << flush;
        return *this;
    }

    template < class T >
    typename enable_if< sizeof(dud<T>(0)) == 1, debug& >::type operator<< (T i) {
        return *this << range(begin(i), end(i)) << "\n";
    }

    template < class T, class b > debug &operator<< (pair < b, T > d) {
        return *this << "(" << d.first << ", " << d.second << ")";
    }

    template <class T> debug &operator<< (rge<T> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it) {
            if (it != d.b) {
               *this << ", ";
            }
            *this << *it;
        }
        return *this << "]";
    }
};

// Leave these extra handy code here, in case of needed in future.
#define fore(i, a, b) for (int i = a; i < b; ++i)
#define prt(x, i, n) { cout << x[i] << (i == n - 1 ? "\n" : " "); }
#define par(x, s, n, v) if(v) cout << #x << ": "; fore(i, s, n) prt(x, i, n)
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }
// template <typename T> void output(T t) { cout << t << "\n"; }
// template <typename T, typename U, typename... Args>
// void output(T t, U u, Args... args) { cout << t << " "; output(u, args...); }

#ifdef _has_trace
    #define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
    template <typename T>
    void _f(const char* name, T&& arg) {
        debug() << name << ": " << arg << '\n';
    }
    template <typename T, typename... Args>
    void _f(const char* names, T&& arg, Args&&... args) {
        const char* split = strchr(names + 1, ',');
        string name = string(names).substr(0, split - names);
        debug() << name << ": " << arg << " |";
        _f(split, args...);
    }
    #define dbstream debug
#endif
