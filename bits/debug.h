#ifndef BYTEME_DEBUG_H_
#define BYTEME_DEBUG_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define EXIT "\033[0m"
#define CYAN "\033[0;36m"

template <class T> struct rge { T b, e; };
template <class T> rge<T> range(T i, T j) { return rge<T>{i, j}; }
template <class T> char dud(...);
template <class T> auto dud(T *x) -> decltype(cout << *x, 0);

template <typename T> struct is_vector : public std::false_type {};
template <typename T, typename A>
struct is_vector<std::vector<T, A>> : public std::true_type {};

template <class T> static void __display_mat(vector<vector<T>> &v) {
  int n = v.size();
  int m = v[0].size();
  int width = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // string str = to_string(j) + "/" + to_string(v[i][j]);
      string str = to_string(v[i][j]);
      width = max(width, (int)str.size());
    }
  }
  fprintf(stderr, "\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // string head = to_string(j);
      string tail = to_string(v[i][j]);
      // string str = head + "/";
      // string str = head;
      string str;
      for (int x = 0 + tail.size() + 1; x < width; x++) {
        str += " ";
      }
      str += tail;
      fprintf(stderr, "%*s", width, str.c_str());
      if (j != m - 1) {
        fprintf(stderr, ", ");
      }
    }
    fprintf(stderr, "\n");
  }
}

