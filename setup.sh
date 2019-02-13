#!/bin/bash
mkdir -p ~/.local/bin/

ln -sf $ALGO/sketch      ~/.local/bin/sketch
ln -sf $ALGO/algo-run    ~/.local/bin/algo-run
ln -sf $ALGO/algo-make   ~/.local/bin/algo-make
ln -sf $ALGO/algo-split  ~/.local/bin/algo-split

cd third_party/bytedump
npm install
npm start

