#!/usr/bin/env python
import sys
import graphviz as gv

# Generate a dot graph
def gen(file, direct=False, zero_index=True):
  with open(file, 'r') as f:
    raw = f.read().strip().split('\n')

  v = [int(x) for x in raw[0].split(' ')]
  n, m = (v[0], n) if len(v) == 1 else (v[0], v[1])
  print(n, m)

  cmts="Dot graph " + file
  dot = gv.Digraph(comment=cmts) if direct else gv.Graph(comment=cmts);

  start, end = (0, n) if zero_index else (1, n + 1)
  for i in range(start, end):
    dot.node(str(i), str(i))

  for i in range(1, m + 1):
    u, v = [int(x) for x in raw[i].split(' ')]
    if zero_index:
      u -= 1
      v -= 1
    dot.edge(str(u), str(v))

  dot.render(file + '.gv', view=True)

if __name__ == "__main__":
  if len(sys.argv) < 2:
    print("""\
      Usage: dots file
      -d(optional: direct graph)
      -i(optional: default zero index)""")
    exit(0);
  direct = False
  zero_index=True
  if len(sys.argv) >= 3:
    for argv in sys.argv[1:]:
      if argv == "-d":
        direct = True
      elif argv == "-i":
        zero_index = False

  gen(sys.argv[1], direct, zero_index);

