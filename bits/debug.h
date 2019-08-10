#include <iostream>
using namespace std;

template <class T> struct rge { T b, e; };
template <class T> rge<T> range(T i, T j) { return rge<T> {i, j}; }
template <class T> char dud(...);
template <class T> auto dud(T* x) -> decltype(cout << *x, 0);

struct debug {
	template<class T>
	typename enable_if<std::is_pointer<T>::value, debug&>::type
		operator<< (std::pair<T, int>& array) {
	// Real place where print out an array.
		cerr << "[";
		for (int i = 0; i < array.second; i++) {
			if (i > 0) {
				cerr << ", ";
			}
			cerr << array.first[i];
		}
		cerr << "]\n";
    return *this;
	}

	template <class T>
	typename enable_if<sizeof(dud<T>(0)) != 1, debug&>::type operator<< (T i) {
		cerr << i << flush;
		return *this;
	}

	template <class T>
	typename enable_if<sizeof(dud<T>(0)) == 1, debug&>::type operator<< (T i) {
		return *this << range(begin(i), end(i)) << "\n";
	}

	template <class T, class b>
	debug &operator<< (pair<b, T> d) {
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
// mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#ifdef LOCAL
	#define dbstream debug
	#define trace(...) __print(#__VA_ARGS__, __VA_ARGS__)

	bool __flag;
	bool __pre;
	template <typename T>
	void __print(const string& names, T arg) {
		string name = names;
		if ((int) name.find("make_pair") != -1) {
			int s = name.find('(');
			int t = name.find(',');
			assert(t - s - 1 > 0);
			name = name.substr(s + 1, t - s - 1);
		}
		int var = sizeof(dud<T>(0));
		__flag = (var == 1);
		if (!__pre && __flag) {
			debug() << "\n";
		}
		debug() << name << ": " << arg << "\n";
		if (__pre && !__flag) {
			debug() << "\n";
		}
	}

	template <typename T, typename... Args>
	void __print(const string& names, T arg, Args... args) {
		int p = -1;
		int n = names.size();
		int x = (int) names.find('(');
		int y = (int) names.find(',');
		if (x != -1 && y != -1 && x < y) {
		// Looking for `()` pair first
		// handle calls like `trace(foo(a, b))`
			p = names.find(')');
			assert(0 <= p && p < n);
			p = names.find(',', p + 1);
		}
		else {
		// Now looking for comma sign to split varibles.
			p = names.find(',');
		}
		assert(p != -1);
		string name = names.substr(0, p);
		if ((int) name.find("make_pair") != -1) {
		// Hacking to print out an array.
		// eg. trace(make_pair(arr, size))
			int s = name.find('(');
			int t = name.find(',');
			assert(t - s - 1 > 0);
			name = name.substr(s + 1, t - s - 1);
		}
		int var = sizeof(dud<T>(0));
		__flag = (var == 1);
		if (!__pre && __flag) {
			debug() << "\n";
		}
		if (is_same<T, const char*>::value) {
		// Add distinguish string at the beginning.
		// So that we can add comments for trace call
		// eg. trace("TEST", var1, var2);
			int w = name.size();
			debug() << name.substr(1, w - 2) << ": | ";
		}
		else {
			debug() << name << ": " << arg << " | ";
		}
		__pre = __flag;
		while (p + 1 < n && names[p + 1] == ' ') {
		// Stripping white spaces.
			p++;
		}
		assert(p + 1 <= n);
		string others = names.substr(p + 1);
		__print(others, args...);
	}
#endif