struct debug {
  template <class T, class N>
  typename enable_if<std::is_pointer<T>::value, debug &>::type
  operator<<(std::tuple<T, N> &array) {
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

  template <class T, class N>
  typename enable_if<is_vector<T>::value, debug &>::type
  operator<<(std::tuple<T, N> &array) {
    // Real place where printing out a vector with custom size N.
    auto mat = std::get<0>(array);
    int n = std::get<1>(array);
    debug() << "[";
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        debug() << ", ";
      }
      // debug() << i << "/" << mat[i];
      debug() << mat[i];
    }
    debug() << "]";
    return *this;
  }

  template <class T, class H, class W>
  typename enable_if<std::is_pointer<T>::value, debug &>::type
  operator<<(std::tuple<T, H, W> &array) {
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

  template <class T> debug &operator<<(vector<vector<T>> &v) {
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
  typename enable_if<sizeof(dud<T>(0)) != 1, debug &>::type operator<<(T i) {
    if (is_floating_point<T>::value) {
      cerr << setprecision(20) << fixed << i << flush;
    } else {
      cerr << i << flush;
    }
    return *this;
  }

  template <class T>
  typename enable_if<sizeof(dud<T>(0)) == 1, debug &>::type operator<<(T i) {
    return *this << range(begin(i), end(i));
  }

  template <class T, class b> debug &operator<<(pair<b, T> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }

  template <class T, class b> debug &operator<<(vector<pair<b, T>> v) {
    int n = v.size();
    *this << "[";
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        *this << ", ";
      }
      *this << "(" << v[i].first << ", " << v[i].second << ")";
    }
    *this << "]";
    return *this;
  }

  template <class T> debug &operator<<(rge<T> d) {
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

template <typename T> void __print(const string &names, T arg) {
  string name(names);
  if ((int)name.find("make_tuple") != -1 || (int)name.find("mt") != -1) {
    int s = name.find('(');
    int t = name.find(',');
    assert(t - s - 1 > 0);
    name = name.substr(s + 1, t - s - 1);
  }
  // TODO(): figure out why this messed up debug stream?
  // if (is_same<T, const char*>::value) {
  //   debug() << arg << "\n";
  // }
  // else {
  debug() << name << ": " << arg << "\n";
  // }
}

template <typename T, typename... Args>
void __print(const string &namexx, T arg, Args... args) {
  int p = -1;
  string names(namexx);
  int n = names.size();
  int x = (int)names.find('(');
  int y = (int)names.find(',');
  if (x != -1 && y != -1 && x < y) {
    // Looking for `()` pair first
    // handle calls like `trace(foo(a, b))`
    p = names.find(')');
    assert(0 <= p && p < n);
    p = names.find(',', p + 1);
  } else {
    // Now looking for comma sign to split varibles.
    p = names.find(',');
  }
  assert(p != -1);
  string name = names.substr(0, p);
  if ((int)name.find("make_tuple") != -1 || (int)name.find("mt") != -1) {
    // Hacking to print out an array.
    // eg. trace(make_tuple(arr, w))
    // eg. trace(make_tuple(arr, h, w))
    int s = name.find('(');
    int t = name.find(',');
    assert(t - s - 1 > 0);
    name = name.substr(s + 1, t - s - 1);
  }
  if (is_same<T, const char *>::value) {
    // Add distinguish string at the beginning.
    // So that we can add comments for trace call
    // eg. trace("TEST", var1, var2);
    int w = name.size();
    debug() << name.substr(1, w - 2) << ": | ";
  } else {
    debug() << name << ": " << arg << " | ";
    // __print(name.c_str(), arg);
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
  debug() << CYAN << "{" << fn << ":" << ln << "} " << EXIT;
  __print(var, arg, args...);
}

#define dbg(...) __dbg(__LINE__, __func__, #__VA_ARGS__, (__VA_ARGS__))

template <typename T>
T &&__dbg(int ln, const string &fn, const string &expr, T &&val) {
  debug() << CYAN << "{" << fn << ":" << ln << "} " << EXIT << expr << " = "
          << val << '\n';
  return std::forward<T>(val);
}

#define debugstream debug

#define xuyixuyi() __set_timer(__LINE__, __func__)
void __set_timer(int line, const string &fn) {
  static clock_t __start_time = -1;
  static bool __start_flag = false;
  static int __last_line = -1;
  clock_t __curr_time = std::clock();
  int __curr_line = line;
  if (__start_flag) {
    cerr << CYAN << "{xuyixuyi:" << fn << "("
         << __last_line << "->" << __curr_line
         << ")} " << EXIT << fixed << std::setprecision(2)
         << 1000.0 * (__curr_time - __start_time) / CLOCKS_PER_SEC << " ms\n";
  }
  if (__start_flag == false) {
    __start_flag = true;
    __last_line = line;
  }
  __start_time = __curr_time;
  __last_line = __curr_line;
}

template<class T> void puts(T t) { cout << t << "\n"; }
template<class T, class U, class... G>
void puts(T t, U u, G... g) { cout << t << " "; puts(u, g...); }

#define assertm(exp, msg) assert(((void)msg, exp))
#define mt make_tuple

#else

template <typename T>
T&& identity(T&& t) {
  return std::forward<T>(t);
}

#define trace(...)
#define dbg(...) identity(__VA_ARGS__)

#endif

// https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Pragmas.html
// #pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wcast-qual"

#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>

class Graphviz {
public:
  explicit Graphviz(const string &name) : name_(name) { create_context(); }

  void add_edge(const string &u, const string &v, const string& label="") {
    Agnode_t *n = agnode(gv_, (char*) u.c_str(), 1);
    Agnode_t *m = agnode(gv_, (char*) v.c_str(), 1);
    Agedge_t *e = agedge(gv_, n, m, 0, 1);
    agsafeset(e, const_cast<char *>("label"), (char *) label.c_str(),
              const_cast<char *>(""));
  }

  void draw_graph() {
    // Set layout engine.
    gvLayout(gvc_, gv_, "dot");
    name_ += ".pdf";
    gvRenderFilename(gvc_, gv_, "pdf", name_.c_str());

    gvFreeLayout(gvc_, gv_);
    agclose(gv_);
    gvFreeContext(gvc_);
  }

private:
  // Set up a graphviz context.
  void create_context() {
    gvc_ = gvContext();
    gv_ = agopen(const_cast<char *>("g"), Agdirected, 0);
  }

  GVC_t *gvc_;
  Agraph_t *gv_;
  std::string name_;
};

#endif // BYTEME_DEBUG_H_
