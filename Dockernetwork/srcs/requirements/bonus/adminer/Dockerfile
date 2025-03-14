FROM debian:bullseye

# Installiere benötigte Pakete
RUN apt-get update && apt-get install -y \
    apache2 \
    php \
    php-mysqli \
    php-pgsql \
    php-sqlite3 \
    curl \
    && apt-get clean

# Entferne die Standard-Indexdatei von Apache
RUN rm -f /var/www/html/index.html

# Installiere Adminer
RUN curl -o /var/www/html/adminer.php https://www.adminer.org/static/download/4.8.1/adminer-4.8.1.php

# Erstelle eine index.php, die zu adminer.php weiterleitet
RUN echo '<?php header("Location: /adminer.php"); ?>' > /var/www/html/index.php

# Apache-Konfiguration anpassen
RUN echo "ServerName localhost" >> /etc/apache2/apache2.conf
RUN echo '<?php phpinfo(); ?>' > /var/www/html/phpinfo.php
RUN sed -i 's/Listen 80/Listen 8080/g' /etc/apache2/ports.conf
RUN sed -i 's/*:80/*:8080/g' /etc/apache2/sites-available/000-default.conf

# Stelle sicher, dass Apache SSL-bezogene Anfragen korrekt behandelt
RUN echo 'SetEnvIf X-Forwarded-Proto "https" HTTPS=on' >> /etc/apache2/apache2.conf

# PHP-Modul aktivieren
RUN a2enmod php7.4
RUN service apache2 restart

EXPOSE 8080

CMD ["apache2ctl", "-D", "FOREGROUND"]