#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>

// A general class for drawing a graph.
class Graphviz {
public:
  Graphviz(const string &name) : name_(name) { create_context(); }

  void AddEgde(const string &u, const string &v, const string& label="") {
    Agnode_t *n = agnode(gv_, (char*) u.c_str(), 1);
    Agnode_t *m = agnode(gv_, (char*) v.c_str(), 1);
    Agedge_t *e = agedge(gv_, n, m, 0, 1);
    agsafeset(e, const_cast<char *>("label"), (char *) label.c_str(),
              const_cast<char *>(""));
  }

  void DrawGraph() {
    // Set layout engine.
    gvLayout(gvc_, gv_, "dot");
    name_ += ".pdf";
    cout << name_ << endl;
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
