FROM ubuntu:25.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    git \
    curl \
    build-essential \
    libssl-dev \
    libjson-c-dev \
    libwebsockets-dev \
    && rm -rf /lib/apt/lists/*

RUN curl -LO https://github.com/tsl0922/ttyd/releases/download/1.7.3/ttyd.x86_64 && \
    chmod +x ttyd.x86_64 && \
    mv ttyd.x86_64 /usr/local/bin/ttyd

WORKDIR /app

COPY . .

RUN g++ main.cpp roleta.cpp -o roleta_jogo

EXPOSE 10000

CMD ["ttyd", "-p", "10000", "-i", "lo", "bash", "-c", "while true; do ./roleta_jogo; echo 'Pressione ENTER para jogar novamente...'; read; done"]