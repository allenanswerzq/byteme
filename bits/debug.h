#include <iostream>
using namespace std;

template < class T > struct rge { T b, e; };
template < class T > rge<T> range(T i, T j) { return rge<T> {i, j}; }
template < class T > char dud(...);
template < class T > auto dud(T* x) -> decltype(cout << *x, 0);

struct debug {
	template < class T >
	typename enable_if< sizeof(dud<T>(0)) != 1, debug& >::type operator<< (T i) {
		cerr << i << flush;
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

// template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
// template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }

// template <class T> void output(T t) { cout << t << "\n"; }
// template <class T, class U, class... Args>
// void output(T t, U u, Args... args) { cout << t << " "; output(u, args...); }

// mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#ifdef _has_trace
	#define dbstream debug
	#define trace(...) print(#__VA_ARGS__, __VA_ARGS__)
	template <class T>
	void print(const char* name, T&& arg) {
		debug() << name << ": " << arg << "\n";
	}
	template <class T, class... Args>
	void print(const char* names, T&& arg, Args&&... args) {
		const char* comma = strchr(names, ',');
		int len = comma - names;
		string name = string(names).substr(0, len);
		debug() << name << ": " << arg << " | ";
		print(comma + 2, args...);
	}
#endif
