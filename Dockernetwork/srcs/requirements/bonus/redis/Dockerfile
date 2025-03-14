FROM debian:bullseye


RUN apt-get update && apt-get install -y \
    redis-server \
    && rm -rf /var/lib/apt/lists/* \
	apt-get install iputils-ping

CMD ["redis-server"]