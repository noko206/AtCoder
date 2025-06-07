FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    git \
    gcc-12 \
    g++-12 \
    php8.2-cli \
    php8.2-mbstring

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 12 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 12 && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN echo "alias ll='ls -la'" >> ~/.bashrc && \
    echo "alias g='g++ -o a -I .'" >> ~/.bashrc && \
    echo 'export HISTCONTROL=ignoreboth' >> ~/.bashrc

CMD ["bash"]
