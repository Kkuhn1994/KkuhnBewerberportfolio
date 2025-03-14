FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    redis-server \
    php-redis \
    php-fpm \
    php-mysqli \
    curl \
    && apt-get clean

RUN mkdir -p /run/php && chown -R www-data:www-data /run/php && chmod 755 /run/php

COPY ./script2.sh ./script.sh
RUN chmod +x script.sh
COPY www.conf /etc/php/7.4/fpm/pool.d/.

ENTRYPOINT ["./script.sh"]