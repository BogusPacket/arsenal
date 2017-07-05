#!/bin/sh
sudo apt-get -y install build-essential python-dev
sudo apt-get -y install apache2
sudo apt-get -y install mysql-server
sudo service apache2 stop
sudo service mysql stop
sudo apt-get -y install php php-mbstring php-gettext libapache2-mod-php
sudo apt-get install -y python-pip
sudo pip install --upgrade pip
sudo pip install mysql-connector-python-rf
sudo apt-get -y install phpmyadmin
sudo phpenmod mcrypt
sudo phpenmod mbstring
sudo cp ./../../config/phpmyadmin.conf /etc/apache2/conf-available/phpmyadmin.c$
sudo apt-get update
sudo apt-get upgrade



