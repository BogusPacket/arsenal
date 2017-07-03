#!/bin/sh
sudo apt-get -y install build-essential python-dev
sudo apt-get -y install apache2
sudo apt-get -y install mysql-server
sudo apt-get -y install php
sudo apt-get -y install libapache2-mod-php
sudo service apache2 restart
sudo apt-get -y update
sudo apt-get -y upgrade
sudo apt-get -y install phpmyadmin
sudo phpenmod mcrypt

