FROM duckll/ctf-box:latest

ENV ALGO=/root/algos

RUN apt-fast update && \
    apt-fast -y install zsh && \
    apt-fast -y install valgrind && \
    apt-fast -y install npm && \
    apt-fast -y install clang && \
    ln -sf /usr/bin/nodejs /usr/bin/node && \
    git clone https://github.com/landcold7/dotfiles.git /root/.dotfiles && \
    bash /root/.dotfiles/script/bootstrap -p || echo "Errors occur."
