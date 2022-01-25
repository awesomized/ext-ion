FROM php:8.1-cli

RUN apt-get update -qy \
    && DEBIAN_FRONTEND=noninteractive \
    apt-get install -qy \
    	build-essential \
    	git \
    	libcurl4-openssl-dev \
    	libicu-dev \
    	libssl-dev \
    	zlib1g-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /tmp

RUN \
	curl -sSLO https://getcomposer.org/download/2.2.5/composer.phar &&\
	curl -sSLO https://replicator.pharext.org/phars/raphf/raphf-2.0.1.ext.phar &&\
	curl -sSLO https://replicator.pharext.org/phars/pecl_http/pecl_http-4.2.1.ext.phar
RUN \
	touch /usr/local/etc/php/conf.d/pecl.ini &&\
	php raphf-*.ext.phar -vi /usr/local/etc/php/conf.d/pecl.ini &&\
	php pecl_http-*.ext.phar -vi /usr/local/etc/php/conf.d/pecl.ini

WORKDIR /app
ENTRYPOINT ["php", "/tmp/composer.phar"]

