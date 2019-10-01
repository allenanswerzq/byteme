#!/bin/bash
mkdir -p $HOME/.local/bin/

ln -sf "$ALGO/sketch"       "$HOME/.local/bin/sketch"
ln -sf "$ALGO/byte-run"     "$HOME/.local/bin/byte-run"
ln -sf "$ALGO/byte-make"    "$HOME/.local/bin/byte-make"
ln -sf "$ALGO/byte-split"   "$HOME/.local/bin/byte-split"

ln -sf "$ALGO/sketch"       "$HOME/.local/bin/sketch"
ln -sf "$ALGO/byte-run"     "$HOME/.local/bin/algo-run"
ln -sf "$ALGO/byte-make"    "$HOME/.local/bin/algo-make"
ln -sf "$ALGO/byte-split"   "$HOME/.local/bin/algo-split"

cd third_party/bytedump
npm install
npm start

