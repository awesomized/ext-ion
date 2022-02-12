FROM php:8.1-cli

RUN apt-get update -qy \
    && DEBIAN_FRONTEND=noninteractive \
    apt-get install -qy \
    	build-essential \
    	git \
        unzip \
    	libcurl4-openssl-dev \
    	libicu-dev \
    	libssl-dev \
    	zlib1g-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /tmp

RUN \
	curl -sSLO https://replicator.pharext.org/phars/raphf/raphf-2.0.1.ext.phar &&\
	curl -sSLO https://replicator.pharext.org/phars/pecl_http/pecl_http-4.2.1.ext.phar &&\
	touch /usr/local/etc/php/conf.d/pecl.ini &&\
	php raphf-*.ext.phar -vi /usr/local/etc/php/conf.d/pecl.ini &&\
	php pecl_http-*.ext.phar -vi /usr/local/etc/php/conf.d/pecl.ini &&\
    rm -f *.ext.phar

WORKDIR /app

# UID is readonly in shell env
ARG USERID=1000
RUN useradd -M -N -d /app -g users -u $USERID -o user

USER user
ENTRYPOINT ["/usr/local/bin/php"]
