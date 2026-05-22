#!/usr/bin/env bash

ROOT_DIR=$(cd $(dirname ${BASH_SOURCE[0]}) && pwd)

#####################################################################
#               For secure signing of NGINX server
#####################################################################

# Copy the self-signed file to appropriate ngix directory
cp $ROOT_DIR/data/self-signed.conf /etc/nginx/snippets/self-signed.conf

# Copy nginx configuration file to default location
cp $ROOT_DIR/data/nginx.default /etc/nginx/sites-available/default

# Copy nginx httpd configuration to its appropriate location
cp $ROOT_DIR/data/nginx.conf /etc/nginx/nginx.conf

# Firewall setting to HTTPS connection
ufw allow 'Nginx Full'

#####################################################################
#              Restart nginx
#####################################################################
systemctl restart nginx

