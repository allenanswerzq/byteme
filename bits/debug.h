#include <iostream>
using namespace std;

#define EXIT "\033[0m"
#define CYAN "\033[0;36m"

template <class T> struct rge { T b, e; };
template <class T> rge<T> range(T i, T j) { return rge<T> {i, j}; }
template <class T> char dud(...);
template <class T> auto dud(T* x) -> decltype(cout << *x, 0);

struct debug {
  template<class T, class N>
  typename enable_if<std::is_pointer<T>::value, debug&>::type
    operator<< (std::tuple<T, N>& array) {
  // Real place where printing out an array.
    auto mat = std::get<0>(array);
    int n = std::get<1>(array);
    debug() << "[";
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        debug() << ", ";
      }
      debug() << mat[i];
    }
    debug() << "]";
    return *this;
  }

  template<class T, class H, class W>
  typename enable_if<std::is_pointer<T>::value, debug&>::type
    operator<< (std::tuple<T, H, W>& array) {
  // Real place where printing out a two dimension array.
    auto mat = std::get<0>(array);
    int h = std::get<1>(array);
    int w = std::get<2>(array);
    debug() << "[";
    for (int i = 0; i < h; i++) {
      auto mati = make_tuple(mat[i], w);
      debug() << mati << '\n';
    }
    debug() << "]";
    return *this;
  }

  template<class T>
  debug& operator<< (vector<vector<T>>& v) {
    if (v.empty()) {
      return *this;
    }
    int n = v.size();
    debug() << "\n[";
    for (int i = 0; i < n; i++) {
      debug() << v[i];
      if (i < n - 1) {
        debug() << ",\n";
      }
    }
    debug() << "]";
    return *this;
  }

  template <class T>
  typename enable_if<sizeof(dud<T>(0)) != 1, debug&>::type operator<< (T i) {
    if (is_floating_point<T>::value) {
      cerr << setprecision(20) << fixed << i << flush;
    }
    else {
      cerr << i << flush;
    }
    return *this;
  }

  template <class T>
  typename enable_if<sizeof(dud<T>(0)) == 1, debug&>::type operator<< (T i) {
    return *this << range(begin(i), end(i));
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

#ifdef LOCAL
  template <typename T>
  void __print(const string& names, T arg) {
    string name = names;
    if ((int) name.find("make_tuple") != -1) {
      int s = name.find('(');
      int t = name.find(',');
      assert(t - s - 1 > 0);
      name = name.substr(s + 1, t - s - 1);
    }
    debug() << name << ": " << arg << "\n";
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
    if ((int) name.find("make_tuple") != -1) {
    // Hacking to print out an array.
    // eg. trace(make_tuple(arr, w))
    // eg. trace(make_tuple(arr, h, w))
      int s = name.find('(');
      int t = name.find(',');
      assert(t - s - 1 > 0);
      name = name.substr(s + 1, t - s - 1);
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
    while (p + 1 < n && names[p + 1] == ' ') {
    // Stripping white spaces.
      p++;
    }
    assert(p + 1 <= n);
    string others = names.substr(p + 1);
    __print(others, args...);
  }

  #define trace(...) __trace(__LINE__, __func__, #__VA_ARGS__, __VA_ARGS__)

  template <typename T, typename... Args>
  void __trace(int ln, const string& fn, const string& var_names, T arg, Args... args) {
    debug() << CYAN << "{" << fn << ":" << ln << "} " << EXIT;
    __print(var_names, arg, args...);
  }
#endif


// template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
// template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }

// mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
