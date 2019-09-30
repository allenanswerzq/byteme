#!/bin/bash
mkdir -p ~/.local/bin/

ln -sf $ALGO/sketch      ~/.local/bin/sketch
ln -sf $ALGO/byte-run    ~/.local/bin/byte-run
ln -sf $ALGO/byte-make   ~/.local/bin/byte-make
ln -sf $ALGO/byte-split  ~/.local/bin/byte-split
ln -sf $ALGO/clean       ~/.local/bin/byte-clean

ln -sf $ALGO/sketch      ~/.local/bin/sketch
ln -sf $ALGO/byte-run    ~/.local/bin/algo-run
ln -sf $ALGO/byte-make   ~/.local/bin/algo-make
ln -sf $ALGO/byte-split  ~/.local/bin/algo-split
ln -sf $ALGO/clean       ~/.local/bin/algo-clean

cd third_party/bytedump
npm install
npm start

