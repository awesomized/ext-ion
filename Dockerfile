FROM php:8.1-cli

RUN apt-get update -qy \
    && DEBIAN_FRONTEND=noninteractive \
    apt-get install -qy cmake git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /tmp
COPY . ion/
RUN cd ion && \
    phpize && \
    ./configure && \
    make clean && \
    make -j $(nproc) && \
    make install INSTALL=install && \
    docker-php-ext-enable ion && \
    rm -rf /tmp/ion
