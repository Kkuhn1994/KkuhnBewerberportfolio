#!/bin/bash

# Set and export variables
export DB_NAME=$(cat /run/secrets/db_name)
export ROOT_USER=$(cat /run/secrets/root_user)
export ROOT_PASSWORD=$(cat /run/secrets/root_password)
export USER=$(cat /run/secrets/user)
export PASSWORD=$(cat /run/secrets/password)

envsubst < init.sql.template > /etc/mysql/init.sql

mysql_install_db
mysqld