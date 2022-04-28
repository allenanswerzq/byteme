/* created   : 2020-10-04 11:18:16
 * accepted  : 2020-10-04 12:04:40
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

#define BINARY_TOKENS(f) \
  f(TOKEN_LEFT_P, /)    \
  f(TOKEN_RIGHT_P, /)   \
  f(TOKEN_PLUS, +)      \
  f(TOKEN_MINUS, -)     \
  f(TOKEN_STAR, *)      \
  f(TOKEN_SLASH, /)

#define ALL_TOKENS(f)     \
  BINARY_TOKENS(f)        \
  f(TOKEN_NUM, "NUM")

enum TokenType {
#define def_token(x, ...) x,
  ALL_TOKENS(def_token)
#undef def_token
};

struct Token {
  string literal_;
  TokenType type_;
};

struct Node;
struct Vistor;
struct BinaryNode;
struct UnaryNode;
struct LiteralNode;
struct GroupNode;

struct Node {
  virtual void accept(Vistor *vistor) = 0;
  virtual string toString() = 0;
};

struct Vistor {
  void visit(Node *node) { node->accept(this); }
  virtual void visitBinaryNode(BinaryNode *node) = 0;
  virtual void visitUnaryNode(UnaryNode *node) = 0;
  virtual void visitLiteralNode(LiteralNode *node) = 0;
  virtual void visitGroupNode(GroupNode *node) = 0;
};

struct BinaryNode : public Node {
  Token op;
  struct Node *left = nullptr;
  struct Node *right = nullptr;

  BinaryNode(Token o, Node *l, Node *r) : op(o), left(l), right(r) {}

  void accept(Vistor *vistor) override { vistor->visitBinaryNode(this); }

  string toString() {
#define get_string(t, c) case t: return #c;
    switch (op.type_) {
      default: { assert(false); return "x"; }
      BINARY_TOKENS(get_string)
    };
#undef get_string
  }
};

struct UnaryNode : public Node {
  Token op;
  struct Node *node = nullptr;

  UnaryNode(Token o, Node *n) : op(o), node(n) {}

  string toString() { return "-"; }

  void accept(Vistor *vistor) override { vistor->visitUnaryNode(this); }
};

struct LiteralNode : public Node {
  string literal;

  LiteralNode(const string &l) : literal(l) {}
  string toString() { return literal; }

  void accept(Vistor *vistor) override { vistor->visitLiteralNode(this); }
};

struct GroupNode : public Node {
  struct Node *expr = nullptr;

  GroupNode(Node *e) : expr(e) {}

  string toString() { return "Group"; }

  void accept(Vistor *vistor) override { vistor->visitGroupNode(this); }
};


struct ASTPrinter : public Vistor {

  void visitBinaryNode(BinaryNode *node) override {
    cout << "(";
    node->left->accept(this);
    cout << node->toString();
    node->right->accept(this);
    cout << ")";
  }

  void visitUnaryNode(UnaryNode *node) override {
    cout << node->toString();
    node->node->accept(this);
  }

  void visitLiteralNode(LiteralNode *node) override {
    cout << node->toString();
  }

  void visitGroupNode(GroupNode *node) override {
    cout << "(group ";
    node->expr->accept(this);
    cout << ")";
  }
};

struct Calculator : public Vistor {
  unordered_map<Node*, int> mp;

  void visitBinaryNode(BinaryNode *node) override {
    if (!node) return;
    node->left->accept(this);
    node->right->accept(this);
#define binary_op(t, op) case t: { mp[node] = mp[node->left] op mp[node->right]; break; }
    switch (node->op.type_) {
      default : { assert(false); }
      BINARY_TOKENS(binary_op)
    }
#undef binary_op
  }

  void visitUnaryNode(UnaryNode *node) override {
    if (!node) return;
    node->node->accept(this);
    mp[node] = -mp[node->node];
  }

  void visitLiteralNode(LiteralNode *node) override {
    if (!node) return;
    mp[node] = stoi(node->literal);
  }

  void visitGroupNode(GroupNode *node) override {
    if (!node) return;
    node->expr->accept(this);
    mp[node] = mp[node->expr];
  }
};

vector<Token> tokenrize(string S) {
  int n = S.size();
  vector<Token> ans;
  for (int i = 0; i < n; i++) {
    while (i < n && S[i] == ' ') i++;
    if (S[i] == '(') {
      ans.push_back(Token{"(", TOKEN_LEFT_P});
    }
    else if (S[i] == ')') {
      ans.push_back(Token{")", TOKEN_RIGHT_P});
    }
    else if (S[i] == '+') {
      ans.push_back(Token{string(1, S[i]), TOKEN_PLUS});
    }
    else if (S[i] == '-') {
      ans.push_back(Token{string(1, S[i]), TOKEN_MINUS});
    }
    else if (S[i] == '*') {
      ans.push_back(Token{string(1, S[i]), TOKEN_STAR});
    }
    else if (S[i] == '/') {
      ans.push_back(Token{string(1, S[i]), TOKEN_STAR});
    }
    else {
      int j = i;
      while (i < n && '0' <= S[i] && S[i] <= '9') {
        i++;
      }
      ans.push_back(Token{S.substr(j, i - j), TOKEN_NUM});
      i--;
    }
  }
  return ans;
}

// BNF
// expression     → term ;
// term           → factor ( ( "-" | "+" ) factor )* ;
// factor         → unary ( ( "/" | "*" ) unary )* ;
// unary          → ( "!" | "-" ) unary
//                | primary ;
// primary        → NUMBER | STRING | "true" | "false" | "nil"
//                | "(" expression ")" ;
// recusive desent parser
struct Parser {
  int cur_ = 0;
  vector<Token> token_;

  Parser(const vector<Token> &token) : token_(token) {}

  void advance() {
    assert(cur_ < token_.size());
    cur_ += 1;
  }

  Token previous() {
    assert(cur_ > 0);
    return token_[cur_ - 1];
  }

  Token peek() {
    assert(cur_ < token_.size());
    return token_[cur_];
  }

  void consume(TokenType type, const string &msg) {
    assert(peek().type_ == type);
    advance();
  }

  bool match(const vector<TokenType> &tokens) {
    for (auto t : tokens) {
      if (cur_ < token_.size() && peek().type_ == t) {
        advance();
        return true;
      }
    }
    return false;
  }

  // expr --> term
  Node *parse_expr() { return parse_term(); }

  // term --> factor ( ( "-" | "+" ) factor )* ;
  Node *parse_term() {
    Node *left = parse_factor();
    while (match({TOKEN_MINUS, TOKEN_PLUS})) {
      Token op = previous();
      Node *right = parse_factor();
      left = new BinaryNode(op, left, right);
    }
    return left;
  }

  // factor --> unary ( ( "/" | "*" ) unary )* ;
  Node *parse_factor() {
    Node *left = parse_unary();
    while (match({TOKEN_SLASH, TOKEN_STAR})) {
      Token op = previous();
      Node *right = parse_unary();
      left = new BinaryNode(op, left, right);
    }
    return left;
  }

  // unary --> ( "!" | "-" ) unary | primary ;
  Node *parse_unary() {
    if (match({TOKEN_MINUS})) {
      Token op = previous();
      Node *root = parse_unary();
      return new UnaryNode(op, root);
    }
    return parse_primary();
  }

  // primary --> NUMBER | STRING | "true" | "false" | "nil"
  //             | "(" expression ")" ;
  Node *parse_primary() {
    if (match({TOKEN_NUM})) {
      return new LiteralNode(previous().literal_);
    } else if (match({TOKEN_LEFT_P})) {
      auto root = parse_expr();
      consume(TOKEN_RIGHT_P, "Expect ) after matching");
      return new GroupNode(root);
    }
    assert(false);
  }
};

class Solution {
public:
  int calculate(string S) {
    Parser p(tokenrize(S));
    Node *root = p.parse_expr();
    assert(root);
    ASTPrinter printer;
    root->accept(&printer);
    Calculator cal;
    root->accept(&cal);
    return cal.mp[root];
  }
};
