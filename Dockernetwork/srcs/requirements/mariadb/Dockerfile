FROM debian:bullseye

RUN apt update && apt upgrade && apt install -y \
	mariadb-server \
	gettext

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/.
COPY init.sql.template .
COPY script.sh .



RUN chmod +x script.sh 
RUN	mkdir /run/mysqld

ENTRYPOINT ["./script.sh"]
