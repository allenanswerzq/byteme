docker build -t algos-box .
docker run -idt --name algos -p 3333:3333 --privileged \
           -v ~/Code/algos:/root/algos --security-opt seccomp:unconfined algos-box

