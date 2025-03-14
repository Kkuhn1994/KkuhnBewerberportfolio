#!/bin/bash

DB_NAME=$(cat /run/secrets/db_name)
ROOT_USER=$(cat /run/secrets/root_user)
ROOT_PASSWORD=$(cat /run/secrets/root_password)
USER=$(cat /run/secrets/user)
PASSWORD=$(cat /run/secrets/password)

cd /var/www/html
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar


./wp-cli.phar core download --allow-root
./wp-cli.phar config create --dbname=$DB_NAME --dbuser=$ROOT_USER --dbpass=$ROOT_PASSWORD --dbhost=mariadb --allow-root
./wp-cli.phar core install --url=localhost --title=inception --admin_user=$ROOT_USER --admin_password=$ROOT_PASSWORD --admin_email=$ROOT_USER@example.com --allow-root
./wp-cli.phar user create $USER $USER@example.com --user_pass=$PASSWORD --role=subscriber --allow-root

./wp-cli.phar user list --allow-root

# Install Redis Object Cache plugin
./wp-cli.phar plugin install redis-cache --activate --allow-root

# Add Redis configuration to wp-config.php
./wp-cli.phar config set WP_REDIS_HOST redis --allow-root
./wp-cli.phar config set WP_REDIS_PORT 6379 --allow-root
./wp-cli.phar config set WP_REDIS_CLIENT phpredis --allow-root
./wp-cli.phar config set WP_REDIS_DATABASE 0 --allow-root


# Enable Redis Object Cache
./wp-cli.phar redis enable --allow-root

php-fpm7.4 -F