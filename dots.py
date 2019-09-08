#!/usr/bin/env python
import sys
import graphviz as gv

# Generate a dot graph
def gen(file, direct=False):
  with open(file, 'r') as f:
    raw = f.read().strip().split('\n')
  # print(raw[0])
  v = [int(x) for x in raw[0].split(' ')]
  if len(v) == 1:
    n = v[0]
    m = n
  else:
    n, m = v
  print(n, m);
  if direct:
    dot = gv.Digraph(comment="Dot graph " + file);
  else:
    dot = gv.Graph(comment="Dot graph " + file);

  for i in range(1, m + 1):
    u, v = [x for x in raw[i].split(' ')]
    dot.node(u, u)
    dot.node(v, v)
    dot.edge(u, v)
  # print(dot.source)
  dot.render(file + '.gv', view=True)

if __name__ == "__main__":
  if len(sys.argv) < 2:
    print("""\
      Usage: dots file -d(optional: direct graph)""")
    exit(0);
  direct = False
  if len(sys.argv) >= 3:
    if sys.argv[2] == "-d":
      direct = True
  gen(sys.argv[1], direct);

