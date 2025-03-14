# Verwende das offizielle Debian Bullseye Image als Basis
FROM debian:bullseye

# Aktualisiere die Paketlisten und installiere Apache
RUN apt-get update && \
    apt-get install -y apache2 && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN rm -f /var/www/html/index.html

# Kopiere die statische Seite ins Webverzeichnis

COPY index.html /var/www/html/.


# Konfiguriere Apache, um auf Port 81 zu lauschen
RUN sed -i 's/Listen 80/Listen 81/g' /etc/apache2/ports.conf && \
    sed -i 's/<VirtualHost \*:80>/<VirtualHost *:81>/g' /etc/apache2/sites-available/000-default.conf

# Starte Apache im Vordergrund
CMD ["apachectl", "-D", "FOREGROUND"]