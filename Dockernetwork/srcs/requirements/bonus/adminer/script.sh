#!/bin/bash

docker stop adminer
docker rm adminer
# docker build -t my-adminer .
# docker run -d -p 8080:8080 --name adminer my-adminer