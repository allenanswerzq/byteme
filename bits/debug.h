#ifndef BYTEME_DEBUG_H_
#define BYTEME_DEBUG_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define EXIT "\033[0m"
#define CYAN "\033[0;36m"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

template <class T>
struct rge {
  T b, e;
};
template <class T>
rge<T> range(T i, T j) {
  return rge<T>{i, j};
}
template <class T>
char dud(...);
template <class T>
auto dud(T *x) -> decltype(cout << *x, 0);

template <typename T>
struct is_vector : public std::false_type {};
template <typename T, typename A>
struct is_vector<std::vector<T, A>> : public std::true_type {};

template <class T>
static void __display_mat(vector<vector<T>> &v) {
  int n = v.size();
  int width = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int)v[i].size(); j++) {
      string str = to_string(v[i][j]);
      width = max(width, (int)str.size());
    }
  }
  cerr << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int)v[i].size(); j++) {
      if (j > 0) {
        cerr << ", ";
      }
      cerr << setw(width) << v[i][j];
    }
    cerr << "\n" << flush;
  }
}

template <class T>
static void __display_mat(vector<T> &v) {
  int n = (int) v.size();
  int width = 0;
  for (int j = 0; j < n; j++) {
    string str = to_string(v[j]);
    width = max(width, (int)str.size());
  }
  for (int j = 0; j < n; j++) {
    if (j > 0) {
      cerr << " ";
    }
    cerr << setw(width) << v[j];
  }
  cerr << flush;
}

