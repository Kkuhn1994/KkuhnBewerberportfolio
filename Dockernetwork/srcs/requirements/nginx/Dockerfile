FROM debian:bullseye

RUN apt update && apt upgrade && apt install -y \
	nginx

COPY default /etc/nginx/sites-available/.

ENTRYPOINT ["nginx", "-g", "daemon off;"]