struct debug {
  template <class T, class N>
  typename enable_if<std::is_pointer<T>::value, debug &>::type operator<<(
      std::tuple<T, N> &array) {
    // Real place where printing out an array.
    auto mat = std::get<0>(array);
    int n = std::get<1>(array);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = mat[i];
    }
    debug() << ans;
    return *this;
  }

  template <class T, class N>
  typename enable_if<is_vector<T>::value, debug &>::type operator<<(
      std::tuple<T, N> &array) {
    // Real place where printing out a vector with custom size N.
    auto mat = std::get<0>(array);
    int n = std::get<1>(array);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = mat[i];
    }
    debug() << ans;
    return *this;
  }


  template <class T, class H, class W>
  typename enable_if<std::is_pointer<T>::value, debug &>::type operator<<(
      std::tuple<T, H, W> &array) {
    // Real place where printing out a two dimension array.
    auto mat = std::get<0>(array);
    int h = std::get<1>(array);
    int w = std::get<2>(array);
    debug() << "[";
    vector<vector<int>> v(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        v[i][j] = mat[i][j];
      }
    }
    __display_mat<int>(v);
    debug() << "]";
    return *this;
  }

  template <class T, class C, class Comp>
  debug &operator<<(priority_queue<T, C, Comp> &v) {
    if (v.empty()) {
      return *this;
    }
    priority_queue<T, C, Comp> tmp = v;
    int n = tmp.size();
    debug() << "[";
    int k = 0;
    while (!tmp.empty()) {
      debug() << tmp.top();
      tmp.pop();
      if (k++ != n - 1) {
        debug() << ' ';
      }
    }
    debug() << "]";
    return *this;
  }

  template <class T>
  typename enable_if<std::is_arithmetic<T>::value, debug &>::type &operator<<(vector<vector<T>> &v) {
    if (v.empty()) {
      return *this;
    }
    debug() << "[";
    __display_mat<T>(v);
    debug() << "]";
    return *this;
  }

  template <class T>
  typename enable_if<!std::is_arithmetic<T>::value, debug &>::type &operator<<(vector<vector<T>> &v) {
    if (v.empty()) {
      return *this;
    }
    debug() << "[\n";
    for (int i = 0; i < (int) v.size(); i++) {
      debug() << v[i] << "\n";
    }
    debug() << "]";
    return *this;
  }

  template <class T>
   typename enable_if<std::is_arithmetic<T>::value, debug &>::type operator<<(vector<T> &v) {
    if (v.empty()) {
      return *this;
    }
    debug() << "[";
    __display_mat<T>(v);
    debug() << "]";
    return *this;
  }

  template <class T>
  typename enable_if<sizeof(dud<T>(0)) != 1, debug &>::type operator<<(T i) {
    if (is_floating_point<T>::value) {
      cerr << setprecision(10) << fixed << i << flush;
    } else if (is_integral<T>::value) {
      const int setw_size = 4;
      cerr << setw(setw_size) << i << flush;
    } else {
      cerr << i << flush;
    }
    return *this;
  }

  template <class T>
  typename enable_if<sizeof(dud<T>(0)) == 1, debug &>::type operator<<(T i) {
    return *this << range(begin(i), end(i));
  }

  template <class T, class b>
  debug &operator<<(pair<b, T> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }

  template <class T, class b>
  debug &operator<<(vector<pair<b, T>> v) {
    int n = v.size();
    *this << "[";
    int width = 0;
    for (int i = 0; i < n; i++) {
      string s = to_string(v[i].first);
      width = max(width, (int) s.size());
      string t = to_string(v[i].second);
      width = max(width, (int) t.size());
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cerr << ", ";
      }
      cerr << "(" << setw(width) << v[i].first << ", "
                  << setw(width) << v[i].second << ")";
    }
    cerr << "]" << flush;
    return *this;
  }

  template <class T>
  debug &operator<<(rge<T> d) {
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

template <typename T>
void __print(const string &names, T arg) {
  string name(names);
  if ((int)name.find("make_tuple") != -1 || (int)name.find("mt") != -1) {
    int s = (int) name.find('(');
    int t = (int) name.find(',');
    assert(t - s - 1 > 0);
    name = name.substr(s + 1, t - s - 1);
  }
  // TODO(): figure out why this messed up debug stream?
  // if (is_same<T, const char*>::value) {
  //   debug() << arg << "\n";
  // }
  // else {
  // debug() << typeid(T).name() << "\n";;
  debug() << name << ": " << arg << "\n";
  // }
}

template <typename T, typename... Args>
void __print(const string &namexx, T arg, Args... args) {
  int p = -1;
  string names(namexx);
  int n = (int)names.size();
  int x = (int)names.find('(');
  int y = (int)names.find(',');
  if (x != -1 && y != -1 && x < y) {
    // Looking for `()` pair first
    // handle calls like `trace(foo(a, b))`
    p = (int) names.find(')');
    assert(0 <= p && p < n);
    p = (int) names.find(',', p + 1);
  } else {
    // Now looking for comma sign to split varibles.
    p = (int) names.find(',');
  }
  assert(p != -1);
  string name = names.substr(0, p);
  if ((int)name.find("make_tuple") != -1 || (int)name.find("mt") != -1) {
    // Hacking to print out an array.
    // eg. trace(make_tuple(arr, w))
    // eg. trace(make_tuple(arr, h, w))
    int s = (int) name.find('(');
    int t = (int) name.find(',');
    assert(t - s - 1 > 0);
    name = name.substr(s + 1, t - s - 1);
  }
  if (is_same<T, const char *>::value) {
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

#if (defined(LOCAL))

#define trace(...) __trace(__LINE__, __func__, #__VA_ARGS__, __VA_ARGS__)

template <typename T, typename... Args>
void __trace(int ln, const string &fn, const string &var, T &&arg,
             Args &&... args) {
  cerr << CYAN << "{" << fn << ":" << setw(3) << ln << "} " << EXIT;
  __print(var, arg, args...);
}

#define dbg(...) __dbg(__LINE__, __func__, #__VA_ARGS__, (__VA_ARGS__))

template <typename T>
T &&__dbg(int ln, const string &fn, const string &expr, T &&val) {
  debug() << CYAN << "{" << fn << ":" << setw(3) << ln << "} " << EXIT << expr << " = "
          << val << '\n';
  return std::forward<T>(val);
}

#define debugstream debug

template <class T>
void puts(T t) {
  cout << t << "\n";
}
template <class T, class U, class... G>
void puts(T t, U u, G... g) {
  cout << t << " ";
  puts(u, g...);
}

#define assertm(exp, msg) assert(((void)msg, exp))
#define mt make_tuple

#else

template <typename T>
T &&identity(T &&t) {
  return std::forward<T>(t);
}

#define trace(...)
#define dbg(...) identity(__VA_ARGS__)

#endif

// https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Pragmas.html
// #pragma GCC diagnostic ignored "-Wsign-conversion"
// #pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wcast-qual"
#pragma GCC diagnostic ignored "-Wunused-parameter"

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>

enum class GraphDrawType {
  Directed,
  Undirected,
};

class Graphviz {
 public:
  Graphviz() : Graphviz(GraphDrawType::Undirected, "g") {}

  explicit Graphviz(GraphDrawType type) : Graphviz(type, "g") {}

  Graphviz(GraphDrawType type, const string &name)
      : gvc_(nullptr), gv_(nullptr), type_(type), name_(name) {
    CreateContext();
  }

  ~Graphviz() { Clear(); }

  void gvSetDirected() {
    type_ = GraphDrawType::Directed;
    Clear();
    CreateContext();
  }

  void gvAddEdge(int a, int b) {
    gvAddEdge(to_string(a), to_string(b), "");
  }

  void gvAddEdge(int a, int b, int c) {
    gvAddEdge(to_string(a), to_string(b), to_string(c));
  }

  void gvAddEdge(const string &u, const string &v, const string &label) {
    assert(++edge_cnt_ < 100);
    Agnode_t *n = agnode(gv_, (char *)u.c_str(), 1);
    Agnode_t *m = agnode(gv_, (char *)v.c_str(), 1);
    Agedge_t *e = agedge(gv_, n, m, 0, 1);
    agsafeset(e, const_cast<char *>("label"), (char *)label.c_str(),
              const_cast<char *>(""));
  }

  void gvDrawGraph() {
    // Set layout engine.
    gvLayout(gvc_, gv_, "dot");
    name_ += ".pdf";
    gvRenderFilename(gvc_, gv_, "pdf", name_.c_str());

    gvFreeLayout(gvc_, gv_);
  }

 private:
  void Clear() {
    agclose(gv_);
    gvFreeContext(gvc_);
  }

  // Set up a graphviz context.
  void CreateContext() {
    gvc_ = gvContext();
    if (type_ == GraphDrawType::Undirected) {
      gv_ = agopen(const_cast<char *>("g"), Agundirected, 0);
    } else {
      gv_ = agopen(const_cast<char *>("g"), Agdirected, 0);
    }
  }

  int edge_cnt_ = 0;
  GVC_t *gvc_;
  Agraph_t *gv_;
  GraphDrawType type_;
  std::string name_;
};

#pragma GCC diagnostic pop

#endif  // BYTEME_DEBUG_H_
